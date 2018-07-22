#include "NetworkThread.h"

NetworkThread::NetworkThread(QObject *parent) : QObject(parent)
{
    m_isConnectedToHost = false;
    m_isSending = false;
    m_sendFlag = false;
    m_rateLimter.set_burst(1024*2);
    m_socket = NULL;

    connect(this, SIGNAL(sigStartSend()),
            this, SLOT(onStartSend()));
    connect(this, SIGNAL(sigConnectToHost(QString,int)),
            this, SLOT(onConnectToHost(QString,int)));

    this->moveToThread(&m_thread);
    m_thread.start();
}

NetworkThread::~NetworkThread()
{
    m_thread.quit();
    m_thread.wait();
}

void NetworkThread::closeConnection()
{
    if (m_isSending) {
        m_sendFlag = false;
    }

    m_socket->close();
}

bool NetworkThread::connectToHost(const QString &ip, int port, QString *errmsg)
{
    emit sigConnectToHost(ip, port);
    return true;
}

void NetworkThread::startSend()
{
    m_sendFlag = true;
    emit sigStartSend();
}

void NetworkThread::stopSend()
{
    m_sendFlag = false;
}

void NetworkThread::setRate(int rate)
{
    m_rateLimter.set_rate(rate);
}

bool NetworkThread::isSending() const
{
    return m_isSending;
}

void NetworkThread::onConnectToHost(QString ip, int port)
{
    m_socket = new QTcpSocket();
    m_socket->connectToHost(ip, port);
    if (!m_socket->waitForConnected(1000)) {
        QString errmsg = m_socket->errorString();
        return;
    }

    m_isConnectedToHost = true;
}

void NetworkThread::onStartSend()
{
    QString data("1234567890abcdefghijklmnopqrstuvwxyz");

    m_isSending = true;
    while (m_sendFlag) {
        m_rateLimter.aquire(data.size());
        int len = m_socket->write(data.toLocal8Bit().data());
        if (-1 == len) {
            QString err = m_socket->errorString();
            break;
        }
        m_socket->flush();
        emit sendLength(len);
    }
    m_isSending = false;

    emit sendStoped();
}


#ifndef NETWORKTHREAD_H
#define NETWORKTHREAD_H

#include <QObject>
#include <QThread>
#include <QtNetwork/QTcpSocket>
#include "TokenBucket.h"

class NetworkThread : public QObject
{
    Q_OBJECT
public:
    explicit NetworkThread(QObject *parent = 0);
    ~NetworkThread();
    void closeConnection();
    bool connectToHost(const QString& ip, int port, QString* errmsg = NULL);

    void startSend();
    void stopSend();
    void setRate(int rate);

    bool isConnectedToHost() const {return m_isConnectedToHost;}
    bool isSending() const;


signals:
    void sigConnectToHost(QString ip, int port);
    void sendLength(int len);
    void sigStartSend();

    void sendStoped();
    void connectionClosed();

private slots:
    void onConnectToHost(QString ip, int port);
    void onStartSend();

private:
    QThread m_thread;
    bool m_isConnectedToHost;
    bool m_isSending;
    bool m_sendFlag;
    TokenBucket m_rateLimter;

    QTcpSocket *m_socket;
};

#endif // NETWORKTHREAD_H

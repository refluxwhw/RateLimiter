#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegExpValidator>
#include <QRegExp>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_len = 0;
    m_isconn = false;

    QRegExpValidator *validator = new QRegExpValidator(this);
    validator->setRegExp(QRegExp("^"
                                 "(1\\d{2}|2[0-4]\\d|25[0-5]|[1-9]\\d|[1-9])\\."
                                 "(1\\d{2}|2[0-4]\\d|25[0-5]|[1-9]\\d|\\d)\\."
                                 "(1\\d{2}|2[0-4]\\d|25[0-5]|[1-9]\\d|\\d)\\."
                                 "(1\\d{2}|2[0-4]\\d|25[0-5]|[1-9]\\d|\\d)"
                                 "$"));
    ui->lineEdit_ip->setValidator(validator);

    connect(&m_net, SIGNAL(sendLength(int)), this, SLOT(onNetSendLength(int)));

    this->startTimer(1000);


    ui->pushButton_send->setEnabled(false);
    on_spinBox_speed_editingFinished();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    if (!m_isconn) {
        return;
    }

    ui->statusbar->showMessage(QString("%1 B/s").arg(m_len));
    m_len = 0;
}

void MainWindow::on_pushButton_connect_clicked()
{
    // connect or disconnect
    if (m_net.isConnectedToHost()) {
        ui->pushButton_send->setEnabled(false);
        ui->lineEdit_ip->setEnabled(true);
        ui->spinBox_port->setEnabled(true);
        m_net.closeConnection();
    } else {
        QString errmsg;
        m_isconn = m_net.connectToHost(ui->lineEdit_ip->text(), ui->spinBox_port->value(), &errmsg);
        if (m_isconn) {
            ui->pushButton_connect->setText("disconnect");
            ui->pushButton_send->setEnabled(true);
            ui->lineEdit_ip->setEnabled(false);
            ui->spinBox_port->setEnabled(false);
        } else {
            // show error
            ui->statusbar->showMessage(errmsg);
        }
    }
}

void MainWindow::on_pushButton_send_clicked()
{
    // start or stop send
    if (m_net.isSending()) {
        m_net.stopSend();
        ui->pushButton_send->setText("start send");
    } else {
        m_net.startSend();
        ui->pushButton_send->setText("stop send");
    }
}

void MainWindow::on_spinBox_speed_editingFinished()
{
    // change speed
    m_net.setRate(ui->spinBox_speed->value());
}

void MainWindow::onNetSendLength(int len)
{
    m_len += len;
}

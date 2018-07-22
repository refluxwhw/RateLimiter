#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "NetworkThread.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    virtual void timerEvent(QTimerEvent* event);

private slots:
    void on_pushButton_connect_clicked();
    void on_pushButton_send_clicked();
    void on_spinBox_speed_editingFinished();
    void onNetSendLength(int len);

private:
    Ui::MainWindow *ui;
    NetworkThread m_net;
    int m_len;
    bool m_isconn;
};

#endif // MAINWINDOW_H

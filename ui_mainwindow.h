/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_3;
    QLineEdit *lineEdit_ip;
    QLabel *label_2;
    QSpinBox *spinBox_port;
    QPushButton *pushButton_connect;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpinBox *spinBox_speed;
    QPushButton *pushButton_send;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(410, 96);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(50, 0));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_3);

        lineEdit_ip = new QLineEdit(centralwidget);
        lineEdit_ip->setObjectName(QStringLiteral("lineEdit_ip"));
        lineEdit_ip->setMinimumSize(QSize(110, 0));

        horizontalLayout->addWidget(lineEdit_ip);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(50, 0));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_2);

        spinBox_port = new QSpinBox(centralwidget);
        spinBox_port->setObjectName(QStringLiteral("spinBox_port"));
        spinBox_port->setMinimumSize(QSize(75, 0));
        spinBox_port->setMaximumSize(QSize(75, 16777215));
        spinBox_port->setMinimum(8888);
        spinBox_port->setMaximum(65536);

        horizontalLayout->addWidget(spinBox_port);

        pushButton_connect = new QPushButton(centralwidget);
        pushButton_connect->setObjectName(QStringLiteral("pushButton_connect"));

        horizontalLayout->addWidget(pushButton_connect);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(50, 0));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label);

        spinBox_speed = new QSpinBox(centralwidget);
        spinBox_speed->setObjectName(QStringLiteral("spinBox_speed"));
        spinBox_speed->setMinimumSize(QSize(75, 0));
        spinBox_speed->setMaximumSize(QSize(75, 16777215));
        spinBox_speed->setMinimum(1);
        spinBox_speed->setMaximum(999999999);

        horizontalLayout_2->addWidget(spinBox_speed);

        pushButton_send = new QPushButton(centralwidget);
        pushButton_send->setObjectName(QStringLiteral("pushButton_send"));

        horizontalLayout_2->addWidget(pushButton_send);


        verticalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label_3->setText(QApplication::translate("MainWindow", "Host:", 0));
        lineEdit_ip->setText(QApplication::translate("MainWindow", "127.0.0.1", 0));
        label_2->setText(QApplication::translate("MainWindow", "Port:", 0));
        pushButton_connect->setText(QApplication::translate("MainWindow", "connect", 0));
        label->setText(QApplication::translate("MainWindow", "Speed:", 0));
        spinBox_speed->setSuffix(QApplication::translate("MainWindow", " B/s", 0));
        pushButton_send->setText(QApplication::translate("MainWindow", "start send", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'mail_interface.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIL_INTERFACE_H
#define UI_MAIL_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mail_Interface
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Mail_Interface)
    {
        if (Mail_Interface->objectName().isEmpty())
            Mail_Interface->setObjectName("Mail_Interface");
        Mail_Interface->resize(800, 600);
        centralwidget = new QWidget(Mail_Interface);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(300, 220, 93, 29));
        Mail_Interface->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Mail_Interface);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        Mail_Interface->setMenuBar(menubar);
        statusbar = new QStatusBar(Mail_Interface);
        statusbar->setObjectName("statusbar");
        Mail_Interface->setStatusBar(statusbar);

        retranslateUi(Mail_Interface);

        QMetaObject::connectSlotsByName(Mail_Interface);
    } // setupUi

    void retranslateUi(QMainWindow *Mail_Interface)
    {
        Mail_Interface->setWindowTitle(QCoreApplication::translate("Mail_Interface", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("Mail_Interface", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mail_Interface: public Ui_Mail_Interface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIL_INTERFACE_H

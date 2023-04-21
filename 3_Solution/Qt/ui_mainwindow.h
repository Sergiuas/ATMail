/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *LoginBtn;
    QPushButton *RegisterBtn;
    QLabel *Logo;
    QLabel *UsernameLabel;
    QLabel *PasswordLabel;
    QLineEdit *textEditPassword;
    QLineEdit *textEditUserName;
    QCheckBox *checkBox;
    QLabel *mail_icon;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(464, 698);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(464, 698));
        MainWindow->setMaximumSize(QSize(464, 698));
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        LoginBtn = new QPushButton(centralwidget);
        LoginBtn->setObjectName("LoginBtn");
        LoginBtn->setGeometry(QRect(140, 500, 191, 61));
        LoginBtn->setCursor(QCursor(Qt::PointingHandCursor));
        LoginBtn->setStyleSheet(QString::fromUtf8("#LoginBtn {\n"
"background-color: transparent;\n"
"border-image: url(:Autentificare_off.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}\n"
"#LoginBtn:hover\n"
"{\n"
"border-image: url(:Autentificare_on.png);\n"
"}"));
        LoginBtn->setAutoDefault(true);
        RegisterBtn = new QPushButton(centralwidget);
        RegisterBtn->setObjectName("RegisterBtn");
        RegisterBtn->setGeometry(QRect(140, 570, 191, 61));
        RegisterBtn->setCursor(QCursor(Qt::PointingHandCursor));
        RegisterBtn->setStyleSheet(QString::fromUtf8("#RegisterBtn {\n"
"background-color: transparent;\n"
"border-image: url(:Inregistrare_off.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}\n"
"#RegisterBtn:hover\n"
"{\n"
"border-image: url(:Inregistrare_on.png);\n"
"}"));
        Logo = new QLabel(centralwidget);
        Logo->setObjectName("Logo");
        Logo->setGeometry(QRect(130, 10, 211, 201));
        Logo->setStyleSheet(QString::fromUtf8("#Logo {\n"
"background-color: transparent;\n"
"border-image: url(:Logo.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        UsernameLabel = new QLabel(centralwidget);
        UsernameLabel->setObjectName("UsernameLabel");
        UsernameLabel->setGeometry(QRect(200, 220, 181, 41));
        QFont font;
        font.setPointSize(18);
        UsernameLabel->setFont(font);
        UsernameLabel->setStyleSheet(QString::fromUtf8("#UsernameLabel\n"
"{\n"
"color:#fff;\n"
"background-color: transparent;\n"
"background:none;\n"
"}"));
        PasswordLabel = new QLabel(centralwidget);
        PasswordLabel->setObjectName("PasswordLabel");
        PasswordLabel->setGeometry(QRect(180, 330, 181, 41));
        PasswordLabel->setFont(font);
        PasswordLabel->setStyleSheet(QString::fromUtf8("#PasswordLabel\n"
"{\n"
"color:#fff;\n"
"background-color: transparent;\n"
"background:none;\n"
"}"));
        textEditPassword = new QLineEdit(centralwidget);
        textEditPassword->setObjectName("textEditPassword");
        textEditPassword->setGeometry(QRect(100, 390, 291, 41));
        QFont font1;
        font1.setPointSize(12);
        textEditPassword->setFont(font1);
        textEditPassword->setStyleSheet(QString::fromUtf8("#textEditPassword\n"
"{\n"
"color:#fff;\n"
"padding-right: 40px;\n"
"border: 2px solid white;\n"
"border-radius:10px;\n"
"}\n"
"\n"
"#textEditPassword:focus\n"
"{\n"
"border: 2px solid yellow;\n"
"}"));
        textEditPassword->setMaxLength(30);
        textEditPassword->setEchoMode(QLineEdit::Password);
        textEditUserName = new QLineEdit(centralwidget);
        textEditUserName->setObjectName("textEditUserName");
        textEditUserName->setGeometry(QRect(100, 270, 291, 41));
        textEditUserName->setFont(font1);
        textEditUserName->setStyleSheet(QString::fromUtf8("#textEditUserName\n"
"{\n"
"color:#fff;\n"
"padding-right: 40px;\n"
"border: 2px solid white;\n"
"border-radius:10px;\n"
"}\n"
"#textEditUserName:focus\n"
"{\n"
"border: 2px solid yellow;\n"
"}"));
        textEditUserName->setMaxLength(255);
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(355, 400, 88, 24));
        checkBox->setCursor(QCursor(Qt::PointingHandCursor));
        checkBox->setStyleSheet(QString::fromUtf8("#checkBox\n"
"{\n"
"background-color: transparent;\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {\n"
"    image: url(:showWhite.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    image: url(:hideWhite.png);\n"
"}"));
        mail_icon = new QLabel(centralwidget);
        mail_icon->setObjectName("mail_icon");
        mail_icon->setGeometry(QRect(353, 275, 31, 31));
        mail_icon->setStyleSheet(QString::fromUtf8("#mail_icon\n"
"{\n"
"background-color: transparent;\n"
"border-image: url(:mail_icon.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 464, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        LoginBtn->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        LoginBtn->setText(QString());
        RegisterBtn->setText(QString());
        Logo->setText(QString());
        UsernameLabel->setText(QCoreApplication::translate("MainWindow", "EMAIL", nullptr));
        PasswordLabel->setText(QCoreApplication::translate("MainWindow", "PASSWORD", nullptr));
        textEditPassword->setPlaceholderText(QCoreApplication::translate("MainWindow", "Introduceti parola", nullptr));
        textEditUserName->setPlaceholderText(QCoreApplication::translate("MainWindow", "Introduceti mail-ul", nullptr));
        checkBox->setText(QString());
        mail_icon->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

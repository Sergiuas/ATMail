/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RegisterWindow
{
public:
    QPushButton *ContinueBtn;
    QPushButton *BackBtn;
    QLineEdit *LastnameEdit;
    QLabel *LastnameLabel;
    QLabel *FirstnameLabel;
    QLineEdit *FirstnameEdit;
    QLabel *EmailLabel;
    QLineEdit *emailEdit;
    QLabel *PassLabel;
    QLineEdit *passEdit;
    QLabel *ConfirmLabel;
    QLineEdit *confirmEdit;
    QCheckBox *checkBox;
    QCheckBox *checkBoxConfirm;

    void setupUi(QDialog *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName("RegisterWindow");
        RegisterWindow->resize(939, 645);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RegisterWindow->sizePolicy().hasHeightForWidth());
        RegisterWindow->setSizePolicy(sizePolicy);
        RegisterWindow->setMinimumSize(QSize(939, 645));
        RegisterWindow->setMaximumSize(QSize(939, 645));
        RegisterWindow->setStyleSheet(QString::fromUtf8("#RegisterWindow\n"
"{\n"
"	background-image:url(:RegisterForm.png);\n"
"}"));
        ContinueBtn = new QPushButton(RegisterWindow);
        ContinueBtn->setObjectName("ContinueBtn");
        ContinueBtn->setGeometry(QRect(731, 590, 171, 51));
        ContinueBtn->setCursor(QCursor(Qt::PointingHandCursor));
        ContinueBtn->setStyleSheet(QString::fromUtf8("#ContinueBtn {\n"
"background-color: transparent;\n"
"border-image: url(:ContinuaBtn.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}\n"
"#ContinueBtn:hover\n"
"{\n"
"border-image: url(:ContinuaBtnOn.png);\n"
"}"));
        BackBtn = new QPushButton(RegisterWindow);
        BackBtn->setObjectName("BackBtn");
        BackBtn->setGeometry(QRect(497, 590, 171, 51));
        BackBtn->setCursor(QCursor(Qt::PointingHandCursor));
        BackBtn->setStyleSheet(QString::fromUtf8("#BackBtn {\n"
"background-color: transparent;\n"
"border-image: url(:InapoiBtn.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}\n"
"#BackBtn:hover\n"
"{\n"
"border-image: url(:InapoiBtnOn.png);\n"
"}"));
        LastnameEdit = new QLineEdit(RegisterWindow);
        LastnameEdit->setObjectName("LastnameEdit");
        LastnameEdit->setGeometry(QRect(540, 170, 331, 41));
        QFont font;
        font.setPointSize(15);
        LastnameEdit->setFont(font);
        LastnameEdit->setStyleSheet(QString::fromUtf8("#LastnameEdit\n"
"{\n"
"    border: 2px solid rgb(0, 0, 128);\n"
"	border-radius: 10px;\n"
"	padding-left: 10px;\n"
"	color:#fff;\n"
"	background-color: rgba(0, 26, 102,.5);\n"
"}\n"
"\n"
"#LastnameEdit:hover\n"
"{\n"
"	border: 2px solid rgb(48,50,62);\n"
"}\n"
"\n"
"#LastnameEdit:focus\n"
"{\n"
"	border: 2px solid rgb(85,170,255);\n"
"	background-color: rgb(43,45,56);\n"
"}"));
        LastnameLabel = new QLabel(RegisterWindow);
        LastnameLabel->setObjectName("LastnameLabel");
        LastnameLabel->setGeometry(QRect(540, 40, 331, 211));
        QFont font1;
        font1.setPointSize(14);
        LastnameLabel->setFont(font1);
        LastnameLabel->setStyleSheet(QString::fromUtf8("#LastnameLabel\n"
"{\n"
"background-color: transparent;\n"
"border-image: url(:Nume.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        FirstnameLabel = new QLabel(RegisterWindow);
        FirstnameLabel->setObjectName("FirstnameLabel");
        FirstnameLabel->setGeometry(QRect(550, 150, 281, 181));
        FirstnameLabel->setFont(font1);
        FirstnameLabel->setStyleSheet(QString::fromUtf8("#FirstnameLabel\n"
"{\n"
"background-color: transparent;\n"
"border-image: url(:Prenume.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        FirstnameEdit = new QLineEdit(RegisterWindow);
        FirstnameEdit->setObjectName("FirstnameEdit");
        FirstnameEdit->setGeometry(QRect(540, 264, 331, 41));
        FirstnameEdit->setFont(font);
        FirstnameEdit->setStyleSheet(QString::fromUtf8("#FirstnameEdit\n"
"{\n"
"    border: 2px solid rgb(0, 0, 128);\n"
"	border-radius: 10px;\n"
"	padding-left: 10px;\n"
"	color:#fff;\n"
"	background-color: rgba(0, 26, 102,.5);\n"
"}\n"
"\n"
"#FirstnameEdit:hover\n"
"{\n"
"	border: 2px solid rgb(48,50,62);\n"
"}\n"
"\n"
"#FirstnameEdit:focus\n"
"{\n"
"	border: 2px solid rgb(85,170,255);\n"
"	background-color: rgb(43,45,56);\n"
"}"));
        EmailLabel = new QLabel(RegisterWindow);
        EmailLabel->setObjectName("EmailLabel");
        EmailLabel->setGeometry(QRect(540, 240, 341, 211));
        EmailLabel->setFont(font1);
        EmailLabel->setStyleSheet(QString::fromUtf8("#EmailLabel\n"
"{\n"
"background-color: transparent;\n"
"border-image: url(:Email.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        emailEdit = new QLineEdit(RegisterWindow);
        emailEdit->setObjectName("emailEdit");
        emailEdit->setGeometry(QRect(540, 364, 331, 41));
        emailEdit->setFont(font);
        emailEdit->setStyleSheet(QString::fromUtf8("#emailEdit\n"
"{\n"
"    border: 2px solid rgb(0, 0, 128);\n"
"	border-radius: 10px;\n"
"	padding-left: 10px;\n"
"	color:#fff;\n"
"	background-color: rgba(0, 26, 102,.5);\n"
"}\n"
"\n"
"#emailEdit:hover\n"
"{\n"
"	border: 2px solid rgb(48,50,62);\n"
"}\n"
"\n"
"#emailEdit:focus\n"
"{\n"
"	border: 2px solid rgb(85,170,255);\n"
"	background-color: rgb(43,45,56);\n"
"}"));
        PassLabel = new QLabel(RegisterWindow);
        PassLabel->setObjectName("PassLabel");
        PassLabel->setGeometry(QRect(430, 370, 311, 191));
        QFont font2;
        font2.setPointSize(12);
        PassLabel->setFont(font2);
        PassLabel->setStyleSheet(QString::fromUtf8("#PassLabel\n"
"{\n"
"background-color: transparent;\n"
"border-image: url(:Parola.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        passEdit = new QLineEdit(RegisterWindow);
        passEdit->setObjectName("passEdit");
        passEdit->setGeometry(QRect(490, 490, 191, 31));
        passEdit->setFont(font);
        passEdit->setStyleSheet(QString::fromUtf8("#passEdit\n"
"{\n"
"    border: 2px solid rgb(0, 0, 128);\n"
"	border-radius: 10px;\n"
"	padding-left: 10px;\n"
"	color:#fff;\n"
"	background-color: rgba(0, 26, 102,.5);\n"
"}\n"
"\n"
"#passEdit:hover\n"
"{\n"
"	border: 2px solid rgb(48,50,62);\n"
"}\n"
"\n"
"#passEdit:focus\n"
"{\n"
"	border: 2px solid rgb(85,170,255);\n"
"	background-color: rgb(43,45,56);\n"
"}"));
        passEdit->setEchoMode(QLineEdit::Password);
        ConfirmLabel = new QLabel(RegisterWindow);
        ConfirmLabel->setObjectName("ConfirmLabel");
        ConfirmLabel->setGeometry(QRect(660, 380, 301, 181));
        ConfirmLabel->setFont(font2);
        ConfirmLabel->setStyleSheet(QString::fromUtf8("#ConfirmLabel\n"
"{\n"
"background-color: transparent;\n"
"border-image: url(:Confirma.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        confirmEdit = new QLineEdit(RegisterWindow);
        confirmEdit->setObjectName("confirmEdit");
        confirmEdit->setGeometry(QRect(720, 490, 191, 31));
        confirmEdit->setFont(font);
        confirmEdit->setStyleSheet(QString::fromUtf8("#confirmEdit\n"
"{\n"
"    border: 2px solid rgb(0, 0, 128);\n"
"	border-radius: 10px;\n"
"	padding-left: 10px;\n"
"	color:#fff;\n"
"	background-color: rgba(0, 26, 102,.5);\n"
"}\n"
"\n"
"#confirmEdit:hover\n"
"{\n"
"	border: 2px solid rgb(48,50,62);\n"
"}\n"
"\n"
"#confirmEdit:focus\n"
"{\n"
"	border: 2px solid rgb(85,170,255);\n"
"	background-color: rgb(43,45,56);\n"
"}"));
        confirmEdit->setEchoMode(QLineEdit::Password);
        checkBox = new QCheckBox(RegisterWindow);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(570, 530, 31, 31));
        checkBox->setMaximumSize(QSize(31, 31));
        checkBox->setCursor(QCursor(Qt::PointingHandCursor));
        checkBox->setStyleSheet(QString::fromUtf8("QCheckBox::indicator:unchecked {\n"
"    image: url(:show.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    image: url(:hide.png);\n"
"}"));
        checkBox->setCheckable(true);
        checkBox->setTristate(false);
        checkBoxConfirm = new QCheckBox(RegisterWindow);
        checkBoxConfirm->setObjectName("checkBoxConfirm");
        checkBoxConfirm->setGeometry(QRect(801, 530, 31, 31));
        checkBoxConfirm->setCursor(QCursor(Qt::PointingHandCursor));
        checkBoxConfirm->setStyleSheet(QString::fromUtf8("QCheckBox::indicator:unchecked {\n"
"    image: url(:show.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    image: url(:hide.png);\n"
"}"));
        ContinueBtn->raise();
        BackBtn->raise();
        LastnameLabel->raise();
        FirstnameLabel->raise();
        EmailLabel->raise();
        PassLabel->raise();
        ConfirmLabel->raise();
        LastnameEdit->raise();
        passEdit->raise();
        FirstnameEdit->raise();
        emailEdit->raise();
        confirmEdit->raise();
        checkBoxConfirm->raise();
        checkBox->raise();

        retranslateUi(RegisterWindow);

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QDialog *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QCoreApplication::translate("RegisterWindow", "Dialog", nullptr));
        ContinueBtn->setText(QString());
        BackBtn->setText(QString());
        LastnameEdit->setPlaceholderText(QCoreApplication::translate("RegisterWindow", "Introduceti numele", nullptr));
        LastnameLabel->setText(QString());
        FirstnameLabel->setText(QString());
        FirstnameEdit->setPlaceholderText(QCoreApplication::translate("RegisterWindow", "Introduceti prenumele", nullptr));
        EmailLabel->setText(QString());
        emailEdit->setPlaceholderText(QCoreApplication::translate("RegisterWindow", "Introduceti email-ul", nullptr));
        PassLabel->setText(QString());
        passEdit->setPlaceholderText(QCoreApplication::translate("RegisterWindow", "Introduceti parola", nullptr));
        ConfirmLabel->setText(QString());
        confirmEdit->setPlaceholderText(QCoreApplication::translate("RegisterWindow", "Introduceti parola", nullptr));
        checkBox->setText(QString());
        checkBoxConfirm->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
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
    QPushButton *ContinuaBtn;
    QPushButton *InapoiBtn;
    QLineEdit *numeEdit;
    QLabel *NumeLabel;
    QLabel *PrenumeLabel;
    QLineEdit *prenumeEdit;
    QLabel *EmailLabel;
    QLineEdit *emailEdit;
    QLabel *ParolaLabel;
    QLineEdit *parolaEdit;
    QLabel *ConfirmaLabel;
    QLineEdit *confirmaEdit;
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
        ContinuaBtn = new QPushButton(RegisterWindow);
        ContinuaBtn->setObjectName("ContinuaBtn");
        ContinuaBtn->setGeometry(QRect(731, 590, 171, 51));
        ContinuaBtn->setCursor(QCursor(Qt::PointingHandCursor));
        ContinuaBtn->setStyleSheet(QString::fromUtf8("#ContinuaBtn {\n"
"background-color: transparent;\n"
"border-image: url(:ContinuaBtn.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}\n"
"#ContinuaBtn:hover\n"
"{\n"
"border-image: url(:ContinuaBtnOn.png);\n"
"}"));
        InapoiBtn = new QPushButton(RegisterWindow);
        InapoiBtn->setObjectName("InapoiBtn");
        InapoiBtn->setGeometry(QRect(497, 590, 171, 51));
        InapoiBtn->setCursor(QCursor(Qt::PointingHandCursor));
        InapoiBtn->setStyleSheet(QString::fromUtf8("#InapoiBtn {\n"
"background-color: transparent;\n"
"border-image: url(:InapoiBtn.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}\n"
"#InapoiBtn:hover\n"
"{\n"
"border-image: url(:InapoiBtnOn.png);\n"
"}"));
        numeEdit = new QLineEdit(RegisterWindow);
        numeEdit->setObjectName("numeEdit");
        numeEdit->setGeometry(QRect(540, 170, 331, 41));
        QFont font;
        font.setPointSize(15);
        numeEdit->setFont(font);
        numeEdit->setStyleSheet(QString::fromUtf8("#numeEdit\n"
"{\n"
"    border: 2px solid rgb(0, 0, 128);\n"
"	border-radius: 10px;\n"
"	padding-left: 10px;\n"
"	color:#fff;\n"
"	background-color: rgba(0, 26, 102,.5);\n"
"}\n"
"\n"
"#numeEdit:hover\n"
"{\n"
"	border: 2px solid rgb(48,50,62);\n"
"}\n"
"\n"
"#numeEdit:focus\n"
"{\n"
"	border: 2px solid rgb(85,170,255);\n"
"	background-color: rgb(43,45,56);\n"
"}"));
        NumeLabel = new QLabel(RegisterWindow);
        NumeLabel->setObjectName("NumeLabel");
        NumeLabel->setGeometry(QRect(540, 40, 331, 211));
        QFont font1;
        font1.setPointSize(14);
        NumeLabel->setFont(font1);
        NumeLabel->setStyleSheet(QString::fromUtf8("#NumeLabel\n"
"{\n"
"background-color: transparent;\n"
"border-image: url(:Nume.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        PrenumeLabel = new QLabel(RegisterWindow);
        PrenumeLabel->setObjectName("PrenumeLabel");
        PrenumeLabel->setGeometry(QRect(550, 150, 281, 181));
        PrenumeLabel->setFont(font1);
        PrenumeLabel->setStyleSheet(QString::fromUtf8("#PrenumeLabel\n"
"{\n"
"background-color: transparent;\n"
"border-image: url(:Prenume.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        prenumeEdit = new QLineEdit(RegisterWindow);
        prenumeEdit->setObjectName("prenumeEdit");
        prenumeEdit->setGeometry(QRect(540, 264, 331, 41));
        prenumeEdit->setFont(font);
        prenumeEdit->setStyleSheet(QString::fromUtf8("#prenumeEdit\n"
"{\n"
"    border: 2px solid rgb(0, 0, 128);\n"
"	border-radius: 10px;\n"
"	padding-left: 10px;\n"
"	color:#fff;\n"
"	background-color: rgba(0, 26, 102,.5);\n"
"}\n"
"\n"
"#prenumeEdit:hover\n"
"{\n"
"	border: 2px solid rgb(48,50,62);\n"
"}\n"
"\n"
"#prenumeEdit:focus\n"
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
        ParolaLabel = new QLabel(RegisterWindow);
        ParolaLabel->setObjectName("ParolaLabel");
        ParolaLabel->setGeometry(QRect(430, 370, 311, 191));
        QFont font2;
        font2.setPointSize(12);
        ParolaLabel->setFont(font2);
        ParolaLabel->setStyleSheet(QString::fromUtf8("#ParolaLabel\n"
"{\n"
"background-color: transparent;\n"
"border-image: url(:Parola.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        parolaEdit = new QLineEdit(RegisterWindow);
        parolaEdit->setObjectName("parolaEdit");
        parolaEdit->setGeometry(QRect(490, 490, 191, 31));
        parolaEdit->setFont(font);
        parolaEdit->setStyleSheet(QString::fromUtf8("#parolaEdit\n"
"{\n"
"    border: 2px solid rgb(0, 0, 128);\n"
"	border-radius: 10px;\n"
"	padding-left: 10px;\n"
"	color:#fff;\n"
"	background-color: rgba(0, 26, 102,.5);\n"
"}\n"
"\n"
"#parolaEdit:hover\n"
"{\n"
"	border: 2px solid rgb(48,50,62);\n"
"}\n"
"\n"
"#parolaEdit:focus\n"
"{\n"
"	border: 2px solid rgb(85,170,255);\n"
"	background-color: rgb(43,45,56);\n"
"}"));
        parolaEdit->setEchoMode(QLineEdit::Password);
        ConfirmaLabel = new QLabel(RegisterWindow);
        ConfirmaLabel->setObjectName("ConfirmaLabel");
        ConfirmaLabel->setGeometry(QRect(660, 380, 301, 181));
        ConfirmaLabel->setFont(font2);
        ConfirmaLabel->setStyleSheet(QString::fromUtf8("#ConfirmaLabel\n"
"{\n"
"background-color: transparent;\n"
"border-image: url(:Confirma.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        confirmaEdit = new QLineEdit(RegisterWindow);
        confirmaEdit->setObjectName("confirmaEdit");
        confirmaEdit->setGeometry(QRect(720, 490, 191, 31));
        confirmaEdit->setFont(font);
        confirmaEdit->setStyleSheet(QString::fromUtf8("#confirmaEdit\n"
"{\n"
"    border: 2px solid rgb(0, 0, 128);\n"
"	border-radius: 10px;\n"
"	padding-left: 10px;\n"
"	color:#fff;\n"
"	background-color: rgba(0, 26, 102,.5);\n"
"}\n"
"\n"
"#confirmaEdit:hover\n"
"{\n"
"	border: 2px solid rgb(48,50,62);\n"
"}\n"
"\n"
"#confirmaEdit:focus\n"
"{\n"
"	border: 2px solid rgb(85,170,255);\n"
"	background-color: rgb(43,45,56);\n"
"}"));
        confirmaEdit->setEchoMode(QLineEdit::Password);
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
        ContinuaBtn->raise();
        InapoiBtn->raise();
        NumeLabel->raise();
        PrenumeLabel->raise();
        EmailLabel->raise();
        ParolaLabel->raise();
        ConfirmaLabel->raise();
        numeEdit->raise();
        parolaEdit->raise();
        prenumeEdit->raise();
        emailEdit->raise();
        confirmaEdit->raise();
        checkBoxConfirm->raise();
        checkBox->raise();

        retranslateUi(RegisterWindow);

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QDialog *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QCoreApplication::translate("RegisterWindow", "Dialog", nullptr));
        ContinuaBtn->setText(QString());
        InapoiBtn->setText(QString());
        numeEdit->setPlaceholderText(QCoreApplication::translate("RegisterWindow", "Introduceti numele", nullptr));
        NumeLabel->setText(QString());
        PrenumeLabel->setText(QString());
        prenumeEdit->setPlaceholderText(QCoreApplication::translate("RegisterWindow", "Introduceti prenumele", nullptr));
        EmailLabel->setText(QString());
        emailEdit->setPlaceholderText(QCoreApplication::translate("RegisterWindow", "Introduceti email-ul", nullptr));
        ParolaLabel->setText(QString());
        parolaEdit->setPlaceholderText(QCoreApplication::translate("RegisterWindow", "Introduceti parola", nullptr));
        ConfirmaLabel->setText(QString());
        confirmaEdit->setPlaceholderText(QCoreApplication::translate("RegisterWindow", "Introduceti parola", nullptr));
        checkBox->setText(QString());
        checkBoxConfirm->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H

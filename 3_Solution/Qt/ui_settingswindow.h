/********************************************************************************
** Form generated from reading UI file 'settingswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSWINDOW_H
#define UI_SETTINGSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SettingsWindow
{
public:
    QLabel *settingsLabel;
    QLineEdit *editSurname;
    QLabel *surnameLabel;
    QLabel *nameLabel;
    QLineEdit *editName;
    QLabel *oldPassLabel;
    QLineEdit *editOldPass;
    QLineEdit *editNewPass;
    QLabel *newPassLabel;
    QPushButton *settings;
    QPushButton *settings_2;
    QCheckBox *visibilityOld;
    QCheckBox *visibilityNew;
    QPushButton *save;

    void setupUi(QDialog *SettingsWindow)
    {
        if (SettingsWindow->objectName().isEmpty())
            SettingsWindow->setObjectName("SettingsWindow");
        SettingsWindow->resize(435, 616);
        SettingsWindow->setStyleSheet(QString::fromUtf8("#SettingsWindow\n"
"{\n"
"	background: #242423;\n"
"}"));
        settingsLabel = new QLabel(SettingsWindow);
        settingsLabel->setObjectName("settingsLabel");
        settingsLabel->setGeometry(QRect(167, 19, 111, 41));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        settingsLabel->setFont(font);
        settingsLabel->setStyleSheet(QString::fromUtf8("#settingsLabel\n"
"{\n"
"color:#fff\n"
"}"));
        editSurname = new QLineEdit(SettingsWindow);
        editSurname->setObjectName("editSurname");
        editSurname->setGeometry(QRect(81, 134, 291, 41));
        QFont font1;
        font1.setPointSize(12);
        editSurname->setFont(font1);
        editSurname->setStyleSheet(QString::fromUtf8("#editSurname\n"
"{\n"
"color:white;\n"
"padding-right: 40px;\n"
"border: 2px solid white;\n"
"border-radius:10px;\n"
"background-color: rgba(0,0,0,0.7);\n"
"}\n"
"#editSurname:focus\n"
"{\n"
"border: 2px solid yellow;\n"
"}"));
        editSurname->setMaxLength(255);
        surnameLabel = new QLabel(SettingsWindow);
        surnameLabel->setObjectName("surnameLabel");
        surnameLabel->setGeometry(QRect(179, 80, 111, 41));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(false);
        surnameLabel->setFont(font2);
        surnameLabel->setStyleSheet(QString::fromUtf8("#surnameLabel\n"
"{\n"
"color:#fff\n"
"}"));
        nameLabel = new QLabel(SettingsWindow);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setGeometry(QRect(167, 195, 111, 41));
        nameLabel->setFont(font2);
        nameLabel->setStyleSheet(QString::fromUtf8("#nameLabel\n"
"{\n"
"color:#fff\n"
"}"));
        editName = new QLineEdit(SettingsWindow);
        editName->setObjectName("editName");
        editName->setGeometry(QRect(80, 249, 291, 41));
        editName->setFont(font1);
        editName->setStyleSheet(QString::fromUtf8("#editName\n"
"{\n"
"color:white;\n"
"padding-right: 40px;\n"
"border: 2px solid white;\n"
"border-radius:10px;\n"
"background-color: rgba(0,0,0,0.7);\n"
"}\n"
"#editName:focus\n"
"{\n"
"border: 2px solid yellow;\n"
"}"));
        editName->setMaxLength(255);
        oldPassLabel = new QLabel(SettingsWindow);
        oldPassLabel->setObjectName("oldPassLabel");
        oldPassLabel->setGeometry(QRect(149, 305, 171, 41));
        oldPassLabel->setFont(font2);
        oldPassLabel->setStyleSheet(QString::fromUtf8("#oldPassLabel\n"
"{\n"
"color:#fff\n"
"}"));
        editOldPass = new QLineEdit(SettingsWindow);
        editOldPass->setObjectName("editOldPass");
        editOldPass->setGeometry(QRect(80, 359, 291, 41));
        editOldPass->setFont(font1);
        editOldPass->setStyleSheet(QString::fromUtf8("#editOldPass\n"
"{\n"
"color:white;\n"
"padding-right: 40px;\n"
"border: 2px solid white;\n"
"border-radius:10px;\n"
"background-color: rgba(0,0,0,0.7);\n"
"}\n"
"#editOldPass:focus\n"
"{\n"
"border: 2px solid yellow;\n"
"}"));
        editOldPass->setMaxLength(255);
        editOldPass->setEchoMode(QLineEdit::Password);
        editNewPass = new QLineEdit(SettingsWindow);
        editNewPass->setObjectName("editNewPass");
        editNewPass->setGeometry(QRect(80, 463, 291, 41));
        editNewPass->setFont(font1);
        editNewPass->setStyleSheet(QString::fromUtf8("#editNewPass\n"
"{\n"
"color:white;\n"
"padding-right: 40px;\n"
"border: 2px solid white;\n"
"border-radius:10px;\n"
"background-color: rgba(0,0,0,0.7);\n"
"}\n"
"#editNewPass:focus\n"
"{\n"
"border: 2px solid yellow;\n"
"}"));
        editNewPass->setMaxLength(255);
        editNewPass->setEchoMode(QLineEdit::Password);
        newPassLabel = new QLabel(SettingsWindow);
        newPassLabel->setObjectName("newPassLabel");
        newPassLabel->setGeometry(QRect(152, 409, 171, 41));
        newPassLabel->setFont(font2);
        newPassLabel->setStyleSheet(QString::fromUtf8("#newPassLabel\n"
"{\n"
"color:#fff\n"
"}"));
        settings = new QPushButton(SettingsWindow);
        settings->setObjectName("settings");
        settings->setGeometry(QRect(-420, -200, 721, 651));
        settings->setCursor(QCursor(Qt::BlankCursor));
        settings->setStyleSheet(QString::fromUtf8("#settings {\n"
"background-color: transparent;\n"
"border-image: url(:gear_transparent.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"\n"
"}"));
        settings->setAutoDefault(true);
        settings_2 = new QPushButton(SettingsWindow);
        settings_2->setObjectName("settings_2");
        settings_2->setGeometry(QRect(150, 210, 721, 651));
        settings_2->setCursor(QCursor(Qt::BlankCursor));
        settings_2->setStyleSheet(QString::fromUtf8("#settings_2 {\n"
"background-color: transparent;\n"
"border-image: url(:gear_transparent.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"\n"
"}"));
        settings_2->setAutoDefault(true);
        visibilityOld = new QCheckBox(SettingsWindow);
        visibilityOld->setObjectName("visibilityOld");
        visibilityOld->setGeometry(QRect(330, 367, 88, 24));
        visibilityOld->setCursor(QCursor(Qt::PointingHandCursor));
        visibilityOld->setStyleSheet(QString::fromUtf8("#visibilityOld\n"
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
        visibilityNew = new QCheckBox(SettingsWindow);
        visibilityNew->setObjectName("visibilityNew");
        visibilityNew->setGeometry(QRect(330, 471, 88, 24));
        visibilityNew->setCursor(QCursor(Qt::PointingHandCursor));
        visibilityNew->setStyleSheet(QString::fromUtf8("#visibilityNew\n"
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
        save = new QPushButton(SettingsWindow);
        save->setObjectName("save");
        save->setGeometry(QRect(155, 550, 141, 41));
        save->setCursor(QCursor(Qt::PointingHandCursor));
        save->setStyleSheet(QString::fromUtf8("#save\n"
"{\n"
"	    background-color: red;\n"
"		border-radius: 19px;\n"
"        color: #fff;\n"
"}\n"
"\n"
"\n"
"#save:hover\n"
"{\n"
"	    background-color: #f72d2d;\n"
"}"));
        settings->raise();
        settings_2->raise();
        settingsLabel->raise();
        editSurname->raise();
        surnameLabel->raise();
        nameLabel->raise();
        editName->raise();
        oldPassLabel->raise();
        editOldPass->raise();
        editNewPass->raise();
        newPassLabel->raise();
        visibilityOld->raise();
        visibilityNew->raise();
        save->raise();

        retranslateUi(SettingsWindow);

        settings->setDefault(true);
        settings_2->setDefault(true);


        QMetaObject::connectSlotsByName(SettingsWindow);
    } // setupUi

    void retranslateUi(QDialog *SettingsWindow)
    {
        SettingsWindow->setWindowTitle(QCoreApplication::translate("SettingsWindow", "Dialog", nullptr));
        settingsLabel->setText(QCoreApplication::translate("SettingsWindow", "Set\304\203ri", nullptr));
        editSurname->setPlaceholderText(QCoreApplication::translate("SettingsWindow", "Introduceti numele", nullptr));
        surnameLabel->setText(QCoreApplication::translate("SettingsWindow", "Nume", nullptr));
        nameLabel->setText(QCoreApplication::translate("SettingsWindow", "Prenume", nullptr));
        editName->setPlaceholderText(QCoreApplication::translate("SettingsWindow", "Introduceti prenumele", nullptr));
        oldPassLabel->setText(QCoreApplication::translate("SettingsWindow", "Parola veche", nullptr));
        editOldPass->setPlaceholderText(QCoreApplication::translate("SettingsWindow", "Introduceti vechea parola", nullptr));
        editNewPass->setPlaceholderText(QCoreApplication::translate("SettingsWindow", "Introduceti noua parola", nullptr));
        newPassLabel->setText(QCoreApplication::translate("SettingsWindow", "Parola noua", nullptr));
        settings->setText(QString());
        settings_2->setText(QString());
        visibilityOld->setText(QString());
        visibilityNew->setText(QString());
        save->setText(QCoreApplication::translate("SettingsWindow", "Salva\310\233i", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsWindow: public Ui_SettingsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWINDOW_H

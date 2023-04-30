/********************************************************************************
** Form generated from reading UI file 'readmail.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_READMAIL_H
#define UI_READMAIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_readMail
{
public:

    void setupUi(QDialog *readMail)
    {
        if (readMail->objectName().isEmpty())
            readMail->setObjectName("readMail");
        readMail->resize(400, 300);

        retranslateUi(readMail);

        QMetaObject::connectSlotsByName(readMail);
    } // setupUi

    void retranslateUi(QDialog *readMail)
    {
        readMail->setWindowTitle(QCoreApplication::translate("readMail", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class readMail: public Ui_readMail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_READMAIL_H

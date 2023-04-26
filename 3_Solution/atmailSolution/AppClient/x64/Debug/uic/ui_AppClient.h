/********************************************************************************
** Form generated from reading UI file 'AppClient.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPCLIENT_H
#define UI_APPCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AppClientClass
{
public:

    void setupUi(QWidget *AppClientClass)
    {
        if (AppClientClass->objectName().isEmpty())
            AppClientClass->setObjectName("AppClientClass");
        AppClientClass->resize(600, 400);

        retranslateUi(AppClientClass);

        QMetaObject::connectSlotsByName(AppClientClass);
    } // setupUi

    void retranslateUi(QWidget *AppClientClass)
    {
        AppClientClass->setWindowTitle(QCoreApplication::translate("AppClientClass", "AppClient", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AppClientClass: public Ui_AppClientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPCLIENT_H

/********************************************************************************
** Form generated from reading UI file 'interface.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE_H
#define UI_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Interface
{
public:
    QLabel *area1;
    QPushButton *pushButton;
    QLabel *Logo;
    QLabel *area2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *inbox;
    QLabel *star;
    QLabel *sent;
    QLabel *trash;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QLabel *work;
    QLabel *personal;
    QLabel *credit;
    QLineEdit *search;
    QLabel *find;
    QCheckBox *sw;
    QLabel *user;
    QPushButton *pushButton_8;
    QPushButton *compose;
    QLabel *label;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QLineEdit *ToLine;
    QLineEdit *SubjectLine;
    QLabel *ToLabel;
    QLabel *SubjectLabel;
    QTextEdit *textEdit;
    QPushButton *send;
    QPushButton *attachment;
    QFrame *line_4;
    QFrame *line_5;
    QLineEdit *attachLine;
    QScrollArea *scrollArea;
    QWidget *scrollZone;

    void setupUi(QDialog *Interface)
    {
        if (Interface->objectName().isEmpty())
            Interface->setObjectName("Interface");
        Interface->resize(1146, 615);
        area1 = new QLabel(Interface);
        area1->setObjectName("area1");
        area1->setGeometry(QRect(0, 0, 331, 621));
        area1->setStyleSheet(QString::fromUtf8("#area1\n"
"{\n"
"	background-color:#242423;\n"
"}"));
        pushButton = new QPushButton(Interface);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 150, 241, 41));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("#pushButton\n"
"{\n"
"        \n"
"        background-color: transparent;\n"
"		border-radius: 20px;\n"
"        color: #fff;\n"
"		text-align: left;\n"
"		padding-left: 50px;\n"
"}\n"
"\n"
"#pushButton:hover\n"
"{\n"
"        background-color:#363634;\n"
"}"));
        Logo = new QLabel(Interface);
        Logo->setObjectName("Logo");
        Logo->setGeometry(QRect(10, 10, 111, 111));
        Logo->setStyleSheet(QString::fromUtf8("#Logo {\n"
"background-color: transparent;\n"
"border-image: url(:Logo.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        area2 = new QLabel(Interface);
        area2->setObjectName("area2");
        area2->setGeometry(QRect(330, -30, 901, 691));
        area2->setStyleSheet(QString::fromUtf8("#area2\n"
"{\n"
"	background-color:#1c1c1b;\n"
"}"));
        pushButton_2 = new QPushButton(Interface);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(20, 210, 241, 41));
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2->setStyleSheet(QString::fromUtf8("#pushButton_2\n"
"{\n"
"        \n"
"        background-color: transparent;\n"
"		border-radius: 20px;\n"
"        color: #fff;\n"
"		text-align: left;\n"
"		padding-left: 50px;\n"
"}\n"
"\n"
"#pushButton_2:hover\n"
"{\n"
"background-color:#363634;\n"
"}"));
        pushButton_3 = new QPushButton(Interface);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(20, 270, 241, 41));
        pushButton_3->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_3->setStyleSheet(QString::fromUtf8("#pushButton_3\n"
"{\n"
"        \n"
"        background-color: transparent;\n"
"		border-radius: 20px;\n"
"        color: #fff;\n"
"		text-align: left;\n"
"		padding-left: 50px;\n"
"}\n"
"\n"
"#pushButton_3:hover\n"
"{\n"
"background-color:#363634;\n"
"}"));
        pushButton_4 = new QPushButton(Interface);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(20, 336, 241, 41));
        pushButton_4->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_4->setStyleSheet(QString::fromUtf8("#pushButton_4\n"
"{\n"
"        \n"
"        background-color: transparent;\n"
"		border-radius: 20px;\n"
"        color: #fff;\n"
"		text-align: left;\n"
"		padding-left: 50px;\n"
"}\n"
"\n"
"#pushButton_4:hover\n"
"{\n"
"background-color:#363634;\n"
"}"));
        inbox = new QLabel(Interface);
        inbox->setObjectName("inbox");
        inbox->setGeometry(QRect(22, 150, 41, 41));
        inbox->setStyleSheet(QString::fromUtf8("#inbox {\n"
"background-color: transparent;\n"
"border-image: url(:inbox.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        star = new QLabel(Interface);
        star->setObjectName("star");
        star->setGeometry(QRect(27, 215, 31, 31));
        star->setStyleSheet(QString::fromUtf8("#star {\n"
"background-color: transparent;\n"
"border-image: url(:star.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        sent = new QLabel(Interface);
        sent->setObjectName("sent");
        sent->setGeometry(QRect(26, 279, 31, 31));
        sent->setStyleSheet(QString::fromUtf8("#sent {\n"
"background-color: transparent;\n"
"border-image: url(:sent.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        trash = new QLabel(Interface);
        trash->setObjectName("trash");
        trash->setGeometry(QRect(22, 336, 41, 41));
        trash->setStyleSheet(QString::fromUtf8("#trash {\n"
"background-color: transparent;\n"
"border-image: url(:trash.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        line = new QFrame(Interface);
        line->setObjectName("line");
        line->setGeometry(QRect(-13, 128, 341, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(Interface);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(-10, 410, 341, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(Interface);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(320, 0, 20, 641));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        pushButton_5 = new QPushButton(Interface);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(20, 430, 241, 41));
        pushButton_5->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_5->setStyleSheet(QString::fromUtf8("#pushButton_5\n"
"{\n"
"        \n"
"        background-color: transparent;\n"
"		border-radius: 20px;\n"
"        color: #fff;\n"
"		text-align: left;\n"
"		padding-left: 50px;\n"
"}\n"
"\n"
"#pushButton_5:hover\n"
"{\n"
"background-color:#363634;\n"
"}"));
        pushButton_6 = new QPushButton(Interface);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(20, 485, 241, 41));
        pushButton_6->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_6->setStyleSheet(QString::fromUtf8("#pushButton_6\n"
"{\n"
"        \n"
"        background-color: transparent;\n"
"		border-radius: 20px;\n"
"        color: #fff;\n"
"		text-align: left;\n"
"		padding-left: 50px;\n"
"}\n"
"\n"
"#pushButton_6:hover\n"
"{\n"
"background-color:#363634;\n"
"}"));
        pushButton_7 = new QPushButton(Interface);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(20, 540, 241, 41));
        pushButton_7->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_7->setStyleSheet(QString::fromUtf8("#pushButton_7\n"
"{\n"
"        \n"
"        background-color: transparent;\n"
"		border-radius: 20px;\n"
"        color: #fff;\n"
"		text-align: left;\n"
"		padding-left: 50px;\n"
"}\n"
"\n"
"#pushButton_7:hover\n"
"{\n"
"background-color:#363634;\n"
"}"));
        work = new QLabel(Interface);
        work->setObjectName("work");
        work->setGeometry(QRect(30, 436, 31, 31));
        work->setStyleSheet(QString::fromUtf8("#work {\n"
"background-color: transparent;\n"
"border-image: url(:folder_blue.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        personal = new QLabel(Interface);
        personal->setObjectName("personal");
        personal->setGeometry(QRect(30, 490, 31, 31));
        personal->setStyleSheet(QString::fromUtf8("#personal {\n"
"background-color: transparent;\n"
"border-image: url(:folder_yellow.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        credit = new QLabel(Interface);
        credit->setObjectName("credit");
        credit->setGeometry(QRect(30, 543, 31, 31));
        credit->setStyleSheet(QString::fromUtf8("#credit {\n"
"background-color: transparent;\n"
"border-image: url(:folder_green.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        search = new QLineEdit(Interface);
        search->setObjectName("search");
        search->setGeometry(QRect(380, 40, 311, 41));
        search->setStyleSheet(QString::fromUtf8("#search\n"
"{\n"
"    color:black;\n"
"	border-radius:20px;\n"
"	padding-left:30px;\n"
"}\n"
"\n"
"#search:focus\n"
"{\n"
"border: 2px solid yellow;\n"
"}"));
        find = new QLabel(Interface);
        find->setObjectName("find");
        find->setGeometry(QRect(390, 52, 21, 21));
        find->setStyleSheet(QString::fromUtf8("#find {\n"
"background-color: transparent;\n"
"border-image: url(:search.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        sw = new QCheckBox(Interface);
        sw->setObjectName("sw");
        sw->setGeometry(QRect(1012, 42, 91, 41));
        sw->setCursor(QCursor(Qt::PointingHandCursor));
        sw->setStyleSheet(QString::fromUtf8("#sw\n"
"{\n"
"background-color: transparent;\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {\n"
"    image: url(:moon.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    image: url(:sun.png);\n"
"}"));
        user = new QLabel(Interface);
        user->setObjectName("user");
        user->setGeometry(QRect(196, 40, 131, 31));
        user->setStyleSheet(QString::fromUtf8("#user\n"
"{\n"
"	color:#fff;\n"
"}"));
        pushButton_8 = new QPushButton(Interface);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(216, 96, 93, 29));
        pushButton_8->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_8->setStyleSheet(QString::fromUtf8("#pushButton_8\n"
"{\n"
"	    background-color: red;\n"
"		border-radius: 10px;\n"
"        color: #fff;\n"
"}\n"
"\n"
"\n"
"#pushButton_8:hover\n"
"{\n"
"	    background-color: #f72d2d;\n"
"}"));
        compose = new QPushButton(Interface);
        compose->setObjectName("compose");
        compose->setGeometry(QRect(777, 36, 151, 51));
        compose->setCursor(QCursor(Qt::PointingHandCursor));
        compose->setStyleSheet(QString::fromUtf8("#compose {\n"
"background-color: transparent;\n"
"border-image: url(:compose.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}\n"
""));
        label = new QLabel(Interface);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 20, 81, 20));
        label->setStyleSheet(QString::fromUtf8("#label\n"
"{\n"
"	color:#fff;\n"
"}"));
        dockWidget = new QDockWidget(Interface);
        dockWidget->setObjectName("dockWidget");
        dockWidget->setGeometry(QRect(660, 130, 481, 481));
        dockWidget->setStyleSheet(QString::fromUtf8("#dockWidget\n"
"{\n"
"	background-color:white;\n"
"	\n"
"}"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName("dockWidgetContents");
        dockWidgetContents->setStyleSheet(QString::fromUtf8("#dockWidgetContents\n"
"{\n"
"background-color:#242423;\n"
"border: 2px solid lightgray;\n"
"}"));
        ToLine = new QLineEdit(dockWidgetContents);
        ToLine->setObjectName("ToLine");
        ToLine->setGeometry(QRect(7, 10, 471, 31));
        ToLine->setStyleSheet(QString::fromUtf8("#ToLine\n"
"{\n"
"	color:white;\n"
"	background:transparent;\n"
"	border:transparent;\n"
"	padding-left:20px\n"
"}"));
        SubjectLine = new QLineEdit(dockWidgetContents);
        SubjectLine->setObjectName("SubjectLine");
        SubjectLine->setGeometry(QRect(7, 60, 471, 31));
        SubjectLine->setStyleSheet(QString::fromUtf8("#SubjectLine\n"
"{\n"
"	color:white;\n"
"	background:transparent;\n"
"	border:transparent;\n"
"	padding-left:46px\n"
"}"));
        ToLabel = new QLabel(dockWidgetContents);
        ToLabel->setObjectName("ToLabel");
        ToLabel->setGeometry(QRect(10, 16, 63, 20));
        ToLabel->setStyleSheet(QString::fromUtf8("#ToLabel\n"
"{\n"
"	color:white;\n"
"}"));
        SubjectLabel = new QLabel(dockWidgetContents);
        SubjectLabel->setObjectName("SubjectLabel");
        SubjectLabel->setGeometry(QRect(10, 67, 63, 20));
        SubjectLabel->setStyleSheet(QString::fromUtf8("#SubjectLabel\n"
"{\n"
"	color:white;\n"
"}"));
        textEdit = new QTextEdit(dockWidgetContents);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(13, 114, 461, 211));
        textEdit->setStyleSheet(QString::fromUtf8("#textEdit\n"
"{\n"
"background-color:#242423;\n"
"color: white;\n"
"}"));
        send = new QPushButton(dockWidgetContents);
        send->setObjectName("send");
        send->setGeometry(QRect(300, 400, 101, 41));
        send->setCursor(QCursor(Qt::PointingHandCursor));
        send->setStyleSheet(QString::fromUtf8("#send {\n"
"background-color: transparent;\n"
"border-image: url(:Send.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}\n"
""));
        send->setAutoDefault(true);
        attachment = new QPushButton(dockWidgetContents);
        attachment->setObjectName("attachment");
        attachment->setGeometry(QRect(420, 407, 21, 31));
        attachment->setCursor(QCursor(Qt::PointingHandCursor));
        attachment->setStyleSheet(QString::fromUtf8("#attachment {\n"
"background-color: transparent;\n"
"border-image: url(:attachment.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}\n"
""));
        attachment->setAutoDefault(true);
        line_4 = new QFrame(dockWidgetContents);
        line_4->setObjectName("line_4");
        line_4->setGeometry(QRect(-40, 34, 531, 20));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(dockWidgetContents);
        line_5->setObjectName("line_5");
        line_5->setGeometry(QRect(-10, 87, 491, 20));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        attachLine = new QLineEdit(dockWidgetContents);
        attachLine->setObjectName("attachLine");
        attachLine->setGeometry(QRect(13, 350, 461, 25));
        attachLine->setStyleSheet(QString::fromUtf8("#attachLine\n"
"{\n"
"	background-color:#242423;\n"
"	color: white;\n"
"}"));
        dockWidget->setWidget(dockWidgetContents);
        SubjectLabel->raise();
        ToLabel->raise();
        ToLine->raise();
        SubjectLine->raise();
        textEdit->raise();
        send->raise();
        attachment->raise();
        line_4->raise();
        line_5->raise();
        attachLine->raise();
        scrollArea = new QScrollArea(Interface);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(338, 110, 801, 491));
        scrollArea->setStyleSheet(QString::fromUtf8("background-color: #242423"));
        scrollArea->setWidgetResizable(true);
        scrollZone = new QWidget();
        scrollZone->setObjectName("scrollZone");
        scrollZone->setGeometry(QRect(0, 0, 799, 489));
        scrollZone->setStyleSheet(QString::fromUtf8("#scrollAreaWidgetContents\n"
"{\n"
"	background-color: #242423;\n"
"}"));
        scrollArea->setWidget(scrollZone);
        area1->raise();
        pushButton->raise();
        Logo->raise();
        area2->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        inbox->raise();
        star->raise();
        sent->raise();
        trash->raise();
        line->raise();
        line_2->raise();
        line_3->raise();
        pushButton_5->raise();
        pushButton_6->raise();
        pushButton_7->raise();
        work->raise();
        personal->raise();
        credit->raise();
        search->raise();
        find->raise();
        sw->raise();
        user->raise();
        pushButton_8->raise();
        compose->raise();
        label->raise();
        scrollArea->raise();
        dockWidget->raise();

        retranslateUi(Interface);
        QObject::connect(compose, &QPushButton::clicked, dockWidget, qOverload<>(&QDockWidget::show));

        send->setDefault(true);
        attachment->setDefault(true);


        QMetaObject::connectSlotsByName(Interface);
    } // setupUi

    void retranslateUi(QDialog *Interface)
    {
        Interface->setWindowTitle(QCoreApplication::translate("Interface", "Dialog", nullptr));
        area1->setText(QString());
        pushButton->setText(QCoreApplication::translate("Interface", "Inbox", nullptr));
        Logo->setText(QString());
        area2->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("Interface", "Starred", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Interface", "Sent", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Interface", "Delete", nullptr));
        inbox->setText(QString());
        star->setText(QString());
        sent->setText(QString());
        trash->setText(QString());
        pushButton_5->setText(QCoreApplication::translate("Interface", "Work", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Interface", "Personal", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Interface", "Credit", nullptr));
        work->setText(QString());
        personal->setText(QString());
        credit->setText(QString());
        search->setPlaceholderText(QCoreApplication::translate("Interface", "Search...", nullptr));
        find->setText(QString());
        sw->setText(QString());
        user->setText(QString());
        pushButton_8->setText(QCoreApplication::translate("Interface", "Log out", nullptr));
        compose->setText(QString());
        label->setText(QCoreApplication::translate("Interface", "Signed as:", nullptr));
        ToLine->setPlaceholderText(QString());
        SubjectLine->setPlaceholderText(QString());
        ToLabel->setText(QCoreApplication::translate("Interface", "To:", nullptr));
        SubjectLabel->setText(QCoreApplication::translate("Interface", "Subject:", nullptr));
        textEdit->setPlaceholderText(QCoreApplication::translate("Interface", "Insert Text...", nullptr));
        send->setText(QString());
        attachment->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Interface: public Ui_Interface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_H

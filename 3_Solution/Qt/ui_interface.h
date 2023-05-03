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
#include <QtWidgets/QGroupBox>
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
    QGroupBox *viewMail;
    QLabel *fromLabel;
    QTextEdit *mailContent;
    QLabel *fromText;
    QPushButton *exitBtn;
    QPushButton *forwardBtn;
    QLabel *forwardTo;
    QPushButton *replyBtn;
    QLabel *replyTo;
    QScrollArea *scrollArea_2;
    QWidget *filesArea;

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
        dockWidget->setEnabled(true);
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
        scrollArea->setEnabled(true);
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
        viewMail = new QGroupBox(Interface);
        viewMail->setObjectName("viewMail");
        viewMail->setEnabled(true);
        viewMail->setGeometry(QRect(338, 110, 801, 491));
        viewMail->setStyleSheet(QString::fromUtf8("#viewMail\n"
"{\n"
"	background: #242423;\n"
"}"));
        fromLabel = new QLabel(viewMail);
        fromLabel->setObjectName("fromLabel");
        fromLabel->setGeometry(QRect(30, 40, 51, 20));
        fromLabel->setStyleSheet(QString::fromUtf8("#fromLabel\n"
"{\n"
"	font-weight:bold;\n"
"	color:white;\n"
"\n"
"}"));
        mailContent = new QTextEdit(viewMail);
        mailContent->setObjectName("mailContent");
        mailContent->setGeometry(QRect(18, 100, 761, 281));
        mailContent->setStyleSheet(QString::fromUtf8("#mailContent\n"
"{\n"
"	background-color:#1c1c1b;\n"
"	color:white;\n"
"}"));
        fromText = new QLabel(viewMail);
        fromText->setObjectName("fromText");
        fromText->setGeometry(QRect(86, 40, 71, 20));
        fromText->setStyleSheet(QString::fromUtf8("#fromText\n"
"{\n"
"        color:white;\n"
"}"));
        exitBtn = new QPushButton(viewMail);
        exitBtn->setObjectName("exitBtn");
        exitBtn->setGeometry(QRect(759, 15, 15, 15));
        exitBtn->setCursor(QCursor(Qt::PointingHandCursor));
        exitBtn->setStyleSheet(QString::fromUtf8("#exitBtn {\n"
"background-color: transparent;\n"
"border-image: url(:red_x.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        exitBtn->setAutoDefault(true);
        forwardBtn = new QPushButton(viewMail);
        forwardBtn->setObjectName("forwardBtn");
        forwardBtn->setGeometry(QRect(570, 20, 131, 29));
        forwardBtn->setCursor(QCursor(Qt::PointingHandCursor));
        forwardBtn->setStyleSheet(QString::fromUtf8("#forwardBtn\n"
"{\n"
"	    background-color: white;\n"
"		border-radius: 13px;\n"
"        color: black;\n"
"}\n"
"\n"
"\n"
"#forwardBtn:hover\n"
"{\n"
"	    background-color: #dbdad9;\n"
"}"));
        forwardTo = new QLabel(viewMail);
        forwardTo->setObjectName("forwardTo");
        forwardTo->setGeometry(QRect(577, 22, 25, 25));
        forwardTo->setStyleSheet(QString::fromUtf8("#forwardTo {\n"
"background-color: transparent;\n"
"border-image: url(:forwardTo.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        replyBtn = new QPushButton(viewMail);
        replyBtn->setObjectName("replyBtn");
        replyBtn->setGeometry(QRect(420, 20, 131, 29));
        replyBtn->setCursor(QCursor(Qt::PointingHandCursor));
        replyBtn->setStyleSheet(QString::fromUtf8("#replyBtn\n"
"{\n"
"	    background-color: white;\n"
"		border-radius: 13px;\n"
"        color: black;\n"
"}\n"
"\n"
"\n"
"#replyBtn:hover\n"
"{\n"
"	    background-color: #dbdad9;\n"
"}"));
        replyTo = new QLabel(viewMail);
        replyTo->setObjectName("replyTo");
        replyTo->setGeometry(QRect(429, 22, 25, 25));
        replyTo->setStyleSheet(QString::fromUtf8("#replyTo {\n"
"background-color: transparent;\n"
"border-image: url(:replyTo.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        scrollArea_2 = new QScrollArea(viewMail);
        scrollArea_2->setObjectName("scrollArea_2");
        scrollArea_2->setGeometry(QRect(20, 390, 761, 80));
        scrollArea_2->setWidgetResizable(true);
        filesArea = new QWidget();
        filesArea->setObjectName("filesArea");
        filesArea->setGeometry(QRect(0, 0, 759, 78));
        filesArea->setStyleSheet(QString::fromUtf8("#filesArea\n"
"{\n"
"	background-color:#1c1c1b;\n"
"	color:white;\n"
"}"));
        scrollArea_2->setWidget(filesArea);
        fromLabel->raise();
        fromText->raise();
        mailContent->raise();
        exitBtn->raise();
        forwardBtn->raise();
        forwardTo->raise();
        replyBtn->raise();
        replyTo->raise();
        scrollArea_2->raise();
        dockWidget->raise();
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
        viewMail->raise();

        retranslateUi(Interface);
        QObject::connect(compose, &QPushButton::clicked, dockWidget, qOverload<>(&QDockWidget::show));

        send->setDefault(true);
        attachment->setDefault(true);
        exitBtn->setDefault(true);


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
        viewMail->setTitle(QString());
        fromLabel->setText(QCoreApplication::translate("Interface", "From:", nullptr));
        mailContent->setHtml(QCoreApplication::translate("Interface", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        fromText->setText(QCoreApplication::translate("Interface", "Expeditor", nullptr));
        exitBtn->setText(QString());
        forwardBtn->setText(QCoreApplication::translate("Interface", "Forward", nullptr));
        forwardTo->setText(QString());
        replyBtn->setText(QCoreApplication::translate("Interface", "Reply", nullptr));
        replyTo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Interface: public Ui_Interface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_H

#include "interface.h"
#include "ui_interface.h"
#include "mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QByteArray>
#include <QFileDialog>
#include <QMessageBox>
#include "smtp.h"
#include <QList>
#include "QPixmap"
#include "QIcon"
#include <QButtonGroup>


using namespace std;

void Interface::openMail()
{
    ui->scrollArea->hide();
    ui->viewMail->show();
    ui->mailContent->setReadOnly(true);
}

void Interface::downloadFile()
{

}

Interface::Interface(QString User,QString Email,QString Password, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Interface)
{
    ui->setupUi(this);

    connect(ui->sw, &QCheckBox::stateChanged, [=](int state){
        if (state == Qt::Checked)
        {
            ui->Logo->setStyleSheet("border-image: url(:Logo_black.png);");
            ui->inbox->setStyleSheet("border-image: url(:inbox_black.png);");
            ui->star->setStyleSheet("border-image: url(:star_black.png);");
            ui->sent->setStyleSheet("border-image: url(:sent_black.png);");
            ui->trash->setStyleSheet("border-image: url(:trash_black.png);");
            ui->pushButton->setStyleSheet("QPushButton#pushButton:hover{background-color:#dbdbdb;}QPushButton#pushButton{background-color: transparent;border-radius: 20px; color: black; text-align: left; padding-left: 50px;}");
            ui->pushButton_2->setStyleSheet("QPushButton#pushButton_2:hover{background-color:#dbdbdb;}QPushButton#pushButton_2{background-color: transparent;border-radius: 20px; color: black; text-align: left; padding-left: 50px;}");
            ui->pushButton_3->setStyleSheet("QPushButton#pushButton_3:hover{background-color:#dbdbdb;}QPushButton#pushButton_3{background-color: transparent;border-radius: 20px; color: black; text-align: left; padding-left: 50px;}");
            ui->pushButton_4->setStyleSheet("QPushButton#pushButton_4:hover{background-color:#dbdbdb;}QPushButton#pushButton_4{background-color: transparent;border-radius: 20px; color: black; text-align: left; padding-left: 50px;}");
            ui->pushButton_5->setStyleSheet("QPushButton#pushButton_5:hover{background-color:#dbdbdb;}QPushButton#pushButton_5{background-color: transparent;border-radius: 20px; color: black; text-align: left; padding-left: 50px;}");
            ui->pushButton_6->setStyleSheet("QPushButton#pushButton_6:hover{background-color:#dbdbdb;}QPushButton#pushButton_6{background-color: transparent;border-radius: 20px; color: black; text-align: left; padding-left: 50px;}");
            ui->pushButton_7->setStyleSheet("QPushButton#pushButton_7:hover{background-color:#dbdbdb;}QPushButton#pushButton_7{background-color: transparent;border-radius: 20px; color: black; text-align: left; padding-left: 50px;}");
            ui->area1->setStyleSheet("background-color:#9e9e9e;");
            ui->area2->setStyleSheet("background-color:#c2c2c2;");
            ui->label->setStyleSheet("color:black;");
            ui->user->setStyleSheet("color:black");
            ui->dockWidgetContents->setStyleSheet("background-color:#9e9e9e;");
            ui->dockWidget->setStyleSheet("background-color:#dbdbdb;");
        }
        else
        {
            ui->Logo->setStyleSheet("border-image: url(:Logo.png);");
            ui->inbox->setStyleSheet("border-image: url(:inbox.png);");
            ui->star->setStyleSheet("border-image: url(:star.png);");
            ui->sent->setStyleSheet("border-image: url(:sent.png);");
            ui->trash->setStyleSheet("border-image: url(:trash.png);");
            ui->pushButton->setStyleSheet("QPushButton#pushButton:hover{background-color:#363634;}QPushButton#pushButton{background-color: transparent;border-radius: 20px; color: white; text-align: left; padding-left: 50px;}");
            ui->pushButton_2->setStyleSheet("QPushButton#pushButton_2:hover{background-color:#363634;}QPushButton#pushButton_2{background-color: transparent;border-radius: 20px; color: white; text-align: left; padding-left: 50px;}");
            ui->pushButton_3->setStyleSheet("QPushButton#pushButton_3:hover{background-color:#363634;}QPushButton#pushButton_3{background-color: transparent;border-radius: 20px; color: white; text-align: left; padding-left: 50px;}");
            ui->pushButton_4->setStyleSheet("QPushButton#pushButton_4:hover{background-color:#363634;}QPushButton#pushButton_4{background-color: transparent;border-radius: 20px; color: white; text-align: left; padding-left: 50px;}");
            ui->pushButton_5->setStyleSheet("QPushButton#pushButton_5:hover{background-color:#363634;}QPushButton#pushButton_5{background-color: transparent;border-radius: 20px; color: white; text-align: left; padding-left: 50px;}");
            ui->pushButton_6->setStyleSheet("QPushButton#pushButton_6:hover{background-color:#363634;}QPushButton#pushButton_6{background-color: transparent;border-radius: 20px; color: white; text-align: left; padding-left: 50px;}");
            ui->pushButton_7->setStyleSheet("QPushButton#pushButton_7:hover{background-color:#363634;}QPushButton#pushButton_7{background-color: transparent;border-radius: 20px; color: white; text-align: left; padding-left: 50px;}");
            ui->area1->setStyleSheet("background-color:#242423");
            ui->area2->setStyleSheet("background-color:#1c1c1b;");
            ui->label->setStyleSheet("color:white;");
            ui->user->setStyleSheet("color:white;");
            ui->dockWidgetContents->setStyleSheet("background-color:#363634;");
            ui->dockWidget->setStyleSheet("background-color:white;");
        }
    });



    this->layout = new QVBoxLayout(ui->scrollZone);
    this->layout->setAlignment(Qt::AlignTop);
    this->layout->setSpacing(10);
    this->layout->setContentsMargins(10,10,10,10);

    this->filesLayout = new QHBoxLayout(ui->filesArea);
    this->filesLayout->setAlignment(Qt::AlignTop);
    this->filesLayout->setSpacing(10);
    this->filesLayout->setContentsMargins(10,10,10,10);

    ui->dockWidget->hide();
    ui->dockWidget->setWindowTitle("New Message");
    ui->user->setText(User);
    this->Email=Email;
    this->Password=Password;
    ui->viewMail->hide();

    ui->search->setClearButtonEnabled(true);

    QButtonGroup *buttonGroup = new QButtonGroup;
    buttonGroup->setExclusive(true);
    ui->pushButton->setCheckable(true);
    ui->pushButton_2->setCheckable(true);
    ui->pushButton_3->setCheckable(true);
    ui->pushButton_4->setCheckable(true);
    ui->pushButton_5->setCheckable(true);
    ui->pushButton_6->setCheckable(true);
    ui->pushButton_7->setCheckable(true);

    buttonGroup->addButton(ui->pushButton);
    buttonGroup->addButton(ui->pushButton_2);
    buttonGroup->addButton(ui->pushButton_3);
    buttonGroup->addButton(ui->pushButton_4);
    buttonGroup->addButton(ui->pushButton_5);
    buttonGroup->addButton(ui->pushButton_6);
    buttonGroup->addButton(ui->pushButton_7);

    connect(ui->pushButton, &QPushButton::toggled, [=](bool checked) {
        if (ui->pushButton->isChecked()) {
            ui->pushButton->setStyleSheet("#pushButton {background-color: #363634; border-radius: 20px;color: #fff; text-align: left;padding-left: 50px;}");
            ui->pushButton_2->setChecked(false);
            ui->pushButton_3->setChecked(false);
            ui->pushButton_4->setChecked(false);
            ui->pushButton_5->setChecked(false);
            ui->pushButton_6->setChecked(false);
            ui->pushButton_7->setChecked(false);
            this->on_pushButton_2_clicked(1);
            this->on_pushButton_3_clicked(1);
            this->on_pushButton_4_clicked(1);
            this->on_pushButton_5_clicked(1);
            this->on_pushButton_6_clicked(1);
            this->on_pushButton_7_clicked(1);
            this->on_pushButton_clicked(0);
        } else {
            ui->pushButton->setStyleSheet("#pushButton {background-color: transparent; border-radius: 20px;color: #fff; text-align: left;padding-left: 50px;} #pushButton:hover{background-color: #363634;}");
        }
    });

    connect(ui->pushButton_2, &QPushButton::toggled, [=](bool checked) {
        if (ui->pushButton_2->isChecked()) {
            ui->pushButton_2->setStyleSheet("#pushButton_2 {background-color: #363634; border-radius: 20px;color: #fff; text-align: left;padding-left: 50px;}");
            ui->pushButton->setChecked(false);
            ui->pushButton_3->setChecked(false);
            ui->pushButton_4->setChecked(false);
            ui->pushButton_5->setChecked(false);
            ui->pushButton_6->setChecked(false);
            ui->pushButton_7->setChecked(false);
            this->on_pushButton_clicked(1);
            this->on_pushButton_3_clicked(1);
            this->on_pushButton_4_clicked(1);
            this->on_pushButton_5_clicked(1);
            this->on_pushButton_6_clicked(1);
            this->on_pushButton_7_clicked(1);
            this->on_pushButton_2_clicked(0);
        } else {
            ui->pushButton_2->setStyleSheet("#pushButton_2 {background-color: transparent; border-radius: 20px;color: #fff; text-align: left;padding-left: 50px;} #pushButton_2:hover{background-color: #363634;}");
        }
    });

    connect(ui->pushButton_3, &QPushButton::toggled, [=](bool checked) {
        if (ui->pushButton_3->isChecked()) {
            ui->pushButton_3->setStyleSheet("#pushButton_3 {background-color: #363634; border-radius: 20px;color: #fff; text-align: left;padding-left: 50px;}");
            ui->pushButton_2->setChecked(false);
            ui->pushButton->setChecked(false);
            ui->pushButton_4->setChecked(false);
            ui->pushButton_5->setChecked(false);
            ui->pushButton_6->setChecked(false);
            ui->pushButton_7->setChecked(false);
            this->on_pushButton_clicked(1);
            this->on_pushButton_2_clicked(1);
            this->on_pushButton_4_clicked(1);
            this->on_pushButton_5_clicked(1);
            this->on_pushButton_6_clicked(1);
            this->on_pushButton_7_clicked(1);
            this->on_pushButton_3_clicked(0);

        } else {
            ui->pushButton_3->setStyleSheet("#pushButton_3 {background-color: transparent; border-radius: 20px;color: #fff; text-align: left;padding-left: 50px;} #pushButton_3:hover{background-color: #363634;}");
        }
    });

    connect(ui->pushButton_4, &QPushButton::toggled, [=](bool checked) {
        if (ui->pushButton_4->isChecked()) {
            ui->pushButton_4->setStyleSheet("#pushButton_4 {background-color: #363634; border-radius: 20px;color: #fff; text-align: left;padding-left: 50px;}");
            ui->pushButton_2->setChecked(false);
            ui->pushButton_3->setChecked(false);
            ui->pushButton->setChecked(false);
            ui->pushButton_5->setChecked(false);
            ui->pushButton_6->setChecked(false);
            ui->pushButton_7->setChecked(false);
            this->on_pushButton_clicked(1);
            this->on_pushButton_2_clicked(1);
            this->on_pushButton_3_clicked(1);
            this->on_pushButton_5_clicked(1);
            this->on_pushButton_6_clicked(1);
            this->on_pushButton_7_clicked(1);
            this->on_pushButton_4_clicked(0);
        } else {
            ui->pushButton_4->setStyleSheet("#pushButton_4 {background-color: transparent; border-radius: 20px;color: #fff; text-align: left;padding-left: 50px;} #pushButton_4:hover{background-color: #363634;}");
        }
    });

    connect(ui->pushButton_5, &QPushButton::toggled, [=](bool checked) {
        if (ui->pushButton_5->isChecked()) {
            ui->pushButton_5->setStyleSheet("#pushButton_5 {background-color: #363634; border-radius: 20px;color: #fff; text-align: left;padding-left: 50px;}");
            ui->pushButton_2->setChecked(false);
            ui->pushButton_3->setChecked(false);
            ui->pushButton_4->setChecked(false);
            ui->pushButton->setChecked(false);
            ui->pushButton_6->setChecked(false);
            ui->pushButton_7->setChecked(false);
            this->on_pushButton_clicked(1);
            this->on_pushButton_2_clicked(1);
            this->on_pushButton_3_clicked(1);
            this->on_pushButton_4_clicked(1);
            this->on_pushButton_6_clicked(1);
            this->on_pushButton_7_clicked(1);
            this->on_pushButton_5_clicked(0);
        } else {
            ui->pushButton_5->setStyleSheet("#pushButton_5 {background-color: transparent; border-radius: 20px;color: #fff; text-align: left;padding-left: 50px;} #pushButton_5:hover{background-color: #363634;}");
        }
    });

    connect(ui->pushButton_6, &QPushButton::toggled, [=](bool checked) {
        if (ui->pushButton_6->isChecked()) {
            ui->pushButton_6->setStyleSheet("#pushButton_6 {background-color: #363634; border-radius: 20px;color: #fff; text-align: left;padding-left: 50px;}");
            ui->pushButton_2->setChecked(false);
            ui->pushButton_3->setChecked(false);
            ui->pushButton_4->setChecked(false);
            ui->pushButton_5->setChecked(false);
            ui->pushButton->setChecked(false);
            ui->pushButton_7->setChecked(false);
            this->on_pushButton_clicked(1);
            this->on_pushButton_2_clicked(1);
            this->on_pushButton_3_clicked(1);
            this->on_pushButton_4_clicked(1);
            this->on_pushButton_5_clicked(1);
            this->on_pushButton_7_clicked(1);
            this->on_pushButton_6_clicked(0);
        } else {
            ui->pushButton_6->setStyleSheet("#pushButton_6 {background-color: transparent; border-radius: 20px;color: #fff; text-align: left;padding-left: 50px;} #pushButton_6:hover{background-color: #363634;}");
        }
    });


    connect(ui->pushButton_7, &QPushButton::toggled, [=](bool checked) {
        if (ui->pushButton_7->isChecked()) {
            ui->pushButton_7->setStyleSheet("#pushButton_7 {background-color: #363634; border-radius: 20px;color: #fff; text-align: left;padding-left: 50px;}");
            ui->pushButton_2->setChecked(false);
            ui->pushButton_3->setChecked(false);
            ui->pushButton_4->setChecked(false);
            ui->pushButton_5->setChecked(false);
            ui->pushButton_6->setChecked(false);
            ui->pushButton->setChecked(false);
            this->on_pushButton_clicked(1);
            this->on_pushButton_2_clicked(1);
            this->on_pushButton_3_clicked(1);
            this->on_pushButton_4_clicked(1);
            this->on_pushButton_5_clicked(1);
            this->on_pushButton_6_clicked(1);
            this->on_pushButton_7_clicked(0);
        } else {
            ui->pushButton_7->setStyleSheet("#pushButton_7 {background-color: transparent; border-radius: 20px;color: #fff; text-align: left;padding-left: 50px;} #pushButton_7:hover{background-color: #363634;}");
        }
    });



}

Interface::~Interface()
{
    delete ui;
}

void Interface::on_pushButton_8_clicked()
{
    QMessageBox::StandardButton reply;
     reply = QMessageBox::question(this, "Sunteti sigur?", "Doriti sa va intoarceti?",
                                   QMessageBox::Yes|QMessageBox::No);
     if (reply == QMessageBox::Yes) {
         this->hide();
         MainWindow *mainWindow=new MainWindow;
         mainWindow->setStyleSheet("background-image:url(:bg.jpg);color:white;");
         mainWindow->setWindowIcon(QIcon(":Logo.png"));
         mainWindow->setWindowTitle("ATMail");
         mainWindow->show();
     }
     else{}

}




void Interface::on_attachment_clicked()
{
    //QString file_name=QFileDialog::getOpenFileName(this,"Select a file","C://");
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->attachLine->setText( fileListString );
}


void Interface::on_send_clicked()
{
    Smtp* smtp = new Smtp(this->Email, this->Password, "smtp.gmail.com", 465);
       connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

       if( !files.isEmpty() )
           smtp->sendMail(this->Email, ui->ToLine->text() , ui->SubjectLine->text(),ui->textEdit->toPlainText(), files );
       else
           smtp->sendMail(this->Email, ui->ToLine->text() , ui->SubjectLine->text(),ui->textEdit->toPlainText());
}

void Interface::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}


void Interface::on_exitBtn_clicked()
{
    ui->viewMail->hide();
    ui->scrollArea->show();
}


void Interface::on_pushButton_clicked(int check)
{

    if (check==0)
    {
        //creare mail-uri (pana la cate vor fi)
        for (int i = 0; i < 7; i++) {
            QToolButton* button = new QToolButton();
            QIcon icon(":mail.png");

            button->setFixedSize(775,50);
            //QPixmap pixmap = icon.pixmap(QSize(100, 100));
            //QIcon resizedIcon(pixmap);
            button->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
            button->setText("Test\nSubject");
            button->setIcon(icon);
            button->setStyleSheet("QToolButton {   background-color: #40403e; border-radius: 5px; color: #fff; } QToolButton:hover { background-color: #4f4f4d} QToolButton:pressed {background-color: #373778;} ");
            connect(button, &QToolButton::clicked, this, &Interface::openMail);

            buttonList.append(button);
        }

        for(QToolButton *button :buttonList)
        {
            layout->addWidget(button);
        }

        //pt fisiere
        for (int i = 0; i < 2; ++i) {
            QToolButton* file = new QToolButton;
            file->setIcon(QIcon(":blackFile.png"));
            file->setIconSize(QSize(32, 32));
            file->setText("File.txt");
            file->setStyleSheet("text-align:center;");
            file->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
            connect(file, &QToolButton::clicked, this, &Interface::downloadFile);

            filesList.append(file);
        }

        for(QToolButton *button :filesList)
        {
            filesLayout->addWidget(button);
        }

    }

    if (check==1)
    {
        if (layout==nullptr)
        {
            return;
        }

        else
        {
            for(QToolButton *button :buttonList)
            {
                layout->removeWidget(button);
                delete button;
            }

            for(QToolButton *button :filesList)
            {
                filesLayout->removeWidget(button);
                delete button;
            }

        }

        buttonList.clear();
        filesList.clear();
    }
}


void Interface::on_pushButton_2_clicked(int check)
{

    if (check==0)
    {
        for (int i = 0; i < 3 ; i++) {
            QToolButton* button = new QToolButton();
            QIcon icon(":mail.png");

            button->setFixedSize(775,50);
            //QPixmap pixmap = icon.pixmap(QSize(100, 100));
            //QIcon resizedIcon(pixmap);
            button->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
            button->setText("Test\nSubject");
            button->setIcon(icon);
            button->setStyleSheet("QToolButton {   background-color: #40403e; border-radius: 5px; color: #fff; } QToolButton:hover { background-color: #4f4f4d} QToolButton:pressed {background-color: #373778;} ");
            connect(button, &QToolButton::clicked, this, &Interface::openMail);

            buttonList.append(button);
        }

        for(QToolButton *button :buttonList)
        {
            layout->addWidget(button);
        }


    }

    if (check==1)
    {
        if (layout==nullptr)
        {
            return;
        }

        else
        {
            for(QToolButton *button :buttonList)
            {
                layout->removeWidget(button);
                delete button;
            }


        }
        buttonList.clear();
    }
}


void Interface::on_pushButton_3_clicked(int check)
{
    if (check==0)
    {
        for (int i = 0; i < 2 ; i++) {
            QToolButton* button = new QToolButton();
            QIcon icon(":mail.png");

            button->setFixedSize(775,50);
            //QPixmap pixmap = icon.pixmap(QSize(100, 100));
            //QIcon resizedIcon(pixmap);
            button->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
            button->setText("Test\nSubject");
            button->setIcon(icon);
            button->setStyleSheet("QToolButton {   background-color: #40403e; border-radius: 5px; color: #fff; } QToolButton:hover { background-color: #4f4f4d} QToolButton:pressed {background-color: #373778;} ");
            connect(button, &QToolButton::clicked, this, &Interface::openMail);

            buttonList.append(button);
        }

        for(QToolButton *button :buttonList)
        {
            layout->addWidget(button);
        }


    }

    if (check==1)
    {
        if (layout==nullptr)
        {
            return;
        }

        else
        {
            for(QToolButton *button :buttonList)
            {
                layout->removeWidget(button);
                delete button;
            }


        }
        buttonList.clear();
    }

}


void Interface::on_pushButton_4_clicked(int check)
{
    if (check==0)
    {
        for (int i = 0; i < 1 ; i++) {
            QToolButton* button = new QToolButton();
            QIcon icon(":mail.png");

            button->setFixedSize(775,50);
            //QPixmap pixmap = icon.pixmap(QSize(100, 100));
            //QIcon resizedIcon(pixmap);
            button->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
            button->setText("Test\nSubject");
            button->setIcon(icon);
            button->setStyleSheet("QToolButton {   background-color: #40403e; border-radius: 5px; color: #fff; } QToolButton:hover { background-color: #4f4f4d} QToolButton:pressed {background-color: #373778;} ");
            connect(button, &QToolButton::clicked, this, &Interface::openMail);

            buttonList.append(button);
        }

        for(QToolButton *button :buttonList)
        {
            layout->addWidget(button);
        }


    }

    if (check==1)
    {
        if (layout==nullptr)
        {
            return;
        }

        else
        {
            for(QToolButton *button :buttonList)
            {
                layout->removeWidget(button);
                delete button;
            }


        }
        buttonList.clear();
    }

}


void Interface::on_pushButton_5_clicked(int check)
{
    if (check==0)
    {
        for (int i = 0; i < 9 ; i++) {
            QToolButton* button = new QToolButton();
            QIcon icon(":mail.png");

            button->setFixedSize(775,50);
            //QPixmap pixmap = icon.pixmap(QSize(100, 100));
            //QIcon resizedIcon(pixmap);
            button->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
            button->setText("Test\nSubject");
            button->setIcon(icon);
            button->setStyleSheet("QToolButton {   background-color: #40403e; border-radius: 5px; color: #fff; } QToolButton:hover { background-color: #4f4f4d} QToolButton:pressed {background-color: #373778;} ");
            connect(button, &QToolButton::clicked, this, &Interface::openMail);

            buttonList.append(button);
        }

        for(QToolButton *button :buttonList)
        {
            layout->addWidget(button);
        }


    }

    if (check==1)
    {
        if (layout==nullptr)
        {
            return;
        }

        else
        {
            for(QToolButton *button :buttonList)
            {
                layout->removeWidget(button);
                delete button;
            }


        }
        buttonList.clear();
    }

}


void Interface::on_pushButton_6_clicked(int check)
{
    if (check==0)
    {
        for (int i = 0; i < 11 ; i++) {
            QToolButton* button = new QToolButton();
            QIcon icon(":mail.png");

            button->setFixedSize(775,50);
            //QPixmap pixmap = icon.pixmap(QSize(100, 100));
            //QIcon resizedIcon(pixmap);
            button->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
            button->setText("Test\nSubject");
            button->setIcon(icon);
            button->setStyleSheet("QToolButton {   background-color: #40403e; border-radius: 5px; color: #fff; } QToolButton:hover { background-color: #4f4f4d} QToolButton:pressed {background-color: #373778;} ");
            connect(button, &QToolButton::clicked, this, &Interface::openMail);

            buttonList.append(button);
        }

        for(QToolButton *button :buttonList)
        {
            layout->addWidget(button);
        }


    }

    if (check==1)
    {
        if (layout==nullptr)
        {
            return;
        }

        else
        {
            for(QToolButton *button :buttonList)
            {
                layout->removeWidget(button);
                delete button;
            }


        }
        buttonList.clear();
    }

}


void Interface::on_pushButton_7_clicked(int check)
{
    if (check==0)
    {
        for (int i = 0; i < 4 ; i++) {
            QToolButton* button = new QToolButton();
            QIcon icon(":mail.png");

            button->setFixedSize(775,50);
            //QPixmap pixmap = icon.pixmap(QSize(100, 100));
            //QIcon resizedIcon(pixmap);
            button->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
            button->setText("Test\nSubject");
            button->setIcon(icon);
            button->setStyleSheet("QToolButton {   background-color: #40403e; border-radius: 5px; color: #fff; } QToolButton:hover { background-color: #4f4f4d} QToolButton:pressed {background-color: #373778;} ");
            connect(button, &QToolButton::clicked, this, &Interface::openMail);

            buttonList.append(button);
        }

        for(QToolButton *button :buttonList)
        {
            layout->addWidget(button);
        }


    }

    if (check==1)
    {
        if (layout==nullptr)
        {
            return;
        }

        else
        {
            for(QToolButton *button :buttonList)
            {
                layout->removeWidget(button);
                delete button;
            }


        }
        buttonList.clear();
    }

}


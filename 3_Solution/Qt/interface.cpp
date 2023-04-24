#include "interface.h"
#include "ui_interface.h"
#include "mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QByteArray>
#include <QFileDialog>
#include <QMessageBox>
#include "smtp.h"

using namespace std;

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


    ui->dockWidget->hide();
    ui->dockWidget->setWindowTitle("New Message");
    ui->user->setText(User);
    this->Email=Email;
    this->Password=Password;
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


#include "interface.h"
#include "ui_interface.h"
#include "mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QByteArray>


using namespace std;

Interface::Interface(QString User, QWidget *parent) :
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
            ui->area1->setStyleSheet("background-color:#9e9e9e");
            ui->area2->setStyleSheet("background-color:#c2c2c2;");
            ui->label->setStyleSheet("color:black;");
            ui->user->setStyleSheet("color:black");
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
        }
    });


//    QFile file("fis.txt");
//    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
//        // Error handling code if the file can't be opened
//        return;
//    }

//    // Reading data from the file
//    QByteArray fileData = file.readAll();

//    // Closing the file when finished
//    file.close();
    ui->user->setText(User);
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




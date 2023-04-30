#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "mainwindow.h"
#include "interface.h"
#include <dbconnection.h>

RegisterWindow::RegisterWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    connect(ui->checkBox, &QCheckBox::stateChanged, [=](int state){
        if (state == Qt::Checked) {
            ui->passEdit->setEchoMode(QLineEdit::Normal);
        } else {
            ui->passEdit->setEchoMode(QLineEdit::Password);
        }
    });

    connect(ui->checkBoxConfirm, &QCheckBox::stateChanged, [=](int state){
        if (state == Qt::Checked) {
            ui->confirmEdit->setEchoMode(QLineEdit::Normal);
        } else {
            ui->confirmEdit->setEchoMode(QLineEdit::Password);
        }
    });
}


RegisterWindow::~RegisterWindow()
{
    delete ui;
}


void RegisterWindow::on_BackBtn_clicked()
{
    QMessageBox::StandardButton reply;
     reply = QMessageBox::question(this, "Sunteti sigur?", "Doriti sa va intoarceti?",
                                   QMessageBox::Yes|QMessageBox::No);
     if (reply == QMessageBox::Yes)
     {
         this->hide();
         MainWindow *mainWindow=new MainWindow;
         mainWindow->setStyleSheet("background-image:url(:bg.jpg);color:white;");
         mainWindow->setWindowIcon(QIcon(":Logo.png"));
         mainWindow->setWindowTitle("ATMail");
         mainWindow->show();
     }

     else{}


}


void RegisterWindow::on_ContinueBtn_clicked()
{
        dbconnection db;

        QString username = ui->emailEdit->text();
        QString password = ui->passEdit->text();
        QString Lastname = ui->LastnameEdit->text();
        QString Firstname = ui->FirstnameEdit->text();
        QString confirm = ui->confirmEdit->text();

        if (password != confirm)
        {

         QMessageBox::critical(this, "Eroare!","Parolele nu corespund!");

        }

        else
        {
            if (db.getDatabase().open() && username!="" && password!=""&& Lastname!="" && Firstname!="" && confirm!="")
            {
                db.registerToApp(Firstname,Lastname,username,password,this);
                this->hide();
            }

            else
            {
                QMessageBox::critical(this,"Ceva nu a mers corect!","Toate campurile trebuiesc completate");
            }

        }

}

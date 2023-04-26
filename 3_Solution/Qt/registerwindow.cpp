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
            ui->parolaEdit->setEchoMode(QLineEdit::Normal);
        } else {
            ui->parolaEdit->setEchoMode(QLineEdit::Password);
        }
    });

    connect(ui->checkBoxConfirm, &QCheckBox::stateChanged, [=](int state){
        if (state == Qt::Checked) {
            ui->confirmaEdit->setEchoMode(QLineEdit::Normal);
        } else {
            ui->confirmaEdit->setEchoMode(QLineEdit::Password);
        }
    });
}


RegisterWindow::~RegisterWindow()
{
    delete ui;
}


void RegisterWindow::on_InapoiBtn_clicked()
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


void RegisterWindow::on_ContinuaBtn_clicked()
{
        dbconnection db;

        QString username = ui->emailEdit->text();
        QString password = ui->parolaEdit->text();
        QString nume = ui->numeEdit->text();
        QString prenume = ui->prenumeEdit->text();
        QString confirma = ui->confirmaEdit->text();

        if (password != confirma)
        {

         QMessageBox::critical(this, "Eroare!","Parolele nu corespund!");

        }

        else
        {
            if (db.getDatabase().open() && username!="" && password!=""&& nume!="" && prenume!="" && confirma!="")
            {
                db.registerToApp(prenume,nume,username,password,this);
                this->hide();
            }

            else
            {
                QMessageBox::critical(this,"Ceva nu a mers corect!","Toate campurile trebuiesc completate");
            }

        }

}

#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "mainwindow.h"
#include "mail_interface.h"

RegisterWindow::RegisterWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
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


void RegisterWindow::on_ContinuaBtn_clicked()
{
    int check=0;

        database = QSqlDatabase::addDatabase("QODBC");

        database.setDatabaseName("DRIVER={SQL Server};SERVER=2648-ATM-5603N;DATABASE=ProiectQt;UID=minulescu.daniel;PWD=;Trusted_Connection=Yes;");

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
            if (database.open())
            {
                QSqlQuery query(QSqlDatabase::database());

                query.prepare(QString("SELECT * FROM users WHERE username = :username"));
                query.bindValue(":username",username);
                if (!query.exec())
                {
                    QMessageBox::information(this,"Ups!","Ceva nu a mers corect");
                }

                else
                {
                    while(query.next())
                    {
                        QString usernameDB= query.value(1).toString();


                        if (usernameDB == username)
                        {
                            QMessageBox::critical(this,"Eroare!", "Aceasta adresa de email este folosita");
                            check=1;
                        }

                    }
                }

                /////////////////////////////////////////
               if (check==0)
               {
                   QSqlQuery qry;

                   qry.prepare("INSERT INTO Users (username,password,nume,prenume)"
                               "VALUES (:username, :password, :nume, :prenume)");

                   qry.bindValue(":username",username);
                   qry.bindValue(":password",password);
                   qry.bindValue(":nume",nume);
                   qry.bindValue(":prenume",prenume);

                   if (qry.exec())
                   {
                       QMessageBox::information(this,"Autentificare reusita!","Datele au fost introduse cu succes");
                       this->hide();
                       Mail_Interface *mailInterface=new Mail_Interface;
                       mailInterface->show();
                   }

                   else
                   {
                       QMessageBox::information(this, "Eroare!","Datele nu au fost introduse!");
                   }

                   }

            }

            else
            {
                QMessageBox::information(this,"Conexiune esuata!","Baza de date nu este conectata!");
            }


        }



}


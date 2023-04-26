#include "dbconnection.h"
#include "interface.h"
#include <fstream>
#include <QMessageBox>


dbconnection::dbconnection()
{
    database = QSqlDatabase::addDatabase("QODBC");
    database.setDatabaseName("DRIVER={SQL Server};SERVER=2648-ATM-5603N;DATABASE=ProiectQt;UID=minulescu.daniel;PWD=;Trusted_Connection=Yes;");

}

QSqlDatabase dbconnection::getDatabase()
{
    return database;
}

void dbconnection::connectToApp(QString username, QString password, MainWindow* mw)
{
        int check=0;

        QMessageBox::information(mw,"Autentificare reusita!","Conexiune la baza de date");
        QSqlQuery query(QSqlDatabase::database());

        query.prepare(QString("SELECT * FROM users WHERE username = :username AND password = :password"));
        query.bindValue(":username", username);
        query.bindValue(":password", password);

        if (!query.exec())
        {
            QMessageBox::information(mw,"Ups!","Ceva nu a mers corect");
        }

        else
        {
            while(query.next())
            {
                QString usernameDB= query.value(1).toString();
                QString passwordDB= query.value(2).toString();
                QString LastName= query.value(3).toString();
                QString FirstName= query.value(4).toString();

                if (usernameDB == username && passwordDB == password)
                {
                    //QMessageBox::information(this,"Succes", "Am trecut mai departe");
                    check=1;
                    fstream fis("fis.txt",ios::out);
                    fis<<FirstName.toStdString()<<" "<<LastName.toStdString();
                    fis.close();

                    fstream email("email.txt",ios::out);
                    email<<usernameDB.toStdString();
                    email.close();

                    fstream passwordtxt("password.txt",ios::out);
                    passwordtxt<<passwordDB.toStdString();
                    passwordtxt.close();

                    QFile file("fis.txt");
                    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                        // Error handling code if the file can't be opened
                        return;
                    }
                    QByteArray fileData = file.readAll();
                    file.close();

                    QFile file2("email.txt");
                    if (!file2.open(QIODevice::ReadOnly | QIODevice::Text)) {
                        // Error handling code if the file can't be opened
                        return;
                    }
                    QByteArray fileData2 = file2.readAll();
                    file2.close();

                    QFile file3("password.txt");
                    if (!file3.open(QIODevice::ReadOnly | QIODevice::Text)) {
                        // Error handling code if the file can't be opened
                        return;
                    }
                    QByteArray fileData3 = file3.readAll();
                    file3.close();

                    //hide();
                    Interface *mailInterface=new Interface(QString::fromUtf8(fileData),QString::fromUtf8(fileData2),QString::fromUtf8(fileData3));
                    mailInterface->setWindowIcon(QIcon(":Logo.png"));
                    mailInterface->setWindowTitle("ATMail");
                    mailInterface->show();
                }

            }
        }

        if (check==0)
        {
            QMessageBox::information(mw,"Eroare","Email sau parola gresita!");

        }




}

void dbconnection::registerToApp(QString firstname, QString lastname, QString email, QString password, RegisterWindow* rw)
{
    int check=0;

    QSqlQuery query(QSqlDatabase::database());

    query.prepare(QString("SELECT * FROM users WHERE username = :username"));
    query.bindValue(":username",email);
    if (!query.exec())
    {
        QMessageBox::information(rw,"Ups!","Ceva nu a mers corect");
    }

    else
    {
        while(query.next())
        {
            QString usernameDB= query.value(1).toString();

            if (usernameDB == email)
            {
                QMessageBox::critical(rw,"Eroare!", "Aceasta adresa de email este folosita");
                check=1;
            }

        }
    }

   if (check==0)
   {
       QSqlQuery qry;

       qry.prepare("INSERT INTO Users (username,password,nume,prenume)"
                   "VALUES (:username, :password, :nume, :prenume)");

       qry.bindValue(":username",email);
       qry.bindValue(":password",password);
       qry.bindValue(":nume",lastname);
       qry.bindValue(":prenume",firstname);

       if (qry.exec())
       {
           QMessageBox::information(rw,"Autentificare reusita!","Datele au fost introduse cu succes");

           Interface *mailInterface=new Interface(firstname+" "+lastname,email,password);
           mailInterface->setWindowIcon(QIcon(":Logo.png"));
           mailInterface->setWindowTitle("ATMail");
           mailInterface->show();
       }

       else
       {
           QMessageBox::information(rw, "Eroare!","Datele nu au fost introduse!");
       }

    }

}

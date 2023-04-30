#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "registerwindow.h"
#include "interface.h"
#include <fstream>
#include <dbconnection.h>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->checkBox, &QCheckBox::stateChanged, [=](int state){
        if (state == Qt::Checked) {
            ui->textEditPassword->setEchoMode(QLineEdit::Normal);
        } else {
            ui->textEditPassword->setEchoMode(QLineEdit::Password);
        }
    });

//    hide();
//    Interface *mailInterface=new Interface("test","ceva@gmail.com","dada");
//    mailInterface->setWindowIcon(QIcon(":Logo.png"));
//    mailInterface->setWindowTitle("ATMail");
//    mailInterface->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_LoginBtn_clicked()
{
    //database = QSqlDatabase::addDatabase("QODBC");
    //database.setDatabaseName("DRIVER={SQL Server};SERVER=2648-ATM-5603N;DATABASE=ProiectQt;UID=minulescu.daniel;PWD=;Trusted_Connection=Yes;");

    QString username = ui->textEditUserName->text();
    QString password = ui->textEditPassword->text();

    dbconnection db;

    if (db.getDatabase().open())
    {
        hide();
        db.connectToApp(username,password,this);
    }

    else
    {
         QMessageBox::information(this,"Conexiune esuata!","Baza de date nu este conectata!");
    }

}


void MainWindow::on_RegisterBtn_clicked()
{
    hide();
    RegisterWindow registerWindow;
    registerWindow.setWindowIcon(QIcon(":Logo.png"));
    registerWindow.setWindowTitle("Register");
    registerWindow.setModal(true);
    registerWindow.exec();

}


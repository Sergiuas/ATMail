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

    fstream in("RememberMe.txt",ios::in);
    string user, pass;
    string flag;
    getline(in, flag);
    getline(in, user);
    getline(in, pass);
    if (flag=="1")
    {
        QString Username = QString::fromStdString(user);
        QString Password= QString::fromStdString(pass);
        ui->textEditUserName->setText(Username);
        ui->textEditPassword->setText(Password);
    }
    in.close();

    hide();
    Interface *mailInterface=new Interface("test","ceva@gmail.com","dada");
    mailInterface->setWindowIcon(QIcon(":Logo.png"));
    mailInterface->setWindowTitle("ATMail");
    mailInterface->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_LoginBtn_clicked()
{


  if (ui->checkBox_2->isChecked())
  {
    fstream f("RememberMe.txt",ios::out);
    f<<"1"<<endl;
    f<<ui->textEditUserName->text().toStdString()<<endl;
    f<<ui->textEditPassword->text().toStdString()<<endl;
    f.close();
  }
  else
  {
    fstream f("RememberMe.txt",ios::out);
    f<<"0"<<endl;
    f.close();
  }

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


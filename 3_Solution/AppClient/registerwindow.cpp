#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "mainwindow.h"
#include "interface.h"
#include "mail_interface.h"
#include "Client.h"

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
        bool stillConnectedWaitingForAnswer = true;

        QString username = ui->emailEdit->text();
        QString password = ui->parolaEdit->text();
        QString lastname = ui->numeEdit->text();
        QString firstname = ui->prenumeEdit->text();
        QString confirm = ui->confirmaEdit->text();

        if (username == "" || password == "" || lastname=="" || confirm == "" || firstname == "")
        {
            QMessageBox::information(this, "Please fill all the boxes!", "Ok");
            return;
        }


        if (password != confirm)
        {

         QMessageBox::critical(this, "Eroare!","Passwords dont match!");
         return;
        }

        Client& c = Client::getInstance();
        c.Incoming().clear();
        c.Register(username.toStdString(), password.toStdString(), firstname.toStdString(), lastname.toStdString() );


        while (c.Incoming().empty())
        {
            if (!c.IsConnected())
            {
                QMessageBox::information(this, "Server down! Client disconnected!", "Ok");

                stillConnectedWaitingForAnswer = false;
                break;
            }
        }
        if (!c.Incoming().empty() && stillConnectedWaitingForAnswer)
        {
            auto msg = c.Incoming().pop_front().msg;
            if (msg.header.id == app::MessageType::RegisterRequest)
            {
                // server has responded to register request.
                char responseback[1024];
                msg >> responseback;
                if (strcmp(responseback, "Success") == 0)
                {
                    credentials.setEmail(username.toStdString());
                    /*credentials.setFirstname(firstname.toStdString());
                    credentials.setLastname(lastname.toStdString());
                    credentials.setPassword(password.toStdString());*/

                    QMessageBox::information(this, "Succes!", "Ok");
                    hide();
                    Interface* mailInterface = new Interface(credentials, new MainWindow);
                    mailInterface->setWindowIcon(QIcon(":Logo.png"));
                    mailInterface->setWindowTitle("ATMail");
                    mailInterface->show();
                }
                if (strcmp(responseback, "AlreadyRegistered") == 0)
                {
                    QMessageBox::information(this, "A user with these credentials is already registered!", "Ok");
                }
            }
        }


        



}

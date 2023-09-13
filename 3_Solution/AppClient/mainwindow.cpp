#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "registerwindow.h"
#include "mail_interface.h"
#include "interface.h"
#include "Client.h"
#include <fstream>

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



	fstream in("RememberMe.txt", ios::in);
	string user, pass;
	string flag;
	getline(in, flag);
	getline(in, user);
	getline(in, pass);
	if (flag == "1")
	{
		QString Username = QString::fromStdString(user);
		QString Password = QString::fromStdString(pass);
		ui->textEditUserName->setText(Username);
		ui->textEditPassword->setText(Password);
	}
	in.close();

	this->setWindowIcon(QIcon(":Logo.png"));
	this->setWindowTitle("ATMail");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_LoginBtn_clicked()
{


	if (ui->checkBox_2->isChecked())
	{
		fstream f("RememberMe.txt", ios::out);
		f << "1" << endl;
		f << ui->textEditUserName->text().toStdString() << endl;
		f << ui->textEditPassword->text().toStdString() << endl;
		f.close();
	}
	else
	{
		fstream f("RememberMe.txt", ios::out);
		f << "0" << endl;
		f.close();
	}

	QString username = ui->textEditUserName->text();
	QString password = ui->textEditPassword->text();

	bool stillConnectedWaitingForAnswer = true;

	if (username == "" || password == "")
	{
		QMessageBox::information(this, "Please fill all the boxes!", "Ok");
		return;
	}

	Client& c = Client::getInstance();
	c.Incoming().clear();
	c.LoginUser(username.toStdString(), password.toStdString());
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
		if (msg.header.id == app::MessageType::LoginRequest)
		{
			char responseback[1024];
			msg >> responseback;
			if (strcmp(responseback, "UsernameInvalidError") == 0)
			{
				QMessageBox::information(this, "Invalid Username! Please try again.", "Ok");
				ui->textEditUserName->clear();
				return;
			}
			if (strcmp(responseback, "PasswordInvalidError") == 0)
			{
				QMessageBox::information(this, "Invalid Password! Please try again.", "Ok");
				
				ui->textEditUserName->clear();
				return;
			}
			if (strcmp(responseback, "SuccessLogin") == 0)
			{
				QMessageBox::information(this, "Succes!", "Ok");
				credentials.setEmail(username.toStdString());
				loadNextInterface();
			}
		}
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

void MainWindow::loadNextInterface()
{	
	
	hide();

	Interface* mailInterface = new Interface(credentials, this); //TODO: de luat din creditentiale
	mailInterface->setWindowIcon(QIcon(":Logo.png"));
	mailInterface->setWindowTitle("ATMail");
	mailInterface->show();
}


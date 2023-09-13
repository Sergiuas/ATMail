#include "mail_interface.h"
#include "ui_mail_interface.h"

Mail_Interface::Mail_Interface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Mail_Interface)
{
    ui->setupUi(this);
}

Mail_Interface::~Mail_Interface()
{
    delete ui;
}

#include "readmail.h"
#include "ui_readmail.h"

readMail::readMail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::readMail)
{
    ui->setupUi(this);

}

readMail::~readMail()
{
    delete ui;
}

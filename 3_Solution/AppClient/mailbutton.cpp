#include "mailbutton.h"
#include "ui_mailbutton.h"

MailButton::MailButton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MailButton)
{
    ui->setupUi(this);
}

MailButton::~MailButton()
{
    delete ui;
}

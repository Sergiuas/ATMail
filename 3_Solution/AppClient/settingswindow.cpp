#include "settingswindow.h"
#include "ui_settingswindow.h"

SettingsWindow::SettingsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);

    connect(ui->visibilityOld, &QCheckBox::stateChanged, [=](int state){
        if (state == Qt::Checked) {
            ui->editOldPass->setEchoMode(QLineEdit::Normal);
        } else {
            ui->editOldPass->setEchoMode(QLineEdit::Password);
        }
    });

    connect(ui->visibilityNew, &QCheckBox::stateChanged, [=](int state){
        if (state == Qt::Checked) {
            ui->editNewPass->setEchoMode(QLineEdit::Normal);
        } else {
            ui->editNewPass->setEchoMode(QLineEdit::Password);
        }
    });

    this->setWindowIcon(QIcon(":Logo.png"));
    this->setWindowTitle("Setari");
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::on_save_clicked()
{
    //if (parolanoua==parolacurenta) nu se poate
    //de bagat cod
    this->hide();
}


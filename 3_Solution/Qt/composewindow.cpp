#include "composewindow.h"
#include "ui_composewindow.h"

ComposeWindow::ComposeWindow(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::ComposeWindow)
{
    ui->setupUi(this);
}

ComposeWindow::~ComposeWindow()
{
    delete ui;
}

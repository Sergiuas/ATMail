#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setStyleSheet("background-image:url(:bg.jpg)");
    w.setWindowIcon(QIcon(":Logo.png"));
    w.setWindowTitle("ATM MAIL");
    w.show();
    return a.exec();
}

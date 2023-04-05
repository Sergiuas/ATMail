#ifndef MAIL_INTERFACE_H
#define MAIL_INTERFACE_H

#include <QMainWindow>

namespace Ui {
class Mail_Interface;
}

class Mail_Interface : public QMainWindow
{
    Q_OBJECT

public:
    explicit Mail_Interface(QWidget *parent = nullptr);
    ~Mail_Interface();

private:
    Ui::Mail_Interface *ui;
};

#endif // MAIL_INTERFACE_H

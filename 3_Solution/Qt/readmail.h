#ifndef READMAIL_H
#define READMAIL_H

#include <QDialog>

namespace Ui {
class readMail;
}

class readMail : public QDialog
{
    Q_OBJECT

public:
    explicit readMail(QWidget *parent = nullptr);
    ~readMail();

private:
    Ui::readMail *ui;
};

#endif // READMAIL_H

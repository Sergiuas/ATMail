#ifndef INTERFACE_H
#define INTERFACE_H

#include <QDialog>

namespace Ui {
class Interface;
}

class Interface : public QDialog
{
    Q_OBJECT

public:
    explicit Interface(QWidget *parent = nullptr);
    ~Interface();

private slots:
    void on_pushButton_8_clicked();

private:
    Ui::Interface *ui;
};

#endif // INTERFACE_H

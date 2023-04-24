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
    explicit Interface(QString User,QString Email, QString Password, QWidget *parent = nullptr);
    ~Interface();

private slots:
    void on_pushButton_8_clicked();


    void on_attachment_clicked();

    void on_send_clicked();

    void mailSent(QString);

private:
    Ui::Interface *ui;
    QStringList files;
    QString Email;
    QString Password;
};

#endif // INTERFACE_H

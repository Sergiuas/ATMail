#ifndef INTERFACE_H
#define INTERFACE_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QToolButton>

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

    void openMail();

    void downloadFile();

    void performSearch(const QString &searchText);

    void on_exitBtn_clicked();

    void on_pushButton_clicked(int check);

    void on_pushButton_2_clicked(int check);

    void on_pushButton_3_clicked(int check);

    void on_pushButton_4_clicked(int check);

    void on_pushButton_5_clicked(int check);

    void on_pushButton_6_clicked(int check);

    void on_pushButton_7_clicked(int check);

private:
    Ui::Interface *ui;
    QStringList files;
    QString Email;
    QString Password;
    QVBoxLayout *layout;
    QList <QToolButton*> buttonList;
    QHBoxLayout* filesLayout;
    QList <QToolButton*> filesList;
};

#endif // INTERFACE_H

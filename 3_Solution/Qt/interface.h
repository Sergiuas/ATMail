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

    void openFolder();

    void downloadFile();

    void performSearch(const QString &searchText);
    void performFolderSearch(const QString &searchText);

    void on_exitBtn_clicked();

    void on_pushButton_clicked(int check);

    void on_pushButton_2_clicked(int check);

    void on_pushButton_3_clicked(int check);

    void on_pushButton_4_clicked(int check);


    void on_forwardBtn_clicked();

    void on_replyBtn_clicked();

    void on_trashBtn_clicked();

    //nou
    void on_favorite_clicked();

    void on_settings_clicked();

    void on_addFolder_clicked();

    void on_addBtn_clicked();

    void on_exitBtn_2_clicked();

    void on_dropDown_currentTextChanged(const QString &arg1);

private:
    Ui::Interface *ui;
    QStringList files;
    QString Email;
    QString Password;
    QVBoxLayout *layout;
    QList <QToolButton*> buttonList;
    QHBoxLayout* filesLayout;
    QList <QToolButton*> filesList;
    QVBoxLayout* folderLayout;
    QList <QToolButton*> folderList;
};

#endif // INTERFACE_H

#ifndef INTERFACE_H
#define INTERFACE_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QToolButton>
#include "MailBox.h"
#include "app_credentials.h"

namespace Ui {
class Interface;
}

class Interface : public QDialog
{
    Q_OBJECT

public:
    explicit Interface(app::credentials credentials, QWidget *parent = nullptr); //QString Email, QString Password,
    ~Interface();

private slots:
    void updateFolders();

    void on_pushButton_8_clicked();

    void on_attachment_clicked();

    void on_send_clicked();

    void mailSent(QString);

    void updateMailBox();

    //void createMailLayout();

    void openMail(size_t mailId);

    void downloadFile(size_t mailId, std::string fileName);

    void on_exitBtn_clicked();

    void on_pushButton_clicked(int check); // inbox

    void on_pushButton_2_clicked(int check); //starred

    void on_pushButton_3_clicked(int check); //send

    void on_pushButton_4_clicked(int check); //trash

    void on_forwardBtn_clicked();

    void on_replyBtn_clicked();

    void performSearch(const QString& searchText);

    void performFolderSearch(const QString& searchText);

    void on_trashBtn_clicked();

    void on_favorite_clicked();

    void on_settings_clicked();

    void on_addFolder_clicked();

    void on_addBtn_clicked();

    void on_exitBtn_2_clicked();

    void on_dropDown_currentTextChanged(const QString& arg1);

    void openFolder(int id_sectiune);

private:
    Ui::Interface *ui;
    QStringList files;
    app::credentials credentials;
    std::vector<std::string> paths;
    QVBoxLayout* layout;
    QList <QToolButton*> buttonList;
    QHBoxLayout* filesLayout;
    QList <QToolButton*> filesList;
    MailBox* mailbox;
    QVBoxLayout* folderLayout;
    QList <QToolButton*> folderList;
};


#endif // INTERFACE_H

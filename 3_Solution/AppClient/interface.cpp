#include "interface.h"
#include "ui_interface.h"
#include "mainwindow.h"
#include "Client.h"
#include <QFile>
#include <QTextStream>
#include <QByteArray>
#include <QFileDialog>
#include <QMessageBox>
#include <QList>
#include "QVBoxLayout"
#include "QToolButton"
#include "QPixmap"
#include "QIcon"
#include <QObject>
#include "UpdateThread.h"
#include <QButtonGroup>
#include "settingswindow.h"
#include <iostream>


using namespace std;


static int last_layout;
static int active_layout; //  values for this: -2 sendbox, -1 inbox, 0 mail opened, 1 trash, 2 starred, id_folder random_folder_name
static int static_id; // for mailID
static std::string cache_subject; //for reply/forward just temporary
static std::string cache_mail;
static std::string cache_content;


Interface::Interface(app::credentials credentials, QWidget *parent) : credentials(credentials),
    QDialog(parent),
    ui(new Ui::Interface)
{
    ui->setupUi(this);
    

    connect(ui->sw, &QCheckBox::stateChanged, [=](int state) {
        if (state == Qt::Checked)
        {
            ui->Logo->setStyleSheet("border-image: url(:Logo_black.png);");
            ui->inbox->setStyleSheet("border-image: url(:inbox_black.png);");
            ui->star->setStyleSheet("border-image: url(:star_black.png);");
            ui->sent->setStyleSheet("border-image: url(:sent_black.png);");
            ui->trash->setStyleSheet("border-image: url(:trash_black.png);");
            ui->pushButton->setStyleSheet("QPushButton#pushButton:hover{background-color:#dbdbdb;}QPushButton#pushButton{background-color: transparent;border-radius: 20px; color: black; text-align: left; padding-left: 50px;}");
            ui->pushButton_2->setStyleSheet("QPushButton#pushButton_2:hover{background-color:#dbdbdb;}QPushButton#pushButton_2{background-color: transparent;border-radius: 20px; color: black; text-align: left; padding-left: 50px;}");
            ui->pushButton_3->setStyleSheet("QPushButton#pushButton_3:hover{background-color:#dbdbdb;}QPushButton#pushButton_3{background-color: transparent;border-radius: 20px; color: black; text-align: left; padding-left: 50px;}");
            ui->pushButton_4->setStyleSheet("QPushButton#pushButton_4:hover{background-color:#dbdbdb;}QPushButton#pushButton_4{background-color: transparent;border-radius: 20px; color: black; text-align: left; padding-left: 50px;}");
            ui->area1->setStyleSheet("background-color:#9e9e9e;");
            ui->area2->setStyleSheet("background-color:#c2c2c2;");
            ui->label->setStyleSheet("color:black;");
            ui->user->setStyleSheet("color:black");
            ui->dockWidgetContents->setStyleSheet("background-color:#9e9e9e;");
            ui->dockWidget->setStyleSheet("background-color:#dbdbdb;");
        }
        else
        {
            ui->Logo->setStyleSheet("border-image: url(:Logo.png);");
            ui->inbox->setStyleSheet("border-image: url(:inbox.png);");
            ui->star->setStyleSheet("border-image: url(:star.png);");
            ui->sent->setStyleSheet("border-image: url(:sent.png);");
            ui->trash->setStyleSheet("border-image: url(:trash.png);");
            ui->pushButton->setStyleSheet("QPushButton#pushButton:hover{background-color:#363634;}QPushButton#pushButton{background-color: transparent;border-radius: 20px; color: white; text-align: left; padding-left: 50px;}");
            ui->pushButton_2->setStyleSheet("QPushButton#pushButton_2:hover{background-color:#363634;}QPushButton#pushButton_2{background-color: transparent;border-radius: 20px; color: white; text-align: left; padding-left: 50px;}");
            ui->pushButton_3->setStyleSheet("QPushButton#pushButton_3:hover{background-color:#363634;}QPushButton#pushButton_3{background-color: transparent;border-radius: 20px; color: white; text-align: left; padding-left: 50px;}");
            ui->pushButton_4->setStyleSheet("QPushButton#pushButton_4:hover{background-color:#363634;}QPushButton#pushButton_4{background-color: transparent;border-radius: 20px; color: white; text-align: left; padding-left: 50px;}");

            ui->area1->setStyleSheet("background-color:#242423");
            ui->area2->setStyleSheet("background-color:#1c1c1b;");
            ui->label->setStyleSheet("color:white;");
            ui->user->setStyleSheet("color:white;");
            ui->dockWidgetContents->setStyleSheet("background-color:#363634;");
            ui->dockWidget->setStyleSheet("background-color:white;");
        }
        });
   // de conectat si eventualele foldere adaugate

    this->layout = new QVBoxLayout(ui->scrollZone);
    this->layout->setAlignment(Qt::AlignTop);
    this->layout->setSpacing(10);
    this->layout->setContentsMargins(10, 10, 10, 10);

    this->filesLayout = new QHBoxLayout(ui->filesArea);
    this->filesLayout->setAlignment(Qt::AlignTop);
    this->filesLayout->setSpacing(10);
    this->filesLayout->setContentsMargins(10, 10, 10, 10);

    this->folderLayout = new QVBoxLayout(ui->folderZone);
    this->folderLayout->setAlignment(Qt::AlignTop);
    this->folderLayout->setSpacing(10);
    this->folderLayout->setContentsMargins(10, 10, 10, 10);

    ui->dockWidget->hide();
    ui->dockWidget->setWindowTitle("New Message");
    //this->Password = Password;
    ui->user->setText(QString::fromStdString(credentials.getEmail()));
    ui->viewMail->hide();
    ui->search->setClearButtonEnabled(true);
    ui->createFolderWindow->hide(); 
    ui->dropDown->addItem(""); 

    QButtonGroup* buttonGroup = new QButtonGroup;
    buttonGroup->setExclusive(true);
    ui->pushButton->setCheckable(true);
    ui->pushButton_2->setCheckable(true);
    ui->pushButton_3->setCheckable(true);
    ui->pushButton_4->setCheckable(true);


    buttonGroup->addButton(ui->pushButton);
    buttonGroup->addButton(ui->pushButton_2);
    buttonGroup->addButton(ui->pushButton_3);
    buttonGroup->addButton(ui->pushButton_4);


    connect(ui->pushButton, &QPushButton::toggled, [=](bool checked) {
        if (ui->pushButton->isChecked()) {
            ui->pushButton->setStyleSheet("#pushButton {background-color: #363634; border-radius: 20px;color: #fff; text-align: left;padding-left: 50px;}");
            ui->pushButton_2->setChecked(false);
            ui->pushButton_3->setChecked(false);
            ui->pushButton_4->setChecked(false);

            this->on_pushButton_2_clicked(1);
            this->on_pushButton_3_clicked(1);
            this->on_pushButton_4_clicked(1);

            this->on_pushButton_clicked(0);
        }
        else {
            ui->pushButton->setStyleSheet("#pushButton {background-color: transparent; border-radius: 20px;color: #fff; text-align: left;padding-left: 50px;} #pushButton:hover{background-color: #363634;}");
        }
        });

    connect(ui->pushButton_2, &QPushButton::toggled, [=](bool checked) {
        if (ui->pushButton_2->isChecked()) {
            ui->pushButton_2->setStyleSheet("#pushButton_2 {background-color: #363634; border-radius: 20px;color: #fff; text-align: left;padding-left: 50px;}");
            ui->pushButton->setChecked(false);
            ui->pushButton_3->setChecked(false);
            ui->pushButton_4->setChecked(false);

            this->on_pushButton_clicked(1);
            this->on_pushButton_3_clicked(1);
            this->on_pushButton_4_clicked(1);

            this->on_pushButton_2_clicked(0);
        }
        else {
            ui->pushButton_2->setStyleSheet("#pushButton_2 {background-color: transparent; border-radius: 20px;color: #fff; text-align: left;padding-left: 50px;} #pushButton_2:hover{background-color: #363634;}");
        }
        });

    connect(ui->pushButton_3, &QPushButton::toggled, [=](bool checked) {
        if (ui->pushButton_3->isChecked()) {
            ui->pushButton_3->setStyleSheet("#pushButton_3 {background-color: #363634; border-radius: 20px;color: #fff; text-align: left;padding-left: 50px;}");
            ui->pushButton_2->setChecked(false);
            ui->pushButton->setChecked(false);
            ui->pushButton_4->setChecked(false);

            this->on_pushButton_clicked(1);
            this->on_pushButton_2_clicked(1);
            this->on_pushButton_4_clicked(1);

            this->on_pushButton_3_clicked(0);

        }
        else {
            ui->pushButton_3->setStyleSheet("#pushButton_3 {background-color: transparent; border-radius: 20px;color: #fff; text-align: left;padding-left: 50px;} #pushButton_3:hover{background-color: #363634;}");
        }
        });

    connect(ui->pushButton_4, &QPushButton::toggled, [=](bool checked) {
        if (ui->pushButton_4->isChecked()) {
            ui->pushButton_4->setStyleSheet("#pushButton_4 {background-color: #363634; border-radius: 20px;color: #fff; text-align: left;padding-left: 50px;}");
            ui->pushButton_2->setChecked(false);
            ui->pushButton_3->setChecked(false);
            ui->pushButton->setChecked(false);

            this->on_pushButton_clicked(1);
            this->on_pushButton_2_clicked(1);
            this->on_pushButton_3_clicked(1);

            this->on_pushButton_4_clicked(0);
        }
        else {
            ui->pushButton_4->setStyleSheet("#pushButton_4 {background-color: transparent; border-radius: 20px;color: #fff; text-align: left;padding-left: 50px;} #pushButton_4:hover{background-color: #363634;}");
        }
        });


    
    connect(ui->search, &QLineEdit::textChanged, this, &Interface::performSearch); // pentru search
    connect(ui->search_2, &QLineEdit::textChanged, this, &Interface::performFolderSearch);


    mailbox = new MailBox;
    updateMailBox();

    try {
        updateFolders();
    }
    catch(std::invalid_argument& e) {
        // Handle the exception here
        qDebug() << "Invalid argument: " << e.what();
    }

    QToolButton* folder = new QToolButton; //pentru a scoate dintr un folder
    folder->setText("not in a folder");
    folderList.append(folder); //aici adauga


    //!!!! TREBUIE SI UN UPDATE SECTIONS CA SA RAMANA PENTRU ALTA rulare! o fac!!!!
    // si o functie pentru stergere foldere;


    QObject* obj = nullptr;
    UpdateThread* mythread = new UpdateThread(obj);
    connect(mythread, &UpdateThread::refreshPage, this, &Interface::updateMailBox);
    mythread->start();


}


Interface::~Interface()
{
    delete ui;
}

void Interface::updateFolders()
{
    Client& c = Client::getInstance();
    c.createFolders(credentials.getEmail());//Adaug direct la send


    
    while (c.Incoming().empty())
    {
        if (!c.IsConnected())
        {
            QMessageBox::information(this, "Server down! Client disconnected!", "Ok");


            break;
        }
    }
    if (!c.Incoming().empty())
    {
        auto msg = c.Incoming().pop_front().msg;
        if (msg.header.id == app::MessageType::CreateFolders)
        {
            int nr_folders;
            int folderId;
            char folderName[1024];

            msg >> nr_folders;

            for (int i = 0; i < nr_folders; i++)
            {
                msg >> folderId >> folderName;
               
                    QToolButton* folder = new QToolButton;
                    QIcon icon(":folder_yellow.png");
                    folder->setFixedSize(290, 35);
                    folder->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
                    folder->setText(QString::fromUtf8(folderName));
                    folder->setIcon(icon);
                    folder->setStyleSheet("QToolButton {   background-color: #40403e; border-radius: 5px; color: #fff; } QToolButton:hover { background-color: #4f4f4d} QToolButton:pressed {background-color: #373778;} ");
                    folderLayout->addWidget(folder);
                    folderList.append(folder); //aici adauga
                    connect(folder, &QToolButton::clicked, this, [=]() {openFolder(folderId);

                    /*        ui->pushButton_4->setChecked(false);
                            ui->pushButton_2->setChecked(false);
                            ui->pushButton_3->setChecked(false);
                            ui->pushButton->setChecked(false);

                            this->on_pushButton_clicked(1);
                            this->on_pushButton_2_clicked(1);
                            this->on_pushButton_3_clicked(1);

                            this->on_pushButton_4_clicked(1);*/

                        });

                    mailbox->addSection(folderId, folderName);
                

            }
        }
    }
}

void Interface::openFolder(int id_sectiune)
{
    if (buttonList.size() != 0) {
        ui->viewMail->hide();
        if (layout == nullptr)
        {
            return;
        }

        else
        {
            for (QToolButton* button : buttonList)
            {
                layout->removeWidget(button);
                delete button;
            }


        }

        buttonList.clear();
    }

  
       /* ui->scrollArea->show();
        ui->viewMail->hide();*/
        active_layout = id_sectiune;
        std::deque trashbox = mailbox->getSectionMails(id_sectiune, credentials.getEmail()); //stared mails tho
        int size = trashbox.size();
        for (int i = 0; i < size; i++) {
            QToolButton* button = new QToolButton();
            QIcon icon(":openedMail.png");
            std::string titlu = "From " + trashbox[i].src + " to " + trashbox[i].dest + "\n" + trashbox[i].subject + "\t\t\t\t\t\t\t\t" + trashbox[i].ora;
            button->setFixedSize(775, 50);
            //QPixmap pixmap = icon.pixmap(QSize(100, 100));
            //QIcon resizedIcon(pixmap);
            button->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
            button->setText(QString::fromStdString(titlu));
            button->setIcon(icon);
            button->setStyleSheet("QToolButton {   background-color: #40403e; border-radius: 5px; color: #fff; } QToolButton:hover { background-color: #4f4f4d} QToolButton:pressed {background-color: #373778;} ");
            connect(button, &QToolButton::clicked, this, [=]() {openMail(trashbox[i].mailId); });
            buttonList.append(button);
        }

        for (QToolButton* button : buttonList)
        {
            layout->addWidget(button);
        }
        ui->scrollArea->show();

}

void Interface::on_forwardBtn_clicked()
{
    ui->dockWidget->show();
    ui->ToLine->clear();
    ui->SubjectLine->setText(QString::fromStdString(cache_subject));
    ui->textEdit->setText(QString::fromStdString(cache_content));
}


void Interface::on_replyBtn_clicked()
{
    ui->dockWidget->show();
    ui->ToLine->setText(QString::fromStdString(cache_mail));
    ui->SubjectLine->setText(QString::fromStdString("Reply: " + cache_subject));
    ui->textEdit->clear();
}



void Interface::performSearch(const QString& searchText)
{
    for (QToolButton* button : buttonList)
    {
        if (button->text().contains(searchText, Qt::CaseInsensitive))
        {
            button->setVisible(true);
        }

        else
        {
            button->setVisible(false);
        }
    }
}


void Interface::performFolderSearch(const QString& searchText)
{
    for (QToolButton* folder : folderList)
    {
        if (folder->text().contains(searchText, Qt::CaseInsensitive))
        {
            folder->setVisible(true);
        }

        else
        {
            folder->setVisible(false);
        }
    }
}

void Interface::updateMailBox()
{
   // send msg to server to see if there s update to its database
    Client& c = Client::getInstance();
    c.checkUpdate(credentials.getEmail(), mailbox->getLastId()); //Adaug direct la send
    

    int a;
    while (c.Incoming().empty())
    {
        if (!c.IsConnected())
        {
            QMessageBox::information(this, "Server down! Client disconnected!", "Ok");

            
            break;
        }
    }
    if (!c.Incoming().empty())
    {
        auto msg = c.Incoming().pop_front().msg;
        if (msg.header.id == app::MessageType::Update)
        {
            size_t number;
            msg >> number;
            int a = mailbox->getLastId();
            
            if (mailbox->getLastId() == 0) {
                for (size_t i = 0; i < number; i++)
                {
                    char subject[1024], src[1024], dest[1024], ora[1024];
                    size_t mailId;
                    int s;
                    bool seen;
                    int files;
                    int section;

                    msg >> mailId >> src >> dest >> subject >> ora >> s >> files >> section;
                    if (s == 0)
                        seen = false;
                    else
                        seen = true;
                    mailbox->addMail(std::string(src), std::string(dest), std::string(subject), mailId, std::string(ora), seen, files, section);
                }
            }
            else if(number!=0)
            {
                
                for (size_t i = 0; i < number; i++)
                {
                    char subject[1024], src[1024], dest[1024], ora[1024];
                    size_t mailId;
                    int s;
                    bool seen;
                    int files;
                    int section;

                    msg >> mailId >> src >> dest >> subject >> ora >> s >> files >> section;

                    if (s == 0)
                        seen = false;
                    else
                        seen = true;
                    
                    if (mailbox->getLastId() != mailId) { //problema sa nu bage 2 mailuri la fel
                        mailbox->addFrontMail(std::string(src), std::string(dest), std::string(subject), mailId, std::string(ora), seen, files, section);
                        mailbox->setLastId(mailId);
                    }
                }
            }
        }

        if (active_layout == -1)
        {
            on_pushButton_clicked(1);
            on_pushButton_clicked(0);
        }

        if (active_layout == -2)
        {
            on_pushButton_3_clicked(1);
            on_pushButton_3_clicked(0);
        }

        if (active_layout == 1)
        {
            on_pushButton_4_clicked(1);
            on_pushButton_4_clicked(0);
        }

        if (active_layout == 2)
        {
            on_pushButton_2_clicked(1);
            on_pushButton_2_clicked(0);
        }
    }

}


void Interface::openMail(size_t mailId)
{

    ui->scrollArea->hide();
    ui->viewMail->show();
    ui->mailContent->setReadOnly(true);
    int files;
    std::vector<std::string> names;
    int read;
    if (active_layout == -1)
        read = 1;
    else
        read = 0;

    if(mailbox->getMail(mailId).section == 2)
        ui->favorite->setStyleSheet("#favorite {background-color: transparent; border-image: url(:favorite_yellow.png); background: none; border: none; background-repeat: none;}");
    else
        ui->favorite->setStyleSheet("#favorite {background-color: transparent; border-image: url(:favorite_white.png); background: none; border: none; background-repeat: none;}");

    Client& c = Client::getInstance(); //trebuie sa trimit la server sa puna seen = 1;
    c.requestMail(mailId, read);
    
    static_id = mailId;

    while (c.Incoming().empty())
    {
        if (!c.IsConnected())
        {
            QMessageBox::information(this, "Server down! Client disconnected!", "Ok");


            break;
        }
    }
    if (!c.Incoming().empty())
    {
        auto msg = c.Incoming().pop_front().msg;
        if (msg.header.id == app::MessageType::Sent)
        {
            char content[4 * 1024];
            char subject[1024];
            char src[1024];
            char aux[1024];
            char dest[1024];
            

            msg >> files;// src >> subject >> content >> files;

            for (int i = 0; i < files; i++)
            {
                msg >> aux;
                names.push_back(std::string(aux));
            }

            msg >> dest >> src >> subject >> content; //Adauga si destinatar

            std::string l_src(src);
            cache_mail = l_src;
            std::string l_subject(subject);
            cache_subject = l_subject;
            std::string l_content(content);
            cache_content = l_content;
            std::string l_dest(dest);

            ui->mailContent->setPlainText(QString::fromStdString("\n" + l_subject + "\n\n" + l_content));

            ui->fromText->setText(QString::fromStdString(l_src));
        }
    }

    if (files != 0)
    {

        for (int i = 0; i < files; ++i) {
            QToolButton* file = new QToolButton;
            file->setIcon(QIcon(":blackFile.png"));
            file->setIconSize(QSize(32, 32));
            file->setText(QString::fromStdString(names[i]));
            file->setStyleSheet("text-align:center;");
            file->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
            connect(file, &QToolButton::clicked, this, [=]() {downloadFile(mailId, names[i]); });

            filesList.append(file);
        }

        for (QToolButton* button : filesList)
        {
            filesLayout->addWidget(button);
        }
    }

    ui->dropDown->clear();

    for (QToolButton* folder : folderList)
    {
        ui->dropDown->addItem(folder->text()); //nou
    }
    last_layout = active_layout;
    active_layout = 0;


}

void Interface::downloadFile(size_t mailId, std::string fileName)
{
    Client& c = Client::getInstance();
    c.requestFile(mailId, fileName);

    while (c.Incoming().empty())
    {
        if (!c.IsConnected())
        {
            QMessageBox::information(this, "Server down! Client disconnected!", "Ok");
            break;
        }
    }
    if (!c.Incoming().empty())
    {
        auto msg = c.Incoming().pop_front().msg;
        if (msg.header.id == app::MessageType::FileSent)
        {

            std::size_t numChunks;
            msg >> numChunks;

            char* username = getenv("USERNAME");
            std::string name(username);
            std::string path = "C:\\Users\\" + name + "\\Downloads\\" + std::string(fileName);

            

            std::ofstream fout(path, std::ios::binary | std::ios::app);// | std::ios::out);

            size_t fileSize = 0;

            for (std::size_t i = 0; i < numChunks; i++)
            {
                char buf[1024];

                std::size_t bytesRead;

                msg >> bytesRead;
                msg >> buf;
                std::cout << buf;
                fout.write(buf, bytesRead);
            }
            fout.close();

        }
    }
}

void Interface::on_exitBtn_clicked()
{
    ui->viewMail->hide();

    mailbox->setSeen(static_id);
    active_layout = last_layout;

    ui->scrollArea->show();
}


void Interface::on_pushButton_8_clicked()
{
    QMessageBox::StandardButton reply;
     reply = QMessageBox::question(this, "Sunteti sigur?", "Doriti sa va intoarceti?",
                                   QMessageBox::Yes|QMessageBox::No);
     if (reply == QMessageBox::Yes) {
         this->hide();
         MainWindow *mainWindow=new MainWindow;
         
         mainWindow->setWindowIcon(QIcon(":Logo.png"));
         mainWindow->setWindowTitle("ATMail");
         mainWindow->show();
     }
     else{}


}




void Interface::on_attachment_clicked()
{
    //QString file_name=QFileDialog::getOpenFileName(this,"Select a file","C://");
    files.clear();
    

    QFileDialog dialog(this);
    QString fileListString = ui->attachLine->text();

    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();


    paths.push_back(files[0].toStdString());
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );
    

    ui->attachLine->setText( fileListString );
    
}


void Interface::on_send_clicked()
{
   /* Smtp* smtp = new Smtp(this->Email, this->Password, "smtp.gmail.com", 465);
       connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

       if( !files.isEmpty() )
           smtp->sendMail(this->Email, ui->ToLine->text() , ui->SubjectLine->text(),ui->textEdit->toPlainText(), files );
       else
           smtp->sendMail(this->Email, ui->ToLine->text() , ui->SubjectLine->text(),ui->textEdit->toPlainText());*/



    if (ui->attachLine->text() == "")
        paths.clear();


    Client& c = Client::getInstance();
    
    c.SendMail(credentials.getEmail(), ui->ToLine->text().toStdString(), ui->SubjectLine->text().toStdString(), ui->textEdit->toPlainText().toStdString(), paths);

    ui->ToLine->clear();
    ui->SubjectLine->clear();
    ui->textEdit->clear();
    ui->attachLine->clear();
    
    

    paths.clear();
}

void Interface::on_pushButton_clicked(int check)
{
    if (buttonList.size() != 0) {
        ui->viewMail->hide();
        if (layout == nullptr)
        {
            return;
        }

        else
        {
            for (QToolButton* button : buttonList)
            {
                layout->removeWidget(button);
                delete button;
            }


        }

        buttonList.clear();
    }

    if (check == 0)
    {
        ui->viewMail->hide();
        ui->scrollArea->show();
        active_layout = -1;
        std::deque inbox = mailbox->getInbox(credentials.getEmail());
        int size = inbox.size();
        for (int i = 0; i < size; i++) {
            QToolButton* button = new QToolButton();

                QIcon icon(":mail.png");
                QIcon icon2(":openedMail.png");
                

            std::string titlu = inbox[i].src + "\n" + inbox[i].subject + "\t\t\t\t\t\t\t\t" + inbox[i].ora;
            button->setFixedSize(775, 50);
            //QPixmap pixmap = icon.pixmap(QSize(100, 100));
            //QIcon resizedIcon(pixmap);
            button->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
            button->setText(QString::fromStdString(titlu));

            if (inbox[i].seen == false)
                button->setIcon(icon);
            else
                button->setIcon(icon2);

            button->setStyleSheet("QToolButton {   background-color: #40403e; border-radius: 5px; color: #fff; } QToolButton:hover { background-color: #4f4f4d} QToolButton:pressed {background-color: #373778;} ");
            connect(button, &QToolButton::clicked, this, [=]() {
                openMail(inbox[i].mailId);
                mailbox->setSeen(inbox[i].mailId);  });

            buttonList.append(button);
        }

        for (QToolButton* button : buttonList)
        {
            layout->addWidget(button);
        }


    }

    if (check == 1)
    {

        if (layout == nullptr)
        {
            return;
        }

        else
        {
            for (QToolButton* button : buttonList)
            {
                layout->removeWidget(button);
                delete button;
            }

            for (QToolButton* button : filesList)
            {
                filesLayout->removeWidget(button);
                delete button;
            }

        }

        buttonList.clear();
        filesList.clear();
    }
}


void Interface::on_pushButton_2_clicked(int check)
{
    if (buttonList.size() != 0) {
        ui->viewMail->hide();
        if (layout == nullptr)
        {
            return;
        }

        else
        {
            for (QToolButton* button : buttonList)
            {
                layout->removeWidget(button);
                delete button;
            }


        }

        buttonList.clear();
    }
    if (check == 0)
    {
        ui->scrollArea->show();
        ui->viewMail->hide();
        active_layout = 2;
        std::deque trashbox = mailbox->getSectionMails(2, credentials.getEmail()); //stared mails tho
        int size = trashbox.size();
        for (int i = 0; i < size; i++) {
            QToolButton* button = new QToolButton();
            QIcon icon(":openedMail.png");
            std::string titlu = "From " + trashbox[i].src + " to " + trashbox[i].dest + "\n" + trashbox[i].subject + "\t\t\t\t\t\t\t\t" + trashbox[i].ora;
            button->setFixedSize(775, 50);
            //QPixmap pixmap = icon.pixmap(QSize(100, 100));
            //QIcon resizedIcon(pixmap);
            button->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
            button->setText(QString::fromStdString(titlu));
            button->setIcon(icon);
            button->setStyleSheet("QToolButton {   background-color: #40403e; border-radius: 5px; color: #fff; } QToolButton:hover { background-color: #4f4f4d} QToolButton:pressed {background-color: #373778;} ");
            connect(button, &QToolButton::clicked, this, [=]() {openMail(trashbox[i].mailId); });

            buttonList.append(button);
        }

        for (QToolButton* button : buttonList)
        {
            layout->addWidget(button);
        }


    }

    if (check == 1)
    {
        ui->viewMail->hide();
        if (layout == nullptr)
        {
            return;
        }

        else
        {
            for (QToolButton* button : buttonList)
            {
                layout->removeWidget(button);
                delete button;
            }


        }
        buttonList.clear();
    }
}


void Interface::on_pushButton_3_clicked(int check)
{
    if (buttonList.size() != 0) {
        ui->viewMail->hide();
        if (layout == nullptr)
        {
            return;
        }

        else
        {
            for (QToolButton* button : buttonList)
            {
                layout->removeWidget(button);
                delete button;
            }


        }

        buttonList.clear();
    }
    if (check == 0)
    {
        ui->scrollArea->show();
        ui->viewMail->hide();
        active_layout = -2;
        std::deque inbox = mailbox->getSendbox(credentials.getEmail());
        int size = inbox.size();
        for (int i = 0; i < size; i++) {
            QToolButton* button = new QToolButton();
            QIcon icon(":openedMail.png");
            std::string titlu ="Dest: " + inbox[i].dest + "\n" + inbox[i].subject + "\t\t\t\t\t\t\t\t" + inbox[i].ora;
            button->setFixedSize(775, 50);
            //QPixmap pixmap = icon.pixmap(QSize(100, 100));
            //QIcon resizedIcon(pixmap);
            button->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
            button->setText(QString::fromStdString(titlu));
            button->setIcon(icon);
            button->setStyleSheet("QToolButton {   background-color: #40403e; border-radius: 5px; color: #fff; } QToolButton:hover { background-color: #4f4f4d} QToolButton:pressed {background-color: #373778;} ");
            connect(button, &QToolButton::clicked, this, [=]() {openMail(inbox[i].mailId); });

            buttonList.append(button);
        }

        for (QToolButton* button : buttonList)
        {
            layout->addWidget(button);
        }


    }

    if (check == 1)
    {
        if (layout == nullptr)
        {
            return;
        }

        else
        {
            for (QToolButton* button : buttonList)
            {
                layout->removeWidget(button);
                delete button;
            }


        }
        buttonList.clear();
    }

}


void Interface::on_pushButton_4_clicked(int check)
{
    if (buttonList.size() != 0) {
        ui->viewMail->hide();
        if (layout == nullptr)
        {
            return;
        }

        else
        {
            for (QToolButton* button : buttonList)
            {
                layout->removeWidget(button);
                delete button;
            }


        }

        buttonList.clear();
    }
    if (check == 0)
    {
        ui->scrollArea->show();
        ui->viewMail->hide();
        active_layout = 1;
        std::deque trashbox = mailbox->getSectionMails(1, credentials.getEmail());
        int size = trashbox.size();
        for (int i = 0; i < size; i++) {
            QToolButton* button = new QToolButton();
            QIcon icon(":openedMail.png");
            std::string titlu = "From " + trashbox[i].src + " to " + trashbox[i].dest + "\n" + trashbox[i].subject + "\t\t\t\t\t\t\t\t" + trashbox[i].ora;
            button->setFixedSize(775, 50);
            //QPixmap pixmap = icon.pixmap(QSize(100, 100));
            //QIcon resizedIcon(pixmap);
            button->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
            button->setText(QString::fromStdString(titlu));
            button->setIcon(icon);
            button->setStyleSheet("QToolButton {   background-color: #40403e; border-radius: 5px; color: #fff; } QToolButton:hover { background-color: #4f4f4d} QToolButton:pressed {background-color: #373778;} ");
            connect(button, &QToolButton::clicked, this, [=]() {openMail(trashbox[i].mailId); });
            buttonList.append(button);
        }

        for (QToolButton* button : buttonList)
        {
            layout->addWidget(button);
        }


    }

    if (check == 1)
    {
        ui->viewMail->hide();
        if (layout == nullptr)
        {
            return;
        }

        else
        {
            for (QToolButton* button : buttonList)
            {
                layout->removeWidget(button);
                delete button;
            }


        }
        buttonList.clear();
    }

}


void Interface::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}

//nou
void Interface::on_favorite_clicked()
{
    Client& c = Client::getInstance();
    if (mailbox->getMail(static_id).section != 2 && active_layout != -2) {
        ui->favorite->setStyleSheet("#favorite {background-color: transparent; border-image: url(:favorite_yellow.png); background: none; border: none; background-repeat: none;}");
        //adaugare la sectiunea starred

        mailbox->setSection(static_id, 2);
        c.addMailInFolder(static_id, 2);

    }
    else if (active_layout != -2)
    {
        ui->favorite->setStyleSheet("#favorite {background-color: transparent; border-image: url(:favorite_white.png); background: none; border: none; background-repeat: none;}");
        mailbox->setSection(static_id, 0);
        c.addMailInFolder(static_id, 0);
     //   Trebuie scos de la sectiunea asta acum
    }
    
}

void Interface::on_trashBtn_clicked()
{
    // Sa fie bagat in sectiunea lui
    if (active_layout != -2) {
        mailbox->setSection(static_id, 1);
        Client& c = Client::getInstance();
        c.addMailInFolder(static_id, 1);
    }
}


//nou
void Interface::on_settings_clicked()
{
    SettingsWindow* settingswindow = new SettingsWindow;
    settingswindow->show();
}


void Interface::on_addFolder_clicked()
{
    ui->createFolderWindow->show();
}


void Interface::on_addBtn_clicked()
{
    int folderId;
    std::string sectionName;

    bool same_folder = false;
    ui->createFolderWindow->hide();

    for (QToolButton* folder : folderList)
    {
        if (folder->text() == ui->editName->text())
        {
            same_folder = true;

        }
    }
    if (same_folder == false) {

        sectionName = ui->editName->text().toStdString();
        ui->editName->clear();

        
        Client& c = Client::getInstance();
        c.addFolder(sectionName);

        while (c.Incoming().empty())
        {
            if (!c.IsConnected())
            {
                QMessageBox::information(this, "Server down! Client disconnected!", "Ok");
                break;
            }
        }
        if (!c.Incoming().empty())
        {
            auto msg = c.Incoming().pop_front().msg;
            if (msg.header.id == app::MessageType::Folder)
            {

                msg >> folderId;

                mailbox->addSection(folderId, sectionName);

            }


            QToolButton* folder = new QToolButton;
            QIcon icon(":folder_yellow.png");
            folder->setFixedSize(290, 35);
            folder->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
            folder->setText(QString::fromStdString(sectionName));
            folder->setIcon(icon);
            folder->setStyleSheet("QToolButton {   background-color: #40403e; border-radius: 5px; color: #fff; } QToolButton:hover { background-color: #4f4f4d} QToolButton:pressed {background-color: #373778;} ");
            connect(folder, &QToolButton::clicked, this, [=]() {openFolder(folderId);

            /*        ui->pushButton_4->setChecked(false);
                    ui->pushButton_2->setChecked(false);
                    ui->pushButton_3->setChecked(false);
                    ui->pushButton->setChecked(false);

                    this->on_pushButton_clicked(1);
                    this->on_pushButton_2_clicked(1);
                    this->on_pushButton_3_clicked(1);

                    this->on_pushButton_4_clicked(1);*/

                });
            folderLayout->addWidget(folder);
            folderList.append(folder); //aici adauga
            
        }
    }
}


void Interface::on_exitBtn_2_clicked()
{
    ui->createFolderWindow->hide();
    ui->editName->clear();
}

void Interface::on_dropDown_currentTextChanged(const QString& arg1)
{
    //
    for (QToolButton* folder : folderList)
    {
        if (folder->text() == arg1)
        {
            std::string t = arg1.toStdString();
            if (arg1.toStdString() == "not in a folder" && active_layout != -2)
            {
                Client& c = Client::getInstance();
                mailbox->setSection(static_id, 0);
                c.addMailInFolder(static_id, 0);
                break;
            }
            else if (folder->text() == arg1 && active_layout != -2)
            {
            Client& c = Client::getInstance();
            int id_folder = mailbox->getSectionIdByName(folder->text().toStdString());
            mailbox->setSection(static_id, id_folder);

            c.addMailInFolder(static_id, id_folder);

            }

        }
    }
    
}



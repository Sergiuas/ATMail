#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <QtSql>
#include <QSql>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <iostream>
#include "mainwindow.h"
#include "registerwindow.h"

using namespace std;

class dbconnection
{

public:
    dbconnection();
    QSqlDatabase getDatabase();
    void connectToApp(QString username, QString password, MainWindow* mw);
    void registerToApp(QString firstname, QString lastname, QString email, QString password, RegisterWindow* rw);

private:
    QSqlDatabase database;
};

#endif // DBCONNECTION_H

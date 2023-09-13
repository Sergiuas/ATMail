#pragma once
#include <QThread>
#include <qthread.h>
#include <app_net.h>

//CLASA AR TREBUI MUTATA in appcommon

class UpdateThread : public QThread {
    Q_OBJECT

public:
    UpdateThread(QObject* parent = nullptr) : QThread(parent), num(0) {}

signals:
    void refreshPage();

protected:
    void run() override {
        while (true) {
            QThread::msleep(1000);
            num++;

            if (num == 5) {
                emit refreshPage();
                num = 0; // reset num
            }
        }
    }

private:
    int num;
};
#ifndef COMPOSEWINDOW_H
#define COMPOSEWINDOW_H

#include <QDockWidget>

namespace Ui {
class ComposeWindow;
}

class ComposeWindow : public QDockWidget
{
    Q_OBJECT

public:
    explicit ComposeWindow(QWidget *parent = nullptr);
    ~ComposeWindow();

private:
    Ui::ComposeWindow *ui;
};

#endif // COMPOSEWINDOW_H

#ifndef MAILBUTTON_H
#define MAILBUTTON_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>

namespace Ui {
class MailButton;
}

class MailButton : public QWidget
{
    Q_OBJECT

public:
    explicit MailButton(QWidget *parent = nullptr);
    MailButton(const QString &name, const QString &subject, const QIcon &icon, QWidget *parent = nullptr)
           : QWidget(parent)
       {
           // Create the name and subject labels
           QLabel *nameLabel = new QLabel(name, this);
           QLabel *subjectLabel = new QLabel(subject, this);

           // Create the icon label and set the icon
           QLabel *iconLabel = new QLabel(this);
           iconLabel->setPixmap(icon.pixmap(32, 32)); // adjust size as desired

           // Create a horizontal layout for the name, subject and icon labels
           QHBoxLayout *layout = new QHBoxLayout(this);
           layout->addWidget(iconLabel);
           layout->addWidget(nameLabel);
           layout->addWidget(subjectLabel);
           layout->setSpacing(10);
           layout->setContentsMargins(10, 10, 10, 10); // add some padding
       }

    ~MailButton();

private:
    Ui::MailButton *ui;
};

#endif // MAILBUTTON_H

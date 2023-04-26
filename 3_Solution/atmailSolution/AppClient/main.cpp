#include "mainwindow.h"
#include "Client.h"

#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	Client& c = Client::getInstance();
	
	w.show();

	return a.exec();

}

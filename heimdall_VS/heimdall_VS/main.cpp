#include "heimdall_VS.h"
#include <QtWidgets/QApplication>



int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	heimdall_VS w;
	w.show();
	return a.exec();
}

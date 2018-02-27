#include "heimdall_VS.h"
#include <QtWidgets/QApplication>

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	heimdall_VS w;
	w.show();

	return a.exec();
}

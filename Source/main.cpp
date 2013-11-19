#include <QApplication>
#include <iostream>
//#include <time.h>

#include "mainWindow.h"

int main(int argc, char *argv[])
{
	ilInit();
	srand ( time(NULL) );

	QApplication app(argc, argv);
	if (!QGLFormat::hasOpenGL()) {
		std::cerr << "This system has no OpenGL support" << std::endl;
		return 1;
	}
	mainWindow win;
	win.show();
	return app.exec();
}


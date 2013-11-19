#include "mainWindow.h"
mainWindow::mainWindow(QMainWindow *parent):QMainWindow(parent) {
	
	setupUi(this);
	wid = new glChain;
	glContainer->addWidget( wid );
	
	connect(addChainPoint,SIGNAL(pressed()),
	       wid, SLOT(addChainPoint() ) );
	
	connect(removeChainPoint, SIGNAL(pressed()),
	      wid,SLOT(removeChainPoint() ));
	
	connect(radius, SIGNAL(sliderMoved (int)),
	      wid, SLOT(setRadius(int) ));
	
	connect(equib, SIGNAL(sliderMoved (int)),
	      wid, SLOT(setEquilibrium(int)) );

	connect(spring, SIGNAL(sliderMoved(int)),
	      wid, SLOT(setSpringConst(int)));

	connect(actionAbout, SIGNAL(triggered()), this, SLOT(about()));

	connect(actionQuit, SIGNAL(triggered()), this, SLOT(close()));
}

void mainWindow::about() {
	QMessageBox::about(this, tr("About glChain"),
				 tr("<h2>glChain Test</h2>"
				   "<p>Just me Playing around with QT and openGL</p>"));
}

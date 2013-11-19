#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qmessagebox.h>
#include "../.tmp/UISrc/ui_mainWindow.h"
#include "glChain.h"

class mainWindow : public QMainWindow, public Ui::MainWindow {
	Q_OBJECT
	
	public:
		mainWindow(QMainWindow *parent = 0);
	private slots:
		void about();
	private:
		glChain* wid;
};

#endif


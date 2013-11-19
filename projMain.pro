
TEMPLATE = app
TARGET = 
DESTDIR = ../projMain
DEPENDPATH += . 
INCLUDEPATH += . 
LIBS += -lIL
OBJECTS_DIR += .tmp/objs
MOC_DIR += .tmp/moc
FORMS +=   Source/mainWindow.ui
UI_HEADERS_DIR += .tmp/UISrc
UI_SOURCES_DIR += .tmp/UISrc

HEADERS += Source/glChain.h Source/image.h Source/mathUtils.h Source/mainWindow.h
SOURCES += Source/glChain.cpp \
           Source/image.cpp \
           Source/main.cpp \
           Source/mathUtils.cpp \
           Source/mainWindow.cpp
	   
QT += opengl
CONFIG += opengl
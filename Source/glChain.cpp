#include <QtGui>
#include <QtOpenGL>
#include <iostream>
#include "glChain.h"

GLuint circle;
GLuint cirTex;

void genDisplayList() {
	circle=glGenLists(1);
	glNewList(circle, GL_COMPILE);

	glBegin(GL_QUADS);
		glTexCoord2f(0,0);glVertex2i(0,0); 
        	glTexCoord2f(1,0);glVertex2i(1,0);
        	glTexCoord2f(1,1);glVertex2i(1,1);
        	glTexCoord2f(0,1);glVertex2d(0,1);
	glEnd();
	glEndList();
	image tmp;
	cirTex = tmp.load("Images/circle.png");
}

glChain::glChain(QWidget *parent):QGLWidget(parent)  {
	setFormat(QGLFormat(QGL::DoubleBuffer ));
	setMouseTracking(true);
	
	myChain.resize(4);
	myChain[0].pos = math::vec3f(150,150,0);
	myChain[0].colour = math::vec3f(math::randFloat(0,1),math::randFloat(0,1),math::randFloat(0,1));
	
	for(int i=1; i<myChain.size(); i++) {
		myChain[i].pos= math::vec3f(math::randInt(0,300), math::randInt(0,300), 0);
		myChain[i].vel= math::vec3f(0,0,0);
		myChain[i].acl = math::vec3f(0,0,0);
		myChain[i].colour = math::vec3f(math::randFloat(0,1),math::randFloat(0,1),math::randFloat(0,1));
	}
	
	chainPointSize = 16;
	equilibriumSize = 16;
	springConst = 1;
	
	timer = new QTimer( this );
	connect(timer, SIGNAL(timeout()), this,SLOT(onTimeOut()));
	timer->start(16);
}

void glChain::initializeGL() {
	glClearColor(0,0,0,0);
	glShadeModel(GL_FLAT);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	genDisplayList();
}

void glChain::resizeGL(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	GLfloat x = GLfloat(width) / height;
	glOrtho (0, width, 0, height, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}


void chainPoint::draw(int size) {
	glBindTexture(GL_TEXTURE_2D,cirTex);
	glTranslated(pos[0], pos[1],0);
	glScalef(-size,size,1);
	glColor3f(colour[0],colour[1],colour[2]);
	glCallList(circle);
}

void glChain::paintGL() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	draw();
}

void glChain::mouseMoveEvent(QMouseEvent *event)
{
	myChain[0].pos[0] = event->x();
	myChain[0].pos[1] = height() - event->y();
	myChain[0].pos[2] = 0;
}

void glChain::mousePressEvent(QMouseEvent *event) {
	if (event->buttons() & Qt::LeftButton) {
		for(int i=1;i<myChain.size();i++) { 
			myChain[i].pos= math::vec3f(math::randInt(0,width()), math::randInt(0,height()), 0);
		}
	}
	
}
void glChain::draw() {
	for(int i=myChain.size()-1;i >= 0; i--) {
		glPushMatrix();
		glLoadIdentity();
		glTranslated(chainPointSize/2, -chainPointSize/2, 0);
		myChain[i].draw(chainPointSize);
		glPopMatrix();
	}
}

void glChain::onTimeOut() {
	for(int i=1; i<myChain.size(); i++) {
		float dist = math::distance(myChain[i-1].pos,myChain[i].pos) - equilibriumSize;
		float force = springConst*dist;
		float ang = 180 - math::getAngle(myChain[i-1].pos,myChain[i].pos);
		myChain[i].acl[0] = force*cos(ang/math::DEG_TO_RAD);
		myChain[i].acl[1] = force*sin(ang/math::DEG_TO_RAD);

		myChain[i].vel = myChain[i].acl;
		myChain[i].pos += myChain[i].vel;
	}
	updateGL();
}

void glChain::addChainPoint() {
	chainPoint tmp;
	tmp.pos = math::vec3f(math::randInt(0,width()), math::randInt(0,height()),0);
	tmp.colour = math::vec3f(math::randFloat(0,1), math::randFloat(0,1), math::randFloat(0,1) );
	myChain.push_back(tmp);
}

void glChain::removeChainPoint() {
	myChain.pop_back();
}

void glChain::setEquilibrium(int equib) {
	equilibriumSize = equib;
}
void glChain::setRadius(int rad) {
	chainPointSize = rad;

}
void glChain::setSpringConst(int  k) {
	springConst = (float)k/50;
}

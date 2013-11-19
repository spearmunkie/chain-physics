#ifndef GLCHAIN_H 
#define GLCHAIN_H

#include <QGLWidget>
#include "mathUtils.h"
#include <vector>
#include "image.h"
//#include <GL/gl.h>

class chainPoint {
	public:
	    math::vec3f vel;
	    math::vec3f pos;
	    math::vec3f acl;
	    math::vec3f colour;
	    chainPoint() {
	    	vel = math::vec3f(0,0,0);
		pos = vel;
		acl = vel;
		colour = vel;
	    }

	   void draw(int size);
};

class glChain: public QGLWidget
{
    Q_OBJECT

	public:
	    glChain(QWidget *parent = 0);
	public slots:
	    void addChainPoint();
	    void removeChainPoint();
	    void setEquilibrium(int equib);
	    void setRadius(int rad);
	    void setSpringConst(int  k);
	protected:
	    void initializeGL();
	    void resizeGL(int width, int height);
	    void paintGL();
	    void mouseMoveEvent(QMouseEvent *event);
	    void mousePressEvent(QMouseEvent *event);
	protected slots:
	     void onTimeOut();
	private:
	    int equilibriumSize;
	    float springConst;
	    int chainPointSize;
	    void draw();
	    std::vector<chainPoint> myChain;
	    QTimer *timer;
};

#endif

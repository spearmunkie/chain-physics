#ifndef IMAGE_H
#define IMAGE_H

#include <GL/gl.h>
#include <IL/il.h>
class image {

	public:
		GLuint load(char * file);
	private:
		ILuint texid;
		GLuint glimage;
};

#endif

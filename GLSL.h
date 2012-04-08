/*
 * GLSL.h
 *
 *  Created on: Apr 8, 2012
 *      Author: pyridoxus
 */

#ifndef GLSL_H_
#define GLSL_H_

#include <iostream>
#include <fstream>
using namespace std;

#include "GL/glew.h"
#include "GL/glut.h"

GLuint CreateProgram( string, string );
GLuint CreateShader( GLenum, string );
void CheckGlErrors( const char * );
int LinkProgram( GLuint );

#endif /* GLSL_H_ */

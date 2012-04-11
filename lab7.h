/*
 * lab7.h
 *
 *  Created on: Apr 8, 2012
 *      Author: pyridoxus
 */

#ifndef LAB7_H_
#define LAB7_H_

#include "GLSL.h"

void Menu();
void myDraw();
void keyboard( unsigned char, int, int );
void myInit(void);

GLuint shaderProgram1;                          // shader program handle
float param[4] = { 1.0, 0.0, 0.0, 1.0 };        // parameter to pass to shader
GLint paramLocation;                            // parameter location

#endif /* LAB7_H_ */

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
void setShaderParameters(void);
void myDraw();
void keyboard( unsigned char, int, int );
void specialKeyFunc( int key, int x, int y );
void myInit(void);

GLuint shaderProgram1;                          // shader program handle
float param[4] = { 1.0, 0.0, 0.0, 1.0 };        // parameter to pass to shader
GLint paramLocation[6];                            // parameter location

GLfloat ctrlAmbient;					// ambient control
GLfloat ctrlSpecular;					// specular control
GLfloat ctrlDiffuse;					// diffuse control
GLfloat ctrlShiny;						// shiny control
GLfloat ctrlSpecularColor[] = { 1.0, 1.0, 1.0, 1.0 };
float lightPos[4] = {0.0, 1.0, 3.0, 1.0};	// Light position
GLfloat lightDiffuse[] = { 1.0, 1.0, 1.0, 1.0 };	// Sphere representing light
GLfloat lightAmbient[] = { 5.0, 5.0, 5.0, 1.0 };	// Sphere representing light
GLfloat lightSpecular[] = { 0.0, 0.0, 0.0, 0.0 };	// Sphere representing light
#endif /* LAB7_H_ */

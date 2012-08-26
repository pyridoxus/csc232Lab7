//This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.

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

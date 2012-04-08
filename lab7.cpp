/*
 * lab7.cpp
 *
 *  Created on: Apr 8, 2012
 *      Author: pyridoxus
 */
#include "lab7.h"

int main( int argc, char *argv[] )
{
  // Print menu
  Menu();

  // Initialize window system
  glutInit( &argc, argv );
  glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
  glutInitWindowSize( 400, 300 );
  glutCreateWindow( "GLSL example 3" );

  // Initialize graphics
  glClearColor( 0.0, 0.0, 0.0, 0.0 );
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  glOrtho( -1.0, 1.0, -1.0, 1.0, -1.0, 1.0 );

  // Resolves which OpenGL extensions are supported by hardware
  if( glewInit() != GLEW_OK )    {
    cerr << "Error reported by glewInit" << endl;
    exit(1);
  }

  // Create shader program
  shaderProgram1 = CreateProgram( "color.vert", "color.frag" );

  // Use shader program
  glUseProgram( shaderProgram1 );

  // Address location of shader uniform variable named “Color”
  paramLocation = glGetUniformLocation( shaderProgram1, "Color" );
  if( paramLocation < 0 )    {
    cerr << "Address location not found" << endl;
    exit(1);
  }

  // Set information for shader variable
  glUniform4fv( paramLocation, 1, param );

  // Callbacks
  glutDisplayFunc( myDraw );
  glutKeyboardFunc( keyboard );

  // Event loop
  glutMainLoop();
  return 0;
}

void myDraw()
{
  // Clear the screen
  glClear( GL_COLOR_BUFFER_BIT );

  // Draw
  glBegin( GL_POLYGON );
  glVertex3f( -0.5, -0.5, 0.0 );
  glVertex3f(  0.5, -0.5, 0.0 );
  glVertex3f(  0.5,  0.5, 0.0 );
  glVertex3f( -0.5,  0.5, 0.0 );
  glEnd();

  // Execute draw commands
  glFlush();
}

// Keyboard callback
void keyboard( unsigned char key, int x, int y )
{
  // Process keys
  switch (key)
    {
    case 'q':        // exit
      exit(1);
      break;
    case '+':        // increase red color
      param[0] = param[0]+0.1 > 1.0 ? 1.0 : param[0]+0.1;
      glUniform4fv( paramLocation, 1, param );                // set shader variable
      break;
    case '-':        // decrease red color
      param[0] = param[0]-0.1 < 0.0 ? 0.0 : param[0]-0.1;
      glUniform4fv( paramLocation, 1, param );                // set shader variable
      break;
    }

  // Redraw the scene
  glutPostRedisplay();
}

// Menu
void Menu()
{
  // Print menu to screen here
  cout << "Keyboard controls" << endl;
  cout << "=================" << endl;
  cout << "+: increase red" << endl;
  cout << "-: decrease red" << endl;
  cout << "q: exit" << endl;
}





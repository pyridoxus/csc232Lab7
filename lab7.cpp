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
  glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH );
  glutInitWindowSize( 520, 390 );
//  glutInitWindowSize( 640, 640 );
  glutCreateWindow( "Craig McCulloch's CSC232 Lab 7" );

  // Initialize graphics
  myInit();
  // Resolves which OpenGL extensions are supported by hardware
  if( glewInit() != GLEW_OK )    {
    cerr << "Error reported by glewInit" << endl;
    exit(1);
  }

  // Create shader program
  shaderProgram1 = CreateProgram( "ADS_perFragment.vert",
  																"ADS_perFragment.frag" );
  setShaderParameters();
//  shaderProgram1 = CreateProgram( "color.vert",
//  																"color.frag" );
//
//  glUseProgram( shaderProgram1 );
//  // Address location of shader uniform variable named “Ambient”
//  paramLocation[0] = glGetUniformLocation( shaderProgram1, "Color" );
//  if( paramLocation[0] < 0 )    {
//    cerr << "Address location not found" << endl;
//    exit(1);
//  }
//
//  // Set information for shader variable
//  glUniform4fv( paramLocation[0], 4, ctrlSpecularColor );

  // Callbacks
  glutDisplayFunc( myDraw );
  glutKeyboardFunc( keyboard );
	glutSpecialFunc( specialKeyFunc );

  // Event loop
  glutMainLoop();
  return 0;
}

void setShaderParameters(void)
{
	// Need to make sure we are setting variables in correct shader program
  glUseProgram( shaderProgram1 );
  // Address location of shader uniform variable named “Ambient”
  paramLocation[0] = glGetUniformLocation( shaderProgram1, "Ka" );
  if( paramLocation[0] < 0 )    {
    cerr << "Address location not found" << endl;
    exit(1);
  }
  // Set information for shader variable
  glUniform1f( paramLocation[0], ctrlAmbient );

  // Address location of shader uniform variable named “Specular”
  paramLocation[1] = glGetUniformLocation( shaderProgram1, "Ks" );
  if( paramLocation[1] < 0 )    {
    cerr << "Address location not found" << endl;
    exit(1);
  }
  // Set information for shader variable
  glUniform1f( paramLocation[1], ctrlSpecular );

  // Address location of shader uniform variable named “Diffuse”
  paramLocation[2] = glGetUniformLocation( shaderProgram1, "Kd" );
  if( paramLocation[2] < 0 )    {
    cerr << "Address location not found" << endl;
    exit(1);
  }
  // Set information for shader variable
  glUniform1f( paramLocation[2], ctrlDiffuse );

  // Address location of shader uniform variable named “roughness”
  paramLocation[3] = glGetUniformLocation( shaderProgram1, "roughness" );
  if( paramLocation[3] < 0 )    {
    cerr << "Address location not found" << endl;
    exit(1);
  }
  // Set information for shader variable
  glUniform1f( paramLocation[3], ctrlShiny );

  // Address location of shader uniform variable named “specularColor”
  paramLocation[4] = glGetUniformLocation( shaderProgram1, "specularColor" );
  if( paramLocation[4] < 0 )    {
    cerr << "Address location not found" << endl;
    exit(1);
  }
  // Set information for shader variable
  glUniform4fv( paramLocation[4], 4, ctrlSpecularColor );

  // Address location of shader uniform variable named “specularColor”
  paramLocation[5] = glGetUniformLocation( shaderProgram1, "lightPos" );
  if( paramLocation[5] < 0 )    {
    cerr << "Address location not found" << endl;
    exit(1);
  }
  // Set information for shader variable
  glUniform4fv( paramLocation[5], 4, lightPos );
	return;
}

void myInit()
{
	ctrlAmbient = 0.1;
	ctrlDiffuse = 0.5;
	ctrlSpecular = 0.5;
	ctrlShiny = 20.0;
	ctrlSpecularColor[0] = 1.0;
	ctrlSpecularColor[1] = 1.0;
	ctrlSpecularColor[2] = 1.0;
	ctrlSpecularColor[3] = 1.0;

	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
//  glOrtho( -4.0, 4.0, -4.0, 4.0, -4.0, 4.0 );
//	glRotatef(180.0, 0.0, 1.0, 0.0);
//	gluPerspective( 30.0, 1.0, 0.01, 10000.0 );
  gluPerspective( 20.0, 1.33, 0.01, 10000.0 );
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef( 0, 0, -7 );
	glClearColor( 0.0, 0.0, 0.0, 0.0 );
	glEnable( GL_DEPTH_TEST );
  glColor3f(1.0, 1.0, 1.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

   // Select shading model
	glShadeModel(GL_SMOOTH);
	// Define light source
	GLfloat light_specular0[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_diffuse0[] = { 1.0, 1.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse0);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular0);
  glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
  glLightModeli( GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR );

	// Enable lighting model
	glEnable(GL_LIGHTING);

	// Enable light 0
	glEnable(GL_LIGHT0);

}

void myDraw()
{
  // Clear the screen
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

  // Draw
//  glBegin( GL_POLYGON );
//  glVertex3f( -0.5, -0.5, 0.0 );
//  glVertex3f(  0.5, -0.5, 0.0 );
//  glVertex3f(  0.5,  0.5, 0.0 );
//  glVertex3f( -0.5,  0.5, 0.0 );
//  glEnd();
	GLfloat diffuse[] = { ctrlDiffuse, ctrlDiffuse, ctrlDiffuse, 1.0 };
	GLfloat specular[] = { 	ctrlSpecular * ctrlSpecularColor[0],
													ctrlSpecular * ctrlSpecularColor[1],
													ctrlSpecular * ctrlSpecularColor[2], 1.0 };
	GLfloat shininess[] = { ctrlShiny, 0.0, 0.0, 0.0 };
	GLfloat ambient[] = { ctrlAmbient, ctrlAmbient, ctrlAmbient, 0.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
//  glLightfv(GL_LIGHT0, GL_DIFFUSE, ctrlSpecularColor);

  // Use No shader program
  glUseProgram( 0 );

  // Sphere representing the light
  glPushMatrix();
  glDisable(GL_LIGHTING);
  glTranslatef( lightPos[0], lightPos[1], lightPos[2]);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, lightDiffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, lightSpecular);
  glLightModelfv( GL_LIGHT_MODEL_AMBIENT, lightAmbient );
  glutSolidSphere( 0.25, 10, 10 );
  glEnable(GL_LIGHTING);
  glPopMatrix();

  glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
  glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);

  glPushMatrix();
  glTranslatef( 0.75, 0.0, 0.0 );
  glutSolidTeapot( 0.5 );
  glPopMatrix();

  glUseProgram( shaderProgram1 );
  glUniform1f( paramLocation[0], ctrlAmbient );
  glUniform1f( paramLocation[1], ctrlSpecular );
  glUniform1f( paramLocation[2], ctrlDiffuse );
  glUniform1f( paramLocation[3], ctrlShiny );
  glUniform4fv( paramLocation[4], 1, ctrlSpecularColor );
  glPushMatrix();
  glTranslatef( -0.75, 0.0, 0.0 );
  glutSolidTeapot( 0.5 );
  glPopMatrix();

// Execute draw commands
  glutSwapBuffers();
//  glFlush();
}

// Keyboard callback
void keyboard( unsigned char key, int x, int y )
{
  glUseProgram( shaderProgram1 );
  // Process keys
  switch (key)
    {
    case 'A':
    	if(ctrlAmbient < 1.0)
    	{
    		ctrlAmbient += 0.02;
    	  glUniform1f( paramLocation[0], ctrlAmbient );
    	}
    break;
    case 'a':
    	if(ctrlAmbient > 0.0)
    	{
    		ctrlAmbient -= 0.02;
    	  glUniform1f( paramLocation[0], ctrlAmbient );
    	}
    break;
    case 'D':
    	if(ctrlDiffuse < 1.0)
    	{
    		ctrlDiffuse += 0.02;
    	  glUniform1f( paramLocation[2], ctrlDiffuse );
    	}
   	break;
    case 'd':
    	if(ctrlDiffuse > 0.0)
    	{
    		ctrlDiffuse -= 0.02;
    	  glUniform1f( paramLocation[2], ctrlDiffuse );
    	}
   	break;
    case 'S':
    	if(ctrlSpecular < 1.0)
    	{
    		ctrlSpecular += 0.02;
    	  glUniform1f( paramLocation[1], ctrlSpecular );
    	}
   	break;
    case 's':
    	if(ctrlSpecular > 0.0)
    	{
    		ctrlSpecular -= 0.02;
    	  glUniform1f( paramLocation[1], ctrlSpecular );
    	}
   	break;
    case 'N':
    	if(ctrlShiny < 100.0)
    	{
    		ctrlShiny += 1.0;
    	  glUniform1f( paramLocation[3], ctrlShiny );
    	}
   	break;
    case 'n':
    	if(ctrlShiny > 0.0)
    	{
    		ctrlShiny -= 1.0;
    	  glUniform1f( paramLocation[3], ctrlShiny );
    	}
   	break;
    case 'R':
    	if(ctrlSpecularColor[0] < 1.0)
    	{
    		ctrlSpecularColor[0] += 0.02;
    		glUniform4fv( paramLocation[4], 1, ctrlSpecularColor );
    	}
    break;
    case 'r':
    	if(ctrlSpecularColor[0] > 0.0)
    	{
    		ctrlSpecularColor[0] -= 0.02;
    		glUniform4fv( paramLocation[4], 1, ctrlSpecularColor );
    	}
   	break;
    case 'G':
    	if(ctrlSpecularColor[1] < 1.0)
    	{
    		ctrlSpecularColor[1] += 0.02;
    		glUniform4fv( paramLocation[4], 1, ctrlSpecularColor );
    	}
   	break;
    case 'g':
    	if(ctrlSpecularColor[1] > 0.0)
    	{
    		ctrlSpecularColor[1] -= 0.02;
    		glUniform4fv( paramLocation[4], 1, ctrlSpecularColor );
    	}
   	break;
    case 'B':
    	if(ctrlSpecularColor[2] < 1.0)
    	{
    		ctrlSpecularColor[2] += 0.02;
    		glUniform4fv( paramLocation[4], 1, ctrlSpecularColor );
    	}
   	break;
    case 'b':
    	if(ctrlSpecularColor[2] > 0.0)
    	{
    		ctrlSpecularColor[2] -= 0.02;
    		glUniform4fv( paramLocation[4], 1, ctrlSpecularColor );
    	}
   	break;
    case 'q':        // exit
      exit(1);
    break;
//    case '+':        // increase red color
//      param[0] = param[0]+0.1 > 1.0 ? 1.0 : param[0]+0.1;
//      glUniform4fv( paramLocation, 1, param );                // set shader variable
//    break;
//    case '-':        // decrease red color
//      param[0] = param[0]-0.1 < 0.0 ? 0.0 : param[0]-0.1;
//      glUniform4fv( paramLocation, 1, param );                // set shader variable
//    break;
    }

  // Redraw the scene
  glutPostRedisplay();
}

void specialKeyFunc( int key, int x, int y )
{
	switch(key)
	{
		case GLUT_KEY_LEFT:			// translate along -x axis
			lightPos[0] -= 0.1;
		break;
		case GLUT_KEY_RIGHT:		// translate along +x axis
			lightPos[0] += 0.1;
		break;
		case GLUT_KEY_DOWN:			// translate along -y axis
			lightPos[1] -= 0.1;
		break;
		case GLUT_KEY_UP:			  // translate along +y axis
			lightPos[1] += 0.1;
		break;
		case GLUT_KEY_PAGE_UP:  // translate along -z axis
			lightPos[2] -= 0.1;
		break;
		case GLUT_KEY_PAGE_DOWN:// translate along +z axis
			lightPos[2] += 0.1;
		break;
	}
  glUseProgram( shaderProgram1 );
  glUniform4fv( paramLocation[5], 4, lightPos );
	// Redraw the scene
  glutPostRedisplay();
	return;
}

// Menu
void Menu()
{
  // Print menu to screen here
  cout << "Keyboard controls" << endl;
  cout << "=================" << endl;
  cout << "A/a increase/decrease ambient level, Ka" << endl;
  cout << "D/d increase/decrease diffuse level, Kd" << endl;
  cout << "S/s increase/decrease specular level, Ks" << endl;
  cout << "N/n increase/decrease shininess" << endl;
  cout << "R/r increase/decrease red specular color component" << endl;
  cout << "G/g increase/decrease green specular color component" << endl;
  cout << "B/b increase/decrease blue specular color component" << endl;
  cout << "Left/Right Arrow  Modify light position in -/+ x direction" << endl;
  cout << "Up/Down Arrow     Modify light position in -/+ y direction" << endl;
  cout << "Page Up/Down      Modify light position in -/+ z direction" << endl;

  cout << "q: exit" << endl;
}





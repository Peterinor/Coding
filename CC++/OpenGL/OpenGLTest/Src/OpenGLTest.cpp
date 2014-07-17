//============================================================================
// Name        : OpenGLTest.cpp
// Author      : ty
// Version     :
// Copyright   : copyright reserved of ty
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include<GL/gl.h>

#include<GL/glut.h>

void Initialize(void);
void DrawScene(void);

int main(int argc, char* argv[])
{
	glutInit(&argc, argv); // Initialize GLUT
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode
	glutInitWindowPosition(50, 100); // Set top-left display window position
	glutInitWindowSize(400, 300); // set display window width and height
	glutCreateWindow("An Example OpenGL Program"); // Create display window

	Initialize(); // Execute initialization procedure
	glutDisplayFunc(DrawScene); // Send graphics to display window

	glutMainLoop(); // Display everything and wait

	return 0;
}

/*
 */
void Initialize(void)
{
	//glClearColor(1.0, 1.0, 1.0, 0.0);                // Set Display-window color to white
	glMatrixMode( GL_PROJECTION); // Set projection parameters
	glLoadIdentity();
	gluOrtho2D(0.0, 200, 0.0, 150); //
} // Initialize

/*
 */
void DrawScene(void)
{
	glClear( GL_COLOR_BUFFER_BIT); // Clear display window

//	glColor3f(1.0, 0.0, 0.0f); // set line segment geometry color to red
//	glBegin( GL_LINES);
//	glVertex2i(0, 0);
//	glVertex2i(190, 140);
//	glEnd();

	glutSolidSphere(30,10,10);

	glFlush(); // Process all OpenGL routines as quickly possible
} // DrawScene

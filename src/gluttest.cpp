

#include "gluttest.h"

/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer

   glFlush();  // Render now
}


/* Main function: GLUT runs as a console application starting at main()  */
int initWindow(int h, int v) {
   int argc = 1;
   char s = 0;
   char *argv = &s;
   glutInit(&argc, &argv);                 // Initialize GLUT
   glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
   glutInitWindowSize(h, v);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutDisplayFunc(display); // Register display callback handler for window re-paint
              // Enter the infinitely event-processing loop
   return 0;
}

void finish(){
	glutMainLoop();
}

#include <windows.h>
#include <GL\glut.h>

void myInit (void)

{
   glClearColor(0.0,0.0,0.0,0.0);
   glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
     gluOrtho2D(0.0, 500.0, 0.0, 400.0);
}
void myDisplay(void)
{
     glClear(GL_COLOR_BUFFER_BIT); // clears the screen
//Left Rotate Rectangle
 glColor3f(0.0f,0.0f,1.0f);
 glBegin(GL_QUADS);
//bottom
          glVertex2i (50, 50);
          glVertex2i (100, 50);
          //top
          glVertex2i (50, 0);
          glVertex2i (100, 50);
        //left
          glVertex2i (0, 50);
          glVertex2i (50, 0);
        //right
          glVertex2i (50, 100);
          glVertex2i (100, 50);

          //glVertex2i (10, -50);
    glEnd();
    glColor3f(0.5f,0.5f,0.5f);
     glPointSize(4.0);
     glBegin(GL_POLYGON);
//bottom
          glVertex2i (100, 0);
          glVertex2i (150, 20);
          //top
          glVertex2i (100, 100);
          glVertex2i (100, 100);
        //left
          glVertex2i (100, 100);
          glVertex2i (100, 100);
        //right
          glVertex2i (320, 100);
          glVertex2i (320, 0);
          //glVertex2i (10, -50);

    glEnd();
//door
glColor3f(0.0f,0.0f,1.0f) ;
glBegin(GL_POLYGON);
//left
        glVertex2i (170,30);
        glVertex2i (170, 50);

//top
          glVertex2i (170, 50);
          glVertex2i (230, 50);

//right
          glVertex2i (230, 50);
          glVertex2i (230, 00);

 //bottom
         glVertex2i (170, 00);
          glVertex2i (230, 00);
          //glVertex2i (10, -50);
    glEnd();
    //Triangle
 	glColor3f(0.0f,1.0f,0.0f) ;
    glBegin(GL_POLYGON);
//bottom
          glVertex2i (100, 100);
          glVertex2i (320, 100);
          //top
          glVertex2i (210, 200);
          glVertex2i (320, 100);
        //left
          glVertex2i (100, 100);
          glVertex2i (100, 310);
          //glVertex2i (10, -50);
    glEnd();
    //Right Window
 glColor3f(1.0f,0.0f,0.0f) ;
glBegin(GL_POLYGON);
//bottom

          glVertex2i (170,120);
          glVertex2i (170, 120);

//top
          glVertex2i (170, 150);
          glVertex2i (250, 150);
//left
          glVertex2i (250, 120);
          glVertex2i (130, 120);
 //right
         glVertex2i (250, 120);
          glVertex2i (170, 150);
    glEnd();
     glFlush();
}
int main (int argc, char **argv)
{
     glutInit (&argc, argv);
     glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
     glutInitWindowSize (640, 480);
     glutInitWindowPosition (10, 10);
     glutCreateWindow ("House");
     glutDisplayFunc (myDisplay);
     myInit();
	 glutMainLoop();
     return 0;
}

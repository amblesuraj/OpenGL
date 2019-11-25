#include <Windows.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void drawPoints(void)
{
double x1 = 100, x2 = 500, x3 = 300, y1 = 100, y2 = 100, y3 = 398;
int midX = (x1 + x2 + x3) / 3;
int midY = (y1 + y2 + y3) / 3;

glClear(GL_COLOR_BUFFER_BIT);
glColor3ub(255, 165, 0);
glBegin(GL_LINES);
glLineWidth(2.5);
glVertex3f(x1, y1, 0);
glVertex3f(x2, y2, 0);
glBegin(GL_LINES);
glLineWidth(2.5);
glVertex3f(x3, y3, 0);
glVertex3f(x1, y1, 0);
glBegin(GL_LINES);
glLineWidth(2.5);
glVertex3f(x2, y2, 0);
glVertex3f(x3, y3, 0);
glColor3ub(0, 255, 0);
double twicePi = 2.0 * 3.142;
int x = midX, y = midY, i, radius = 95;
glBegin(GL_LINES); //BEGIN CIRCLE

for (i = 0; i <= 1000; i++) {
glVertex2f(
(x + (radius * cos(i * twicePi / 200))), (y + (radius * sin(i * twicePi / 200)))
);
}
glEnd();
glFlush();
}
void circle()
{
double x1 = 100, x2 = 500, x3 = 300, y1 = 100, y2 = 100, y3 = 398;
double midX = (x1 + x2 + x3) / 3;
double midY = (y1 + y2 + y3) / 3;
glBegin(GL_POINTS);
glVertex2d(midX, midY);
glEnd();
glFlush();

}
void Init()
{
glClearColor(0.0, 0.0, 0.0, 0);
glColor3f(1.0, 0.5, 0.0);
gluOrtho2D(0, 640, 0, 480);
}
int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowPosition(0, 0);
glutInitWindowSize(640, 480);
glutCreateWindow("Circle In Triangle");
Init();
glutDisplayFunc(drawPoints);
glutMainLoop();
return 0;
}

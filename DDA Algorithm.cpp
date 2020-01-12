#include<windows.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

int XStart,YStart,XEnd,YEnd;
void init()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
}
void display()
{
        //Find dx and dy
        int dx = XEnd - XStart;
        int dy = YEnd - YStart;


        int steps = dx;

        if(abs(dy) > abs(dx))

            steps = dy;

        //Convert to double
        double x = 1.0 * XStart;
        double y = 1.0 * YStart;

        //x and y increment
        double increment_x = 1.0 * dx /steps;
        double increment_y = 1.0 * dy /steps;

       // glClearColor(1.0,1.0,1.0,1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_POINTS);
       //     glColor3f(1.0,0.0,0.0);
            glVertex2d(x,y);
            for(int i=1;i<=steps;i++)
            {
                x+=increment_x;
                y+=increment_y;
                glVertex2d(round(x),round(y));
            }
        glEnd();
        glFlush();

}
int main(int argc,char **argv)
{
    printf("Enter x1 and y1 co-ordinates :: \n");
    scanf("%d%d",&XStart,&YStart);

    printf("Enter x2 and y2 co-ordinates :: \n");
    scanf("%d%d",&XEnd,&YEnd);

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(1,1);
    glutInitWindowSize(500,500);
    glutCreateWindow("DDA LINE ALGORITHM");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}

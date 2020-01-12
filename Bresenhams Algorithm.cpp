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
        glBegin(GL_POINTS);
       int dx = XEnd-XStart;
       int dy = YEnd-YStart;

       //For increase and decrease as per the Bresenham's formula
       int x_direction = 1;
       int y_direction = 1;

       if(dx < 0)
       {
           dx = -dx;
           x_direction = -1;
       }

       if(dy < 0)
       {
           dy = -dy;
           y_direction = -1;
       }
        int x = XStart,y = YStart;
        glVertex2d(x,y);

        //slope determining

        if(dx > dy)
        {
                int p = 2 * dy - dx;
                int twody = 2 * dy;
                int dyMinusdx = 2 * dy - 2 * dx;

                for(int i=1;i<=dx; i++)
                {
                    x+=x_direction;
                    if(p<0)
                    {
                        p+=twody;
                    }
                    else
                    {
                        p+= dyMinusdx;
                        y+= y_direction;
                    }
                    glVertex2d(x,y);

                }
        }
        else
        {
                int p = 2 * dy - dx;
                int twodx = 2 * dx;
                int dxMinusdy = 2 * dx- 2 * dy;

                for(int i=1;i<=dx; i++)
                {
                    y+=y_direction;
                    if(p<0)
                    {
                        p+=twodx;
                    }
                    else
                    {
                        p+= dxMinusdy;
                        x+= x_direction;
                    }
                    glVertex2d(x,y);

                }

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

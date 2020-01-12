#include<windows.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

int XMin = -100,YMin = -100,XMax = 100,YMax = 100;

float m = 0; //slope

int XStart,YStart,XEnd,YEnd;
float x,y;


void drawBitmap(char *c,int x,int y,int l)
{
    glRasterPos2i(x,y);
    for(int i= 0;i<l ;i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,*c);
        c++;
    }

}
void mouse(int button,int state,int x,int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(XStart == 0 && YStart == 0)
        {
            XStart = x - 300;
            YStart = 300 - y;
            XEnd = XStart;
            YEnd = YStart;
        }
        else
        {
            XEnd = x - 300;
            YEnd = 300 - y;
        }
    }
}

void init()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluOrtho2D(0,500,0,500);
    gluOrtho2D(-300,300,-300,300);
}
void display()
{

        glColor3f(1.0,1.0,1.0);
        drawBitmap("Press R to reset",-250,10,16);
        drawBitmap("Press C to Clip",-250,40,15);

        glColor3f(1.0,1.0,0.0);
        glBegin(GL_QUADS);
        glVertex2i(XMin,YMin);
        glVertex2i(XMin,YMax);
        glVertex2i(XMax,YMax);
        glVertex2i(XMax,YMin);

        glEnd();
        glColor3f(1.0,0.0,1.0);
        glLineWidth(2);
        glBegin(GL_LINES);
        glVertex2f(XStart,YStart);
        glVertex2f(XEnd,YEnd);



        glEnd();
        glFlush();
}





void check_edge(int c, float XTest ,float YTest)
{
    if((c & 8 ) > 0)  //interaction with top edge
    {
        y= YMax;
        x = XTest + (YMax - YTest) / m;
    }
    else if((c & 4 ) > 0) //interaction with bootom edge
    {
        y= YMin;
        x = XTest + (YMin - YTest) / m;
    }
    else if((c & 2) > 0) //interaction with left edge
    {
        x= XMax;
        y = YTest + m* (XMax - XTest);
    }
    else if((c & 1)> 0) //interaction with right edge
    {
        x= XMin;
        y = YTest + m* (XMin - XTest);
    }
}

int code(int x,int y)
{
    int c = 0;
    if(y > YMax)
        c = 8; //point on top 8

    if(y < YMin)
        c = 4; //point on bottom 4

    if(x > XMax)
        c = c | 2 ; //logical or with 0010

    if(x < XMin)
        c = c | 1 ; // logical or with 0001

    return c;

}


void cohen(float x1, float y1,float x2, float y2)
{
    int c1 = code(x1,y1);
    int c2 = code(x2,y2);

    m = (y2 - y1)/(x2 - x1);

    while((c1 | c2) > 0) // c1 or c2 != 0000 .  at least one of the point should lie on the outside of clipping window
    {
        if((c1 & c2) > 0)
        {
            //line is completely outside of clipping window
            XStart = 0;
            YStart = 0;
            XEnd = 0;
            YEnd = 0;
            display();
            return;
        }
        if(c1 != 0)
        {
            check_edge(c1,XStart,YStart);
            XStart = x;
            YStart = y;
            c1 = code(XStart,YStart);
        }

        if(c2 != 0)
        {
            check_edge(c2,XEnd,YEnd);
            XEnd = x;
            YEnd = y;
            c1 = code(XEnd,YEnd);
        }
    }
    display();
}


void keyBoard( unsigned char key,int x,int y)
{
    if(key == 'r')
    {
        XStart =0;
        YStart = 0;
        XEnd=0;
        YEnd=0;
    }
    if(key == 'c')
    {

        cohen(XStart,YStart,XMax,YMax);
        glFlush();
    }
}


int main(int argc,char **argv)
{
  /*  printf("Enter x1 and y1 co-ordinates :: \n");
    scanf("%d%d",&XStart,&YStart);

    printf("Enter x2 and y2 co-ordinates :: \n");
    scanf("%d%d",&XEnd,&YEnd);
*/
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(1,1);
    glutInitWindowSize(600,600);
    glutCreateWindow("Cohen Suderland Line clipping algorithm");
    glutDisplayFunc(display);

    glutMouseFunc(mouse);
    glutKeyboardFunc(keyBoard);
    init();
    glutMainLoop();
    return 0;
}

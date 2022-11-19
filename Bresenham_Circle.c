//Name- Mrunal Kashid
//Roll No-23238
//Batch-F10
//Bresenham Circle Drawing Algorithm
#include<iostream>
#include<GL/glut.h>
#include<math.h>

int xc=300,yc=300,r=70;
bool flag=1;

struct color{
GLubyte r,g,b;
};

void init()
{
glClearColor(1,1,1,0);
glClear(GL_COLOR_BUFFER_BIT);
gluOrtho2D(0,600,0,600);
glColor3f(0,0,0);
}

void plotpixel(int x,int y)
{
glPointSize(1.5);
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
glFlush();
}

void octant(int xc,int yc,int x,int y)
{
plotpixel(xc+x,yc+y);
plotpixel(xc+y,yc+x);
plotpixel(xc+y,yc-x);
plotpixel(xc+x,yc-y);
plotpixel(xc-x,yc-y);
plotpixel(xc-y,yc-x);
plotpixel(xc-y,yc+x);
plotpixel(xc-x,yc+y);
}

void circleMP(int xc,int yc,int r)
{
int d=3-2*r;
int x=0,y=r;
octant(xc,yc,x,y);
while(y>=x)
{
x++;
 if(d>0)
{
y--;
d=d+4*(x-y)-10;
}
else
d=d+4*x+6;
octant(xc,yc,x,y);
}
}

int main(int argc,char**argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(0,0);
glutInitWindowSize(500,500);
glutCreateWindow("Bresenhem circle");
init();
circleMP(xc,yc,r);
glutMainLoop();
return 0;
}






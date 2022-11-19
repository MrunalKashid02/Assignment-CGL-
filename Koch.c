#include<GL/freeglut.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#define Radian (3.14/180)
#define XMAX 1400
#define YMAX 900
void init();
void draw();
void draw_Koch(float,float,float,float,int);
void init(){
glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0,0.0,0.0,0.0);
	
	glColor3f(1.0,1.0,1.0);
	gluOrtho2D(0.0,XMAX,0.0,YMAX);


}
void draw(int n)
{


glBegin(GL_LINES);
//draw_Koch(100,100,400,100,n);
//draw_Koch(400,100,400,300,n);
//draw_Koch(400,300,100,300,n);
//draw_Koch(100,300,100,100,n);
	draw_Koch(600,100,800,400,n);
	draw_Koch(800,400,400,400,n);
	draw_Koch(400,400,600,100,n);
glEnd();
glFlush();


}
void draw_Koch(float xa,float ya,float xb, float yb,int n){
 float xc,yc,xd,yd,xmid,ymid;
 
 xc=(2*xa+xb)/3;
 yc=(2*ya+yb)/3;
 
 xd=(2*xb+xa)/3;
 yd=(2*yb+ya)/3;
 
 
 
 xmid= xc+ ((xd-xc)*cos(60*Radian)+(xd-xc)*sin(60*Radian));
 ymid= yc- ((yd-yc)*sin(60*Radian)+(xd-xc)*cos(60*Radian));
 
 
 if(n>0){
 	draw_Koch(xa,xb,xc,yc,n-1);
 	draw_Koch(xc,yc,xmid,ymid,n-1);
 	draw_Koch(xmid,ymid,xd,yd,n-1);
 	draw_Koch(xd,yd,xb,yb,n-1);
 
 }
 else{
 	glVertex2f(xa,ya);
 	glVertex2f(xc,yc);
 	
 	glVertex2f(xc,yc);
 	glVertex2f(xmid,ymid);
 	
 	glVertex2f(xmid,ymid);
 	glVertex2f(xd,yd);
 	
 	glVertex2f(xd,yd);
 	glVertex2f(xb,yb);
 
 
 }
 glFlush();





}

int main(int argc,char** argv){
int n;
printf("Enter the Iteration");
scanf("%d",&n);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowPosition(0,0);
glutInitWindowSize(XMAX,YMAX);
glutCreateWindow("KOCH CURVE");
init();
draw(n);
glutMainLoop();
return 0;



}

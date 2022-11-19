
//Name –Mrunal Kashid
//Rollno – 23238
//Batch – F-10
//Problem – Draw a line using Bresenham’s Algorithm



#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
float x1,x2,y3,y2;
int c;
void display(void)
{
	float dx,dy,i1,i2,d,m,xinc,yinc,p,x,y;
	int n;
	if(c==1){
		n=1;
	}else if(c==2){
		n=3;
	}else if(c==3){
		n=5;
	}
	m= dy/dx;
	dx=abs(x2-x1);
	dy=abs(y2-y3);
	p=2*dx-dy;
	x= x1;
	y=y3;
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	if(x2>x1){
		xinc=1;
	}else{
		xinc = -1;
	}if(y2>y3){
		yinc=1;
	}else{
		yinc = -1;
	}
	if(m>0){
		for(int k =0;k<dx;k++){
			if(p<=0){
				p=p+2*dy;
			}else{
				p =p+2*dy-2*dx;
				y+=yinc;
			}
			x+=xinc;
			if(k%n==0){
			glBegin(GL_POINTS);
			glVertex2i(x,y);
			glEnd();
		}
	}
	}else{
		x=x1;
		y=y3;
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		glEnd();
		for(int k =0;k<dy;k++){
			if(p<=0){
			p=p+2*dx;
			}else{
			p =p+2*dx-2*dy;
			x+=xinc;
		}
		y+=yinc;
		if(k%n==0){
			glBegin(GL_POINTS);
			glVertex2i(x,y);
			glEnd();
		}
	}
	}
	glFlush();
}
void init(void)
{
	glClearColor(0.7,0.7,0.7,0.7);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100,100,-100,100);
}
int main(int argc, char** argv)
{
	printf("Enter the value of x1 : ");
	scanf("%f",&x1);
	printf("Enter the value of y3 : ");
	scanf("%f",&y3);
	printf("Enter the value of x2 : ");
	scanf("%f",&x2);
	printf("Enter the value of y2 : ");
	scanf("%f",&y2);
	printf("Enter 1 for solid line \n");
	printf("Enter 2 for dashed line \n");
	printf("Enter 3 for dotted line \n");
	printf("Enter your choice: ");
	scanf("%d",&c);
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100,100);
	glutCreateWindow ("Bresenhams Line Algo");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

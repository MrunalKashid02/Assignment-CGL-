#include<GL/freeglut.h>
#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
void init(){

glClearColor(1.0,1.0,1.0,0.0);
glClear(GL_COLOR_BUFFER_BIT);
gluOrtho2D(0,500,0,500);
glMatrixMode(GL_PROJECTION);
glColor3f(0.2,0.1,0.3);


}
void DDA(float X01,float Y01,float X2,float Y2){
float dx=X2-X01;
float dy=Y2-Y01;
float step;


if(abs(dx)>abs(dy)){
 step=abs(dx);
}
else{
	step=abs(dy);
}
float Xinc=dx/(float) step;
float Yinc=dy/(float) step;



glBegin(GL_POINTS);
glColor3f(0.2,0.1,0.3);
glVertex2d(X01,Y01);

for (int i=0;i<step;i++){

X01+=Xinc;
Y01+=Yinc;

glVertex2d(X01,Y01);


}
glEnd();
glFlush();






}
void plot(){

	DDA(100, 100, 100, 300);
    DDA(100, 300, 400, 300);
    DDA(400, 300, 400, 100);
    DDA(400, 100, 300, 100);
    DDA(300, 100, 315, 75);
    DDA(315, 75, 165, 75);
    DDA(165, 75, 175, 100);
    DDA(175, 100, 100, 100);
    
    
    
    DDA(125, 125, 125, 275);
    DDA(125, 275, 375, 275);
    DDA(375, 275, 375, 125);
    DDA(375, 125, 125, 125);
    DDA(125, 125, 200, 200);
    DDA(200, 200, 250, 125);
    DDA(250, 125, 300, 250);
    DDA(300, 250, 375, 125);
    
    glFlush();


}


int main(int argv, char** argc){
glutInit(&argv,argc);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(100,100);
glutCreateWindow("Monitor");
init();
glutDisplayFunc(plot);
glutMainLoop();
return 0;



}

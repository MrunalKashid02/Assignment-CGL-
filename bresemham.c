#include<GL/glut.h>
#include<GL/freeglut.h>
#include<stdio.h>
#include<math.h>

void init(){
glClearColor(1.0,1.0,1.0,0.0);
glClear(GL_COLOR_BUFFER_BIT);
gluOrtho2D(0.0,640.0,0.0,480.0);
glBegin(GL_POINTS);
glColor3f(1.0,0.4,0.3);

glEnd();
glFlush();

}

void DDA(float X0,float Y0,float Xn,float Yn){

float dx,dy,step,Xinc,Yinc;

dx=Xn-X0;
dy=Yn-Y0;

if(abs(dx)>abs(dy)){
	step=abs(dx);

}
else{
	step=abs(dy);
}
Xinc=dx/(float) step;
Yinc=dy/(float) step;
glBegin(GL_POINTS);
glColor3f(1.0,0.4,0.3);
glVertex2d(X0,Y0);

for(int i=0;i<step;i++){
	X0+=Xinc;
	Y0+=Yinc;
	glVertex2d(X0,Y0);


}

glEnd();
glFlush();








}
void PlotPixel(void){

//DDA(200,100,100,300);//100
//DDA(400,300,100,400);
DDA(400,100,400,300);
DDA(300,100,400,300);



}


int main(int argv, char **argc){


glutInit(&argv,argc);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowPosition(0,0);
glutInitWindowSize(600,400);
glutCreateWindow("BY DDA ALGORITHM");
init();
glutDisplayFunc(PlotPixel);
glutMainLoop();

return 0;




}



#include<GL/freeglut.h>
#include<GL/gl.h>
#include<math.h>

using namespace std;
void init()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,640,480,0);
}

		
void boundary_fill(int x,int y,float *fill_color,float *bound)
{
	float color[3]={0,0,1};
	//float bound[3]={1,0,0};
	glReadPixels(x,y,1,1,GL_RGB,GL_FLOAT,color);//values are put into c
	//if color not equal to backgroung color and filling color put color
	if((color[0]!=bound[0] || color[1]!=bound[1] || color[2]!=bound[2]) && (color[0]!=fill_color[0] || color[1]!=fill_color[1] || color[2]!=fill_color[2]))
	{
		glColor3f(color[0],color[1],color[2]);
		glBegin(GL_POINTS);
		glVertex2i(x,y);//put pixel
		glEnd();
		glFlush();
		boundary_fill(x+1,y,fill_color,bound);//right pixel
		boundary_fill(x-1,y,fill_color,bound);//left pixel
		boundary_fill(x,y+1,fill_color,bound);//upper pixel
		boundary_fill(x,y-1,fill_color,bound);//lower pixel

		boundary_fill(x-1,y+1,fill_color,bound);//lower pixel
		boundary_fill(x+1,y+1,fill_color,bound);//lower pixel
		boundary_fill(x+1,y-1,fill_color,bound);//lower pixel
		boundary_fill(x-1,y-1,fill_color,bound);//lower pixel
	}
}

void renderfunction()
{
	glLineWidth(5);
	glPointSize(3);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINE_LOOP);
		glVertex2i(150,100);
		glVertex2i(300,400);
		glVertex2i(400,150);
	
	glEnd();
	glFlush();
	

}
void mousepoint(int button,int state,int x,int y ){
y=480-y;
if(button==GLUT_LEFT_BUTTON){
	if(state==GLUT_DOWN)
	{
		float bound[]={1,0,0};
		float color[]={0,0,1};
		boundary_fill(x,y,bound,color);
	}
}
}

int main(int argc,char**argv)
{
	glutInit(&argc,argv);
	glutInitWindowSize(500,500);
	glutCreateWindow("Polygon fillling");

	glutDisplayFunc(renderfunction);
	glutMouseFunc(mousepoint);
	init();
	glutMainLoop();
	return 0;
}
//render- triangle drawing
//mouse clicking- for ploting points from mouse
// boundary fill- algorithm fun
//init- colors are defined

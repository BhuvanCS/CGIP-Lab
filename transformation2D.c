#define BLACK
#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
GLfloat Triangle[3][3]={{150.0,300.0,225.0},{150.0,150.0,350.0},{1.0,1.0,1.0}};
GLfloat rotatement[3][3]={{0},{0},{0}};
GLfloat Result[3][3]={{0},{0},{0}};
GLfloat m=0;
GLfloat n=0;
float theta;
void triangle()
{
	glBegin(GL_LINE_LOOP);
	glVertex2f(Triangle[0][0],Triangle[1][0]);
	glVertex2f(Triangle[0][1],Triangle[1][1]);
	glVertex2f(Triangle[0][2],Triangle[1][2]);
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);
	triangle();
	glTranslatef(m,n,0);
	glRotatef(theta,0,0,1);
	glTranslatef(-m,-n,0);
	glColor3f(0,0,1);
	triangle();
	glFlush();
}
void myinit()
{
	glClearColor(1,1,1,1);
	glColor3f(1,0,0);
	glPointSize(1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,500,0,500);
}
int main(int argc,char **argv)
{
	int ch;
	printf("Enter choice\n 1:Rotation about origin \n 2:rotation about a fixed point\n:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:printf("Enter the rotation angle in degree:");
			scanf("%f",&theta);
			break;
		case 2:printf("Enter the fixed point:");
			scanf("%f%f",&m,&n);
			printf("Enter the rotation angle:");
			scanf("%f",&theta);
			break;
	}
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Triangle rotaion");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
	return 0;
}

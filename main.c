#include <stdio.h>
#include <stdlib.h>
#include "GL/gl.h"
#include "GL/glut.h"
#include <time.h>
#include <math.h>       /* log */
#include <stdint.h>
#define WIDTH 640
#define HEIGHT 480
//#define pi 3.1415
/*
int Light0 = 1, Light1 = 1, Light2 = 1;
int Material = 3;
float intens[1];
float ugl[1];
float napravlenie[3] = {0.5,0.5,0.5};

float eye[3] = {0.4,0.6,0.4};
float center[3] = {0.0, 0.0, 0.0};
float up[3] = {0.4, 0.6, 0.8};
float uglX=1.0, uglY=1.0;
float mat_dif[4],mat_amb[4],mat_spec[4];
int shininess = 10;
void draw(void);

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective( 45.0, (GLfloat)w/h, 1.0,100.0);
}

void Keyboard(int key, int xx, int yy) {

#define ESCAPE '\033'

	switch (key) {
		case ESCAPE : exit(0); break;
		case '1': Material=1; break;
		case '2': Material=2; break;
		case '3': Material=3; break;
		case '4': if(Light0) {Light0=0;} else {Light0=1;}  break;
		case '5': if(Light1) {Light1=0;} else {Light1=1;}  break;
		case 's': center[0]-=0.007;center[1]-=0.01;break;
		case 'w': center[0]+=0.007;center[1]+=0.01;break;
		case 'a': center[1]-=0.01;center[2]-=0.01;break;
		case 'd': break;
		//case '6': if(Light2) {Light2=0;} else {Light2=1;}  break;
	}

	//center[0] = center[0] + cos(uglX*M_PI/180);
	//center[1] = center[1] - sin(uglY*M_PI/180);
	//center[2] = center[2] + cos(uglX*M_PI/180);

    //printf("%f\n",center[1]);

	draw();
}
void draw(void) {
    glMatrixMode (GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(
	 eye[0],eye[1],eye[2],
	  center[0],center[1],center[2],
	  up[0],up[1],up[2]);

	if (Light0) {
		glEnable(GL_LIGHT0);
	} else {
		glDisable(GL_LIGHT0);
	}
	if (Light1) {
		glEnable(GL_LIGHT1);
	} else {
		glDisable(GL_LIGHT1);
	}
    if (Light2) {
		glEnable(GL_LIGHT2);
	} else {
		glDisable(GL_LIGHT2);
	}

	glPushMatrix();

    float light0_pos[] = {0.0,0.0,0.0,1.0};
    float light1_pos[] = {0.6,0.2,0.2,0.0};
    float light2_pos[] = {-0.6,0.2,0.2,1.0};

    float light_diffuse1[] = {1.0,0.0,0.0,1.0};
    float light_diffuse2[] = {0.0,1.0,0.0,1.0};

    float ambient1[] = {0.1,0.5,0.6,1.0};
    float ambient2[] = {0.0,0.0,0.0,1.0};

	glLightfv(GL_LIGHT0,GL_POSITION,light0_pos);
	glLightfv(GL_LIGHT1,GL_POSITION,light1_pos);
    glLightfv(GL_LIGHT2,GL_POSITION,light2_pos);

	glLightfv(GL_LIGHT1,GL_AMBIENT,light_diffuse1);
	glLightfv(GL_LIGHT2,GL_AMBIENT,light_diffuse2);

    glLightfv(GL_LIGHT1,GL_AMBIENT,ambient1);
	glLightfv(GL_LIGHT2,GL_AMBIENT,ambient2);

	switch (Material) {
		case 1:
			mat_dif[0]=0.157fĶ;	mat_dif[1]=0.097f;	mat_dif[2]= 0.01f;
			mat_amb[0]=0.157f;	mat_amb[1]=0.125f;	mat_amb[2]= 0.077f;
			mat_spec[0]=0.2f;	mat_spec[1]=0.2f;	mat_spec[2]=0.2f;
			shininess = 50;
			break;
		case 2:
			mat_dif[0]=0.215f;	mat_dif[1]=0.215f;	mat_dif[2]= 0.215f;
			mat_amb[0]=0.215f;	mat_amb[1]=0.215f;	mat_amb[2]= 0.215f;
			mat_spec[0]=0.0f;	mat_spec[1]=0.0f;	mat_spec[2]=0.0f;
			shininess = 128;
			break;
		case 3:
			mat_dif[0]=0.0f;	mat_dif[1]=0.0f;	mat_dif[2]= 0.0f;
			mat_amb[0]=0.99f;	mat_amb[1]=0.99f;	mat_amb[2]= 0.99f;
			mat_spec[0]=0.99f;	mat_spec[1]=0.99f;	mat_spec[2]=0.99f;
			shininess = 10;
			break;
	}
	glShadeModel(GL_SMOOTH);
	glMaterialfv (GL_FRONT_AND_BACK,GL_AMBIENT, mat_dif);
	glMaterialfv (GL_FRONT_AND_BACK,GL_DIFFUSE, mat_amb);
	glMaterialfv (GL_FRONT_AND_BACK,GL_SPECULAR, mat_spec);
	glMaterialf (GL_FRONT_AND_BACK,GL_SHININESS,shininess);
    glutSolidSphere(.4f, 64, 64);
    glPopMatrix();
	glFlush();
    glutSwapBuffers();

}


int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(20, 20);
    glClearColor(0.1f, 0.2f, 0.4f, 0);
    glutCreateWindow("Levan Gogohia");
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, 1);
    glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
    glutKeyboardFunc(Keyboard);
    glutDisplayFunc(draw);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
*/

float spec[4]={0.0,0.0,0.0,0.0},spec_w[4] ={0.0,1.0,0.0,1.0},spec_s[4]={0.0,1.0,0.0,1.0},spec_m[4]={0.0,1.0,0.0,1.0};
float color[3]={0.57,0.46,0.0},color_w[3]={0.57,0.46,0.0},color_s[3]={1.0,0.0,1.0},color_m[3]={1.0,1.0,0.0};
float shi=50,shi_w=50,shi_s=120,shi_m=50;
double r=1,O=1.57,f=1.57,x,y,z,pi=3.14,cam[3]={0,1,0};
int shininess = 10;
float mat_dif[4],mat_amb[4],mat_spec[4];
int Material = 3;

void DrawBall()
{  	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

		switch (Material) {
		case 1:
			mat_dif[0]=0.157f;	mat_dif[1]=0.097f;	mat_dif[2]= 0.01f;
			mat_amb[0]=0.157f;	mat_amb[1]=0.125f;	mat_amb[2]= 0.077f;
			mat_spec[0]=0.2f;	mat_spec[1]=0.2f;	mat_spec[2]=0.2f;
			shininess = 50;
			    for (int i=0; i < 3; i++)
                    color[i]=color_w[i];

			break;
		case 2:
			mat_dif[0]=0.215f;	mat_dif[1]=0.215f;	mat_dif[2]= 0.215f;
			mat_amb[0]=0.215f;	mat_amb[1]=0.215f;	mat_amb[2]= 0.215f;
			mat_spec[0]=0.0f;	mat_spec[1]=0.0f;	mat_spec[2]=0.0f;
			shininess = 128;
			break;
		case 3:
			mat_dif[0]=0.0f;	mat_dif[1]=0.0f;	mat_dif[2]= 0.0f;
			mat_amb[0]=0.99f;	mat_amb[1]=0.99f;	mat_amb[2]= 0.99f;
			mat_spec[0]=0.99f;	mat_spec[1]=0.99f;	mat_spec[2]=0.99f;
			shininess = 10;
			break;
	}


	glMaterialfv (GL_FRONT_AND_BACK,GL_AMBIENT, mat_dif);
	glMaterialfv (GL_FRONT_AND_BACK,GL_DIFFUSE, mat_amb);
	glMaterialfv (GL_FRONT_AND_BACK,GL_SPECULAR, mat_spec);
	glMaterialf (GL_FRONT_AND_BACK,GL_SHININESS,shininess);


	//glMaterialfv(GL_FRONT,GL_SPECULAR,spec);
	//glMaterialf(GL_FRONT,GL_SHININESS,shi);

	 GLUquadricObj *quadObj;
	 glColor3fv(color);
	 quadObj = gluNewQuadric();
     glutSolidSphere(0.5,500,500);
     gluDeleteQuadric(quadObj);
}

void Display(void)
{
    DrawBall();
	float light_position_0[] = {1.0,1.0,-1.8,0};
	float light_diffuse_0[] = {0.7,0.7,0.7,0.7};

	float light_position_1[] = {-0.5,0.0,-1.0,1.0};
    float light_diffuse_1[] = {1,0.1,0.1,1.0};
    float light_direction_1[] = {0.5,0.0,1.0,1.0};


	//------------------------------------------------
     glEnable(GL_LIGHT0);
	 glLightfv( GL_LIGHT0, GL_POSITION,light_position_0);
	 glLightfv( GL_LIGHT0, GL_DIFFUSE,light_diffuse_0);

     glEnable(GL_LIGHT1);
     glLightfv( GL_LIGHT1, GL_DIFFUSE,light_diffuse_1 );
     glLightfv( GL_LIGHT1, GL_POSITION,light_position_1);
     glLightfv( GL_LIGHT1, GL_SPOT_DIRECTION,light_direction_1);
     glLightf(GL_LIGHT1, GL_SPOT_CUTOFF,20);
	 glLightf(GL_LIGHT1, GL_SPOT_EXPONENT,128);
	 glEnable(GL_LIGHTING);

	 glutSwapBuffers();
}

void Reshape(GLsizei width,GLsizei height)
{
}

void Keyboard(unsigned char key, int x1, int y1)
{
	switch (key)
  {
  case 'a': f+=pi/50;break;
  case 'd': f-=pi/50;break;
  case 'w': O-=pi/50;break;
  case 's': O+=pi/50;break;
    case '1' : Material = 1;break;
    case '2' : Material = 2;break;
    case '3' : Material = 3;break;
    case 'i': x+=0.01; cam[0]+=-0.01;  break;
    default: break;
  }

  glLoadIdentity();
  x = sin((double)O)*sin((double)f);
  y = cos((double)O);
  z = sin((double)O)*cos((double)f);
  gluLookAt(x,y,z,-x,-y,-z,cam[0],cam[1],cam[2]);
  glutPostRedisplay();

	/*switch (key)
  {
  case '1':
	for (int i=0; i < 4; i++)
    spec[i]=spec_w[i];
    for (int i=0; i < 3; i++)
    color[i]=color_w[i];
    shi=shi_w;
	break;

  case '2':
	for (int i=0; i < 4; i++)
    spec[i]=spec_s[i];
    for (int i=0; i < 3; i++)
    color[i]=color_s[i];
    shi=shi_s;
	break;
  case '3':
	 for (int i=0; i < 4; i++)
    spec[i]=spec_m[i];
    for (int i=0; i < 3; i++)
    color[i]=color_m[i];
    shi=shi_m;
	break;
  }*/

  }


void main(int argc,char **argv)
{
     glutInit(&argc,argv);
     glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
     glutInitWindowSize(600,600);
     glutInitWindowPosition(400,300);
     glutCreateWindow("lab 2");
     //OpenFile();
	 glutDisplayFunc(Display);
     glutReshapeFunc(Reshape);
	 glutIdleFunc(Display);
	 glutKeyboardFunc(Keyboard);

	 glEnable(GL_DEPTH_TEST);
     glEnable(GL_COLOR_MATERIAL);

	 glClearColor(0.8,0.8,0.8,0.5);

     glEnable(GL_NORMALIZE);
	 glShadeModel(GL_SMOOTH);

	 glutMainLoop();

}

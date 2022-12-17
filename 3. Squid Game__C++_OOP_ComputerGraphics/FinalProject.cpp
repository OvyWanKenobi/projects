#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <windows.h>
#include <mmsystem.h>
using namespace std;

void axistemplete();
int displaying=1;

//menu
void room();
void lobbyui();
void leftwallart();
void rightwallart();
void middlewallgate();
void middlewallsquidgame();
void ball();


int state=1;
float panx = 0.4;
float panz = 0.5;
float movez = 0;
float movex=0;
int showtxt1=1;
int showpressx=1;
float pressxalpha=1;
int pressxwait=0;

//menu

//game
void gameui();
void doll();
void player();
void guard();
void lifebadge();
void cash();
void cashball();
void cloud();

int resetvalues=0;
float r=0;

float manz = 8;
float manpos=8;
//float mx=1, my=1, mz=10;
//float tx=0,ty=0,tz=0, cx=0, cy=1, cz=-8;

float r_lefthand=0,r_righthand=0,r_leftleg=0,r_rightleg=0;
float r_dollhead=0;
int cashbuffer = 1;

float ctx[50], cty[50], ctz[50], rc[50],  rx[50],  ry[50], rz[50];
float clz=-25, clz2=-50;

int red=1, green = 0;

int eliminate=-1;
int life = 0, fail=0;
int second=120;
float pinkblink=0;
int moving =0;
int win=0;
int rotatehead=1;
float r_cashball=0;
int gunshots=0;
int pinkblinkcount=0;
int stateg=0;
int startcount = 4;
int loading=1;
int loadtimer=1000;

//game


void init() {
    glClearColor(0.412, 0.412, 0.412, 1.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);//for rgba
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);// for stroke font


}

void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}


void axistemplete(){
glPushMatrix();//axistemplate
        glBegin(GL_LINES);
            glColor4f(1.0, 1.0, 0.0, 0.7);
            glVertex3f (-10, 0.0, 0.0);
            glVertex3f (10, 0.0, 0.0);
            glVertex3f (0.0, -10, 0.0);
            glVertex3f (0.0, 10, 0.0);
            glVertex3f (0.0, 0, -10.0);
            glVertex3f (0.0, 0, 10.0);


            glColor4f(1.0, 0.0, 0.0, 0.7);
            for(int i=-10; i<=10; i++){
            glVertex3f (i, 0.05, 0.0);
            glVertex3f (i, -0.05, 0.0);
             glVertex3f (0.05, i, 0.0);
            glVertex3f (-0.05, i, 0.0);
            glVertex3f (0, 0.05, i);
            glVertex3f (0, -0.05, i);
            }
            for(float i=-10.5; i<=10.5; i++){
            glVertex3f (i, 0.03, 0.0);
            glVertex3f (i, -0.03, 0.0);
             glVertex3f (0.03, i, 0.0);
            glVertex3f (-0.03, i, 0.0);
            glVertex3f (0, 0.03, i);
            glVertex3f (0, -0.03, i);
            }

        glEnd();
         glPointSize(3);
            glBegin(GL_POINTS);
            glColor4f(0.0, 0.0, 1.0, 1);
            for(float i=-10.5; i<=10.5; i=i+0.1){
            glVertex3f (i, 0, 0);
            glVertex3f (0, i, 0);
            glVertex3f (0, 0, i);
            }
            glEnd();
    glPopMatrix(); //axistemplate
}

/* *******************************************************************
**************************GAME FUNCTIONS***************************
******************************************************************* */


void game(){
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective


glPushMatrix();//look at

    gluLookAt(0.5,1,manz+3,  0,1,manz,  0,1,0);




            glPushMatrix();
               //     axistemplete();
            glPopMatrix();

             glPushMatrix();//floor upper
                      glRotatef(90,1,0,0);
                      glBegin(GL_POLYGON);
                      if(loading==1){
                        glColor4f(0.741, 0.718, 0.420, 1);

                      }else{
                        if(green==1){
                        glColor4f(0.741, 0.718, 0.420, 1);
                      }
                      if(red==1){
                        glColor4f(1,0,0, 1);
                      }


                      }


                           glVertex3f (-5, 8, 0.001);
                           glVertex3f (5, 8, 0.001);
                           glVertex3f (5, -8, 0.001);
                           glVertex3f (-5, -8, 0.001);
                      glEnd();

                      glBegin(GL_POLYGON);//pink line
                      glColor3f(1,0,1);
                            glVertex3f (-5, -8, -0.002);
                           glVertex3f (5, -8, -0.002);
                           glVertex3f (5, -8.3, -0.002);
                           glVertex3f (-5, -8.3, -0.002);
                      glEnd();




            glPopMatrix();//floor upper  end

            glPushMatrix();//floor border

                glRotatef(90,1,0,0);
                  glBegin(GL_POLYGON);

                        glColor4f(0.827, 0.827, 0.827, 1);
                       glVertex3f (-6, 12, 0.002);
                       glVertex3f (6, 12, 0.002);
                       glVertex3f (6, -12, 0.002);
                       glVertex3f (-6, -12, 0.002);
                  glEnd();
            glPopMatrix();//floor border end

            glPushMatrix();//wall right
                  glBegin(GL_POLYGON);
                        glColor4f(0.000, 0.749, 1.000, 1);
                       glVertex3f (6.001, 7, -12);
                       glColor4f(0.878, 1.000, 1.000, 1);
                       glVertex3f (6.001, 2.25, -12);
                       glColor4f(0.878, 1.000, 1.000, 1);
                       glVertex3f (6.001, 2.25, 12);
                       glColor4f(0.000, 0.749, 1.000, 1);
                       glVertex3f (6.001, 7, 12);

                  glEnd();

                  glBegin(GL_POLYGON);
                       glColor4f(0.878, 1.000, 1.000, 1);
                       glVertex3f (6, 2.25, -12);
                       glColor4f(0.133, 0.545, 0.133, 1);
                       glVertex3f (6, 1.5, -12);
                       glColor4f(0.133, 0.545, 0.133, 1);
                       glVertex3f (6, 1.5, 12);
                       glColor4f(0.878, 1.000, 1.000, 1);
                       glVertex3f (6, 2.25, 12);
                     glEnd();

                  glBegin(GL_POLYGON);
                       glColor4f(0.957, 0.643, 0.376, 1);
                       glVertex3f (6, 1.5, -12);
                       glColor4f(0.871, 0.722, 0.529, 1);
                       glVertex3f (6, 0, -12);
                       glColor4f(0.871, 0.722, 0.529, 1);
                       glVertex3f (6, 0, 12);
                       glColor4f(0.957, 0.643, 0.376, 1);
                       glVertex3f (6, 1.5, 12);
                     glEnd();
            glPopMatrix();//wall right end

             glPushMatrix();//wall front
                  glBegin(GL_POLYGON);
                        glColor4f(0.000, 0.749, 1.000, 1);
                       glVertex3f (-6, 7, -12.001);
                       glColor4f(0.000, 0.749, 1.000, 1);
                       glVertex3f (6, 7, -12.001);
                       glColor4f(0.878, 1.000, 1.000, 1);
                       glVertex3f (6, 2.25, -12.001);
                       glColor4f(0.878, 1.000, 1.000, 1);
                       glVertex3f (-6, 2.25, -12.001);

                  glEnd();

                  glBegin(GL_POLYGON);
                       glColor4f(0.878, 1.000, 1.000, 1);
                       glVertex3f (-6, 2.25, -12);
                       glColor4f(0.878, 1.000, 1.000, 1);
                       glVertex3f (6, 2.25, -12);
                       glColor4f(0.133, 0.545, 0.133, 1);
                       glVertex3f (6, 1.5, -12);
                       glColor4f(0.133, 0.545, 0.133, 1);
                       glVertex3f (-6, 1.5, -12);
                     glEnd();

                  glBegin(GL_POLYGON);
                       glColor4f(0.957, 0.643, 0.376, 1);
                       glVertex3f (-6, 1.5, -12);
                       glColor4f(0.871, 0.722, 0.529, 1);
                       glVertex3f (6, 1.5, -12);
                       glColor4f(0.871, 0.722, 0.529, 1);
                       glVertex3f (6, 0,-12);
                       glColor4f(0.957, 0.643, 0.376, 1);
                       glVertex3f (-6, 0, -12);
                     glEnd();
            glPopMatrix();//wall front end

             glPushMatrix();//wall left
                  glBegin(GL_POLYGON);
                        glColor4f(0.000, 0.749, 1.000, 1);
                       glVertex3f (-6.001, 7, -12);
                       glColor4f(0.878, 1.000, 1.000, 1);
                       glVertex3f (-6.001, 2.25, -12);
                       glColor4f(0.878, 1.000, 1.000, 1);
                       glVertex3f (-6.001, 2.25, 12);
                       glColor4f(0.000, 0.749, 1.000, 1);
                       glVertex3f (-6.001, 7, 12);

                  glEnd();

                  glBegin(GL_POLYGON);
                       glColor4f(0.878, 1.000, 1.000, 1);
                       glVertex3f (-6, 2.25, -12);
                       glColor4f(0.133, 0.545, 0.133, 1);
                       glVertex3f (-6, 1.5, -12);
                       glColor4f(0.133, 0.545, 0.133, 1);
                       glVertex3f (-6, 1.5, 12);
                       glColor4f(0.878, 1.000, 1.000, 1);
                       glVertex3f (-6, 2.25, 12);
                     glEnd();

                  glBegin(GL_POLYGON);
                       glColor4f(0.957, 0.643, 0.376, 1);
                       glVertex3f (-6, 1.5, -12);
                       glColor4f(0.871, 0.722, 0.529, 1);
                       glVertex3f (-6, 0, -12);
                       glColor4f(0.871, 0.722, 0.529, 1);
                       glVertex3f (-6, 0, 12);
                       glColor4f(0.957, 0.643, 0.376, 1);
                       glVertex3f (-6, 1.5, 12);
                     glEnd();
            glPopMatrix();//wall left end

             glPushMatrix();//wall back
                  glBegin(GL_POLYGON);
                        glColor4f(0.000, 0.749, 1.000, 1);
                       glVertex3f (-6, 7, 12);
                       glColor4f(0.000, 0.749, 1.000, 1);
                       glVertex3f (6, 7, 12);
                       glColor4f(0.878, 1.000, 1.000, 1);
                       glVertex3f (6, 2.25, 12);
                       glColor4f(0.878, 1.000, 1.000, 1);
                       glVertex3f (-6, 2.25, 12);

                  glEnd();

                  glBegin(GL_POLYGON);
                       glColor4f(0.878, 1.000, 1.000, 1);
                       glVertex3f (-6, 2.25, 12);
                       glColor4f(0.878, 1.000, 1.000, 1);
                       glVertex3f (6, 2.25, 12);
                       glColor4f(0.133, 0.545, 0.133, 1);
                       glVertex3f (6, 1.5, 12);
                       glColor4f(0.133, 0.545, 0.133, 1);
                       glVertex3f (-6, 1.5, 12);
                     glEnd();

                  glBegin(GL_POLYGON);
                       glColor4f(0.957, 0.643, 0.376, 1);
                       glVertex3f (-6, 1.5, 12);
                       glColor4f(0.871, 0.722, 0.529, 1);
                       glVertex3f (6, 1.5, 12);
                       glColor4f(0.871, 0.722, 0.529, 1);
                       glVertex3f (6, 0,12);
                       glColor4f(0.957, 0.643, 0.376, 1);
                       glVertex3f (-6, 0, 12);
                     glEnd();
            glPopMatrix();//wall back end


            glPushMatrix();//put player here
                  glTranslatef(0,0.4,manz);
                  glScalef(0.35,0.35,0.35);
                  glRotatef(180,0,1,0);
                  player();
        glPopMatrix();//put player here

            glPushMatrix();//guard1
                   glTranslatef(1.75,0.35,-10.5);
                  glScalef(0.35,0.35,0.35);
                 // glRotatef(180,0,1,0);
                  guard();
            glPopMatrix();//guard1

            glPushMatrix();//guard2
                   glTranslatef(-1.75,0.35,-10.5);
                  glScalef(0.35,0.35,0.35);
                 // glRotatef(180,0,1,0);
                  guard();
            glPopMatrix();//guard2

            glPushMatrix();//DOLL
                glTranslatef(0,1.25,-10.5);
                glScalef(0.4,0.425,0.4);
                    doll();
            glPopMatrix();//DOLL

            glPushMatrix();//cloud
                glTranslatef(-0.9,10,clz);
                 glScalef(1.1,1,1);
                    cloud();
            glPopMatrix();//cloud

              glPushMatrix();//cloud2
                glTranslatef(-0.9,10,clz2);
                 glScalef(1.1,1,1);
                    cloud();
            glPopMatrix();//cloud2


            glPushMatrix();//sky
            glTranslatef(0,20,0);
                glRotatef(90,1,0,0);
                  glBegin(GL_POLYGON);

                        glColor4f(0.529, 0.808, 0.922, 1);
                       glVertex3f (-30, 70, 0.002);
                       glColor4f(0.275, 0.510, 0.706, 1);
                       glVertex3f (30, 70, 0.002);
                       glColor4f(0.529, 0.808, 0.922, 1);
                       glVertex3f (30, -70, 0.002);
                       glColor4f(0.275, 0.510, 0.706, 1);
                       glVertex3f (-30, -70, 0.002);
                  glEnd();
            glPopMatrix();//sky




             glPushMatrix();//HOUSE
             glTranslatef(0,0,11);
             glScalef(0.8,0.8,1);

                    glBegin(GL_POLYGON);

                        glColor4f(1.000, 0.549, -0.000, 1);
                       glVertex3f (-2.5, 2.25, -0.002);
                       glVertex3f (2.5, 2.25, -0.002);
                       glVertex3f (1.75, 3.50, -0.002);
                       glVertex3f (-1.75, 3.50, -0.002);
                  glEnd();

                  glBegin(GL_POLYGON);

                        glColor4f(0.878, 1.000, 1.000, 1);
                       glVertex3f (-0.7, 2.25, -0.005);

                       glVertex3f (0.7, 2.25, -0.005);

                       glVertex3f (0.7, 4, -0.005);

                       glVertex3f (-0.7, 4, -0.005);
                  glEnd();


                  glBegin(GL_POLYGON);

                        glColor4f(0.180, 0.545, 0.341, 1);
                       glVertex3f (-1, 1.5, -0.002);

                       glVertex3f (1, 1.5, -0.002);

                       glVertex3f (1, 0, -0.002);

                       glVertex3f (-1, 0, -0.002);
                  glEnd();


                  glBegin(GL_POLYGON);

                        glColor4f(0.878, 1.000, 1.000, 1);
                       glVertex3f (-2, 2.75, 0);

                       glVertex3f (2, 2.75, 0);

                       glVertex3f (2, 0, 0);

                       glVertex3f (-2, 0, 0);
                  glEnd();
            glPopMatrix();//HOUSE








glPopMatrix();//lookat




glPushMatrix();//gameui
glTranslatef(0,0,2.4);
glScalef(0.5,0.5,1);
    gameui();
glPopMatrix();//gameui

if(loading==1){
glPushMatrix();
     glTranslatef(0,0,-2);
     glPushMatrix();

                       glColor3f(1,0,1);
                        glTranslatef(-0.45, 0.45, 0);
                        glScalef(0.0005, 0.0005, 0.0005);
                       glLineWidth(3.0);
                      char text[] =" - INSTRUCTIONS - ";
                      for(int i=0; i<strlen(text); i++){
                          glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, text[i]);
                      }


                        glLineWidth(1.0);
    glPopMatrix();
    glPushMatrix();

                       glLineWidth(2.0);
                       glPushMatrix();
                        glColor3f(1,1,1);
                        glTranslatef(-1, 0.32, 0.02);
                        glScalef(0.00035, 0.00035, 0.00035);
                            char text1[] =" WELCOME TO SQUID GAME. YOU WILL BE PLAYING RED LIGHT, GREEN LIGHT.";
                      for(int i=0; i<strlen(text1); i++){
                          glutStrokeCharacter(GLUT_STROKE_ROMAN, text1[i]);
                      }
                        glPopMatrix();

                        glPushMatrix();
                        glColor3f(1,1,1);
                        glTranslatef(-1.16, 0.22, 0);
                        glScalef(0.00035, 0.00035, 0.00035);
                            char text2[] =" YOU ARE ALLOWED TO MOVE FORWARD WHEN ITS GREEN LIGHT. STOP WHEN ITS RED LIGHT.";
                      for(int i=0; i<strlen(text2); i++){
                          glutStrokeCharacter(GLUT_STROKE_ROMAN, text2[i]);
                      }
                        glPopMatrix();
                        glPushMatrix();
                        glColor3f(1,1,1);
                        glTranslatef(-0.9, 0.12, 0);
                        glScalef(0.00035, 0.00035, 0.00035);
                            char text3[] ="IF YOUR MOVEMENT IS DETECTED AFTERWARDS YOU WILL BE ''ELIMINATED''.";
                      for(int i=0; i<strlen(text3); i++){
                          glutStrokeCharacter(GLUT_STROKE_ROMAN, text3[i]);
                      }
                        glPopMatrix();
                        glPushMatrix();
                        glColor3f(1,1,1);
                        glTranslatef(-0.8, 0, 0);
                        glScalef(0.00035, 0.00035, 0.00035);
                            char text4[] ="YOU HAVE TO CROSS THE PINK LINE BEFORE TIMER RUNS OUT.";
                      for(int i=0; i<strlen(text4); i++){
                          glutStrokeCharacter(GLUT_STROKE_ROMAN, text4[i]);
                      }
                        glPopMatrix();
                        glPushMatrix();
                        glColor3f(1,1,1);
                        glTranslatef(-0.8, -0.12, 0);
                        glScalef(0.00035, 0.00035, 0.00035);
                            char text5[] ="YOU HAVE BEEN GIVEN THREE LIFES TO COMPLETE THE LEVEL.";
                      for(int i=0; i<strlen(text5); i++){
                          glutStrokeCharacter(GLUT_STROKE_ROMAN, text5[i]);
                      }
                        glPopMatrix();
                        glPushMatrix();
                        glColor3f(1,1,1);
                        glTranslatef(-0.45, -0.25, 0);
                        glScalef(0.00035, 0.00035, 0.00035);
                            char text6[] ="HOLD ' UP KEY ' TO MOVE FORWARD";
                      for(int i=0; i<strlen(text6); i++){
                          glutStrokeCharacter(GLUT_STROKE_ROMAN, text6[i]);
                      }
                        glPopMatrix();
                        glPushMatrix();
                         glColor3f(1,0,0);
                        glTranslatef(-0.18, -0.43, 0);
                        glScalef(0.00035, 0.00035, 0.00035);
                            char text7[] ="Press 'Z' to Begin.";
                      for(int i=0; i<strlen(text7); i++){
                          glutStrokeCharacter(GLUT_STROKE_ROMAN, text7[i]);
                      }
                        glPopMatrix();

                       glLineWidth(1.0);
     glPopMatrix();
    glPushMatrix();
        glTranslatef(0,-0.6,0);
        glScalef(0.4,0.4,1);
            glBegin(GL_POLYGON);

                glColor4f(0,0,0, 0.6);
                    glVertex3f (-3, 3, 0);
                    glVertex3f (3, 3, 0);
                    glVertex3f (3, 0, 0);
                    glVertex3f (-3, 0, 0);
            glEnd();
    glPopMatrix();




glPopMatrix();
}


	glutSwapBuffers();
}

void gameui(){

glTranslatef(0,0,-5);

    float r,g;


if(red==1){
    r=1,g=0;
}

if(green==1){
    r=0,g=1;
}
	glPushMatrix();//light status
	glTranslatef(0,1.5,0);
         glLineWidth(6);
        //glRotatef(90,1,0,0);
          glBegin(GL_LINE_LOOP);

                glColor4f(r, g, 0, 1);
               glVertex3f (1, 0.5, 0);
               glVertex3f (-1, 0.5, 0);
               glVertex3f (-1, 0, 0);
               glVertex3f (1, 0, 0);
          glEnd();
          glLineWidth(1);

          glBegin(GL_POLYGON);

                glColor4f(r, g, 0, 1);
               glVertex3f (0.8, 0.4, 0);
               glVertex3f (-0.8, 0.4, 0);
               glVertex3f (-0.8, 0.1, 0);
               glVertex3f (0.8, 0.1, 0);
          glEnd();

            glColor3f(1,1,1);
            glTranslatef(-0.7, 0.16, 0.002);
            glScalef(0.0015, 0.0015, 0.0);
            glLineWidth(3.0);

                if(red==1){

                     char text[] ="RED LIGHT";
                     for(int i=0; i<strlen(text); i++)
              glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, text[i]);
                }

                if(green==1){

                    char text[] ="GREEN LIGHT";
                    for(int i=0; i<strlen(text); i++)
              glutStrokeCharacter(GLUT_STROKE_ROMAN, text[i]);

                }

             // GLUT_STROKE_ROMAN
             //GLUT_STROKE_MONO_ROMAN
             glLineWidth(1.0);


	glPopMatrix();//light status

	glPushMatrix();//eliminated
        glTranslatef(0,0.4,0);
        glScalef(0.8,0.8,0.8);
        if(eliminate==1){


            glPushMatrix();
             glScalef(0.75,0.75,0.75);

                     glPushMatrix();
                    lifebadge();
                    glPopMatrix();

                     glPushMatrix();
                    glRotatef(45,0,0,1);
                    glBegin(GL_POLYGON);

                               glColor4f(0.1, 0.1, 0.1, pinkblink);
                               glVertex3f (-1, 1, 0.012);
                               glVertex3f (1, 1, 0.012);
                               glVertex3f (1, -1, 0.012);
                               glVertex3f (-1, -1, 0.012);
                    glEnd();
                    glPopMatrix();

            glPopMatrix();
            if(pinkblinkcount>=7){
               glPushMatrix();

                      glColor3f(1,0,0);
                        glTranslatef(-1.5, -1, 0.01);
                        glScalef(0.003, 0.003, 0.0);
                       glLineWidth(5.0);
                      char text[] ="ELIMINATED";
                      for(int i=0; i<strlen(text); i++){
                          glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, text[i]);
                      }
                        glLineWidth(1.0);
                glPopMatrix();
                glPushMatrix();

                      glColor3f(1,1,1);
                        glTranslatef(-1.5, -1, 0.01);
                        glScalef(0.003, 0.003, 0.0);
                       glLineWidth(8.0);

                      char text1[] ="ELIMINATED";
                      for(int i=0; i<strlen(text1); i++){
                          glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, text1[i]);
                      }
                        glLineWidth(1.0);
                glPopMatrix();
                glPushMatrix();

                      glColor3f(1,0,1);
                        glTranslatef(-1.2, -1.4, 0.01);
                        glScalef(0.0009, 0.0009, 0.0);
                       glLineWidth(2.0);
                      char text2[] ="PRESS 'M' TO GO BACK TO MENU";
                      for(int i=0; i<strlen(text2); i++){
                          glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, text2[i]);
                      }
                        glLineWidth(1.0);
                glPopMatrix();

                 glPushMatrix();

                      glColor3f(1,1,1);
                        glTranslatef(-1.2, -1.4, 0.01);
                        glScalef(0.0009, 0.0009, 0.0);
                       glLineWidth(4.0);
                      char text21[] ="PRESS 'M' TO GO BACK TO MENU";
                      for(int i=0; i<strlen(text21); i++){
                          glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, text21[i]);
                      }
                        glLineWidth(1.0);
                glPopMatrix();

            }
        }

	glPopMatrix();//eliminated ui end


	glPushMatrix();//life remain
        glPushMatrix();
            glColor3f(1,1,1);
                        glTranslatef(-3.5, 1.75, 0.01);
                        glScalef(0.001, 0.001, 0.0);
                       glLineWidth(2.0);
                      char text2[] ="Life Remaining : ";
                      for(int i=0; i<strlen(text2); i++){
                          glutStrokeCharacter(GLUT_STROKE_ROMAN, text2[i]);
                      }
                        glLineWidth(1.0);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-2.25, 1.8, 0.01);
        glScalef(0.1, 0.1, 0.1);
            if(life<3){
                glPushMatrix();
                lifebadge();
                glPopMatrix();
                if(life<2){
                    glPushMatrix();
                    glTranslatef(3, 0, 0);
                    lifebadge();
                    glPopMatrix();
                    if(life<1){
                        glPushMatrix();
                        glTranslatef(6, 0, 0);
                        lifebadge();
                        glPopMatrix();
                    }
                }
            }

        glPopMatrix();

	glPopMatrix();//life remain end


   glPushMatrix();//time

            glColor3f(1,1,1);
                        glTranslatef(2, 1.75, 0.01);
                        glScalef(0.001, 0.001, 0.0);
                       glLineWidth(2.0);
                       string str = "Time Remaining : " +to_string(second);
                      char time[(str.length())+1];
                        strcpy(time, str.c_str());
                      for(int i=0; i<strlen(time); i++){
                          glutStrokeCharacter(GLUT_STROKE_ROMAN,+time[i]);
                      }
                        glLineWidth(1.0);

    glPopMatrix();//time

if(startcount>=0 && startcount<4){
    glPushMatrix();//countdown

            glColor3f(1,1,1);
                    glTranslatef(-0.5, -0.3, 0.01);
                        glScalef(0.01, 0.01, 0);
                       glLineWidth(8.0);
                       string str2 = to_string(startcount);
                      char time2[(str2.length())+1];
                        strcpy(time2, str2.c_str());
                      for(int i=0; i<strlen(time2); i++){
                          glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,+time2[i]);
                      }

                        glLineWidth(1.0);

    glPopMatrix();//countdown

    glPushMatrix();
            glColor3f(1,0,0);
            glTranslatef(-0.5, -0.3, 0.01);
                glScalef(0.01, 0.01, 0);
                       glLineWidth(20.0);
                       string str3 = to_string(startcount);
                      char time3[(str3.length())+1];
                        strcpy(time3, str3.c_str());
                      for(int i=0; i<strlen(time3); i++){
                          glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,+time3[i]);
                      }
                     glLineWidth(1.0);
    glPopMatrix();
}

    if(fail==1){
    glPushMatrix();//moved

                      glColor3f(1,1,1);
                        glTranslatef(-2.5, -0.5, 0.01);
                        glScalef(0.0015, 0.0015, 0.0);
                       glLineWidth(3.0);
                      char moved[] ="You moved in Red Light. Lost a life.";
                      for(int i=0; i<strlen(moved); i++){
                          glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, moved[i]);
                      }
                        glLineWidth(1.0);
    glPopMatrix();//moved
     glPushMatrix();//moved

                      glColor3f(1,0,1);
                        glTranslatef(-2.5, -0.5, 0.01);
                        glScalef(0.0015, 0.0015, 0.0);
                       glLineWidth(5.0);
                      char moved1[] ="You moved in Red Light. Lost a life.";
                      for(int i=0; i<strlen(moved1); i++){
                          glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, moved1[i]);
                      }
                        glLineWidth(1.0);
    glPopMatrix();//moved
    }

    glPushMatrix();//upbutton
        if(moving==1){
          glTranslatef(2.8, -1, -0.02);
        }else if(moving ==0){
            glTranslatef(2.75, -0.9, 0.02);
        }
          glRotatef(5,-1,0,0);
          glRotatef(5,0,-1,0);
          glScalef(0.8, 0.8, 0.2);
                glPushMatrix();
                if(moving==1){
                glColor4f(0.412, 0.412, 0.412,1);
                glutSolidCube(1);
                }else if(moving ==0){
                glColor4f(0.753, 0.753, 0.753,1);
                glutSolidCube(1);
                }

                glColor4f(0, 0, 0,1);
                glutWireCube(1);

                glBegin(GL_POLYGON);
                glColor4f(0.2, 0.2, 0.2,1);
                    glVertex3f(-0.3,0.1,0.501);
                    glVertex3f(0,0.4,0.501);
                    glVertex3f(0.3,0.1,0.501);
                glEnd();
                 glBegin(GL_POLYGON);
                glColor4f(0.2, 0.2, 0.2,1);
                    glVertex3f(-0.1,0.1,0.501);
                    glVertex3f(0.1,0.1,0.501);
                    glVertex3f(0.1,-0.4,0.501);
                    glVertex3f(-0.1,-0.4,0.501);
                glEnd();
            glPopMatrix();
    glPopMatrix();//upbutton end




    if(win==1){

    glPushMatrix();//winner ui
        glPushMatrix();
        glTranslatef(0,0,-0.5);
            cashball();
        glPopMatrix();

        glPushMatrix();
         glColor3f(1,0,0);
                glTranslatef(-0.8, -1, 0.25);
                glScalef(0.003, 0.003, 0.003);
                glLineWidth(5.0);
                char winner1[] ="WINNER";
                for(int i=0; i<strlen(winner1); i++){
                    glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, winner1[i]);
                }
                        glLineWidth(1.0);
          glPopMatrix();
          glPushMatrix();

                      glColor3f(1,1,1);
                        glTranslatef(-0.8, -1, 0.25);
                        glScalef(0.003, 0.003, 0.003);
                       glLineWidth(8.0);
                      char winner2[] ="WINNER";
                      for(int i=0; i<strlen(winner2); i++){
                          glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, winner2[i]);
                      }
                        glLineWidth(1.0);
                glPopMatrix();
                glPushMatrix();

                      glColor3f(1,0,1);
                        glTranslatef(-1.25, -1.4, 0.01);
                        glScalef(0.0009, 0.0009, 0.0);
                       glLineWidth(2.0);
                      char text6[] ="PRESS 'M' TO GO BACK TO MENU";
                      for(int i=0; i<strlen(text6); i++){
                          glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, text6[i]);
                      }
                        glLineWidth(1.0);
                glPopMatrix();
                glPushMatrix();

                      glColor3f(1,1,1);
                        glTranslatef(-1.25, -1.4, 0.01);
                        glScalef(0.0009, 0.0009, 0.0);
                       glLineWidth(3.0);
                      char text61[] ="PRESS 'M' TO GO BACK TO MENU";
                      for(int i=0; i<strlen(text61); i++){
                          glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, text61[i]);
                      }
                        glLineWidth(1.0);
                glPopMatrix();

    glPopMatrix();//winner ui
}

}//gameui end

void cloud(){

glPushMatrix();//clouds1

     glScalef(1,1,1.25);
        glPushMatrix();
            glTranslatef(-0.5,0,0.3);
            glScalef(1,0.4,1.25);

            glColor3f(0.902, 0.902, 0.980);
            glutSolidCube(1);
            glColor3f(0.663, 0.663, 0.663);
            glutWireCube(1);
            glColor3f(	0.703, 0.703, 0.703);
            glBegin(GL_POLYGON);
                glVertex3f(-0.5,-0.501,-0.5);
                glVertex3f(0.5,-0.501,-0.5);
                glVertex3f(0.5,-0.501,0.5);
                glVertex3f(-0.5,-0.501,0.5);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(1,0,0);
            glScalef(2,0.4,3);

                glColor3f(0.902, 0.902, 0.980);
                glutSolidCube(1);
                glColor3f(0.763, 0.763, 0.763);
                glutWireCube(1);
                   glColor3f(	0.703, 0.703, 0.703);
                glBegin(GL_POLYGON);
                    glVertex3f(-0.5,-0.501,-0.5);
                    glVertex3f(0.5,-0.501,-0.5);
                    glVertex3f(0.5,-0.501,0.5);
                    glVertex3f(-0.5,-0.501,0.5);
                glEnd();

        glPopMatrix();


        glPushMatrix();
            glTranslatef(2.25,0,-0.4);
            glScalef(0.75,0.4,1);

                glColor3f(0.902, 0.902, 0.980);
                glutSolidCube(1);
                glColor3f(0.763, 0.763, 0.763);
                glutWireCube(1);
                   glColor3f(	0.703, 0.703, 0.703);
                glBegin(GL_POLYGON);
                    glVertex3f(-0.5,-0.501,-0.5);
                    glVertex3f(0.5,-0.501,-0.5);
                    glVertex3f(0.5,-0.501,0.5);
                    glVertex3f(-0.5,-0.501,0.5);
                glEnd();
        glPopMatrix();

glPopMatrix();//clouds1




glPushMatrix();//clouds2
    glTranslatef(-5,1,-8);
        glPushMatrix();
        glTranslatef(-0.5,0,0.9);
        glScalef(1.5,0.4,0.8);

            glColor3f(0.902, 0.902, 0.980);
            glutSolidCube(1);
            glColor3f(0.663, 0.663, 0.663);
            glutWireCube(1);
            glColor3f(	0.703, 0.703, 0.703);
            glBegin(GL_POLYGON);
                glVertex3f(-0.5,-0.501,-0.5);
                glVertex3f(0.5,-0.501,-0.5);
                glVertex3f(0.5,-0.501,0.5);
                glVertex3f(-0.5,-0.501,0.5);
            glEnd();
    glPopMatrix();

        glPushMatrix();
            glTranslatef(1,0,0);
            glScalef(1.5,0.4,5);

                glColor3f(0.902, 0.902, 0.980);
                glutSolidCube(1);
                glColor3f(0.763, 0.763, 0.763);
                glutWireCube(1);
                   glColor3f(	0.703, 0.703, 0.703);
                glBegin(GL_POLYGON);
                    glVertex3f(-0.5,-0.501,-0.5);
                    glVertex3f(0.5,-0.501,-0.5);
                    glVertex3f(0.5,-0.501,0.5);
                    glVertex3f(-0.5,-0.501,0.5);
                glEnd();

        glPopMatrix();


        glPushMatrix();
            glTranslatef(2.25,0,2);
            glScalef(1.2,0.4,2.1);

                glColor3f(0.902, 0.902, 0.980);
                glutSolidCube(1);
                glColor3f(0.763, 0.763, 0.763);
                glutWireCube(1);
                   glColor3f(	0.703, 0.703, 0.703);
                glBegin(GL_POLYGON);
                    glVertex3f(-0.5,-0.501,-0.5);
                    glVertex3f(0.5,-0.501,-0.5);
                    glVertex3f(0.5,-0.501,0.5);
                    glVertex3f(-0.5,-0.501,0.5);
                glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(2.25,0,-1);
            glScalef(1.2,0.4,2.1);

                glColor3f(0.902, 0.902, 0.980);
                glutSolidCube(1);
                glColor3f(0.763, 0.763, 0.763);
                glutWireCube(1);
                   glColor3f(	0.703, 0.703, 0.703);
                glBegin(GL_POLYGON);
                    glVertex3f(-0.5,-0.501,-0.5);
                    glVertex3f(0.5,-0.501,-0.5);
                    glVertex3f(0.5,-0.501,0.5);
                    glVertex3f(-0.5,-0.501,0.5);
                glEnd();

        glPopMatrix();

glPopMatrix();//clouds2


glPushMatrix();//clouds3
    glTranslatef(3,0.2,-10);
     glScalef(1.3,1,1.5);
        glPushMatrix();
            glTranslatef(0.5,0,0.3);
            glScalef(1.25,0.4,1.25);

            glColor3f(0.902, 0.902, 0.980);
            glutSolidCube(1);
            glColor3f(0.663, 0.663, 0.663);
            glutWireCube(1);
            glColor3f(	0.703, 0.703, 0.703);
            glBegin(GL_POLYGON);
                glVertex3f(-0.5,-0.501,-0.5);
                glVertex3f(0.5,-0.501,-0.5);
                glVertex3f(0.5,-0.501,0.5);
                glVertex3f(-0.5,-0.501,0.5);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(1.5,0,0);
            glScalef(2,0.4,4);

                glColor3f(0.902, 0.902, 0.980);
                glutSolidCube(1);
                glColor3f(0.763, 0.763, 0.763);
                glutWireCube(1);
                   glColor3f(	0.703, 0.703, 0.703);
                glBegin(GL_POLYGON);
                    glVertex3f(-0.5,-0.501,-0.5);
                    glVertex3f(0.5,-0.501,-0.5);
                    glVertex3f(0.5,-0.501,0.5);
                    glVertex3f(-0.5,-0.501,0.5);
                glEnd();

        glPopMatrix();


        glPushMatrix();
            glTranslatef(-0.5,0,-0.6);
            glScalef(1.25,0.4,2);

                glColor3f(0.902, 0.902, 0.980);
                glutSolidCube(1);
                glColor3f(0.763, 0.763, 0.763);
                glutWireCube(1);
                   glColor3f(	0.703, 0.703, 0.703);
                glBegin(GL_POLYGON);
                    glVertex3f(-0.5,-0.501,-0.5);
                    glVertex3f(0.5,-0.501,-0.5);
                    glVertex3f(0.5,-0.501,0.5);
                    glVertex3f(-0.5,-0.501,0.5);
                glEnd();
        glPopMatrix();

glPopMatrix();//clouds3


glPushMatrix();//clouds4
    glTranslatef(-2.3,0.8,8);
     glScalef(1,1,1.25);
        glPushMatrix();
            glTranslatef(-0.5,0,-0.6);
            glScalef(1.25,0.4,1.25);

            glColor3f(0.902, 0.902, 0.980);
            glutSolidCube(1);
            glColor3f(0.663, 0.663, 0.663);
            glutWireCube(1);
            glColor3f(	0.703, 0.703, 0.703);
            glBegin(GL_POLYGON);
                glVertex3f(-0.5,-0.501,-0.5);
                glVertex3f(0.5,-0.501,-0.5);
                glVertex3f(0.5,-0.501,0.5);
                glVertex3f(-0.5,-0.501,0.5);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-2,0,0);
            glScalef(2,0.4,3.5);

                glColor3f(0.902, 0.902, 0.980);
                glutSolidCube(1);
                glColor3f(0.763, 0.763, 0.763);
                glutWireCube(1);
                   glColor3f(	0.703, 0.703, 0.703);
                glBegin(GL_POLYGON);
                    glVertex3f(-0.5,-0.501,-0.5);
                    glVertex3f(0.5,-0.501,-0.5);
                    glVertex3f(0.5,-0.501,0.5);
                    glVertex3f(-0.5,-0.501,0.5);
                glEnd();

        glPopMatrix();


        glPushMatrix();
            glTranslatef(0.5,0,-0.6);
            glScalef(1.25,0.4,2);

                glColor3f(0.902, 0.902, 0.980);
                glutSolidCube(1);
                glColor3f(0.763, 0.763, 0.763);
                glutWireCube(1);
                   glColor3f(	0.703, 0.703, 0.703);
                glBegin(GL_POLYGON);
                    glVertex3f(-0.5,-0.501,-0.5);
                    glVertex3f(0.5,-0.501,-0.5);
                    glVertex3f(0.5,-0.501,0.5);
                    glVertex3f(-0.5,-0.501,0.5);
                glEnd();
        glPopMatrix();

glPopMatrix();//clouds4



glPushMatrix();//clouds5
    glTranslatef(5,0.5,7.75);
        glPushMatrix();
        glTranslatef(-0.65,0,0.9);
        glScalef(2,0.4,1.2);

            glColor3f(0.902, 0.902, 0.980);
            glutSolidCube(1);
            glColor3f(0.663, 0.663, 0.663);
            glutWireCube(1);
            glColor3f(	0.703, 0.703, 0.703);
            glBegin(GL_POLYGON);
                glVertex3f(-0.5,-0.501,-0.5);
                glVertex3f(0.5,-0.501,-0.5);
                glVertex3f(0.5,-0.501,0.5);
                glVertex3f(-0.5,-0.501,0.5);
            glEnd();
    glPopMatrix();

        glPushMatrix();
            glTranslatef(1,0,0);
            glScalef(3.5,0.4,4);

                glColor3f(0.902, 0.902, 0.980);
                glutSolidCube(1);
                glColor3f(0.763, 0.763, 0.763);
                glutWireCube(1);
                   glColor3f(	0.703, 0.703, 0.703);
                glBegin(GL_POLYGON);
                    glVertex3f(-0.5,-0.501,-0.5);
                    glVertex3f(0.5,-0.501,-0.5);
                    glVertex3f(0.5,-0.501,0.5);
                    glVertex3f(-0.5,-0.501,0.5);
                glEnd();

        glPopMatrix();


        glPushMatrix();
            glTranslatef(2.25,0,2);
            glScalef(1.8,0.4,2.1);

                glColor3f(0.902, 0.902, 0.980);
                glutSolidCube(1);
                glColor3f(0.763, 0.763, 0.763);
                glutWireCube(1);
                   glColor3f(	0.703, 0.703, 0.703);
                glBegin(GL_POLYGON);
                    glVertex3f(-0.5,-0.501,-0.5);
                    glVertex3f(0.5,-0.501,-0.5);
                    glVertex3f(0.5,-0.501,0.5);
                    glVertex3f(-0.5,-0.501,0.5);
                glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(2.25,0,-2);
            glScalef(1.2,0.6,2.1);

                glColor3f(0.902, 0.902, 0.980);
                glutSolidCube(1);
                glColor3f(0.763, 0.763, 0.763);
                glutWireCube(1);
                   glColor3f(	0.703, 0.703, 0.703);
                glBegin(GL_POLYGON);
                    glVertex3f(-0.5,-0.501,-0.5);
                    glVertex3f(0.5,-0.501,-0.5);
                    glVertex3f(0.5,-0.501,0.5);
                    glVertex3f(-0.5,-0.501,0.5);
                glEnd();

        glPopMatrix();

glPopMatrix();//clouds5



}

void cash(){
glPushMatrix();
    glScalef(0.5,0.1,0.2);
    glPushMatrix();
    glScalef(0.6,1,1.1);
       glBegin(GL_TRIANGLE_FAN);
           glColor3f(1.000, 0.980, 0.804);
          for(int i=0;i<360;i++)
            {
             float pi=3.1416;
             float A=(i*2*pi)/360;
             float r=0.2;
             float x = r * cos(A);
             float z = r * sin(A);
             glVertex3f(x,0.501,z);
              }
       glEnd();
       glBegin(GL_TRIANGLE_FAN);
           glColor3f(1.000, 0.980, 0.804);
          for(int i=0;i<360;i++)
            {
             float pi=3.1416;
             float A=(i*2*pi)/360;
             float r=0.2;
             float x = r * cos(A);
             float z = r * sin(A);
             glVertex3f(x,-0.501,z);
              }
       glEnd();
       glPopMatrix();
       glPushMatrix();
        glColor4f(0.180, 0.545, 0.341, 1);
        glutSolidCube(1);
        glColor4f(0,0,0, 1);
        glutWireCube(1.002);
        glColor4f(0,0,0, 1);
        glutWireCube(1.002);
        glColor4f(0,0,0, 1);
        glutWireCube(1.002);
        glColor4f(0,0,0, 1);
        glutWireCube(1.002);

    glPopMatrix();
glPopMatrix();
}

void cashball(){


            if(cashbuffer==1){

                for(int l=0; l<50; l++){
            ctx[l]=((float)(rand()%(5-0 + 1) + 0)/10);
             cty[l]=((float)(rand()%(5-0 + 1) + 0)/10);
            ctz[l]=((float)(rand()%(5-0 + 1) + 0)/10);
             rc[l]=(float)(rand()%(360-1 + 1) + 1);
           rx[l]=(float)(rand()%(1-0 + 1) + 0);
             ry[l]=(float)(rand()%(1-0 + 1) + 0);
             rz[l]=(float)(rand()%(1-0 + 1) + 0);

            }
                cashbuffer=0;
            }


            glPushMatrix();//cash
            glScalef(1.1,1,1);

             glRotatef(r_cashball,0,1,0);


            for(int k=0; k<30; k++){
            /*
            glPushMatrix();
                glTranslatef(ctx[k],cty[k],ctz[k]);
                glRotatef(rc[k],rx[k],ry[k],rz[k]);
                cash();
            glPopMatrix();
            */
            glPushMatrix();
                glTranslatef(-ctx[k],-cty[k],-ctz[k]);
                glRotatef(-rc[k],-rx[k],-ry[k],-rz[k]);
                cash();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(-ctx[k],-cty[k],ctz[k]);
                glRotatef(-rc[k],-rx[k],-ry[k],-rz[k]);
                cash();
            glPopMatrix();
            /*
            glPushMatrix();
                glTranslatef(-ctx[k],cty[k],-ctz[k]);
                glRotatef(-rc[k],-rx[k],-ry[k],-rz[k]);
                cash();
            glPopMatrix();
            */
            glPushMatrix();
                glTranslatef(ctx[k],-cty[k],-ctz[k]);
                glRotatef(-rc[k],-rx[k],-ry[k],-rz[k]);
                cash();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(ctx[k],-cty[k],ctz[k]);
                glRotatef(-rc[k],-rx[k],-ry[k],-rz[k]);
                cash();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(-ctx[k],cty[k],ctz[k]);
                glRotatef(-rc[k],-rx[k],-ry[k],-rz[k]);
                cash();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(ctx[k],cty[k],-ctz[k]);
                glRotatef(-rc[k],-rx[k],-ry[k],-rz[k]);
                cash();
            glPopMatrix();


            }

        glPopMatrix();

        glPushMatrix();
            glRotatef(90,0,0,-1);
            glRotatef(r_cashball,-1,0,0);
            glColor4f(0.722, 0.525, 0.043,1);
              glutWireSphere(1.01,20,5);
            glColor4f(1.000, 0.800, 0.000,0.6);
              glutSolidSphere(1,50,50);
        glPopMatrix();

}

void lifebadge(){

                glRotatef(45,0,0,1);

                    glBegin(GL_POLYGON);
                       glColor4f(1, 0, 1, 1);
                       glVertex3f (-1, 1, 0);
                       glVertex3f (1, 1, 0);
                       glVertex3f (1, -1, 0);
                       glVertex3f (-1, -1, 0);
                    glEnd();
                    glBegin(GL_POLYGON);
                       glColor4f(0.180, 0.545, 0.341, 1);
                       glVertex3f (-0.4, 0.35, 0.002);
                       glVertex3f (0.3, -0.45, 0.002);
                       glVertex3f (-0.25, -1, 0.002);
                       glVertex3f (-1, -1, 0.002);
                       glVertex3f (-1, 0, 0.002);
                    glEnd();
                    glBegin(GL_LINE_LOOP);
                       glColor4f(0.1, 0.1, 0.1, 1);
                       glVertex3f (-0.4, 0.35, 0.0015);
                       glVertex3f (0.3, -0.45, 0.0015);
                       glVertex3f (-0.25, -1, 0.0015);
                       glVertex3f (-1, -1, 0.0015);
                       glVertex3f (-1, 0, 0.0015);
                    glEnd();
                    glBegin(GL_POLYGON);
                       glColor4f(0.180, 0.545, 0.341, 1);
                       glVertex3f (-0.8, 0.475, 0.0015);
                       glVertex3f (-0.6, 0.225, 0.0015);
                       glVertex3f (-1, 0, 0.0015);
                       glVertex3f (-1, 0.4, 0.0015);
                    glEnd();
                    glBegin(GL_POLYGON);
                       glColor4f(0.180, 0.545, 0.341, 1);
                       glVertex3f (-0.25, -1, 0.002);
                       glVertex3f (0.05, -0.7, 0.002);
                       glVertex3f (0.2, -1, 0.002);
                    glEnd();
                    glBegin(GL_POLYGON);
                       glColor4f(1.000, 0.871, 0.678, 1);
                       glVertex3f (-0.25,0.2 , 0.002);
                       glVertex3f (0.175, -0.275, 0.002);
                       glVertex3f (0.35, -0.11, 0.002);
                       glVertex3f (-0.05, 0.35, 0.002);
                    glEnd();
                    glPushMatrix();

                      glColor3f(1,1,1);

                        glTranslatef(-0.9, 0, 0.005);
                        glScalef(0.0035, 0.0035, 0.0);
                        glRotatef(45, 0, 0,-1);
                       glLineWidth(4);
                      char text4[] ="456";
                      for(int i=0; i<strlen(text4); i++){
                          glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, text4[i]);
                      }
                        glLineWidth(1.0);
                    glPopMatrix();
}

void doll(){

glPushMatrix();//head
    glTranslatef(0,1.6,0.1);
    glRotatef(90,0,-1,0);
    glRotated(r_dollhead,0,-1,0);
        glColor4f(0.871, 0.722, 0.529, 1);
         glutWireSphere(0.553,10,10);
        glColor4f(1.000, 0.894, 0.769, 1);
         glutSolidSphere(0.55,30,20);

    glPushMatrix();  //face
        glTranslatef(0.54,0.05,0.2);
        glScalef(0.8,0.7,0.8);
        glRotatef(90,0,1,0);

            glPushMatrix();//eye 1
            glTranslatef(0,0,0);
            glScalef(1,0.5,1);
                glBegin(GL_TRIANGLE_FAN);
                glColor4f(1.000, 0.980, 0.980, 1);
                for(int i=0;i<360;i++)
                {
                    float pi=3.1416;
                    float A=(i*2*pi)/360;
                    float r=0.15;
                    float x = r * cos(A);
                    float y = r * sin(A);
                    glVertex3f(x,y,0);
                }
              glEnd();
              glScalef(1,2,1);
                  glBegin(GL_TRIANGLE_FAN);
                glColor4f(0, 0, 0, 1);
                for(int i=0;i<360;i++)
                {
                    float pi=3.1416;
                    float A=(i*2*pi)/360;
                    float r=0.07;
                    float x = r * cos(A);
                    float y = r * sin(A);
                    glVertex3f(x,y,0.01);
                }
              glEnd();
            glPopMatrix();//eye1 end

            glPushMatrix();//eye 2
            glTranslatef(0.5,0,0);
            glScalef(1,0.5,1);
                glBegin(GL_TRIANGLE_FAN);
                glColor4f(1.000, 0.980, 0.980, 1);
                for(int i=0;i<360;i++)
                {
                    float pi=3.1416;
                    float A=(i*2*pi)/360;
                    float r=0.15;
                    float x = r * cos(A);
                    float y = r * sin(A);
                    glVertex3f(x,y,0);
                }
              glEnd();
              glScalef(1,2,1);
                  glBegin(GL_TRIANGLE_FAN);
                glColor4f(0, 0, 0, 1);
                for(int i=0;i<360;i++)
                {
                    float pi=3.1416;
                    float A=(i*2*pi)/360;
                    float r=0.07;
                    float x = r * cos(A);
                    float y = r * sin(A);
                    glVertex3f(x,y,0.01);
                }
              glEnd();
            glPopMatrix();//eye2 end

            glPushMatrix();//lips
                glTranslatef(0.25,-0.5,-0.05);
                glScalef(1.5,0.5,1);
                    glBegin(GL_TRIANGLE_FAN);
                    glColor4f(0.700, 0.078, 0.235, 1);
                    for(int i=0;i<360;i++)
                    {
                        float pi=3.1416;
                        float A=(i*2*pi)/360;
                        float r=0.15;
                        float x = r * cos(A);
                        float y = r * sin(A);
                        glVertex3f(x,y,0);
                    }
                  glEnd();

                  glScalef(1,0.25,1);
                  glBegin(GL_TRIANGLE_FAN);
                    glColor4f(0.1, 0.1, 0.1, 0.8);
                    for(int i=0;i<360;i++)
                    {
                        float pi=3.1416;
                        float A=(i*2*pi)/360;
                        float r=0.15;
                        float x = r * cos(A);
                        float y = r * sin(A);
                        glVertex3f(x,y,0.01);
                    }
                  glEnd();
                    glTranslatef(0,0,0.001);
                          glBegin(GL_TRIANGLE_FAN);
                    glColor4f(0.1, 0.1, 0.1, 0.8);
                    for(int i=0;i<360;i++)
                    {
                        float pi=3.1416;
                        float A=(i*2*pi)/360;
                        float r=0.16;
                        float x = r * cos(A);
                        float y = r * sin(A);
                        glVertex3f(x,y,0);
                    }
                  glEnd();

            glPopMatrix();//lips end

    glPopMatrix(); //Face END
glPushMatrix();//hair top
    glTranslatef(-0.02,0.01,0);
    glScalef(1.3,1.3,1.3);
    glRotatef(35,0,0,1);
        float angle,length,radius, width,samples, outer, rhair;

          for(int i=0; i<100; i++){
            glPushMatrix();
                    glRotatef(rhair,0,-1,0);
                    glRotatef(5,0,0,1);
                        angle=0;            // starting angle in radians
                        length= 1.8;           // length of arc in radians, >0 6.28319rad=360degree
                        radius=0.5   ;        // inner radius, >0
                        width=0      ;      // width of arc, >0
                        samples =20;   // number of circle samples, >=3

                        outer = radius + width;
                        glBegin( GL_QUAD_STRIP );
                        glColor3f(0.1,0.1,0.1);
                        for( int i = 0; i <= samples; i++ )
                        {
                            float a = angle + ( i / samples ) * length;
                            glVertex3f( radius * cos( a ), radius * sin( a ),0.05  );
                            glVertex3f( outer * cos( a ), outer * sin( a ), -0.05  );
                        }
                        glEnd();
            glPopMatrix();

            rhair+=5;
          }
    glPopMatrix();//hair top

    glPushMatrix();//hair left
    glTranslatef(0,0.03,0.03);
    glScalef(1.2,1.2,1.2);
    glRotatef(35,1,0,0);
    glRotatef(20,0,0,1);
        float angle1,length1,radius1, width1,samples1, outer1, rhair1;

          for(int i=0; i<100; i++){
            glPushMatrix();
                    glRotatef(rhair1,0,-1,0);
                    glRotatef(5,0,0,1);
                        angle1=0;            // starting angle in radians
                        length1= 1.8;           // length of arc in radians, >0 6.28319rad=360degree
                        radius1=0.5   ;        // inner radius, >0
                        width1=0      ;      // width of arc, >0
                        samples1 =50;   // number of circle samples, >=3

                        outer1 = radius1 + width1;
                        glBegin( GL_QUAD_STRIP );
                        glColor3f(0.1,0.1,0.1);
                        for( int i = 0; i <= samples1; i++ )
                        {
                            float a = angle1 + ( i / samples1 ) * length1;
                            glVertex3f( radius1 * cos( a ), radius1 * sin( a ),0.05  );
                            glVertex3f( outer1 * cos( a ), outer1 * sin( a ), -0.05  );
                        }
                        glEnd();
            glPopMatrix();

            rhair1+=5;
          }
    glPopMatrix();//hair left

    glPushMatrix();//hair left
    glTranslatef(0.05,0.01,0.01);
    glScalef(1.2,1.2,1.2);
    glRotatef(35,-1,0,0);
    glRotatef(20,0,0,1);
        float angle2,length2,radius2, width2,samples2, outer2, rhair2;

          for(int i=0; i<100; i++){
            glPushMatrix();
                    glRotatef(rhair2,0,-1,0);
                    glRotatef(5,0,0,1);
                        angle2=0;            // starting angle in radians
                        length2= 1.8;           // length of arc in radians, >0 6.28319rad=360degree
                        radius2=0.5   ;        // inner radius, >0
                        width2=0      ;      // width of arc, >0
                        samples2 =50;   // number of circle samples, >=3

                        outer2 = radius2 + width2;
                        glBegin( GL_QUAD_STRIP );
                        glColor3f(0.1,0.1,0.1);
                        for( int i = 0; i <= samples2; i++ )
                        {
                            float a = angle2 + ( i / samples2 ) * length2;
                            glVertex3f( radius2 * cos( a ), radius2 * sin( a ),0.05  );
                            glVertex3f( outer2 * cos( a ), outer2 * sin( a ), -0.05  );
                        }
                        glEnd();
            glPopMatrix();

            rhair2+=5;
          }
    glPopMatrix();//hair right

    glPushMatrix();
        glTranslatef(-0.66, -0.24, 0.49);
        glRotatef(332,-1,0,0);
        glScalef(0.2,0.2,0.7);
        glColor3f(0.1,0.1,0.1);
        glutSolidCube(1);

    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.66, -0.24, -0.4);
        glRotatef(150,1,0,0);
        glScalef(0.2,0.2,0.7);
        glColor3f(0.1,0.1,0.1);
        glutSolidCube(1);

    glPopMatrix();

glPopMatrix();//head end



glPushMatrix();//shirt
    glTranslatef(0,0,0.05);
    glRotatef(90,1,0,0);
    glScalef(1,0.85,1);
        glColor4f(1.000, 0.471, 0.000,1);
        GLUquadricObj*p = gluNewQuadric();
        gluQuadricDrawStyle(p,GLU_FILL);
        gluCylinder(p, 0.60, 1.0 , 1.25 , 50, 50);
        glColor3f(1.000, 0.271, 0.000);
        GLUquadricObj*y = gluNewQuadric();
        gluQuadricDrawStyle(y,GLU_LINE);
        gluCylinder(y, 0.61, 1.01 , 1.25 , 20, 1);
glPopMatrix();//shirt end

glPushMatrix();//FULL TORSO
    glTranslatef(0,0.53,-0.14);
    glScalef(0.52,0.52,0.6);
            glPushMatrix();//torso fill
                glColor3f(1.000, 0.471, 0.000);
                glPushMatrix();
                    glScalef(1,1,0.7);
                    glTranslatef(0,0,0.4);
                    glColor3f(1.000, 0.471, 0.000);
                    glutSolidCube(2);
             glPopMatrix();


                glBegin(GL_POLYGON);

                    glVertex3f (-1, 0.4, 1.4);
                    glVertex3f (1, 0.4, 1.4);
                    glVertex3f (1, -1, 1);
                    glVertex3f (-1, -1, 1);
                glEnd();
                glBegin(GL_POLYGON);

                    glVertex3f (-1, 0.4, 1.4);
                    glVertex3f (1, 0.4, 1.4);
                    glVertex3f (1, 1, 1);
                    glVertex3f (-1, 1, 1);
                glEnd();

                glBegin(GL_TRIANGLES);
                    glVertex3f (1, 0.4, 1.4);
                    glVertex3f (1, 1, 1);
                    glVertex3f (1, -1, 1);

                glEnd();
                 glBegin(GL_TRIANGLES);
                    glVertex3f (-1, 0.4, 1.4);
                    glVertex3f (-1, 1, 1);
                    glVertex3f (-1, -1, 1);

                glEnd();
                glBegin(GL_POLYGON);
                    glColor3f(1.000, 0.900, 0.000);
                    glVertex3f (-0.75, 0.55, 1.38);
                    glVertex3f (0.75, 0.55, 1.38);
                    glVertex3f (0.75, 1, 1.01);
                    glVertex3f (-0.75, 1, 1.01);
                glEnd();
        glPopMatrix();//torso fill END

        glPushMatrix();//torso Line
            glScalef(1,1,1.01);
                glLineWidth(1);
                glColor3f(1.000, 0.271, 0.000);
                glPushMatrix();
                    glScalef(1,1,0.7);
                    glTranslatef(0,0,0.4);
                    glutWireCube(2);
                glPopMatrix();


                glBegin(GL_LINE_LOOP);

                    glVertex3f (-1, 0.4, 1.4);
                    glVertex3f (1, 0.4, 1.4);
                    glVertex3f (1, -1, 1);
                    glVertex3f (-1, -1, 1);
                glEnd();
                glBegin(GL_LINE_LOOP);

                    glVertex3f (-1, 0.4, 1.4);
                    glVertex3f (1, 0.4, 1.4);
                    glVertex3f (1, 1, 1);
                    glVertex3f (-1, 1, 1);
                glEnd();

                glLineWidth(1);
        glPopMatrix();//torso Line end

glPopMatrix();//FULL TORSO END

glPushMatrix();//left leg whole
        glPushMatrix();
        glTranslatef(-0.4,-1.2,0);
        glScalef(0.8,2.5,0.9);
        glColor3f(1.000, 0.894, 0.769);
            glutSolidCube(0.5);
        glColor3f(0.627, 0.322, 0.176);
            glutWireCube(0.5);
        glPopMatrix();

        glPushMatrix();//left leg socks
        glTranslatef(-0.4,-2.25,0);
        glScalef(0.8,1.75,0.9);
        glColor3f(0.973, 0.973, 1.000);
            glutSolidCube(0.5);
        glColor3f(0.863, 0.863, 0.863);
            glutWireCube(0.5);
        glPopMatrix();//left leg socks

         glPushMatrix();//left shoe
        glTranslatef(-0.4,-2.8,0.13);
        glScalef(0.9,0.5,1.5);
        glColor3f(0.100, 0.100, 0.100);
            glutSolidCube(0.5);
        glColor3f(0,0,0);
            glutWireCube(0.5);
        glPopMatrix();//left shoe


glPopMatrix();//left left whole end

glPushMatrix();//right leg whole
        glPushMatrix();//knee
        glTranslatef(0.4,-1.2,0);
        glScalef(0.8,2.5,0.9);
        glColor3f(1.000, 0.894, 0.769);
            glutSolidCube(0.5);
        glColor3f(0.627, 0.322, 0.176);
            glutWireCube(0.5);
        glPopMatrix();//knee

        glPushMatrix();//right leg socks
        glTranslatef(0.4,-2.25,0);
        glScalef(0.8,1.75,0.9);
        glColor3f(0.973, 0.973, 1.000);
            glutSolidCube(0.5);
        glColor3f(0.863, 0.863, 0.863);
            glutWireCube(0.5);
        glPopMatrix();//right leg socks

         glPushMatrix();//right shoe
        glTranslatef(0.4,-2.8,0.13);
        glScalef(0.9,0.5,1.5);
        glColor3f(0.100, 0.100, 0.100);
            glutSolidCube(0.5);
        glColor3f(0,0,0);
            glutWireCube(0.5);
        glPopMatrix();//right shoe


glPopMatrix();//right leg whole end

glPushMatrix();//left hand full
     glRotatef(10,0,0,-1);
     glTranslatef(0,-0.1,0.1);
        glPushMatrix();//left shoulder
        glTranslatef(-0.77,0.76,0);
        glScalef(0.55,1.1,1.1);

        glColor3f(1.000, 0.900, 0.000);
            glutSolidCube(0.5);
        glColor3f(0.545, 0.271, 0.075);
            glutWireCube(0.5);
        glPopMatrix();//left shoulder

         glPushMatrix();//left arm
        glTranslatef(-0.77,0,0);
        glScalef(0.55,2,1.1);
        //glRotatef(10,0,0,-1);
        glColor3f(1.000, 0.894, 0.769);
            glutSolidCube(0.5);
        glColor3f(0.627, 0.322, 0.176);
            glutWireCube(0.5);
        glPopMatrix();//left arm
glPopMatrix();//left hand full

glPushMatrix();//right hand full
     glRotatef(10,0,0,1);
     glTranslatef(0,-0.1,0.1);
        glPushMatrix();//right shoulder
        glTranslatef(0.77,0.76,0);
        glScalef(0.55,1.1,1.1);

        glColor3f(1.000, 0.900, 0.000);
            glutSolidCube(0.5);
        glColor3f(0.545, 0.271, 0.075);
            glutWireCube(0.5);
        glPopMatrix();//right shoulder

         glPushMatrix();//right arm
        glTranslatef(0.77,0,0);
        glScalef(0.55,2,1.1);
        //glRotatef(10,0,0,-1);
        glColor3f(1.000, 0.894, 0.769);
            glutSolidCube(0.5);
        glColor3f(0.627, 0.322, 0.176);
            glutWireCube(0.5);
        glPopMatrix();//right arm
glPopMatrix();//right hand full

}

void player(){
glPushMatrix();//player full
       glPushMatrix();//torso
            glTranslatef(0,0.9,0);
            glScalef(1,1.25,0.6);
                glPushMatrix();
                    glColor3f(0.180, 0.545, 0.341);
                    glutSolidCube(1);
                    glColor3f(0.000, 0.300, 0.000);
                    glutWireCube(1);
                glPopMatrix();
                glPushMatrix();
                    glBegin(GL_POLYGON);
                    glColor4f(0.100, 0.100, 0.100,0.5);
                    glVertex3f(-0.2,0.5,0.5);
                    glVertex3f(0.2,0.5,0.5);
                    glVertex3f(0.2,-0.5,0.5);
                    glVertex3f(-0.2,-0.5,0.5);
                    glEnd();
                glPopMatrix();
                glPushMatrix();
                    glBegin(GL_POLYGON);
                    glColor4f(1.000, 0.941, 0.961,1);
                    glVertex3f(-0.19,0.49,0.502);
                    glVertex3f(0.19,0.49,0.502);
                    glVertex3f(0.19,-0.49,0.502);
                    glVertex3f(-0.19,-0.49,0.502);
                    glEnd();
                glPopMatrix();
                glPushMatrix();
               glTranslatef(0.35,0.075,-0.502);
                glScalef(0.002, 0.002, 0.002);
                glRotatef(180,0,1,0);
                glLineWidth(3);
                      char text4[] ="456";
                      for(int i=0; i<strlen(text4); i++){
                          glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, text4[i]);
                      }
                        glLineWidth(1.0);
                glPopMatrix();
        glPopMatrix();//torso


        glPushMatrix();//head
            glTranslatef(0,1.75,0.02);
            glScalef(0.7,0.45,0.4);
                glPushMatrix();
                    glColor3f(1.000, 0.871, 0.678);
                    glutSolidCube(1);
                    glColor3f(0.671, 0.622, 0.529);
                    glutWireCube(1);
                glPopMatrix();
                glPushMatrix();//hair
                    //glTranslatef(0,1,0);
                    glBegin(GL_POLYGON);
                    glColor4f(0, 0, 0,1);
                    glVertex3f(-0.5,0.5,0.502);
                    glVertex3f(0.5,0.5,0.502);
                    glVertex3f(0.5,0.15,0.502);
                    glVertex3f(-0.5,0.15,0.502);
                    glEnd();
                    glBegin(GL_POLYGON);
                    glColor4f(0, 0, 0,1);
                    glVertex3f(-0.502,0.5,-0.5);
                    glVertex3f(-0.502,0.5,0.5);
                    glVertex3f(-0.502,0.15,0.5);
                    glVertex3f(-0.502,0.0,-0.5);
                    glEnd();
                    glBegin(GL_POLYGON);
                    glColor4f(0, 0, 0,1);
                    glVertex3f(-0.5,0.5,-0.502);
                    glVertex3f(0.5,0.5,-0.502);
                    glVertex3f(0.5,-0.1,-0.502);
                    glVertex3f(-0.5,-0.1,-0.502);
                    glEnd();
                     glBegin(GL_POLYGON);
                    glColor4f(0, 0, 0,1);
                    glVertex3f(0.502,0.5,-0.5);
                    glVertex3f(0.502,0.5,0.5);
                    glVertex3f(0.502,0.15,0.5);
                    glVertex3f(0.502,0.0,-0.5);
                    glEnd();
                    glBegin(GL_POLYGON);
                    glColor4f(0, 0, 0,1);
                    glVertex3f(-0.50,0.502,0.5);
                    glVertex3f(0.50,0.502,0.5);
                    glVertex3f(0.50,0.502,-0.5);
                    glVertex3f(-0.50,0.502,-0.5);
                    glEnd();
                glPopMatrix();//hair

                glPushMatrix();//face

                    glColor4f(0.1, 0.1, 0.1,1);
                    glBegin(GL_POLYGON);
                    glVertex3f(-0.29,0.1,0.505);
                    glVertex3f(-0.11,0.1,0.505);
                    glVertex3f(-0.11,-0.05,0.505);
                    glVertex3f(-0.29,-0.05,0.505);
                    glEnd();
                    glColor4f(0.1, 0.1, 0.1,1);
                    glBegin(GL_POLYGON);
                    glVertex3f(0.29,0.1,0.505);
                    glVertex3f(0.11,0.1,0.505);
                    glVertex3f(0.11,-0.05,0.505);
                    glVertex3f(0.29,-0.05,0.505);
                    glEnd();
                    glColor4f(0.1, 0.1, 0.1,1);
                    glBegin(GL_POLYGON);
                    glVertex3f(-0.15,-0.25,0.505);
                    glVertex3f(0.15,-0.25,0.505);
                    glVertex3f(0.15,-0.325,0.505);
                    glVertex3f(-0.15,-0.325,0.505);
                    glEnd();
                glPopMatrix();//face
        glPopMatrix();//head


        glPushMatrix();//left hand
         glTranslatef(0.67,1.44,0.04);
            glRotatef(r_lefthand,-1,0,0);//move arm

                glPushMatrix();//left shoulder

                glScalef(0.3,0.6,0.3);
                glTranslatef(0,-0.5,0);
                    glColor3f(0.180, 0.545, 0.341);
                    glutSolidCube(1);
                    glColor3f(0.000, 0.300, 0.000);
                    glutWireCube(1);

                    glBegin(GL_POLYGON);
                    glColor4f(1.000, 0.941, 0.961,1);
                    glVertex3f(0.502,0.49,0.20);
                    glVertex3f(0.502,0.49,-0.20);
                    glVertex3f(0.502,-0.15,-0.20);
                    glVertex3f(0.502,-0.15,0.20);
                    glEnd();

                     glBegin(GL_POLYGON);
                    glColor4f(1.000, 0.941, 0.961,1);
                    glVertex3f(0.49,0.502,0.20);
                    glVertex3f(-0.49,0.502,0.20);
                    glVertex3f(-0.49,0.502,-0.20);
                    glVertex3f(0.49,0.502,-0.20);
                    glEnd();


                glPopMatrix();//left shoulder end

                glPushMatrix();//left arm

                glTranslatef(0,-0.8,0.03);
                glScalef(0.25,0.4,0.3);
                glRotatef(7,-1,0,0);
                    glColor3f(1.000, 0.871, 0.678);
                    glutSolidCube(1);
                    glColor3f(0.671, 0.622, 0.529);
                    glutWireCube(1);
                glPopMatrix();//left arm end

        glPopMatrix();//right hand END


        glPushMatrix();//right hand
         glTranslatef(-0.67,1.44,0.04);
            glRotatef(r_righthand,-1,0,0);//move arm

                glPushMatrix();//right shoulder

                glScalef(0.3,0.6,0.3);
                glTranslatef(0,-0.5,0);
                    glColor3f(0.180, 0.545, 0.341);
                    glutSolidCube(1);
                    glColor3f(0.000, 0.300, 0.000);
                    glutWireCube(1);

                    glBegin(GL_POLYGON);
                    glColor4f(1.000, 0.941, 0.961,1);
                    glVertex3f(-0.502,0.49,0.20);
                    glVertex3f(-0.502,0.49,-0.20);
                    glVertex3f(-0.502,-0.15,-0.20);
                    glVertex3f(-0.502,-0.15,0.20);
                    glEnd();

                     glBegin(GL_POLYGON);
                    glColor4f(1.000, 0.941, 0.961,1);
                    glVertex3f(-0.49,0.502,0.20);
                    glVertex3f(0.49,0.502,0.20);
                    glVertex3f(0.49,0.502,-0.20);
                    glVertex3f(-0.49,0.502,-0.20);
                    glEnd();


                glPopMatrix();//right shoulder end

                glPushMatrix();//right arm

                glTranslatef(0,-0.8,0.03);
                glScalef(0.25,0.4,0.3);
                glRotatef(7,-1,0,0);
                    glColor3f(1.000, 0.871, 0.678);
                    glutSolidCube(1);
                    glColor3f(0.671, 0.622, 0.529);
                    glutWireCube(1);
                glPopMatrix();//left arm end

        glPopMatrix();//right hand END


        glPushMatrix();//left leg
            glTranslatef(0.255,0.325,0.02);
            glRotatef(r_leftleg,-1,0,0);//move leg
                glPushMatrix();//pant

                glTranslatef(0,-0.5,0.02);
                glScalef(0.4,1,0.4);
                     glColor3f(0.180, 0.545, 0.341);
                    glutSolidCube(1);
                    glColor3f(0.000, 0.300, 0.000);
                    glutWireCube(1);

                    glBegin(GL_POLYGON);
                    glColor4f(1.000, 0.941, 0.961,1);
                    glVertex3f(0.502,0.49,0.20);
                    glVertex3f(0.502,0.49,-0.20);
                    glVertex3f(0.502,-0.49,-0.20);
                    glVertex3f(0.502,-0.49,0.20);
                glEnd();
                glPopMatrix();//pant

                glPushMatrix();//shoe

                glTranslatef(0,-1.1,0.09);
                glScalef(0.4,0.2,0.55);
                     glColor3f(1.000, 0.941, 0.961);
                    glutSolidCube(1);
                    glColor3f(0.100, 0.100, 0.100);
                    glutWireCube(1);

                glPopMatrix();
        glPopMatrix();//left leg




        glPushMatrix();//right leg
            glTranslatef(-0.255,0.325,0.02);
            glRotatef(r_rightleg,-1,0,0);//move leg
                glPushMatrix();//rightpant

                glTranslatef(0,-0.5,0.02);
                glScalef(0.4,1,0.4);
                     glColor3f(0.180, 0.545, 0.341);
                    glutSolidCube(1);
                    glColor3f(0.000, 0.300, 0.000);
                    glutWireCube(1);

                    glBegin(GL_POLYGON);
                    glColor4f(1.000, 0.941, 0.961,1);
                    glVertex3f(-0.502,0.49,0.20);
                    glVertex3f(-0.502,0.49,-0.20);
                    glVertex3f(-0.502,-0.49,-0.20);
                    glVertex3f(-0.502,-0.49,0.20);
                glEnd();
                glPopMatrix();//rightpant

                glPushMatrix();//rightshoe

                glTranslatef(0,-1.1,0.09);
                glScalef(0.4,0.2,0.55);
                     glColor3f(1.000, 0.941, 0.961);
                    glutSolidCube(1);
                    glColor3f(0.100, 0.100, 0.100);
                    glutWireCube(1);

                glPopMatrix();//rightshoe
        glPopMatrix();//right leg

glPopMatrix();
}

void guard(){

glPushMatrix();//guard full
       glPushMatrix();//torso
            glTranslatef(0,0.9,0);
            glScalef(1,1.25,0.6);
                glPushMatrix();
                    glColor3f(0.900, 0.000, 0.900);
                    glutSolidCube(1);
                    glColor3f(0.1, 0.1, 0.1);
                    glutWireCube(1);
                glPopMatrix();
                glPushMatrix();
                    glBegin(GL_POLYGON);
                    glColor4f(0.100, 0.100, 0.100,0.9);
                    glVertex3f(-0.03,0.5,0.55);
                    glVertex3f(0.03,0.5,0.55);
                    glVertex3f(0.03,-0.5,0.55);
                    glVertex3f(-0.03,-0.5,0.55);
                    glEnd();
                glPopMatrix();

        glPopMatrix();//torso


        glPushMatrix();//gun

            glRotatef(20,0,0,-1);
            glTranslatef(-0.3,0,0);
        glTranslatef(0,1,0.5);
            glPushMatrix();
            glScalef(0.8,0.1,0.1);
                glColor3f(0.1, 0.1, 0.1);
                glutSolidCube(1);
                glColor3f(0.5, 0.5, 0.5);
                glutWireCube(1);
            glPopMatrix();
            glPushMatrix();
             glTranslatef(-0.05,-0.11,0);
            glScalef(0.07,0.3,0.07);
            glRotatef(20,0,0,-1);
                glColor3f(0.1, 0.1, 0.1);
                glutSolidCube(1);
                glColor3f(0.5, 0.5, 0.5);
                glutWireCube(1);
            glPopMatrix();
            glPushMatrix();
             glTranslatef(0.17,-0.11,0);
            glScalef(0.07,0.3,0.07);

                glColor3f(0.1, 0.1, 0.1);
                glutSolidCube(1);
                glColor3f(0.5, 0.5, 0.5);
                glutWireCube(1);
            glPopMatrix();
        glPopMatrix();//gun end

        glPushMatrix();//head
            glTranslatef(0,1.75,0.02);
            glScalef(0.7,0.45,0.4);
                glPushMatrix();
                    glColor3f(0.1, 0.1, 0.1);
                    glutSolidCube(1);
                    glColor3f(0.1, 0.1, 0.1);
                    glutWireCube(1);
                glPopMatrix();
                glPushMatrix();//hair
                    //glTranslatef(0,1,0);

                    glBegin(GL_POLYGON);
                    glColor3f(0.900, 0.000, 0.900);
                    glVertex3f(-0.502,0.5,-0.5);
                    glVertex3f(-0.502,0.5,0.65);
                    glVertex3f(-0.502,-0.5,0.65);
                    glVertex3f(-0.502,-0.5,-0.5);
                    glEnd();
                    glBegin(GL_POLYGON);
                    glColor3f(0.900, 0.000, 0.900);
                    glVertex3f(-0.5,0.5,-0.502);
                    glVertex3f(0.5,0.5,-0.502);
                    glVertex3f(0.5,-0.5,-0.502);
                    glVertex3f(-0.5,-0.5,-0.502);
                    glEnd();
                     glBegin(GL_POLYGON);
                    glColor3f(0.900, 0.000, 0.900);
                    glVertex3f(0.502,0.5,-0.5);
                    glVertex3f(0.502,0.5,0.65);
                    glVertex3f(0.502,-0.5,0.65);
                    glVertex3f(0.502,-0.5,-0.5);
                    glEnd();
                    glBegin(GL_POLYGON);
                    glColor3f(0.900, 0.000, 0.900);
                    glVertex3f(-0.50,0.502,0.65);
                    glVertex3f(0.50,0.502,0.65);
                    glVertex3f(0.50,0.502,-0.5);
                    glVertex3f(-0.50,0.502,-0.5);
                    glEnd();
                glPopMatrix();//hair

                glPushMatrix();//face
                    glLineWidth(2);
                    glColor4f(0.9, 0.9, 0.9,1);
                    glBegin(GL_LINE_LOOP);
                    glVertex3f(0,0.25,0.55);
                    glVertex3f(0.2,-0.25,0.55);
                    glVertex3f(-0.2,-0.25,0.55);

                    glEnd();
                    glLineWidth(1);
                glPopMatrix();//face
        glPopMatrix();//head


        glPushMatrix();//right hand
         glTranslatef(-0.67,1.44,0.04);


                glPushMatrix();//right shoulder
                glRotatef(40,-1,0,0);
                glScalef(0.3,0.6,0.3);
                glTranslatef(0,-0.5,0);
                    glColor3f(0.900, 0.000, 0.900);
                    glutSolidCube(1);
                    glColor3f(0.1, 0.1, 0.1);
                    glutWireCube(1);
                glPopMatrix();//right shoulder end

                glTranslatef(-0.56,-0.85,0.45);//arm rotate for grabing gun
                glRotatef(120,0,0,1);//arm rotate for grabing gun

                glPushMatrix();//right arm

                glTranslatef(0,-0.85,0.03);
                glScalef(0.25,0.5,0.3);
                glRotatef(7,-1,0,0);
                     glColor3f(0.900, 0.000, 0.900);
                    glutSolidCube(1);
                    glColor3f(0.1, 0.1, 0.1);
                    glutWireCube(1);
                     glTranslatef(0,-0.36,0);
                    glScalef(1.02,0.3,1.02);
                     glBegin(GL_POLYGON);
                    glColor3f(0.1, 0.1, 0.1);
                    glutSolidCube(1);
                    glColor3f(0.5, 0.5, 0.5);
                    glutWireCube(1);
                    glEnd();
                glPopMatrix();//right arm end

        glPopMatrix();//right hand END


            glPushMatrix();//left hand

         glTranslatef(0.67,1.44,0.04);
            glRotatef(30,-1,0,0);

                glPushMatrix();//left shoulder

                glScalef(0.3,0.6,0.3);
                glTranslatef(0,-0.5,0);
                    glColor3f(0.900, 0.000, 0.900);
                    glutSolidCube(1);
                    glColor3f(0.1, 0.1, 0.1);
                    glutWireCube(1);
                glPopMatrix();//left shoulder end

                 glTranslatef(0.76,-0.6,-0.01);//arm rotate for grabing gun
                glRotatef(80,0,0,-1);//arm rotate for grabing gun

                glPushMatrix();//left arm

                glTranslatef(0,-0.85,0.03);
                glScalef(0.25,0.5,0.3);

                     glColor3f(0.900, 0.000, 0.900);
                    glutSolidCube(1);
                    glColor3f(0.1, 0.1, 0.1);
                    glutWireCube(1);
                     glTranslatef(0,-0.36,0);
                    glScalef(1.02,0.3,1.02);
                     glBegin(GL_POLYGON);
                    glColor3f(0.1, 0.1, 0.1);
                    glutSolidCube(1);
                    glColor3f(0.5, 0.5, 0.5);
                    glutWireCube(1);
                    glEnd();
                glPopMatrix();//left arm end

        glPopMatrix();//left hand END



        glPushMatrix();//left leg
            glTranslatef(0.255,0.325,0.02);
            glRotatef(0,-1,0,0);
                glPushMatrix();//pant

                glTranslatef(0,-0.5,0.02);
                glScalef(0.4,1,0.4);
                     glColor3f(0.900, 0.000, 0.900);
                    glutSolidCube(1);
                    glColor3f(0.1, 0.1, 0.1);
                    glutWireCube(1);

                glPopMatrix();//pant

                glPushMatrix();//shoe

                glTranslatef(0,-1.1,0.09);
                glScalef(0.4,0.2,0.55);
                    glColor3f(0.1, 0.1, 0.1);
                    glutSolidCube(1);
                    glColor3f(0.5, 0.5, 0.5);
                    glutWireCube(1);

                glPopMatrix();
        glPopMatrix();//left leg




        glPushMatrix();//right leg
            glTranslatef(-0.255,0.325,0.02);
            glRotatef(0,-1,0,0);
                glPushMatrix();//rightpant

                glTranslatef(0,-0.5,0.02);
                glScalef(0.4,1,0.4);
                     glColor3f(0.900, 0.000, 0.900);
                    glutSolidCube(1);
                    glColor3f(0.1, 0.1, 0.1);
                    glutWireCube(1);

                glEnd();
                glPopMatrix();//rightpant

                glPushMatrix();//rightshoe

                glTranslatef(0,-1.1,0.09);
                glScalef(0.4,0.2,0.55);
                     glColor3f(0.1, 0.1, 0.1);
                    glutSolidCube(1);
                    glColor3f(0.5, 0.5, 0.5);
                    glutWireCube(1);

                glPopMatrix();//rightshoe
        glPopMatrix();//right leg

glPopMatrix();
//guard end
}

void updatemix(int value){
if(displaying==3){
    if(rotatehead==-1){
        if(r_dollhead<180){
            r_dollhead+=10;
        }
    }
    if(rotatehead==1){
        if(r_dollhead>0){
            r_dollhead-=10;
        }

    }



    if(manz <-8.3){
        win=1;
    }


     if(clz<30){

        clz += 0.02;
    }else{
       clz=-30;
    }

      if(clz2<15){

        clz2 += 0.02;
    }else{
       clz2=-60;
    }

}



    if(r_cashball>360){
        r_cashball=0;
    }else{
    r_cashball+=0.5;
    }
glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in n milliseconds
	glutTimerFunc(1000/60, updatemix, 0);

}

void loadingbgm(int value){

    if(displaying==3 && loading==1){
        loadtimer=10100;
	sndPlaySound("loading.wav",SND_ASYNC|SND_LOOP);
    }
glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in n milliseconds
glutTimerFunc(loadtimer, loadingbgm, 0);
}


void startcountdown(int value){
if(displaying==3 && loading==0){
if(startcount>=0){

    startcount--;
    cout<<startcount<<endl;
}
}
glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in n milliseconds
glutTimerFunc(1250, startcountdown, 0);
}

void timerclockupdate(int value){
if(displaying==3){
    //minute
    if(eliminate!=1 && startcount<0 && win!=1){
    if(second>0){
        second--;
    }
    }

    if(second<=0 && manz>-0.83){
        eliminate=1;
        cout<<"TimerELIMINATED: "<<eliminate<<endl;

    }
}
glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in n milliseconds
glutTimerFunc(1000, timerclockupdate, 0);
}

void updateredgreenlight(int value){

      float random=0;
      if(displaying==3){
       int lower, higher;
       int tim;
      if (manz<0){
        lower= 3, higher =5;
      }else if (manz<4 && manz>0){
        lower= 2, higher =4;
      }else if (manz<=8 && manz>4){
         lower= 2, higher =3;
      }


        if(eliminate!=1 && win!=1 && startcount<0){
            random = ((rand() % (higher-lower+1))+lower);
                tim=random;
            random = (random/10);
            cout<<random<<endl;


            if(red==0 && green==1){
                green =0;
                red=1;
                manpos=manz;
                rotatehead=1;
                cout<<"red light"<<endl;

            }else if (red==1 && green==0){
                green =1;
                red=0;
                rotatehead=-1;
                cout<<"green light"<<endl;
                if(fail==1){
                   fail=0;
                   cout<<"fail: "<<fail<<endl;
                   life++;
                    cout<<"life minus: "<<life<<endl;
                }
            }

            if(tim == 2 && green == 1){
            cout<<"play2"<<endl;
            sndPlaySound("doll2.wav",SND_ASYNC);

            }
            if(tim == 3 && green == 1){
            cout<<"play3"<<endl;
            sndPlaySound("doll3.wav",SND_ASYNC);
            }
            if(tim == 4 && green == 1){
            cout<<"play4"<<endl;
            sndPlaySound("doll4.wav",SND_ASYNC);
            }
            if(tim == 5 && green == 1){
            cout<<"play5"<<endl;
            sndPlaySound("doll5.wav",SND_ASYNC);
            }



        }

}

	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in n milliseconds
	glutTimerFunc(1000/random, updateredgreenlight, 0);

}

void gunshot(int value){
if(displaying==3){
    if(eliminate==1 && gunshots==0){

        sndPlaySound("Sniper.wav",SND_ASYNC);
        gunshots=1;
    }
}
    glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in n milliseconds
	glutTimerFunc(3000, gunshot, 0);
}

void upbutton(int value){
if(displaying==3){
if(eliminate!=1 && fail!=1 && startcount<0){
    if(moving==1){
        moving=0;

    }
}
}
glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in n milliseconds
	glutTimerFunc(0500, upbutton, 0);
}

void pinkblinkeliminate(int value){

    if(displaying==3){
    if(eliminate==1 && pinkblinkcount<7){

        if(pinkblink==0.5){
            pinkblink=0;
            //cout<<"Pinkblink 0: "<<pinkblink<<endl;
            pinkblinkcount++;
        }else if(pinkblink==0){
            pinkblink=0.5;
            //cout<<"Pinkblink 0.5"<<pinkblink<<endl;
            pinkblinkcount++;
        }

    }
    }
    glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in n milliseconds
	glutTimerFunc(0500, pinkblinkeliminate, 0);
}

void updatelife(int value){

    if(displaying==3){
          if((red==1) && (manpos!=manz))
          {
              fail=1;


          }
    }
glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in n milliseconds
	glutTimerFunc(1000/60, updatelife, 0);
}

void eliminated(int value){

if(displaying==3){
          if(life>2){
          eliminate=1;

          //cout<<"ELIMINATED: "<<eliminate<<endl;
          }
}
    glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in n milliseconds
	glutTimerFunc(1000/60, eliminated, 0);

}

void keymoveman(int key, int x, int y){

if(displaying==3){
    if(eliminate!=1 && fail!=1 && startcount<0){
       switch(key){
        case GLUT_KEY_UP:
            moving=1;
            manz-=0.025;
            if(stateg==0){
                if(r_lefthand<60){
                    r_lefthand+=8;
                }else{
                stateg=1;
                }

                  if(r_righthand>-60){
                    r_righthand-=8;
                }else{
                stateg=1;
                }

                  if(r_leftleg>-30){
                    r_leftleg-=4;
                }else{
                stateg=1;
                }

                if(r_rightleg<30){
                    r_rightleg+=4;
                }else{
                stateg=1;
                }


            }else{
                if(r_lefthand>-60){
                    r_lefthand-=8;
                }else{
                stateg=0;
                }

                if(r_righthand<60){
                r_righthand+=8;
                }else{
                stateg=0;
                }

                if(r_leftleg<30){
                r_leftleg+=4;
                }else{
                stateg=0;
                }

                  if(r_rightleg>-30){
                    r_rightleg-=4;
                }else{
                stateg=0;
                }

            }
            cout<<manz<<endl;
            glutPostRedisplay();


        break;


        default:

        break;
       }
    }
  }
}


/* *******************************************************************
**************************GAME FUNCTIONS***************************
******************************************************************* */


/* *******************************************************************
**************************MENU FUNCTIONS***************************
******************************************************************* */
void mainmenu() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	glTranslatef(0.0, 0.0, -4.6); //Move forward 5 units


glPushMatrix();//lookat

  gluLookAt(panx,0,panz,  0,0,0,  0,1,0);
  glTranslatef(movex,0,movez);

    glPushMatrix();
       room();
    glPopMatrix();


glPushMatrix();
     glTranslatef(0,1.2,-0.5);
     glScalef(0.5, 0.5 , 0.5);
    cashball();

glPopMatrix();

glPopMatrix();//lookat end


glPushMatrix();
       lobbyui();
glPopMatrix();



glutSwapBuffers();
}

void lobbyui(){
glPushMatrix();//lobbysymbols
     glTranslatef(0,0,3);
     glScalef(0.225, 0.225 , 1);

       glPushMatrix();//square
                glTranslatef(1.25,0,0);
                //glRotatef(90, 0 , 0, 1);
                glLineWidth(5);
                 glBegin(GL_LINE_LOOP);
                    glColor3f(1.0, 1.0, 1.0);
                     glVertex3f (-0.5, -0.5, 0.0);
                     glVertex3f (0.5, -0.5, 0.0);
                     glVertex3f (0.5, 0.5, 0.0);
                     glVertex3f (-0.5, 0.5, 0.0);
                 glEnd();
                 glLineWidth(1);
        glPopMatrix();

        glPushMatrix();//triangle
            glLineWidth(5);
             glBegin(GL_LINE_LOOP);
                glColor3f(1.0, 0.0, 1.0);
                 glVertex3f (-0.5, -0.5, 0.0);
                 glVertex3f (0.5, -0.5, 0.0);
                 glVertex3f (0, 0.5, 0.0);
             glEnd();
            glLineWidth(1);
        glPopMatrix();

        glPushMatrix();//circle
            glLineWidth(5);
             glTranslatef(-1.25, 0.0, 0.0);
             glBegin(GL_LINE_LOOP);
             glColor3f(1.0, 1.0, 1.0);
                for(int i=0;i<360;i++)
                {
                    float pi=3.1416;
                    float A=(i*2*pi)/360;
                    float r=0.5;
                    float x = r * cos(A);
                    float y = r * sin(A);
                    glVertex3f(x,y,0);
                }
              glEnd();
              glLineWidth(1);
        glPopMatrix();

        glPushMatrix(); // symbol box violet
        glTranslatef(0,0,-0.01);
             glBegin(GL_POLYGON);
                glColor4f(0.098, 0.098, 0.439, 0.4);
                 glVertex3f (-2.5, -1, 0.0);
                 glVertex3f (2.5, -1, 0.0);
                 glVertex3f (2.5, 1, 0.0);
                 glVertex3f (-2.5, 1, 0.0);
             glEnd();
        glPopMatrix();
        glPushMatrix(); // symbol box black
             glBegin(GL_POLYGON);
                glColor4f(0.000, 0.000, 0.000, 0.4);
                 glVertex3f (-2.5, -1, 0.0);
                 glVertex3f (2.5, -1, 0.0);
                 glVertex3f (2.5, 1, 0.0);
                 glVertex3f (-2.5, 1, 0.0);
             glEnd();
        glPopMatrix();
        glPushMatrix();

                      glColor3f(1,1,1);
                        glTranslatef(2.5, -2.5, 0.01);
                        glScalef(0.001, 0.001, 0.0);


                       glLineWidth(1.5);
                      char text[] ="by ASHIQUR RAHMAN 18-38779-3";
                      for(int i=0; i<strlen(text); i++){
                          glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, text[i]);
                      }
                        glLineWidth(1.0);
        glPopMatrix();
glPopMatrix();//lobbysymbol end



glPushMatrix();
        glColor4f(1.0, 0.0, 0.0, pressxalpha);
        //glScalef(1,1,1);
        glTranslatef(-0.25, -0.4, 3);
        glRasterPos3f(0, 0, 0);

          char txt1[]="PRESS X TO START THE GAME";
          for( int i=0; i<strlen(txt1); i++){
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, txt1[i]);
          }
glPopMatrix();



}

void room(){

    glPushMatrix();//whole room
      glScalef(1,1,1.25);

       /*
        glPushMatrix();
           glTranslatef(0,1.2 ,-1);
           // glRotatef(90, 0 , 1, 0);
           glScalef(0.8, 0.8 , 0.8);
               ball();
        glPopMatrix();
       */
        glPushMatrix();// whole left wall
            glTranslatef(-3.5,0 ,-1);
            glRotatef(90, 0 , 1, 0);
            glScalef(2.5, 1.5 , 1);

                    glPushMatrix();//placing art on left wall

                         glTranslatef(-0.2, -0.2 ,0.02);
                         glScalef(0.25, 0.4 , 1);
                        leftwallart();
                    glPopMatrix();//placing art on left wall end

                    glPushMatrix();//horizontal line on left wall
                        glTranslatef(0, 0 ,0);
                        glLineWidth(2);
                        glBegin(GL_LINES);
                        glColor4f(0.000, 0.000, 0.000, 0.85);
                         glVertex3f (-2, -0.25, 0.0);
                         glVertex3f (2, -0.25, 0.0);
                         glEnd();
                         glLineWidth(1);
                    glPopMatrix();//horizontal line on left wall END

                    glPushMatrix();//surface of left wall
                           glTranslatef(0, 0 ,-0.02);

                            glBegin(GL_POLYGON);

                                glColor3f(0.863, 0.863, 0.863);
                                 glVertex3f (1.98, -0.98, 0.0);
                                 glVertex3f (-1.98, -0.98, 0.0);
                                 glVertex3f (-1.98, 0.98, 0.0);
                                 glVertex3f (1.98, 0.98, 0.0);
                             glEnd();
                    glPopMatrix();// surface of left wall END

                    glPushMatrix();//black borderof left wall
                         glTranslatef(0, 0 ,-0.03);
                         glScalef(1.02, 1.02 , 1);
                         glBegin(GL_POLYGON);
                             glColor4f(0.000, 0.000, 0.000, 0.85);
                             glVertex3f (2, -1, 0.0);
                             glVertex3f (-2, -1, 0.0);
                             glVertex3f (-2, 1, 0.0);
                             glVertex3f (2, 1, 0.0);
                         glEnd();

                   glPopMatrix();//black borderof left wall END


        glPopMatrix(); //whole leftwall end


        glPushMatrix();// whole right wall
            glTranslatef(3.5,0 ,-1);
             glRotatef(90, 0 , 1, 0);
             glScalef(2.5, 1.5 , -1);

                    glPushMatrix();//placing art on right wall
                         glTranslatef(-0.25, -0.5 ,0.02);
                         glScalef(0.4, 0.5 , 1);
                         rightwallart();
                    glPopMatrix();//placing art on right wall end


                    glPushMatrix();//horizontal line on right wall
                        glTranslatef(0, 0 ,0);
                        glLineWidth(2);
                        glBegin(GL_LINES);
                        glColor4f(0.000, 0.000, 0.000, 0.85);
                         glVertex3f (-2, -0.25, 0.0);
                         glVertex3f (2, -0.25, 0.0);
                         glEnd();
                         glLineWidth(1);
                    glPopMatrix();//horizontal line on right wall END

                    glPushMatrix();//surface of right wall
                           glTranslatef(0, 0 ,-0.02);

                            glBegin(GL_POLYGON);

                                glColor3f(0.863, 0.863, 0.863);
                                 glVertex3f (1.98, -0.98, 0.0);
                                 glVertex3f (-1.98, -0.98, 0.0);
                                 glVertex3f (-1.98, 0.98, 0.0);
                                 glVertex3f (1.98, 0.98, 0.0);
                             glEnd();
                    glPopMatrix();// surface of right wall END

                    glPushMatrix();//black border of right wall
                         glTranslatef(0, 0 ,-0.03);
                         glScalef(1.02, 1.02 , 1);
                         glBegin(GL_POLYGON);
                             glColor4f(0.000, 0.000, 0.000, 0.85);
                             glVertex3f (2, -1, 0.0);
                             glVertex3f (-2, -1, 0.0);
                             glVertex3f (-2, 1, 0.0);
                             glVertex3f (2, 1, 0.0);
                         glEnd();

                   glPopMatrix();//black border of right wall END


        glPopMatrix(); //whole right wall end

        glPushMatrix();// whole middle wall
              glTranslatef(0,0 ,-6);
             //glRotatef(90, 0 , 1, 0);
             glScalef(2, 1.5 , 1);

                    glPushMatrix();//placing art on middle wall
                         glTranslatef(-0.2, 0.1 ,0.1);
                         glScalef(0.3, 0.3 , 1);
                         middlewallsquidgame();
                    glPopMatrix();//placing art on middle wall end

                    glPushMatrix();//placing gate on middle wall
                         glTranslatef(0, -1 ,0.05);
                         glScalef(0.35, 0.35 , 1);
                         middlewallgate();
                    glPopMatrix();//placing gate on middle wall end

                    glPushMatrix();//horizontal line on middle wall
                        glTranslatef(0, 0 ,0);
                        glLineWidth(2);
                        glBegin(GL_LINES);
                        glColor4f(0.000, 0.000, 0.000, 0.85);
                         glVertex3f (-2, -0.25, 0.0);
                         glVertex3f (2, -0.25, 0.0);
                         glEnd();
                         glLineWidth(1);
                    glPopMatrix();//horizontal line on middle wall END

                    glPushMatrix();//surface of middle wall
                           glTranslatef(0, 0 ,-0.02);

                            glBegin(GL_POLYGON);

                                glColor3f(0.863, 0.863, 0.863);
                                 glVertex3f (1.98, -0.98, 0.0);
                                 glVertex3f (-1.98, -0.98, 0.0);
                                 glVertex3f (-1.98, 0.98, 0.0);
                                 glVertex3f (1.98, 0.98, 0.0);
                             glEnd();
                    glPopMatrix();// surface of middle wall END

                    glPushMatrix();//black border of middle wall
                         glTranslatef(0, 0 ,-0.03);
                         glScalef(1.02, 1.02 , 1);
                         glBegin(GL_POLYGON);
                             glColor4f(0.000, 0.000, 0.000, 0.85);
                             glVertex3f (2, -1, 0.0);
                             glVertex3f (-2, -1, 0.0);
                             glVertex3f (-2, 1, 0.0);
                             glVertex3f (2, 1, 0.0);
                         glEnd();

                   glPopMatrix();//black border of middle wall END


        glPopMatrix(); //whole middle wall end

        glPushMatrix();// whole ceiling
             glTranslatef(0,1.6 ,-4);
             glRotatef(90, 1 , 0, 0);
             glScalef(1.9, 6.5 , 1);


                    glPushMatrix();//surface of ceiling
                           glTranslatef(0, 0 ,-0.02);

                            glBegin(GL_POLYGON);

                                glColor3f(0.000, 0.502, 0.502);
                                 glVertex3f (1.98, -0.98, 0.0);
                                 glVertex3f (-1.98, -0.98, 0.0);
                                 glVertex3f (-1.98, 0.98, 0.0);
                                 glVertex3f (1.98, 0.98, 0.0);
                             glEnd();
                    glPopMatrix();// surface of ceiling END

                    glPushMatrix();//black border of ceiling
                         glTranslatef(0, 0 ,-0.03);
                         glScalef(1.02, 1.02 , 1);
                         glBegin(GL_POLYGON);
                             glColor4f(0.000, 0.000, 0.000, 0.85);
                             glVertex3f (2, -1, 0.0);
                             glVertex3f (-2, -1, 0.0);
                             glVertex3f (-2, 1, 0.0);
                             glVertex3f (2, 1, 0.0);
                         glEnd();

                   glPopMatrix();//black border of ceiling END


        glPopMatrix(); //whole ceiling end

        glPushMatrix();// whole floor

                glTranslatef(0,-1.7 ,-4);
                 glRotatef(90, -1 , 0, 0);
                 glScalef(2.4, 6.7 , 1);

                    glPushMatrix();//surface of floor
                           glTranslatef(0, 0 ,-0.02);

                            glBegin(GL_POLYGON);

                                glColor3f(0.412, 0.412, 0.412);
                                 glVertex3f (1.98, -0.98, 0.0);
                                 glVertex3f (-1.98, -0.98, 0.0);
                                 glVertex3f (-1.98, 0.98, 0.0);
                                 glVertex3f (1.98, 0.98, 0.0);
                             glEnd();
                    glPopMatrix();// surface of floor END

                    glPushMatrix();//black border of floor
                         glTranslatef(0, 0 ,-0.03);
                         glScalef(1.02, 1.02 , 1);
                         glBegin(GL_POLYGON);
                             glColor4f(0.000, 0.000, 0.000, 0.85);
                             glVertex3f (2, -1, 0.0);
                             glVertex3f (-2, -1, 0.0);
                             glVertex3f (-2, 1, 0.0);
                             glVertex3f (2, 1, 0.0);
                         glEnd();

                   glPopMatrix();//black border of floor END


        glPopMatrix(); //whole floor end

    glPopMatrix();//whole room end

}

void rightwallart(){

glPushMatrix();//bodies

   glTranslatef(-0.4, 1.1 , 0 );
   glScalef(0.65, 0.65 ,0);

   glPushMatrix();//man1
   glTranslatef(-1, 0.05 , 0 );
   glScalef(1.05, 1.05, 0);
     glPushMatrix();// hand arm man1
     glTranslatef(-0.11, -0.02, 0);
     glRotatef(50, 0 , 0, 1);
       glBegin(GL_POLYGON);
         glColor4f(0.000, 0.000, 0.000, 0.8);
        glVertex3f(-0.2, 0, 0);
        glVertex3f(0.02, 0, 0);
        glVertex3f(0.02, 0.1, 0);
        glVertex3f(-0.2, 0.1, 0);
       glEnd();
    glPopMatrix();
    glPushMatrix();//hand man1
            glRotatef(30, 0 , 0, -1);
            glTranslatef(0.1, -0.3, 0);

             glBegin(GL_POLYGON);
                glColor4f(0.000, 0.000, 0.000, 0.85);
                glVertex3f(-0.2, 0, 0);
              glVertex3f(0.05, 0, 0);
              glVertex3f(0.05, 0.1, 0);
              glVertex3f(-0.2, 0.1, 0);

          glEnd();
    glPopMatrix();

    glPushMatrix();//ciclehead
        //glTranslatef(-1.15, 1.2, 0);
        glBegin(GL_TRIANGLE_FAN);
         glColor4f(0.000, 0.000, 0.000, 0.85);
            for(int i=0;i<360;i++)
            {
                float pi=3.1416;
                float A=(i*2*pi)/360;
                float r=0.15;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex3f(x,y,0);
            }
          glEnd();
    glPopMatrix();

    glPushMatrix();//torso man1
        glTranslatef(0.05, 0, 0);
        glRotatef(15, 0 , 0, 1);
         glBegin(GL_POLYGON);
            glColor4f(0.000, 0.000, 0.000, 0.85);
          glVertex3f(-0.125, -0.15, 0);
          glVertex3f(0.125, -0.15, 0);
          glVertex3f(0.120, -0.70, 0);
          glVertex3f(-0.125, -0.70, 0);
          glEnd();
    glPopMatrix();

    glPushMatrix();//leg man1
        glTranslatef(0.250, 0, 0);
        //glRotatef(15, 0 , 0, 1);
         glBegin(GL_POLYGON);
            glColor4f(0.000, 0.000, 0.000, 0.85);
          glVertex3f(-0.09, -0.70, 0);
          glVertex3f(0.05, -0.70, 0);
          glVertex3f(0.02, -1.3, 0);
          glVertex3f(-0.09, -1.3, 0);
          glEnd();
    glPopMatrix();
    glPopMatrix();//man1
// MAN 2
   glPushMatrix();//man2
    glTranslatef(1, 0 , 0);
    glPushMatrix();// hand1 arm man2
     glTranslatef(-0.3, -0.45, 0);
     glRotatef(10, 0 , 0, -1);
       glBegin(GL_POLYGON);
        glColor4f(0.000, 0.000, 0.000, 0.85);
        glVertex3f(-0.25, 0, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0.1, 0);
        glVertex3f(-0.25, 0.1, 0);

       glEnd();
    glPopMatrix();
    glPushMatrix();//hand1 bicep man2
       glTranslatef(-0.07, -0.3, 0);
          glRotatef(30, 0 , 0, 1);
             glBegin(GL_POLYGON);
                glColor4f(0.000, 0.000, 0.000, 0.85);
                glVertex3f(-0.25, 0, 0);
              glVertex3f(0.0, 0, 0);
              glVertex3f(0.0, 0.1, 0);
              glVertex3f(-0.25, 0.1, 0);

          glEnd();
    glPopMatrix();
     glPushMatrix();// hand2 arm man2
     glTranslatef(0.5, -0.45, 0);
     glRotatef(10, 0 , 0, -1);
       glBegin(GL_POLYGON);
        glColor4f(0.000, 0.000, 0.000, 0.85);
        glVertex3f(-0.25, 0, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0.1, 0);
        glVertex3f(-0.25, 0.1, 0);

       glEnd();
    glPopMatrix();
    glPushMatrix();//hand2 bicep man2
      glTranslatef(0.3, -0.4, 0);
          glRotatef(30, 0 , 0, -1);
             glBegin(GL_POLYGON);
                glColor4f(0.000, 0.000, 0.000, 0.85);
                glVertex3f(-0.25, 0, 0);
              glVertex3f(0.0, 0, 0);
              glVertex3f(0.0, 0.1, 0);
              glVertex3f(-0.25, 0.1, 0);

          glEnd();
    glPopMatrix();

    glPushMatrix();//torso man2
        glTranslatef(0, -0.70, 0);
        //glRotatef(2, 0 , 0, 1);
         glBegin(GL_POLYGON);
          glColor4f(0.000, 0.000, 0.000, 0.85);
          glVertex3f(-0.125, 0, 0);
          glVertex3f(0.125, 0, 0);
          glVertex3f(0.125, 0.55, 0);
          glVertex3f(-0.125, 0.55, 0);
          glEnd();
    glPopMatrix();

    glPushMatrix();//leg1up man2
        glTranslatef(-0.2, -1, 0);
        glRotatef(20, 0 , 0, -1);
         glBegin(GL_POLYGON);
            glColor4f(0.000, 0.000, 0.000, 0.85);
          glVertex3f(-0.06, 0, 0);
          glVertex3f(0.06, 0, 0);
          glVertex3f(0.06, 0.3, 0);
          glVertex3f(-0.06, 0.3, 0);
          glEnd();
    glPopMatrix();
    glPushMatrix();//leg1bottom man2
        glTranslatef(-0.2, -1.3, 0);
        //glRotatef(20, 0 , 0, -1);
         glBegin(GL_POLYGON);
            glColor4f(0.000, 0.000, 0.000, 0.85);
          glVertex3f(-0.06, 0, 0);
          glVertex3f(0.06, 0, 0);
          glVertex3f(0.06, 0.3, 0);
          glVertex3f(-0.06, 0.3, 0);
          glEnd();
    glPopMatrix();
    glPushMatrix();//leg2up man2
        glTranslatef(0.1, -1, 0);
        glRotatef(2, 0 , 0, 1);
         glBegin(GL_POLYGON);
            glColor4f(0.000, 0.000, 0.000, 0.85);
          glVertex3f(-0.06, 0, 0);
          glVertex3f(0.06, 0, 0);
          glVertex3f(0.06, 0.3, 0);
          glVertex3f(-0.06, 0.3, 0);
          glEnd();
    glPopMatrix();
    glPushMatrix();//leg2bottom man2
     glTranslatef(0.4, -1.1, 0);
       glRotatef(70, 0 , 0, 1);
         glBegin(GL_POLYGON);
            glColor4f(0.000, 0.000, 0.000, 0.85);
          glVertex3f(-0.06, 0, 0);
          glVertex3f(0.06, 0, 0);
          glVertex3f(0.06, 0.3, 0);
          glVertex3f(-0.06, 0.3, 0);
          glEnd();
    glPopMatrix();
    glPushMatrix();//ciclehead
        //glTranslatef(-1.15, 1.2, 0);
        glBegin(GL_TRIANGLE_FAN);
         glColor4f(0.000, 0.000, 0.000, 0.85);
            for(int i=0;i<360;i++)
            {
                float pi=3.1416;
                float A=(i*2*pi)/360;
                float r=0.15;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex3f(x,y,0);
            }
          glEnd();
     glPopMatrix();

  glPopMatrix();//man2

  //MAN 3

   glPushMatrix();//man3
     glTranslatef(2, 0 , 0);
        glPushMatrix();// hand1 arm man3
         glTranslatef(-0.3, -0.25, 0);
         glRotatef(85, 0 , 0, -1);
           glBegin(GL_POLYGON);
            glColor4f(0.000, 0.000, 0.000, 0.85);
                glVertex3f(-0.125, -0.05, 0);
                  glVertex3f(0.125, -0.05,0 );
                  glVertex3f(0.125, 0.05, 0);
                  glVertex3f(-0.125, 0.05, 0);
           glEnd();
        glPopMatrix();
        glPushMatrix();//hand1 bicep man3
           glTranslatef(-0.15, -0.35, 0);
              //glRotatef(30, 0 , 0, 1);
                 glBegin(GL_POLYGON);
                    glColor4f(0.000, 0.000, 0.000, 0.85);
                    glVertex3f(-0.125, -0.05, 0);
                  glVertex3f(0.125, -0.05,0 );
                  glVertex3f(0.125, 0.05, 0);
                  glVertex3f(-0.125, 0.05, 0);

              glEnd();
        glPopMatrix();
         glPushMatrix();// hand2 arm man3
         glTranslatef(0.15, -0.6, 0);
         glRotatef(85, 0 , 0, 1);
           glBegin(GL_POLYGON);
            glColor4f(0.000, 0.000, 0.000, 0.85);
                    glVertex3f(-0.125, -0.05, 0);
                  glVertex3f(0.125, -0.05,0 );
                  glVertex3f(0.125, 0.05, 0);
                  glVertex3f(-0.125, 0.05, 0);

           glEnd();
        glPopMatrix();
        glPushMatrix();//hand2 bicep man3
          glTranslatef(0.15, -0.35, 0);
              glRotatef(85, 0 , 0, -1);
                 glBegin(GL_POLYGON);
                    glColor4f(0.000, 0.000, 0.000, 0.85);
                   glVertex3f(-0.125, -0.05, 0);
                  glVertex3f(0.125, -0.05,0 );
                  glVertex3f(0.125, 0.05, 0);
                  glVertex3f(-0.125, 0.05, 0);

              glEnd();
        glPopMatrix();

        glPushMatrix();//torso man3
            glTranslatef(-0.1, -0.70, 0);
            glRotatef(10, 0 , 0, -1);
             glBegin(GL_POLYGON);
              glColor4f(0.000, 0.000, 0.000, 0.85);
              glVertex3f(-0.125, 0, 0);
              glVertex3f(0.125, 0, 0);
              glVertex3f(0.125, 0.55, 0);
              glVertex3f(-0.125, 0.55, 0);
              glEnd();
        glPopMatrix();

        glPushMatrix();//leg1up man3
            glTranslatef(-0.3, -0.75, 0);
            glRotatef(70, 0 , 0, -1);
             glBegin(GL_POLYGON);
                glColor4f(0.000, 0.000, 0.000, 0.85);
              glVertex3f(-0.06, -0.15, 0);
              glVertex3f(0.06, -0.15, 0);
              glVertex3f(0.06, 0.15, 0);
              glVertex3f(-0.06, 0.15, 0);
              glEnd();
        glPopMatrix();
        glPushMatrix();//leg1bottom man3
            glTranslatef(-0.4, -0.95, 0);
            glRotatef(5, 0 , 0, -1);
             glBegin(GL_POLYGON);
                glColor4f(0.000, 0.000, 0.000, 0.85);
              glVertex3f(-0.06, -0.15, 0);
              glVertex3f(0.06, -0.15, 0);
              glVertex3f(0.06, 0.15, 0);
              glVertex3f(-0.06, 0.15, 0);
              glEnd();
        glPopMatrix();
        glPushMatrix();//leg2up man3
            glTranslatef(-0.05, -0.85, 0);
            glRotatef(2, 0 , 0, 1);
             glBegin(GL_POLYGON);
                glColor4f(0.000, 0.000, 0.000, 0.85);
             glVertex3f(-0.06, -0.15, 0);
              glVertex3f(0.06, -0.15, 0);
              glVertex3f(0.06, 0.15, 0);
              glVertex3f(-0.06, 0.15, 0);
              glEnd();
        glPopMatrix();
        glPushMatrix();//leg2bottom man3
         glTranslatef(-0.04, -1.15, 0);
           glRotatef(5, 0 , 0, 1);
             glBegin(GL_POLYGON);
                glColor4f(0.000, 0.000, 0.000, 0.85);
            glVertex3f(-0.06, -0.15, 0);
              glVertex3f(0.06, -0.15, 0);
              glVertex3f(0.06, 0.15, 0);
              glVertex3f(-0.06, 0.15, 0);
              glEnd();
        glPopMatrix();
        glPushMatrix();//ciclehead
            //glTranslatef(-1.15, 1.2, 0);
            glBegin(GL_TRIANGLE_FAN);
             glColor4f(0.000, 0.000, 0.000, 0.85);
                for(int i=0;i<360;i++)
                {
                    float pi=3.1416;
                    float A=(i*2*pi)/360;
                    float r=0.15;
                    float x = r * cos(A);
                    float y = r * sin(A);
                    glVertex3f(x,y,0);
                }
              glEnd();
         glPopMatrix();

      glPopMatrix();//man3

      //MAN 4

   glPushMatrix();//man4
     glTranslatef(2.75, 0 , 0);
        glPushMatrix();// hand1 arm man4
         glTranslatef(-0.4, -0.2, 0);
         glRotatef(10, 0 , 0, -1);
           glBegin(GL_POLYGON);
            glColor4f(0.000, 0.000, 0.000, 0.85);
                glVertex3f(-0.125, -0.05, 0);
                  glVertex3f(0.125, -0.05,0 );
                  glVertex3f(0.125, 0.05, 0);
                  glVertex3f(-0.125, 0.05, 0);
           glEnd();
        glPopMatrix();
        glPushMatrix();//hand1 bicep man4
           glTranslatef(-0.15, -0.20, 0);
              glRotatef(5, 0 , 0, 1);
                 glBegin(GL_POLYGON);
                    glColor4f(0.000, 0.000, 0.000, 0.85);
                    glVertex3f(-0.125, -0.05, 0);
                  glVertex3f(0.125, -0.05,0 );
                  glVertex3f(0.125, 0.05, 0);
                  glVertex3f(-0.125, 0.05, 0);

              glEnd();
        glPopMatrix();
         glPushMatrix();// hand2 arm man4
         glTranslatef(-0.25, -0.520, 0);
         glRotatef(25, 0 , 0, 1);
           glBegin(GL_POLYGON);
            glColor4f(0.000, 0.000, 0.000, 0.85);
                    glVertex3f(-0.125, -0.05, 0);
                  glVertex3f(0.125, -0.05,0 );
                  glVertex3f(0.125, 0.05, 0);
                  glVertex3f(-0.125, 0.05, 0);

           glEnd();
        glPopMatrix();
        glPushMatrix();//hand2 bicep man4
          glTranslatef(-0.1, -0.40, 0);
              glRotatef(50, 0 , 0, 1);
                 glBegin(GL_POLYGON);
                    glColor4f(0.000, 0.000, 0.000, 0.85);
                   glVertex3f(-0.125, -0.05, 0);
                  glVertex3f(0.125, -0.05,0 );
                  glVertex3f(0.125, 0.05, 0);
                  glVertex3f(-0.125, 0.05, 0);

              glEnd();
        glPopMatrix();

        glPushMatrix();//torso man4
            glTranslatef(0.15, -0.70, 0);
            glRotatef(15, 0 , 0, 1);
             glBegin(GL_POLYGON);
              glColor4f(0.000, 0.000, 0.000, 0.85);
              glVertex3f(-0.125, 0, 0);
              glVertex3f(0.125, 0, 0);
              glVertex3f(0.125, 0.55, 0);
              glVertex3f(-0.125, 0.55, 0);
              glEnd();
        glPopMatrix();

        glPushMatrix();//leg1up man4
            glTranslatef(0.05, -0.85, 0);
            glRotatef(5, 0 , 0, -1);
             glBegin(GL_POLYGON);
              glColor4f(0.000, 0.000, 0.000, 0.85);
              glVertex3f(-0.06, -0.15, 0);
              glVertex3f(0.06, -0.15, 0);
              glVertex3f(0.06, 0.15, 0);
              glVertex3f(-0.06, 0.15, 0);
              glEnd();
        glPopMatrix();
        glPushMatrix();//leg1bottom man4
            glTranslatef(0.125, -1.1, 0);
           glRotatef(25, 0 , 0, 1);
             glBegin(GL_POLYGON);
               glColor4f(0.000, 0.000, 0.000, 0.85);
              glVertex3f(-0.06, -0.15, 0);
              glVertex3f(0.06, -0.15, 0);
              glVertex3f(0.06, 0.15, 0);
              glVertex3f(-0.06, 0.15, 0);
              glEnd();
        glPopMatrix();
        glPushMatrix();//leg2up man4
            glTranslatef(0.125, -0.85, 0);
            glRotatef(10, 0 , 0, -1);
             glBegin(GL_POLYGON);
                glColor4f(0.000, 0.000, 0.000, 0.85);
             glVertex3f(-0.06, -0.15, 0);
              glVertex3f(0.06, -0.15, 0);
              glVertex3f(0.06, 0.15, 0);
              glVertex3f(-0.06, 0.15, 0);
              glEnd();
        glPopMatrix();
        glPushMatrix();//leg2bottom man4
         glTranslatef(0.04, -1.125, 0);
           glRotatef(20, 0 , 0, -1);
             glBegin(GL_POLYGON);
                glColor4f(0.000, 0.000, 0.000, 0.85);
            glVertex3f(-0.06, -0.15, 0);
              glVertex3f(0.06, -0.15, 0);
              glVertex3f(0.06, 0.15, 0);
              glVertex3f(-0.06, 0.15, 0);
              glEnd();
        glPopMatrix();
        glPushMatrix();//ciclehead
            //glTranslatef(-1.15, 1.2, 0);
            glBegin(GL_TRIANGLE_FAN);
             glColor4f(0.000, 0.000, 0.000, 0.85);
                for(int i=0;i<360;i++)
                {
                    float pi=3.1416;
                    float A=(i*2*pi)/360;
                    float r=0.15;
                    float x = r * cos(A);
                    float y = r * sin(A);
                    glVertex3f(x,y,0);
                }
              glEnd();
         glPopMatrix();

      glPopMatrix();//man4

glPopMatrix();//bodies

glBegin (GL_POLYGON);
   glColor4f(0.000, 0.000, 0.000, 0.85);
  glVertex3f(-1.5, 0, 0.002);
  glVertex3f(1.75, 0, 0.002);
  glVertex3f(1.75, 0.25, 0.002);
  glVertex3f(-1.5, 0.25, 0.002);
glEnd();

glBegin (GL_POLYGON);
   glColor4f(0.000, 0.000, 0.000, 0.85);
  glVertex3f(-1.4, 0, 0);
  glVertex3f(-1.25, 0, 0);
  glVertex3f(-1.25, 1.75, 0);
  glVertex3f(-1.4, 1.75, 0);
glEnd();


glutPostRedisplay();
} //leftwallart end

void leftwallart(){
glPushMatrix(); //full art

    glPushMatrix(); //Boxes
        glTranslatef(0, 0 , 0);
        glScalef(0.85,0.85,1);
        float a=-3,b=-2.5;
        for(int i=0; i<7; i++){
           glPushMatrix(); //Box1-7
              glBegin (GL_POLYGON);
                glColor4f(0.000, 0.000, 0.000, 0.85);
                  glVertex3f(a, 0, 0);
                  glVertex3f(b, 0, 0);
                  glVertex3f(b, -1.25, 0);
                  glVertex3f(a, -1.25, 0);
             glEnd();
          glPopMatrix();//Box3-7 end
           a+=1; b+=1;
           }

        glPushMatrix();
           glTranslatef(0, 0 , 0.01);
              glBegin (GL_POLYGON);
                 glColor3f(0.863, 0.863, 0.863);
                  glVertex3f(-1.85, 0, 0);
                  glVertex3f(-1.65, 0, 0);
                  glVertex3f(-1.60, -0.2, 0);
                  glVertex3f(-1.75, -0.4, 0);
                  glVertex3f(-1.57, -0.9, 0);
                  glVertex3f(-1.85, -0.5, 0);
                  glVertex3f(-1.88, -0.35, 0);
                  glVertex3f(-1.7, -0.25, 0);
                  glVertex3f(-1.8, -0.15, 0);
             glEnd();

        glPopMatrix();

    glPopMatrix();//Boxes end

    glPushMatrix();//bodies

        glTranslatef(0, 1 , 0);
        glScalef(0.75,0.75,1);

          //MAN 1
           glPushMatrix();//man1
             glTranslatef(-1.9, -0.2 , 0);
                glPushMatrix();// hand1 arm man1
               glTranslatef(-0.50, 0.08, 0);
                 glRotatef(45, 0 , 0, -1);
                   glBegin(GL_POLYGON);
                    glColor4f(0.000, 0.000, 0.000, 0.85);
                        glVertex3f(-0.125, -0.05, 0);
                          glVertex3f(0.125, -0.05,0 );
                          glVertex3f(0.125, 0.05, 0);
                          glVertex3f(-0.125, 0.05, 0);
                   glEnd();
                glPopMatrix();
                glPushMatrix();//hand1 bicep man1
                   glTranslatef(-0.35, -0.1, 0);
                      glRotatef(45, 0 , 0, -1);
                         glBegin(GL_POLYGON);
                            glColor4f(0.000, 0.000, 0.000, 0.85);
                            glVertex3f(-0.125, -0.05, 0);
                          glVertex3f(0.125, -0.05,0 );
                          glVertex3f(0.125, 0.05, 0);
                          glVertex3f(-0.125, 0.05, 0);

                      glEnd();
                glPopMatrix();
                 glPushMatrix();// hand2 arm man1
                 glTranslatef(0.2, 0.08, 0);
                 glRotatef(45, 0 , 0, 1);
                   glBegin(GL_POLYGON);
                    glColor4f(0.000, 0.000, 0.000, 0.85);
                            glVertex3f(-0.125, -0.05, 0);
                          glVertex3f(0.125, -0.05,0 );
                          glVertex3f(0.125, 0.05, 0);
                          glVertex3f(-0.125, 0.05, 0);

                   glEnd();
                glPopMatrix();
                glPushMatrix();//hand2 bicep man1
                  glTranslatef(0.05, -0.05, 0);
                      glRotatef(45, 0 , 0, 1);
                         glBegin(GL_POLYGON);
                            glColor4f(0.000, 0.000, 0.000, 0.85);
                           glVertex3f(-0.125, -0.05, 0);
                          glVertex3f(0.125, -0.05,0 );
                          glVertex3f(0.125, 0.05, 0);
                          glVertex3f(-0.125, 0.05, 0);

                      glEnd();
                glPopMatrix();

                glPushMatrix();//torso man1
                    glTranslatef(-0.1, -0.70, 0);
                    glRotatef(6, 0 , 0, 1);
                     glBegin(GL_POLYGON);
                      glColor4f(0.000, 0.000, 0.000, 0.85);
                      glVertex3f(-0.125, 0, 0);
                      glVertex3f(0.125, 0, 0);
                      glVertex3f(0.125, 0.55, 0);
                      glVertex3f(-0.125, 0.55, 0);
                      glEnd();
                glPopMatrix();

                glPushMatrix();//leg1up man1
                    glTranslatef(-0.3, -0.75, 0);
                    glRotatef(50, 0 , 0, -1);
                     glBegin(GL_POLYGON);
                        glColor4f(0.000, 0.000, 0.000, 0.85);
                      glVertex3f(-0.06, -0.15, 0);
                      glVertex3f(0.06, -0.15, 0);
                      glVertex3f(0.06, 0.15, 0);
                      glVertex3f(-0.06, 0.15, 0);
                      glEnd();
                glPopMatrix();
                glPushMatrix();//leg1bottom man1
                    glTranslatef(-0.5, -0.9, 0);
                    glRotatef(52, 0 , 0, -1);
                     glBegin(GL_POLYGON);
                        glColor4f(0.000, 0.000, 0.000, 0.85);
                      glVertex3f(-0.06, -0.15, 0);
                      glVertex3f(0.06, -0.15, 0);
                      glVertex3f(0.06, 0.15, 0);
                      glVertex3f(-0.06, 0.15, 0);
                      glEnd();
                glPopMatrix();
                glPushMatrix();//leg2up man1
                    glTranslatef(0, -0.75, 0);
                    glRotatef(70, 0 , 0, 1);
                     glBegin(GL_POLYGON);
                        glColor4f(0.000, 0.000, 0.000, 0.85);
                     glVertex3f(-0.06, -0.15, 0);
                      glVertex3f(0.06, -0.15, 0);
                      glVertex3f(0.06, 0.15, 0);
                      glVertex3f(-0.06, 0.15, 0);
                      glEnd();
                glPopMatrix();
                glPushMatrix();//leg2bottom man1
                 glTranslatef(0.25, -0.8, 0);
                   glRotatef(90, 0 , 0, 1);
                     glBegin(GL_POLYGON);
                    glColor4f(0.000, 0.000, 0.000, 0.85);
                    glVertex3f(-0.06, -0.15, 0);
                      glVertex3f(0.06, -0.15, 0);
                      glVertex3f(0.06, 0.15, 0);
                      glVertex3f(-0.06, 0.15, 0);
                      glEnd();
                glPopMatrix();
                glPushMatrix();//ciclehead
                    glTranslatef(-0.2, 0, 0);
                    glBegin(GL_TRIANGLE_FAN);
                     glColor4f(0.000, 0.000, 0.000, 0.85);
                        for(int i=0;i<360;i++)
                        {
                            float pi=3.1416;
                            float A=(i*2*pi)/360;
                            float r=0.15;
                            float x = r * cos(A);
                            float y = r * sin(A);
                            glVertex3f(x,y,0);
                        }
                      glEnd();
                 glPopMatrix();

              glPopMatrix();//man1

              //MAN 2

           glPushMatrix();//man2
             glTranslatef(0.35, 0 , 0);
                glPushMatrix();// hand1 arm man2
                 glTranslatef(-0.4, -0.2, 0);
                 glRotatef(10, 0 , 0, -1);
                   glBegin(GL_POLYGON);
                    glColor4f(0.000, 0.000, 0.000, 0.85);
                        glVertex3f(-0.125, -0.05, 0);
                          glVertex3f(0.125, -0.05,0 );
                          glVertex3f(0.125, 0.05, 0);
                          glVertex3f(-0.125, 0.05, 0);
                   glEnd();
                glPopMatrix();
                glPushMatrix();//hand1 bicep man2
                   glTranslatef(-0.15, -0.20, 0);
                      glRotatef(5, 0 , 0, 1);
                         glBegin(GL_POLYGON);
                            glColor4f(0.000, 0.000, 0.000, 0.85);
                            glVertex3f(-0.125, -0.05, 0);
                          glVertex3f(0.125, -0.05,0 );
                          glVertex3f(0.125, 0.05, 0);
                          glVertex3f(-0.125, 0.05, 0);

                      glEnd();
                glPopMatrix();
                 glPushMatrix();// hand2 arm man2
                 glTranslatef(0.05, -0.520, 0);
                 glRotatef(25, 0 , 0, 1);
                   glBegin(GL_POLYGON);
                    glColor4f(0.000, 0.000, 0.000, 0.85);
                            glVertex3f(-0.125, -0.05, 0);
                          glVertex3f(0.125, -0.05,0 );
                          glVertex3f(0.125, 0.05, 0);
                          glVertex3f(-0.125, 0.05, 0);

                   glEnd();
                glPopMatrix();
                glPushMatrix();//hand2 bicep man2
                  glTranslatef(0.15, -0.35, 0);
                      glRotatef(70, 0 , 0, -1);
                         glBegin(GL_POLYGON);
                            glColor4f(0.000, 0.000, 0.000, 0.85);
                           glVertex3f(-0.125, -0.05, 0);
                          glVertex3f(0.125, -0.05,0 );
                          glVertex3f(0.125, 0.05, 0);
                          glVertex3f(-0.125, 0.05, 0);

                      glEnd();
                glPopMatrix();

                glPushMatrix();//torso man2
                    glTranslatef(-0.1, -0.70, 0);
                    glRotatef(10, 0 , 0, -1);
                     glBegin(GL_POLYGON);
                      glColor4f(0.000, 0.000, 0.000, 0.85);
                      glVertex3f(-0.125, 0, 0);
                      glVertex3f(0.125, 0, 0);
                      glVertex3f(0.125, 0.55, 0);
                      glVertex3f(-0.125, 0.55, 0);
                      glEnd();
                glPopMatrix();

                glPushMatrix();//leg2up man2
                    glTranslatef(-0.05, -0.85, 0);
                    glRotatef(2, 0 , 0, 1);
                     glBegin(GL_POLYGON);
                        glColor4f(0.000, 0.000, 0.000, 0.85);
                     glVertex3f(-0.06, -0.15, 0);
                      glVertex3f(0.06, -0.15, 0);
                      glVertex3f(0.06, 0.15, 0);
                      glVertex3f(-0.06, 0.15, 0);
                      glEnd();
                glPopMatrix();
                glPushMatrix();//leg2bottom man2
                 glTranslatef(-0.04, -1.15, 0);
                   glRotatef(5, 0 , 0, 1);
                     glBegin(GL_POLYGON);
                        glColor4f(0.000, 0.000, 0.000, 0.85);
                    glVertex3f(-0.06, -0.15, 0);
                      glVertex3f(0.06, -0.15, 0);
                      glVertex3f(0.06, 0.15, 0);
                      glVertex3f(-0.06, 0.15, 0);
                      glEnd();
                glPopMatrix();
                glPushMatrix();//leg1up man2
                    glTranslatef(-0.2, -0.85, 0);
                    glRotatef(20, 0 , 0, -1);
                     glBegin(GL_POLYGON);
                        glColor4f(0.000, 0.000, 0.000, 0.85);
                     glVertex3f(-0.06, -0.15, 0);
                      glVertex3f(0.06, -0.15, 0);
                      glVertex3f(0.06, 0.15, 0);
                      glVertex3f(-0.06, 0.15, 0);
                      glEnd();
                glPopMatrix();
                glPushMatrix();//leg1bottom man2
                 glTranslatef(-0.3, -1.125, 0);
                   glRotatef(20, 0 , 0, -1);
                     glBegin(GL_POLYGON);
                        glColor4f(0.000, 0.000, 0.000, 0.85);
                    glVertex3f(-0.06, -0.15, 0);
                      glVertex3f(0.06, -0.15, 0);
                      glVertex3f(0.06, 0.15, 0);
                      glVertex3f(-0.06, 0.15, 0);
                      glEnd();
                glPopMatrix();
                glPushMatrix();//ciclehead
                    //glTranslatef(-1.15, 1.2, 0);
                    glBegin(GL_TRIANGLE_FAN);
                     glColor4f(0.000, 0.000, 0.000, 0.85);
                        for(int i=0;i<360;i++)
                        {
                            float pi=3.1416;
                            float A=(i*2*pi)/360;
                            float r=0.15;
                            float x = r * cos(A);
                            float y = r * sin(A);
                            glVertex3f(x,y,0);
                        }
                      glEnd();
                 glPopMatrix();

              glPopMatrix();//man2 end

              //MAN 3

          glPushMatrix();//man3
           glTranslatef(1.1, 0.05 , 0 );
           glScalef(1.05, 1.05, 0);
             glPushMatrix();// hand arm man3
             glTranslatef(-0.15, -0.520, 0);
                 glRotatef(25, 0 , 0, 1);
                   glBegin(GL_POLYGON);
                    glColor4f(0.000, 0.000, 0.000, 0.85);
                            glVertex3f(-0.125, -0.05, 0);
                          glVertex3f(0.125, -0.05,0 );
                          glVertex3f(0.125, 0.05, 0);
                          glVertex3f(-0.125, 0.05, 0);

                   glEnd();
                glPopMatrix();
                glPushMatrix();//hand bicep man3
                  glTranslatef(0.0, -0.40, 0);
                      glRotatef(50, 0 , 0, 1);
                         glBegin(GL_POLYGON);
                            glColor4f(0.000, 0.000, 0.000, 0.85);
                           glVertex3f(-0.125, -0.05, 0);
                          glVertex3f(0.125, -0.05,0 );
                          glVertex3f(0.125, 0.05, 0);
                          glVertex3f(-0.125, 0.05, 0);

                      glEnd();
            glPopMatrix();

            glPushMatrix();//ciclehead
                //glTranslatef(-1.15, 1.2, 0);
                glBegin(GL_TRIANGLE_FAN);
                 glColor4f(0.000, 0.000, 0.000, 0.85);
                    for(int i=0;i<360;i++)
                    {
                        float pi=3.1416;
                        float A=(i*2*pi)/360;
                        float r=0.15;
                        float x = r * cos(A);
                        float y = r * sin(A);
                        glVertex3f(x,y,0);
                    }
                  glEnd();
            glPopMatrix();

            glPushMatrix();//torso man3
                glTranslatef(0.05, 0, 0);
                glRotatef(15, 0 , 0, 1);
                 glBegin(GL_POLYGON);
                    glColor4f(0.000, 0.000, 0.000, 0.85);
                  glVertex3f(-0.125, -0.15, 0);
                  glVertex3f(0.125, -0.15, 0);
                  glVertex3f(0.120, -0.70, 0);
                  glVertex3f(-0.125, -0.70, 0);
                  glEnd();
            glPopMatrix();

            glPushMatrix();//leg man3
                glTranslatef(0.250, 0, 0);
                //glRotatef(15, 0 , 0, 1);
                 glBegin(GL_POLYGON);
                    glColor4f(0.000, 0.000, 0.000, 0.85);
                  glVertex3f(-0.09, -0.70, 0);
                  glVertex3f(0.05, -0.70, 0);
                  glVertex3f(0.02, -1.3, 0);
                  glVertex3f(-0.09, -1.3, 0);
                  glEnd();
            glPopMatrix();
            glPopMatrix();//man3

        // MAN 4

           glPushMatrix();//man4
            glTranslatef(2.85, 0 , 0);
            glPushMatrix();// hand1 arm man4
             glTranslatef(-0.3, -0.45, 0);
             glRotatef(10, 0 , 0, -1);
               glBegin(GL_POLYGON);
                glColor4f(0.000, 0.000, 0.000, 0.85);
                glVertex3f(-0.25, 0, 0);
                glVertex3f(0, 0, 0);
                glVertex3f(0, 0.1, 0);
                glVertex3f(-0.25, 0.1, 0);

               glEnd();
            glPopMatrix();
            glPushMatrix();//hand1 bicep man4
               glTranslatef(-0.07, -0.3, 0);
                  glRotatef(30, 0 , 0, 1);
                     glBegin(GL_POLYGON);
                        glColor4f(0.000, 0.000, 0.000, 0.85);
                        glVertex3f(-0.25, 0, 0);
                      glVertex3f(0.0, 0, 0);
                      glVertex3f(0.0, 0.1, 0);
                      glVertex3f(-0.25, 0.1, 0);

                  glEnd();
            glPopMatrix();
             glPushMatrix();// hand2 arm man4
             glTranslatef(0.5, -0.45, 0);
             glRotatef(10, 0 , 0, -1);
               glBegin(GL_POLYGON);
                glColor4f(0.000, 0.000, 0.000, 0.85);
                glVertex3f(-0.25, 0, 0);
                glVertex3f(0, 0, 0);
                glVertex3f(0, 0.1, 0);
                glVertex3f(-0.25, 0.1, 0);

               glEnd();
            glPopMatrix();
            glPushMatrix();//hand2 bicep man4
              glTranslatef(0.3, -0.4, 0);
                  glRotatef(30, 0 , 0, -1);
                     glBegin(GL_POLYGON);
                        glColor4f(0.000, 0.000, 0.000, 0.85);
                        glVertex3f(-0.25, 0, 0);
                      glVertex3f(0.0, 0, 0);
                      glVertex3f(0.0, 0.1, 0);
                      glVertex3f(-0.25, 0.1, 0);

                  glEnd();
            glPopMatrix();

            glPushMatrix();//torso man4
                glTranslatef(0, -0.70, 0);
                //glRotatef(2, 0 , 0, 1);
                 glBegin(GL_POLYGON);
                  glColor4f(0.000, 0.000, 0.000, 0.85);
                  glVertex3f(-0.125, 0, 0);
                  glVertex3f(0.125, 0, 0);
                  glVertex3f(0.125, 0.55, 0);
                  glVertex3f(-0.125, 0.55, 0);
                  glEnd();
            glPopMatrix();

            glPushMatrix();//leg1up man4
                glTranslatef(-0.2, -1, 0);
                glRotatef(20, 0 , 0, -1);
                 glBegin(GL_POLYGON);
                    glColor4f(0.000, 0.000, 0.000, 0.85);
                  glVertex3f(-0.06, 0, 0);
                  glVertex3f(0.06, 0, 0);
                  glVertex3f(0.06, 0.3, 0);
                  glVertex3f(-0.06, 0.3, 0);
                  glEnd();
            glPopMatrix();
            glPushMatrix();//leg1bottom man4
                glTranslatef(-0.2, -1.3, 0);
                //glRotatef(20, 0 , 0, -1);
                 glBegin(GL_POLYGON);
                    glColor4f(0.000, 0.000, 0.000, 0.85);
                  glVertex3f(-0.06, 0, 0);
                  glVertex3f(0.06, 0, 0);
                  glVertex3f(0.06, 0.3, 0);
                  glVertex3f(-0.06, 0.3, 0);
                  glEnd();
            glPopMatrix();
            glPushMatrix();//leg2up man4
                glTranslatef(0.1, -1, 0);
                glRotatef(2, 0 , 0, 1);
                 glBegin(GL_POLYGON);
                    glColor4f(0.000, 0.000, 0.000, 0.85);
                  glVertex3f(-0.06, 0, 0);
                  glVertex3f(0.06, 0, 0);
                  glVertex3f(0.06, 0.3, 0);
                  glVertex3f(-0.06, 0.3, 0);
                  glEnd();
            glPopMatrix();
            glPushMatrix();//leg2bottom man4
             glTranslatef(0.4, -1.1, 0);
               glRotatef(70, 0 , 0, 1);
                 glBegin(GL_POLYGON);
                    glColor4f(0.000, 0.000, 0.000, 0.85);
                  glVertex3f(-0.06, 0, 0);
                  glVertex3f(0.06, 0, 0);
                  glVertex3f(0.06, 0.3, 0);
                  glVertex3f(-0.06, 0.3, 0);
                  glEnd();
            glPopMatrix();
            glPushMatrix();//ciclehead
                //glTranslatef(-1.15, 1.2, 0);
                glBegin(GL_TRIANGLE_FAN);
                 glColor4f(0.000, 0.000, 0.000, 0.85);
                    for(int i=0;i<360;i++)
                    {
                        float pi=3.1416;
                        float A=(i*2*pi)/360;
                        float r=0.15;
                        float x = r * cos(A);
                        float y = r * sin(A);
                        glVertex3f(x,y,0);
                    }
                  glEnd();
             glPopMatrix();

          glPopMatrix();//man4 end

        glPopMatrix();//bodies end

glPopMatrix();//full art end

}

void middlewallsquidgame(){
 glPushMatrix();//whole squid game letter

            glPushMatrix();

                glLineWidth(5.0);
                glColor3f(0,0,0);
                glTranslatef(-1.5, 1.5, 0);
                glScalef(0.010, 0.006, 0.0);
                char text[] ="SOUID";
                for(int i=0; i<strlen(text); i++)
                  glutStrokeCharacter(GLUT_STROKE_ROMAN, text[i]);
                 // GLUT_STROKE_ROMAN
                 //GLUT_STROKE_MONO_ROMAN
                 glLineWidth(1.0);
            glPopMatrix();

            glPushMatrix();
                glLineWidth(5.0);
                glColor3f(0,0,0);
                glTranslatef(-0.72, 0.5, 0);
                glScalef(0.010, 0.006, 0.0);
                char text1[] ="GAME";
                for(int i=0; i<strlen(text1); i++)
                  glutStrokeCharacter(GLUT_STROKE_ROMAN, text1[i]);
                 // GLUT_STROKE_ROMAN
                 //GLUT_STROKE_MONO_ROMAN
                 glLineWidth(1.0);
            glPopMatrix();


            glPushMatrix();

                glTranslatef(0,0, 0.001);
                glBegin(GL_TRIANGLES);
                    glColor3f(1,0,1);
                  glVertex3f (0.265, 0.48, 0.0);
                 glVertex3f (0.92, 0.48, 0.0);
                glVertex3f (0.58, 1, 0.0);
                glEnd();
            glPopMatrix();


            glPushMatrix();
                glTranslatef(0,0, 0.001);
                glBegin(GL_POLYGON);
                    glColor3f(1,0,1);
                  glVertex3f (2.12, 0.56, 0.0);
                 glVertex3f (2.69, 0.56, 0.0);
                glVertex3f (2.69, 1.04, 0.0);
                glVertex3f (2.12, 1.04, 0.0);
                glEnd();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0,0, 0.002);
                glBegin(GL_POLYGON);
                    glColor3f(0,0,0);
                  glVertex3f (2.35, 0.73, 0.0);
                 glVertex3f (3.1, 0.73, 0.0);
                glVertex3f (3.1, 0.86, 0.0);
                glVertex3f (2.35, 0.86, 0.0);
                glEnd();
            glPopMatrix();

            glPushMatrix();
                    glTranslatef(-0.24, 1.8, 0.001);
                    glScalef(0.8,0.6,1);
                    glBegin(GL_TRIANGLE_FAN);
                    glColor3f(1,0,1);
                        for(int i=0;i<360;i++)
                        {
                            float pi=3.1416;
                            float A=(i*2*pi)/360;
                            float r=0.4;
                            float x = r * cos(A);
                            float y = r * sin(A);
                            glVertex3f(x,y,0);
                          }
                glEnd();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0,0, 0.002);
                glBegin(GL_QUADS);
                    glColor3f(0,0,0);
                  glVertex3f (-0.27, 1.8, 0.0);
                 glVertex3f (-0.12, 1.8, 0.0);
                glVertex3f (0.32, 1.3, 0.0);
                glVertex3f (0.18, 1.3, 0.0);
                glEnd();
            glPopMatrix();


            glPushMatrix();
                glTranslatef(0,0, 0.002);
                glBegin(GL_QUADS);
                    glColor3f(0,0,0);
                  glVertex3f (0.925, 2, 0.0);
                 glVertex3f (1.025, 2, 0.0);
                glVertex3f (1.025, 2.6, 0.0);
                glVertex3f (0.925, 2.6, 0.0);
                glEnd();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(-0.15,-1.05, 0.002);
                glRotatef(10,0,0,-1);
                glBegin(GL_QUADS);
                    glColor3f(0,0,0);
                  glVertex3f (-0.26, 1.8, 0.0);
                 glVertex3f (-0.13, 1.8, 0.0);
                glVertex3f (0.31, 1.3, 0.0);
                glVertex3f (0.19, 1.3, 0.0);
                glEnd();
            glPopMatrix();


 glPopMatrix();//whole squid game letter
}

void middlewallgate(){
        glPushMatrix(); //whole arc
            glTranslatef(0,0,0.8);
            glPushMatrix();//arc border
                 glTranslatef(0,0,0.001);

                        float angle=0;            // starting angle in radians
                        float length= 3.142;           // length of arc in radians, >0
                        float radius=1.95   ;        // inner radius, >0
                        float width=0.95      ;      // width of arc, >0
                        float samples =50;   // number of circle samples, >=3

                         float outer = radius + width;
                        glBegin( GL_QUAD_STRIP );
                        glColor3f(0,0,0);
                        for( int i = 0; i <= samples; i++ )
                        {
                            float a = angle + ( i / samples ) * length;
                            glVertex2f( radius * cos( a ), radius * sin( a ) );
                            glVertex2f( outer * cos( a ), outer * sin( a ) );
                        }
                        glEnd();

            glPopMatrix();

            glPushMatrix();//arc
            glTranslatef(0,0,0.002);

                    float angle1=0;            // starting angle in radians
                        float length1= 3.142;           // length of arc in radians, >0
                        float radius1=2   ;        // inner radius, >0
                        float width1=0.85      ;      // width of arc, >0
                        float samples1 =50;   // number of circle samples, >=3

                         float outer1 = radius1 + width1;
                        glBegin( GL_QUAD_STRIP );
                        glColor3f(0.961, 0.961, 0.961);
                        for( int i = 0; i <= samples1; i++ )
                        {
                            float a = angle1 + ( i / samples1 ) * length1;
                            glVertex2f( radius1 * cos( a ), radius1 * sin( a ) );
                            glVertex2f( outer1 * cos( a ), outer1 * sin( a ) );
                        }
                        glEnd();

            glPopMatrix();

        glPopMatrix(); //whole arc end


           float arcz = 0.79;
           while(arcz>=0) {
                glPushMatrix();//arc repeat
                 glTranslatef(0,0,arcz);

                    float angle2=0;            // starting angle in radians
                        float length2= 3.142;           // length of arc in radians, >0
                        float radius2=1.95   ;        // inner radius, >0
                        float width2=0.95      ;      // width of arc, >0
                        float samples2 =50;   // number of circle samples, >=3

                         float outer2 = radius2 + width2;
                        glBegin( GL_QUAD_STRIP );
                        glColor3f(0.900, 0.900, 0.900);
                        for( int i = 0; i <= samples2; i++ )
                        {
                            float a = angle2 + ( i / samples2 ) * length2;
                            glVertex2f( radius2 * cos( a ), radius2 * sin( a ) );
                            glVertex2f( outer2 * cos( a ), outer2 * sin( a ) );
                        }
                        glEnd();
                glPopMatrix();
            arcz = arcz - 0.01;
            }


        glPushMatrix();//tv border
               glTranslatef(0,0,0.81);
              glBegin(GL_POLYGON);
                    glColor4f(0.000, 0.000, 0.000, 1);
                        glVertex3f (-1.25, 2.1, 0.0);
                        glVertex3f (1.25, 2.1, 0.0);
                        glVertex3f (1.25, 3.1, 0.0);
                        glVertex3f (-1.25, 3.1, 0.0);
               glEnd();

        glPopMatrix();

        glPushMatrix();//tv
               glTranslatef(0,0,0.82);
              glBegin(GL_POLYGON);
                    glColor4f(0.412, 0.412, 0.412, 0.75);
                        glVertex3f (-1.22, 2.13, 0.0);
                        glVertex3f (1.22, 2.13, 0.0);
                        glVertex3f (1.22, 3.07, 0.0);
                        glVertex3f (-1.22, 3.07, 0.0);
               glEnd();

        glPopMatrix();

        glPushMatrix(); //number 456

            glLineWidth(3.0);
            glColor3f(0.196, 0.804, 0.196);
            glTranslatef(-0.7, 2.5, 0.83);
            glScalef(0.004, 0.003, 0.005);
            char text[] ="456";
            for(int i=0; i<strlen(text); i++)
              glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, text[i]);
             // GLUT_STROKE_ROMAN
             //GLUT_STROKE_MONO_ROMAN
             glLineWidth(1.0);
        glPopMatrix();

        glPushMatrix(); //whole gate
            glTranslatef(0,0.15,0.001);
                  glPushMatrix(); // gate border
                        glTranslatef(0,0,-0.01);
                             glBegin(GL_POLYGON);
                                glColor4f(0.000, 0.000, 0.000, 0.8);
                                 glVertex3f (-0.85, 1.05, 0.0);
                                 glVertex3f (0.85, 1.05, 0.0);
                                 glVertex3f (0.85, 0, 0.0);
                                 glVertex3f (-0.85, 0, 0.0);
                             glEnd();
                        glPopMatrix();
                glPushMatrix(); // gate
                        glTranslatef(0,0,0.001);
                             glBegin(GL_POLYGON);
                                glColor3f(0.653, 0.653, 0.653);
                                 glVertex3f (-0.8, 1, 0.0);
                                 glVertex3f (0.8, 1, 0.0);
                                 glVertex3f (0.8, 0, 0.0);
                                 glVertex3f (-0.8, 0, 0.0);
                             glEnd();
                    glPopMatrix();

                glPushMatrix();//vertical line on gate
                            glTranslatef(0, 0, 0.02);
                            glLineWidth(2);
                            glBegin(GL_LINES);
                            glColor4f(0.000, 0.000, 0.000, 0.85);
                            glVertex3f (0, 1, 0.0);
                            glVertex3f (0, 0, 0.0);
                            glEnd();
                            glLineWidth(1);
                glPopMatrix();

        glPopMatrix();//whole gate end

        glPushMatrix();//gate ramp
           glTranslatef(0,0.05,0.5);
            glRotatef(80,-1,0,0);
            glBegin(GL_POLYGON);
                glColor3f(0.212, 0.212, 0.212);
                glVertex3f (-1, -0.5, 0.0);
                glVertex3f (1, -0.5, 0.0);
                glVertex3f (1, 0.5, 0.0);
                glVertex3f (-1, 0.5, 0.0);
            glEnd();
        glPopMatrix();

}

void updateroom(int value) {
if(displaying==1){
    switch (state)
    {
        case 1:
            if (panx > 0 && panz < 3) {
                panx -= 0.005;
                panz += 0.001;;
            }else{
              state = 2;
            }
            break;
        case 2:
            if (panx > -0.4 && panz > 0) {
                panx -= 0.005;
                panz -= 0.001;;
            }else{
              state = 3;
            }
            break;
        case 3:
            if (movez < 7) {
                movez += 0.045;;
            }else{
              state = 4;
            }
            break;

        case 4:
            if (movex <=0.15 && panx < 0 && panz < 3) {
                movex -= 0.0025;;
                panx += 0.005;
                panz += 0.001;;
            }else{
              state = 5;
            }
        break;

         case 5:
            if (movex < 0.3 && panx < 0.36 && panz > 0) {
                movex -= 0.0025;;
                panx += 0.005;
                panz -= 0.001;;
            }else{
              state = 6;
            }
        break;

         case 6:
            if (movez > 0) {
                movez -= 0.045;;
            }else{
                state= 1;
                panx = 0.4;
                panz = 0.5;
                movez = 0;
                movex=0;
            }
        break;
	}

}
	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in n milliseconds
	glutTimerFunc(1000/50, updateroom, 0);
}

void updatepressx(int value){
if(displaying==1){
if(showpressx == 1 && pressxwait == 3){
        pressxwait=0;
        pressxalpha = 0;
        showpressx = 0;
    }else{
        pressxwait++;
       pressxalpha =1;
       showpressx = 1;
    }
}
	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in n milliseconds
	glutTimerFunc(1000/5, updatepressx, 0);

}


/* *******************************************************************
**************************MENU FUNCTIONS***************************
******************************************************************* */
void reset(int value){

if(resetvalues==1){
 resetvalues=0;
 state=1;
 panx = 0.4;
 panz = 0.5;
 movez = 0;
 movex=0;
 showtxt1=1;
 showpressx=1;
 pressxalpha=1;
 pressxwait=0;

 r=0;

 manz = 8;
 manpos=8;
//float mx=1, my=1, mz=10;
//float tx=0,ty=0,tz=0, cx=0, cy=1, cz=-8;

 r_lefthand=0,r_righthand=0,r_leftleg=0,r_rightleg=0;
 r_dollhead=0;
cashbuffer = 1;

 float ctx[50], cty[50], ctz[50], rc[50],  rx[50],  ry[50], rz[50];
 float clz=-25, clz2=-50;

 red=1, green = 0;

 eliminate=-1;
 life = 0, fail=0;
 second=120;
 pinkblink=0;
 moving =0;
 win=0;
 rotatehead=1;
r_cashball=0;
 gunshots=0;
 pinkblinkcount=0;
 stateg=0;
 startcount = 4;
 loading=1;
 loadtimer=1000;
}

glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in n milliseconds
	glutTimerFunc(1000/60, reset, 0);
}

void keyboard(unsigned char key, int x, int y){

    if(displaying==1){

        switch(key){
            case 'x':
                glutDisplayFunc(game);
                sndPlaySound(NULL,SND_ASYNC);
                displaying=3;
            break;
        }

      }





if(displaying==3 && loading==1){
  switch(key){

    case 'z':
       loading=0;
       sndPlaySound(NULL,SND_ASYNC);
        glutPostRedisplay();

    break;

  }
      }


      if(displaying==3 && loading==0){
  switch(key){
 case 'm':
        displaying=1;
        resetvalues=1;


            sndPlaySound("menumusic.wav",SND_ASYNC|SND_LOOP);
         glutDisplayFunc(mainmenu);
 break;

  }
      }







/*
    switch(key){
    case 'i':
        mz-=0.2;
        cout<<"mz = "<<mz<<endl;
        glutPostRedisplay();
    break;
    case 'k':
        mz+=0.2;
         cout<<"mz = "<<mz<<endl;
        glutPostRedisplay();
    break;
    case 'j':
         mx-=0.2;
          cout<<"mx = "<<mx<<endl;
         glutPostRedisplay();
    break;
    case 'l':
         mx+=0.2;
          cout<<"mx = "<<mx<<endl;
         glutPostRedisplay();
    break;
    case 'u':
        my+=0.2;
         cout<<"my = "<<my<<endl;
        glutPostRedisplay();
    break;
    case 'h':
        my-=0.2;
         cout<<"my = "<<my<<endl;
        glutPostRedisplay();
    break;

    case 'w':
        ty+=0.01;
         cout<<"ty = "<<ty<<endl;
        glutPostRedisplay();
    break;
    case 's':
        ty-=0.01;
         cout<<"ty = "<<ty<<endl;
        glutPostRedisplay();
    break;
    case 'a':
        tx-=0.01;
         cout<<"tx = "<<tx<<endl;
        glutPostRedisplay();
    break;
    case 'd':
        tx+=0.01;
         cout<<"tx = "<<tx<<endl;
        glutPostRedisplay();
    break;
    case 'q':
        tz+=0.01;
         cout<<"tz = "<<tz<<endl;
        glutPostRedisplay();
    break;
    case 'e':
        tz-=0.01;
         cout<<"tz = "<<tz<<endl;
        glutPostRedisplay();
    break;
    case 'r':
        if(r<360)
        {r+=2;}
        else{r=0;}
         cout<<"r = "<<r<<endl;
        glutPostRedisplay();
    break;

    }
    */

}


int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(1350, 690);
	glutInitWindowPosition(5,5);

	//Create the window
	glutCreateWindow("Squid Game");
	init();

	//Set handler functions

	if (displaying == 1){
        glutDisplayFunc(mainmenu);
        sndPlaySound("menumusic.wav",SND_ASYNC|SND_LOOP);//add extended versio

	}


	glutTimerFunc(0, updateroom, 0);
	glutTimerFunc(0, updatepressx, 0);

	if(displaying == 3){
    glutDisplayFunc(game);

	}

    glutTimerFunc(0, loadingbgm, 0);
	glutTimerFunc(0, updateredgreenlight, 0);
	glutTimerFunc(0, eliminated, 0);
    glutTimerFunc(0, updatelife, 0);
    glutTimerFunc(0, timerclockupdate, 0);
    glutTimerFunc(0, pinkblinkeliminate, 0);
    glutTimerFunc(0, updatemix, 0);
    glutTimerFunc(0, gunshot, 0);
    glutTimerFunc(0, upbutton, 0);
    glutTimerFunc(0, startcountdown, 0);
        glutTimerFunc(0, reset, 0);
glutKeyboardFunc(keyboard);
glutSpecialFunc(keymoveman);
	glutReshapeFunc(handleResize);

    //glutFullScreen();

	glutMainLoop();
	return 0;
}










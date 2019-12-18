

#include <stdlib.h>
#include<Windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<math.h>

#include<stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/GLAUX.h>

double a=0.0,b=0.0,c=3.0;
GLfloat	l_t=0;
float PI=3.1416;



GLuint texture[50];
void LoadGLTextures()
{
	glPushMatrix();
	AUX_RGBImageRec* TextureImage;

	glGenTextures(6,texture);

	if (TextureImage = auxDIBImageLoad("D:\\A.FDrive\\CSE-414 Computer Graphics Sessional\\3D projects\\Bus_Stand_3D\\Bus_Stand_3D\\bin\\Debug\\staircase12.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}
	if (TextureImage = auxDIBImageLoad("D:\\A.FDrive\\CSE-414 Computer Graphics Sessional\\3D projects\\Bus_Stand_3D\\Bus_Stand_3D\\bin\\Debug\\wall.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[1]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}
	if (TextureImage = auxDIBImageLoad("D:\\A.FDrive\\CSE-414 Computer Graphics Sessional\\3D projects\\Bus_Stand_3D\\Bus_Stand_3D\\bin\\Debug\\crest.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}
	if (TextureImage = auxDIBImageLoad("D:\\A.FDrive\\CSE-414 Computer Graphics Sessional\\3D projects\\Bus_Stand_3D\\Bus_Stand_3D\\bin\\Debug\\road.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[3]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}
	if (TextureImage = auxDIBImageLoad("D:\\A.FDrive\\CSE-414 Computer Graphics Sessional\\3D projects\\Bus_Stand_3D\\Bus_Stand_3D\\bin\\Debug\\grass.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[4]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}
	if (TextureImage = auxDIBImageLoad("D:\\A.FDrive\\CSE-414 Computer Graphics Sessional\\3D projects\\Bus_Stand_3D\\Bus_Stand_3D\\bin\\Debug\\bus.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[5]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}
	if (TextureImage = auxDIBImageLoad("D:\\A.FDrive\\CSE-414 Computer Graphics Sessional\\3D projects\\Bus_Stand_3D\\Bus_Stand_3D\\bin\\Debug\\window1.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[6]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}



}

void init(void)
{

   glClearColor (0.07, 0.82, 0.98, 0);
   glOrtho(-5,5,-5,5,-5,5);
   LoadGLTextures();
}

void busStop()
{
    ///Right wall
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glColor3ub(169,169,169);
    glBegin(GL_QUADS);
       glTexCoord2f(0,0); glVertex3f(-0.05,0.05,-0.8); //1
       glTexCoord2f(0,1); glVertex3f(-0.05,0.9,-0.8);  //2
        glTexCoord2f(1,1);glVertex3f(-0.05,0.9,-1);  //3
        glTexCoord2f(1,0); glVertex3f(-0.05,0.1,-1);  //4
    glEnd();
    glPopMatrix();

    ///Left wall
    glPushMatrix();
    glTranslatef(-0.7,0.0,0.0);
    glColor3ub(169,169,169);
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glBegin(GL_QUADS);
        glTexCoord2f(0,0); glVertex3f(-0.05,0.05,-0.8); //1
       glTexCoord2f(0,1);  glVertex3f(-0.05,0.9,-0.8);  //2
       glTexCoord2f(1,1);  glVertex3f(-0.05,0.9,-1);  //3
       glTexCoord2f(1,0); glVertex3f(-0.05,0.1,-1);  //4
    glEnd();
    glPopMatrix();

    ///Roof

    glColor3ub(255,255,0); ///Dark gray
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glBegin(GL_QUADS);
         glTexCoord2f(0,0); glVertex3f(-0.05,0.9,-0.8); //1
         glTexCoord2f(0,1); glVertex3f(-0.75,0.9,-0.8);  //2
         glTexCoord2f(1,1); glVertex3f(-0.75,0.9,-1);  //3
         glTexCoord2f(1,0); glVertex3f(-0.05,0.9,-1);  //4
    glEnd();

    ///Shade
    glColor3ub(165,42,42);
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glBegin(GL_QUADS);
       glTexCoord2f(0,0); glVertex3f(-0.05,0.9,-0.8);
        glTexCoord2f(0,1); glVertex3f(-0.75,0.9,-0.8);
        glTexCoord2f(1,1); glVertex3f(-0.75,0.7,-0.6);
       glTexCoord2f(1,0);  glVertex3f(-0.05,0.7,-0.6);
    glEnd();

    ///Stop Sign
    glPushMatrix();
    glColor3ub(255,255,0);

    //glBindTexture(GL_TEXTURE_2D, texture[7]);
    glBegin(GL_POLYGON);

    /*for(int i=0;i<100;i++){
        float angle = 2*PI*i/100;

        glVertex3f(-0.75+cos(angle)*0.1,0.55+sin(angle)*0.1,-0.65);
    }*/

    /*glTexCoord2f(0,1);*/ glVertex3f(-0.80,0.55,-0.65);
    /*glTexCoord2f(1,1);*/ glVertex3f(-0.80,0.40,-0.65);
    /*glTexCoord2f(1,1);*/ glVertex3f(-0.70,0.40,-0.65);
    /*glTexCoord2f(1,0);*/ glVertex3f(-0.70,0.55,-0.65);
    glEnd();
    glPopMatrix();

    ///Stop Sign Stand
    glLineWidth(3.0);
    glBegin(GL_LINES);
        glColor3ub(0,0,0);
        glVertex3f(-0.75,0.05,-0.65);
        glVertex3f(-0.75,0.55,-0.65);

    glEnd();



    ///Shade Stand
    glLineWidth(3.0);
    glBegin(GL_LINES);
        glColor3ub(0,0,0);
        glVertex3f(-0.08,0.75,-0.65);
        glVertex3f(-0.08,0.05,-0.65);
        glVertex3f(-0.70,0.75,-0.65);
        glVertex3f(-0.70,0.05,-0.65);

    glEnd();

    ///Back wall
     glColor3ub(10,50,80); ///Dark gray
     glBindTexture(GL_TEXTURE_2D, texture[1]);
    glBegin(GL_QUADS);
        glTexCoord2f(0,0); glVertex3f(-0.05,0.1,-1); //1
        glTexCoord2f(0,1); glVertex3f(-0.75,0.1,-1);  //2
        glTexCoord2f(1,1); glVertex3f(-0.75,0.9,-1);  //3
        glTexCoord2f(1,0); glVertex3f(-0.05,0.9,-1);  //4
    glEnd();






}

void wheelsFront()
{
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);

    for(int i=0;i<100;i++){
        float angle = 2*PI*i/100;

        glVertex3f(0.30+cos(angle)*0.06,0.05+sin(angle)*0.06,-0.05);
    }
    glEnd();

    glBegin(GL_POLYGON);

    for(int i=0;i<100;i++){
        float angle = 2*PI*i/100;

        glVertex3f(0.80+cos(angle)*0.06,0.05+sin(angle)*0.06,-0.05);
    }
    glEnd();

}

void wheelsBack()
{
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);

    for(int i=0;i<100;i++){
        float angle = 2*PI*i/100;

        glVertex3f(0.30+cos(angle)*0.06,0.05+sin(angle)*0.06,-0.40);
    }
    glEnd();

    glBegin(GL_POLYGON);

    for(int i=0;i<100;i++){
        float angle = 2*PI*i/100;

        glVertex3f(0.80+cos(angle)*0.06,0.05+sin(angle)*0.06,-0.40);
    }
    glEnd();

}




void windowStripesFront()
{
    glLineWidth(1.0);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
        glVertex3f(0.28,0.50,-0.05);
        glVertex3f(0.28,0.3,-0.05);

        glVertex3f(0.38,0.50,-0.05);
        glVertex3f(0.38,0.3,-0.05);

        glVertex3f(0.48,0.50,-0.05);
        glVertex3f(0.48,0.3,-0.05);

        glVertex3f(0.58,0.50,-0.05);
        glVertex3f(0.58,0.3,-0.05);

        glVertex3f(0.68,0.50,-0.05);
        glVertex3f(0.68,0.3,-0.05);

        glVertex3f(0.78,0.50,-0.05);
        glVertex3f(0.78,0.3,-0.05);

        glVertex3f(0.88,0.50,-0.05);
        glVertex3f(0.88,0.3,-0.05);
    glEnd();
}



void windowFront()
{

    windowStripesFront();
    //glBindTexture(GL_TEXTURE_2D, texture[6]);
    glBegin(GL_QUADS);
        glColor3ub(179,224,242);

        /*glTexCoord2f(0,0);*/ glVertex3f(0.18,0.3,-0.05);
        /*glTexCoord2f(0,1);*/ glVertex3f(0.18,0.50,-0.05);
        /*glTexCoord2f(1,1);*/ glVertex3f(0.94,0.50,-0.05);
        /*glTexCoord2f(1,0);*/ glVertex3f(0.94,0.3,-0.05);
    glEnd();



}


void windowStripesback()
{
    glLineWidth(1.0);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
        glVertex3f(0.18,0.50,-0.40);
        glVertex3f(0.18,0.3,-0.40);

        glVertex3f(0.38,0.50,-0.40);
        glVertex3f(0.38,0.3,-0.40);

        glVertex3f(0.48,0.50,-0.40);
        glVertex3f(0.48,0.3,-0.40);

        glVertex3f(0.58,0.50,-0.40);
        glVertex3f(0.58,0.3,-0.40);

        glVertex3f(0.68,0.50,-0.40);
        glVertex3f(0.68,0.3,-0.40);

        glVertex3f(0.78,0.50,-0.40);
        glVertex3f(0.78,0.3,-0.40);

        glVertex3f(0.88,0.50,-0.40);
        glVertex3f(0.88,0.3,-0.40);
    glEnd();
}

void windowBack()
{
    windowStripesback();
    glBegin(GL_QUADS);
        glColor3ub(179,224,242);

        glVertex3f(0.05,0.3,-0.40);
        glVertex3f(0.08,0.50,-0.40);
        glVertex3f(0.94,0.50,-0.40);
        glVertex3f(0.94,0.3,-0.40);
    glEnd();
}

void door()
{
    glLineWidth(1.0);
    glBegin(GL_LINES);
        glColor3f(0.0,0.0,0.0);
        glVertex3f(0.10,0.55,-0.05);
        glVertex3f(0.10,0.07,-0.05);
    glEnd();

     glBegin(GL_POLYGON);
        glColor3ub(113,197,231); ///Sky blue

        glVertex3f(0.02,0.07,-0.05); //1
        glVertex3f(0.02,0.3,-0.05); //2
        glVertex3f(0.07,0.55,-0.05); //3
        glVertex3f(0.15,0.55,-0.05); //4
        glVertex3f(0.15,0.07,-0.05); //5
    glEnd();
}

void busRoof()
{
     ///Top
     glBegin(GL_QUADS);
        glColor3f(0.0,0.0,1.0);
        glVertex3f(0.05,0.6,-0.05); //3

        glVertex3f(0.05,0.6,-0.40);

        glVertex3f(0.95,0.6,-0.40);
        glColor3ub(18,210,249);
        glVertex3f(0.95,0.6,-0.05); //4
    glEnd();

}

void busBack()
{
    wheelsBack();
    windowBack();
     ///Back
     glBegin(GL_POLYGON);
        glColor3f(1.0,0.0,0.0); ///Red

        glVertex3f(0.0,0.05,-0.40); //1
        glVertex3f(0.0,0.3,-0.40); //2
        glVertex3f(0.05,0.6,-0.40); //3
        glVertex3f(0.95,0.6,-0.40); //4
        glVertex3f(0.96,0.58,-0.40); //5
        glVertex3f(0.96,0.05,-0.40); //6

    glEnd();
}

void rightWindow()
{
    //windowStripesback();
    glBegin(GL_QUADS);
        glColor3ub(179,224,242);

        glVertex3f(0.96,0.3,-0.07);
        glVertex3f(0.96,0.50,-0.07);
        glVertex3f(0.96,0.50,-0.38);
        glVertex3f(0.96,0.3,-0.38);
    glEnd();

}

void busRight()
{
    rightWindow();
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);

        glVertex3f(0.95,0.6,-0.05); //1
        glVertex3f(0.95,0.6,-0.40); //2
        glVertex3f(0.96,0.58,-0.40); //3
        glVertex3f(0.96,0.05,-0.40); //4
        glVertex3f(0.96,0.05,-0.05); //5
        glVertex3f(0.96,0.58,-0.05); //6
    glEnd();
}

void bumper()
{
     ///Bumper
     glBegin(GL_QUADS);
        glColor3ub(0,255,0);
        glVertex3f(0.0,0.05,-0.04);
        glVertex3f(0.0,0.09,-0.04);
        glVertex3f(0.0,0.09,-0.41);
        glVertex3f(0.0,0.05,-0.41);
    glEnd();
}

void busLeft()
{
    bumper();
    ///Glass
    glBegin(GL_QUADS);
        glColor3ub(179,224,242);
        glVertex3f(0.0,0.3,-0.05); //1
        glVertex3f(0.05,0.55,-0.05); //2
        glVertex3f(0.05,0.55,-0.40); //3
        glVertex3f(0.0,0.3,-0.40); //4
    glEnd();
    ///Upper part of glass
     glBegin(GL_QUADS);
        glColor3ub(255,0,0);
        glVertex3f(0.05,0.55,-0.05);
        glVertex3f(0.05,0.6,-0.05);
        glVertex3f(0.05,0.6,-0.40);
        glVertex3f(0.05,0.55,-0.40);
    glEnd();
    ///Lower part of glass
     glBegin(GL_QUADS);
        glColor3ub(255,0,0);
        glVertex3f(0.0,0.05,-0.05);
        glVertex3f(0.0,0.3,-0.05);
        glVertex3f(0.0,0.3,-0.40);
        glVertex3f(0.0,0.05,-0.40);
    glEnd();



}


void bus()
{
    ///Main Body
    glTranslatef(-0.1,0.0,0.0);
    wheelsFront();
    windowFront();
    busRoof();
    busBack();
    door();
    busRight();
    busLeft();

    glBegin(GL_POLYGON);
        ///Front
        glColor3f(1.0,0.0,0.0); ///Red
        glTranslatef(-0.1,0.0,0.0);

         glVertex3f(0.0,0.05,-0.05); //1
         glVertex3f(0.0,0.3,-0.05); //2
         glVertex3f(0.05,0.6,-0.05); //3
         glVertex3f(0.95,0.6,-0.05); //4
        glVertex3f(0.96,0.58,-0.05); //5
        glVertex3f(0.96,0.05,-0.05); //6

        ///Top
       /* glColor3f(0.0,1.0,0.0);
        glVertex3f(0.05,0.6,-0.05); //3
        glVertex3f(0.05,0.6,-0.40);
        glVertex3f(0.95,0.6,-0.40);
        glVertex3f(0.95,0.6,-0.05); //4*/




    glEnd();

    ///Door


}

void quad()
{
        ///Road_Begins
        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, texture[3]);
        glBegin(GL_QUADS);

           //glColor3f(0.0,0.0,0.0);

            glTexCoord2f(0,0); glVertex3f(-1.0,0.0,0.5);
           glTexCoord2f(0,1); glVertex3f(-1.0,0.0,-0.5);
           glTexCoord2f(1,1); glVertex3f(1.0,0.0,-0.5);
           glTexCoord2f(1,0); glVertex3f(1.0,0.0,0.5);


        glEnd();
        glPopMatrix();
        ///Road Ends

        ///RoadLine Begins

        /*glLineWidth(3.0);
        glBegin(GL_LINES);
            glColor3f(1.0,1.0,1.0);

            glVertex3f(-0.95,0.0,0);
            glVertex3f(-0.75,0.0,0);

            glVertex3f(-0.60,0.0,0);
            glVertex3f(-0.40,0.0,0);

            glVertex3f(-0.25,0.0,0);
            glVertex3f(-0.05,0.0,0);

            glVertex3f(0.10,0.0,0);
            glVertex3f(0.30,0.0,0);

            glVertex3f(0.45,0.0,0);
            glVertex3f(0.65,0.0,0);

            glVertex3f(0.80,0.0,0);
            glVertex3f(0.98,0.0,0);
        glEnd();
        glPopMatrix();*/
        ///RoadLine Ends

        ///Footpath(Front Face)
       /* glColor3f(0,0,1); ///Silver color
        glRectf(-1.0,0.0,1.0,0.05);*/
        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, texture[0]);
        glBegin(GL_QUADS);
            //glColor3f(0,0,1); ///Blue color
            glTexCoord3f(0,0,0); glVertex3f(-1.0,0.0,-0.5);
            glTexCoord3f(0,0,1); glVertex3f(-1.0,0.05,-0.5);
            glTexCoord3f(0,1,0); glVertex3f(1.0,0.05,-0.5);
            glTexCoord3f(0,1,1); glVertex3f(1.0,0.0,-0.5);
        glEnd();
        glPopMatrix();

        ///Top face
        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, texture[0]);
        glBegin(GL_QUADS);
            glColor3ub(128,128,128); ///Red color

            glTexCoord3f(0,0,0); glVertex3f(-1.0,0.05,-0.5);
            glTexCoord3f(0,0,1); glVertex3f(-1.0,0.05,-0.7);
            glTexCoord3f(0,1,0); glVertex3f(1.0,0.05,-0.7);
            glTexCoord3f(0,1,1); glVertex3f(1.0,0.05,-0.5);
        glEnd();
        glPopMatrix();

        ///Grass(Bus stop side)

        glBindTexture(GL_TEXTURE_2D, texture[4]);
         glBegin(GL_QUADS);
            //glColor3f(0,1,0); ///Green color

            glTexCoord2f(0,0); glVertex3f(-1.0,0.05,-0.7);
            glTexCoord2f(0,1); glVertex3f(-1.0,0.1,-1);
            glTexCoord2f(1,1); glVertex3f(1.0,0.1,-1);
            glTexCoord2f(1,0); glVertex3f(1.0,0.05,-0.7);
        glEnd();


        ///Grass(Opposite of bus stop)

        glBindTexture(GL_TEXTURE_2D, texture[4]);
         glBegin(GL_QUADS);
            //glColor3f(0,1,0); ///Green color

            glTexCoord2f(0,0); glVertex3f(-1.0,0.0,0.5);
            glTexCoord2f(0,1); glVertex3f(-1.0,0.0,1);
            glTexCoord2f(1,1); glVertex3f(1.0,0.0,1);
            glTexCoord2f(1,0); glVertex3f(1.0,0.0,0.5);
        glEnd();



        ///Back




}

void bsFloor()
{
     ///Floor of Bus Stop
    glColor3ub(255,255,0); ///Dark gray
    //glBindTexture(GL_TEXTURE_2D, texture[1]);
    glBegin(GL_QUADS);
        glVertex3f(-0.05,0.05,-0.8); //1
         glVertex3f(-0.75,0.05,-0.8);  //2
         glVertex3f(-0.75,0.1,-1);  //3
         glVertex3f(-0.05,0.1,-1);  //4
    glEnd();
}


void display(void)
{

   glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT); // GL_COLOR_BUFFER_BIT indicates that the buffer is currently enabled for color writing
   glMatrixMode(GL_PROJECTION);       // Specify which matrix is the current matrix mode
   glLoadIdentity();                  // Replace the current matrix with the identity matrix
   int w=glutGet(GLUT_WINDOW_WIDTH);
   int h=glutGet(GLUT_WINDOW_HEIGHT);
   gluPerspective(37,w/h,0.1,100);    // fovy specifies the field of view angle in degrees in y direction, aspect specifies aspect ratio that determines the field of view in the x direction, znear and zfar specifies the distance from viewer to the near and far clipping plane respectively (always positive)
   glMatrixMode(GL_MODELVIEW);       //  To allow transformation on 3D object

   glLoadIdentity();
   gluLookAt(                        //  eyex, eyey, eyez specify the position of the eye point, centerx, centery, centerz specify the position of reference point, upx, upy, upz specify the direction of up vector
               a,b,c,
               0,0,0,
               0,1,0
             );
   glPushMatrix();
   glRotatef(l_t,0.0f,1.0f,0.0f);

   glEnable(GL_TEXTURE_2D);
   //bsFloor();
   quad();
   bus();
    glDisable(GL_TEXTURE_2D);

   glPushMatrix();
   glTranslatef(0.05,0.0,0.0);
   glEnable(GL_TEXTURE_2D);
   busStop();
   glDisable(GL_TEXTURE_2D);
   glPopMatrix();

   glPopMatrix();

   glutSwapBuffers();

}
void my_keyboard(unsigned char key, int p, int q)
{
switch (key) {
    case 'f':  //front view
        a=0.0,b=0.0,c=5.0,l_t=0;
        glutPostRedisplay();
		break;
    case 'b':  //back view
        a=0.0,b=0.0,c=-5.0,l_t=0;
        glutPostRedisplay();
		break;
    case 'l':  //left view
        a=-5.0,b=0.0,c=0.0,l_t=0;
        glutPostRedisplay();
		break;
    case 'r':  //right view
        a=5.0,b=0.0,c=0.0,l_t=0;
        glutPostRedisplay();
		break;
    case 't': //top view
        a=0.0,b=5.0,c=0.0001,l_t=0;
        glutPostRedisplay();
		break;
    case 'm': //bottom view
        a=0.0,b=-5.0,c=0.0001,l_t=0;
        glutPostRedisplay();
		break;
     default:
        break;
}
}

void spinDisplay_left(void)		//spin speed
{

    l_t =l_t-0.2;
    glutPostRedisplay();
}

void spinDisplay_right(void)		//spin speed
{

    l_t =l_t+0.2;
    glutPostRedisplay();
}

void specialKeys(int key,int x,int y)
{
    if(key==GLUT_KEY_RIGHT)
           a++;
    else if(key==GLUT_KEY_LEFT)
            a--;
    else if(key==GLUT_KEY_UP)
            c--;
    else if(key==GLUT_KEY_DOWN)
            c++;
    glutPostRedisplay();
}

void mouse(int button, int state, int s, int t)
{

   switch (button)
   {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay_left);
         break;
      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay_right);
          break;
      case GLUT_MIDDLE_BUTTON:
          if (state == GLUT_DOWN)
            glutIdleFunc(NULL);
         break;
      default:
         break;
   }
}

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (800, 600);
	glutInitWindowPosition (0, 0);
	glutCreateWindow ("Bus Stop");
	init();
	glEnable(GL_DEPTH_TEST);
    glutSpecialFunc(specialKeys);
    glutDisplayFunc(display);
    glutKeyboardFunc(my_keyboard);
    glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

static int shoulder = 0, elbow = 0, dedo1 = 0, dedo2 = 0, dedo3 = 0;

void init(void) 
{
  glClearColor (0.0, 0.0, 0.0, 0.0);
  glShadeModel (GL_FLAT);
}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);		//apaga
   glPushMatrix();				//salva a matriz embaixo (empurra)
   glTranslatef (-1.0, 0.0, 0.0);		//		
   glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);	//multiplica pela matriz T que estava no topo da pilha
   glTranslatef (1.0, 0.0, 0.0);			//
   glPushMatrix();
   glScalef (2.0, 0.4, 1.0);
   glutWireCube (1.0);
   glPopMatrix();

   glTranslatef (1.0, 0.0, 0.0); 		//translação que muda o eixo de rotação para ele não rotacionar na origem, se não a rotação ficaria em relação ao eixo central do cubo e não a arestas
   glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);
   glTranslatef (1.0, 0.0, 0.0);
   glPushMatrix();
   glScalef (2.0, 0.4, 1.0);
   glutWireCube (1.0);
   glPopMatrix();

   //desenhando os dedos:
   //dedo 1:
   glPushMatrix();
   glTranslatef (0.3, 0.0, 0.2);
   glRotatef ((GLfloat) dedo1, 0.0, 0.0, 1.0);
   glTranslatef (1.0, 0.0, 0.0);
   glPushMatrix();
   glScalef (2.0, 0.4, 1.0);
   glutWireCube (0.3);
   glPopMatrix();
   glPopMatrix();

   //dedo 2:
   glPushMatrix();
   glTranslatef (0.3, 0.0, 0.0);
   glRotatef ((GLfloat) dedo2, 0.0, 0.0, 1.0);
   glTranslatef (1.0, 0.0, 0.0);
   glPushMatrix();
   glScalef (2.0, 0.4, 1.0);
   glutWireCube (0.3);
   glPopMatrix();
   glPopMatrix();

   //dedo 3:
   glPushMatrix();
   glTranslatef (0.3, 0.0, -0.2);
   glRotatef ((GLfloat) dedo3, 0.0, 0.0, 1.0);
   glTranslatef (1.0, 0.0, 0.0);
   glPushMatrix();
   glScalef (2.0, 0.4, 1.0);
   glutWireCube (0.3);
   glPopMatrix();
   glPopMatrix();

   glPopMatrix();
   glutSwapBuffers();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef (0.0, 0.0, -5.0);
}

void keyboard (unsigned char key, int x, int y)
{
   switch (key) {
      case 's':   /*  s key rotates at shoulder  */
         shoulder = (shoulder + 5) % 360;
         glutPostRedisplay();
         break;
      case 'S':
         shoulder = (shoulder - 5) % 360;
         glutPostRedisplay();
         break;
      case 'e':  /*  e key rotates at elbow  */
         elbow = (elbow + 5) % 360;
         glutPostRedisplay();
         break;
      case 'z':
      if (dedo1 >= 0 && dedo1 < 60){
         dedo1 = (dedo1 + 5) % 360;
      }else{
	 dedo1 = 60;
      }
         glutPostRedisplay();
         break;
      case 'Z':
      if (dedo1 <= 60 && dedo1 > 0){
         dedo1 = (dedo1 - 5) % 360;
      }else{
	 dedo1 = 0;
      }
         glutPostRedisplay();
         break;
      case 'x':
         dedo2 = (dedo2 + 5) % 360;
         glutPostRedisplay();
         break;
      case 'c':
         dedo3 = (dedo3 + 5) % 360;
         glutPostRedisplay();
         break;
      default:
         break;
   }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);		
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   //3 eventos:
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}

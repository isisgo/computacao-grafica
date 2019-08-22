#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);
   glColor3f (1.0, 1.0, 1.0);
   glLoadIdentity ();             /* clear the matrix */
           /* viewing transformation  */
   //gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); //trabalha na pilha model/view
   // A função glTranslatef() abaixo move o mundo no eixo z para -5, que é a mesma coisa de mover a câmera para +5
   glTranslatef(0.0, 0.0, -5.0);	//câmera posicionada em 5	
   glScalef (1.0, 2.0, 1.0);      /* modeling transformation */ 
   glutWireCube (1.0);		//tamanho do cubo que é desenhado na origem, 0.5 pra cada lado dos eixos
   glFlush ();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   //glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0); //define o plano de corte --- projeção, pilha projection
   gluPerspective(60.0, 1.0, 4.6, 5.4);	//angulo de abertura de visao da camera, razao de aspecto - tamanho da janela (acima de 1 ou abaixo de 1), plano de corte mais perto e plano de corte mais longe (ambos iguais o Frustum)
   //gluPerspective(30.0, 1.0, 1.5, 5.4); //com esse valor de plano de corte mais longe do Frustum
   //gluPerspective(60.0, 1.0, 4.6, 5.4); //com esses dois últimos valores cortamos os dois planos do cubo
   glMatrixMode (GL_MODELVIEW);
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutMainLoop();
   return 0;
}

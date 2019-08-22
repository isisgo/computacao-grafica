#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);	//cor de apagar: preto
   glShadeModel (GL_FLAT);
}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);	//apaga o buffer (janela)
   glColor3f (1.0, 1.0, 1.0);		//acerta a cor para branco
   glLoadIdentity ();             /* clear the matrix */
   //pega a matriz identidade e coloca na pilha model/view - transforma de coordenada de mundo para coordenada de câmera
           /* viewing transformation  */
   gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);	//informa pro OpenGL pra onde a camera está olhando 
   //os 3 primeiros parametros sao a posição da camera, os 3 próximos são para onde ela está olhando, e os 3 últimos são o vUP -> look from, lookat, vUP
   glScalef (1.0, 2.0, 1.0);      /* modeling transformation */ //scale, translate ou rotate - move o mundo
   glutWireCube (1.0);

   glMatrixMode (GL_MODELVIEW);
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); //single buffer pq nao tem animação
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);	//posição em relação ao monitor
   glutCreateWindow (argv[0]); 		//cria a janela
   init ();
   glutDisplayFunc(display); 		//funcao display com evento de display (ocorre toda vez que vc faz uma operação com sua janela - ex. mudar o tam.)
   glutReshapeFunc(reshape);		//funcao que redesenha
   glutMainLoop();
   return 0;
}

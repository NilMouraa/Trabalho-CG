#include <stdio.h>
#include <string.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include "Introducao.h"
#include "Tela.h"
#include "TiroEspecial.h"
#include "Bloco.h"

using namespace std;

#define DIM_X_TANK 15.0
#define DIM_Y_TANK 15.0
#define DIM_X_BLOC 18.0
#define DIM_Y_BLOC 18.0

GLfloat x2 = 100.0f;
GLfloat y2 = 150.0f;
GLfloat xstep = 1.0f;
GLfloat ystep = 1.0f;
GLsizei rsize = 20;
GLfloat windowWidth;
GLfloat windowHeight;

//********************CABEÇALHOS********************
void Timer(int value);

//*************************************************


Bloco      *b = new Bloco(50, 50, 0, DIM_X_BLOC, DIM_Y_BLOC);
Bloco      *b1 = new Bloco(50, 68, 0, DIM_X_BLOC, DIM_Y_BLOC);
Bloco      *b2 = new Bloco(50, 86, 0, DIM_X_BLOC, DIM_Y_BLOC);
Bloco      *b3 = new Bloco(50, 104, 0, DIM_X_BLOC, DIM_Y_BLOC);
Bloco      *b4 = new Bloco(50, 122, 0, DIM_X_BLOC, DIM_Y_BLOC);
Bloco      *b5 = new Bloco(50, 140, 0, DIM_X_BLOC, DIM_Y_BLOC);
Bloco      *b6 = new Bloco(50, 158, 0, DIM_X_BLOC, DIM_Y_BLOC);
TiroEspecial *te = new TiroEspecial(0, 0, 0);
bool criou = false;
//Introducao *intro = new Introducao		();
//TiroEspecial *tiro	= new TiroEspecial	(100,10,0);
//Explosao   *explo   = new Explosao		(100,100,0,75,2);
Tank	   *t = new Tank(100, 100, 0, 1);
Tela	   *tela = new Tela();


bool crtlTecla = false;

void keyboardDown(unsigned char key, int x, int y) {

	switch (key)
	{
	case 'f':
		crtlTecla = !crtlTecla;
		if (crtlTecla)
			glutFullScreen();
		else
			glutReshapeWindow(1024, 690);
		break;
	case 'a':
		t->viraEsquerda(1, tela->semColisao(t, 1, 'e',1));
		break;

	case 'd':
		t->viraDireita(1,tela->semColisao(t,1,'d',1));
		
		break;

	case 'w':
		t->viraCima(1, tela->semColisao(t, 1, 'c',1));
		break;

	case 's':
		t->viraBaixo(1, tela->semColisao(t, 1, 'b',1));
		break;
	case 32:
		cout << "entrou32";



		if (t->getAngulo() == 0) {
			t->atiraEspecial(t->getPosiCentroX(), t->getPosiY() + 1.15*t->getDimY() + 70);
		}
		else if (t->getAngulo() == 180) {
			t->atiraEspecial(t->getPosiCentroX(), t->getPosiY() - 1.15*t->getDimY() - 70);
		}
		break;
	}

}
void Timer(int value)
{

	glutPostRedisplay();
	glutTimerFunc(1, Timer, 1);
}
void Desenha(void) {

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	if (!criou) {
		tela->addBloco(b);
		tela->addBloco(b1);
		tela->addBloco(b2);
		tela->addBloco(b3);
		tela->addBloco(b4);
		tela->addBloco(b5);
		tela->addBloco(b6);
		tela->addTankes(t);
		criou = true;
	}
	tela->desenhaBlocos();
	tela->desenhaTankes();
	if (te->getStatus() != 'i') {
		te->desenha(0, 100);
	}

	//introdu->Desenha();
	//introdu->Incrementa(3);
	//tiro->desenha(100,250);

	/*explo->desenha();
	explo->incrementaTamanho(1);*/
	//tela->desenhaTankes();
	//tela->desenhaBlocos();
	/*explo->desenha();
	explo->incrementaTamanho(1);
	explo-> desenhaParte('g');
	explo-> desenhaParte('m');
	explo-> desenhaParte('c');*/
	glFlush();

}
void Inicializa(void) {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
void AlteraTamanhoJanela(GLsizei w, GLsizei h) {
	if (h == 0)h = 1;

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (w <= h)
		gluOrtho2D(0.0f, 250.0f, 0.0f, 250.0f*h / w);
	else
		gluOrtho2D(0.0f, 250.0f*w / h, 0.0f, 250.0f);
}
int main(int argc, char **argv) {

	glutInit(&argc, argv);
	glutInitWindowSize(1024, 690);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Game");
	glutDisplayFunc(Desenha);
	glutKeyboardFunc(keyboardDown);
	glutReshapeFunc(AlteraTamanhoJanela);
	glutTimerFunc(1, Timer, 1);
	Inicializa();
	glutMainLoop();

	return 0;
}
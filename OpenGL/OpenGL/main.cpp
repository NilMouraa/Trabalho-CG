#include <stdio.h>
#include <string.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include "Introducao.h"
#include "Tela.h"
#include "TiroEspecial.h"
#include "Bloco.h"
#include "Tutorial.h"

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
void RetanguloMenu(char op);

//*************************************************


Bloco      *b = new Bloco(50, 50, 0, DIM_X_BLOC, DIM_Y_BLOC);
Bloco      *b1 = new Bloco(50, 68, 0, DIM_X_BLOC, DIM_Y_BLOC);
Bloco      *b2 = new Bloco(50, 86, 0, DIM_X_BLOC, DIM_Y_BLOC);
Bloco      *b3 = new Bloco(50, 104, 0, DIM_X_BLOC, DIM_Y_BLOC);
Bloco      *b4 = new Bloco(50, 122, 0, DIM_X_BLOC, DIM_Y_BLOC);
Bloco      *b5 = new Bloco(50, 140, 0, DIM_X_BLOC, DIM_Y_BLOC);
Bloco      *b6 = new Bloco(50, 158, 0, DIM_X_BLOC, DIM_Y_BLOC);
//TiroEspecial *te = new TiroEspecial(0, 0, 0,);
bool criou = false;
bool introAtiva = true;
bool menuAtiva = false;
bool tutorialAtiva = false;
Introducao *intro = new Introducao();
Tutorial *Tuto = new Tutorial();

//TiroEspecial *tiro	= new TiroEspecial	(100,10,0);
//Explosao   *explo   = new Explosao		(100,100,0,75,2);
Tank	   *t = new Tank(100, 100, 0, 1);
Tela	   *tela = new Tela();



bool fullscreenAtiva = false;

void keyboardDown(unsigned char key, int x, int y) {

	switch (key)
	{
	case 'f':
		fullscreenAtiva = !fullscreenAtiva;
		if (fullscreenAtiva)
			glutFullScreen();
		else
			glutReshapeWindow(1024, 690);
		break;
	case 'a':
		t->viraEsquerda(1, tela->semColisao(t, 1, 'e', 1));
		break;

	case 'd':
		t->viraDireita(1, tela->semColisao(t, 1, 'd', 1));

		break;

	case 'w':
		t->viraCima(1, tela->semColisao(t, 1, 'c', 1));
		break;

	case 's':
		t->viraBaixo(1, tela->semColisao(t, 1, 'b', 1));
		break;
	case 32:

		break;
	case 13:
		if (introAtiva) {
			intro->Incrementa(500);
			introAtiva = false;
			menuAtiva = true;
		}
		else if ((!introAtiva) && menuAtiva) {
			RetanguloMenu('j');
			Sleep(200);
		}
		break;
	case 'o':
		if ((!introAtiva) && menuAtiva) {
			RetanguloMenu('o');
			Sleep(200);
			tutorialAtiva = true;
			menuAtiva = false;
		}
		break;
	case 27:
		if ((!introAtiva) && menuAtiva) {
			RetanguloMenu('s');
			Sleep(200);
			exit(0);
		}
		break;
	case 8:
		if (tutorialAtiva && !(menuAtiva)) {
			RetanguloMenu('v');
			Sleep(200);
			tutorialAtiva = false;
			menuAtiva = true;
		}
	}

}
void mouseClick(int button, int state, int x, int y) {

	y = -y + windowHeight;
	y = 252 * y / windowHeight;
	x = 360 * x / windowWidth;

	if (x > 144 && x < 216) {
		if (y > 90 && y < 108) {
			if (introAtiva) {
				intro->Incrementa(500);
				introAtiva = false;
				menuAtiva = true;
			}
			else if ((!introAtiva) && menuAtiva) {
				RetanguloMenu('j');
				Sleep(200);
			}
		}
		else if (y > 54 && y < 72) {
			if ((!introAtiva) && menuAtiva) {
				RetanguloMenu('o');
				Sleep(200);
				tutorialAtiva = true;
				menuAtiva = false;
			}
		}
		else if (y > 18 && y < 36) {
			if ((!introAtiva) && menuAtiva) {
				RetanguloMenu('s');
				Sleep(200);
				exit(0);
			}
		}
	}
	else if (x > 252 && x < 324) {
		if (y > 18 && y < 36) {
			if ((tutorialAtiva) && !menuAtiva) {
				RetanguloMenu('v');
				Sleep(200);
				tutorialAtiva = false;
				menuAtiva = true;
			}
		}
	}
}
void Timer(int value)
{

	glutPostRedisplay();
	glutTimerFunc(1, Timer, 1);
}
void renderBitmapString(float x, float y, void *font, const char *string) {
	const char *c;
	glRasterPos2f(x, y);
	for (c = string; *c != '\0'; c++) {
		glutBitmapCharacter(font, *c);
	}
}
void DesenhaBlocosMenu() {
	glPushMatrix();
	for (int i = 0; i <= 127; i += 18) {
		for (int j = 0; j <= 108; j += 18) {

			Bloco *b1 = new Bloco(i, j, 0, DIM_X_BLOC, DIM_Y_BLOC);
			Bloco *b2 = new Bloco(i + 216, j, 0, DIM_X_BLOC, DIM_Y_BLOC);

			b1->desenha();
			b2->desenha();
		}
	}
	for (int i = 144; i <= 326; i += 18) {
		for (int j = 108; j >= 0; j -= 36) {
			Bloco *b2 = new Bloco(i, j, 0, DIM_X_BLOC, DIM_Y_BLOC);

			b2->desenha();

		}
	}
	glPopMatrix();
}
void RetanguloMenu(char op) {
	glPushMatrix();

	glColor3f(1, 0, 0);
	if (op == 'j') {
		glTranslatef(144, 90, 0);
	}
	else if (op == 'o') {
		glTranslatef(144, 54, 0);
	}
	else if (op == 's') {
		glTranslatef(144, 18, 0);
	}
	else if (op == 'v') {
		glTranslatef(252, 18, 0);
	}
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(0, 2);
	glVertex2f(72, 2);
	glVertex2f(72, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(0, 16);
	glVertex2f(0, 18);
	glVertex2f(72, 18);
	glVertex2f(72, 16);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(0, 18);
	glVertex2f(2, 18);
	glVertex2f(2, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(70, 0);
	glVertex2f(70, 18);
	glVertex2f(72, 18);
	glVertex2f(72, 0);
	glEnd();

	glPopMatrix();
	glFlush();
}
void DesenhaMenu() {
	glPushMatrix();
	int font = (int)GLUT_BITMAP_TIMES_ROMAN_24;
	char *texto = "Jogar";
	renderBitmapString(170, 96, (void *)font, texto);
	texto = "Opcoes";
	renderBitmapString(167, 60, (void *)font, texto);
	texto = "Sair";
	renderBitmapString(173, 24, (void *)font, texto);
	DesenhaBlocosMenu();
	glPopMatrix();
}
void Desenha(void) {

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	/*if (!criou) {
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
	/*if (te->getStatus() != 'i') {
		te->desenha(0, 100);
	}*/

	if (introAtiva || menuAtiva) {
		intro->Desenha(windowWidth, 280);
		intro->Incrementa(1);
		if (intro->getFim()) {
			DesenhaMenu();
			introAtiva = false;
			menuAtiva = true;
		}
	}
	else if (tutorialAtiva) {
		Tuto->desenha();
	}


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

	windowWidth = w;
	windowHeight = h;
	//if (h == 0)h = 1;

	//glViewport(0, 0, w, h);
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();

	//if (w <= h)
	//	gluOrtho2D(0.0f, 250.0f, 0.0f, 250.0f*h / w);
	//else
	//	gluOrtho2D(0.0f, 250.0f*w / h, 0.0f, 250.0f);

	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0f, 360.0f, 0.0f, 252.0f);
	/*glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();*/
}
int main(int argc, char **argv) {

	glutInit(&argc, argv);
	glutInitWindowSize(993.6, 690);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Game");
	glutDisplayFunc(Desenha);
	glutKeyboardFunc(keyboardDown);
	glutMouseFunc(mouseClick);
	glutReshapeFunc(AlteraTamanhoJanela);
	glutTimerFunc(1, Timer, 1);
	Inicializa();
	glutMainLoop();

	return 0;
}


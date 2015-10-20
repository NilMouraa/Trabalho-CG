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
#include "Final.h"
#include "GameOver.h"
#include "Reinicio.h"
#include "TelaChefao.h"
#include "FimDeFase.h"

using namespace std;

#define DIM_X_TANK 15.0
#define DIM_Y_TANK 15.0
#define DIM_X_BLOC 18.0
#define DIM_Y_BLOC 18.0

GLfloat x2		= 100.0f;
GLfloat y2		= 150.0f;
GLfloat xstep	= 1.0f;
GLfloat ystep	= 1.0f;
GLsizei rsize	= 20;

GLfloat windowWidth;
GLfloat windowHeight;

//********************CABEÇALHOS********************
void Timer(int value);
void RetanguloMenu(char op);

void Desenha(void);

//*************************************************


Bloco      *b  = new Bloco(50, 50, 0, DIM_X_BLOC, DIM_Y_BLOC);
Bloco      *b1 = new Bloco(50, 68, 0, DIM_X_BLOC, DIM_Y_BLOC);
Bloco      *b2 = new Bloco(50, 86, 0, DIM_X_BLOC, DIM_Y_BLOC);
Bloco      *b3 = new Bloco(50, 104, 0, DIM_X_BLOC, DIM_Y_BLOC);
Bloco      *b4 = new Bloco(50, 122, 0, DIM_X_BLOC, DIM_Y_BLOC);
Bloco      *b5 = new Bloco(50, 140, 0, DIM_X_BLOC, DIM_Y_BLOC);
Bloco      *b6 = new Bloco(50, 158, 0, DIM_X_BLOC, DIM_Y_BLOC);


bool criou				= false;
bool introAtiva			= true;
bool menuAtiva			= false;
bool tutorialAtiva		= false;
bool fase1Ativa			= false;
bool fase2Ativa			= false;
bool fase3Ativa			= false;
bool bossFase1Ativa		= false;
bool bossFase2Ativa		= false;
bool bossFase3Ativa		= false;
bool fimDeFase1Ativa	= false;
bool fimDeFase2Ativa	= false;
bool fimDeFase3Ativa	= false;
bool fullscreenAtiva	= false;
bool fimJogoAtiva		= false;
bool gameOverAtiva		= false;
bool reinicioAtiva		= false;

Introducao *intro		= new Introducao();
Tank	   *t			= new Tank(290, 100, 0, 7);
Tank       *p1			= new Tank(290, 100, 0, 6);
Tank       *p2			= new Tank(290, 100, 0, 6);
GameOver   *go			= new GameOver();
Final      *f			= new Final();
FimDeFase  *fimFase		= new FimDeFase(1);
Reinicio   *r			= new Reinicio();
TelaChefao *telaBoss	= new TelaChefao(3);
Tela       *tela	    = new Tela(1);
Tutorial   *Tuto		= new Tutorial();


void keyboardUp(unsigned char key, int x, int y) {
	switch (key)
	{
	case 32:
		if (fase1Ativa || fase2Ativa || fase3Ativa)tela->Atira(1);
		if (bossFase1Ativa || bossFase2Ativa || bossFase3Ativa)telaBoss->Atira(1);
		break;
	}
}

void keyboardDown(unsigned char key, int x, int y) {

	switch (key)
	{
	case 'f':
		fullscreenAtiva = !fullscreenAtiva;
		if (fullscreenAtiva)
			glutFullScreen();
		else
			glutReshapeWindow(993.6, 690);
		break;
	case 'a':
		if (fase1Ativa || fase2Ativa || fase3Ativa)tela->MoveTankPlayer('e', 1);
		if (bossFase1Ativa || bossFase2Ativa || bossFase3Ativa)telaBoss->MoveTankPlayer('e', 1);
		break;

	case 'd':
		if (fase1Ativa || fase2Ativa || fase3Ativa)tela->MoveTankPlayer('d', 1);
		if (bossFase1Ativa || bossFase2Ativa || bossFase3Ativa)telaBoss->MoveTankPlayer('d', 1);
		break;

	case 'w':
		if (fase1Ativa || fase2Ativa || fase3Ativa)tela->MoveTankPlayer('c', 1);
		if (bossFase1Ativa || bossFase2Ativa || bossFase3Ativa)telaBoss->MoveTankPlayer('c', 1);
		break;

	case 's':
		if (fase1Ativa || fase2Ativa || fase3Ativa)tela->MoveTankPlayer('b', 1);
		if (bossFase1Ativa || bossFase2Ativa || bossFase3Ativa)telaBoss->MoveTankPlayer('b', 1);
		break;

		//enter
	case 13:
		if (introAtiva) {
			intro->Incrementa(500);
			introAtiva = false;
			menuAtiva = true;
		}
		else if ((!introAtiva) && menuAtiva && (!fase1Ativa)) {
			RetanguloMenu('j');
			Sleep(200);
			fase1Ativa = true;
			introAtiva = false;
			menuAtiva = false;
		}
		else if (fase1Ativa)tela->setPlayer2();
		break;
	case 'o':
		if ((!introAtiva) && menuAtiva) {
			RetanguloMenu('o');
			Sleep(200);
			tutorialAtiva = true;
			menuAtiva = false;
		}
		break;
		//Esc
	case 27:
		if ((!introAtiva) && menuAtiva) {
			RetanguloMenu('s');
			Sleep(200);
			exit(0);
		}
		break;
		//Backspace
	case 8:
		if (tutorialAtiva && !(menuAtiva)) {
			RetanguloMenu('v');
			Sleep(200);
			tutorialAtiva = false;
			menuAtiva = true;
		}
		break;
	}

}
void mouseClick(int button, int state, int x, int y) {
	cout << "\n X: " << x;
	cout << "\n Y: " << y;
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
			else if ((!introAtiva) && menuAtiva && (!fase1Ativa)) {
				RetanguloMenu('j');
				Sleep(200);
				fase1Ativa = true;
				introAtiva = false;
				menuAtiva = false;
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
	glPushMatrix();
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
	else if (fimDeFase1Ativa) {
		fimFase->desenha();
		if (fimFase->getStatus() == 't')fimDeFase1Ativa = false;
	}
	else if (fimDeFase2Ativa) {
		fimFase->desenha();
		if (fimFase->getStatus() == 't')fimDeFase2Ativa = false;
	}
	else if (fimDeFase3Ativa) {
		fimFase->desenha();
		if (fimFase->getStatus() == 't')fimDeFase3Ativa = false;
	}
	else if (fase1Ativa) {
		if (reinicioAtiva) {
			if (r->getStatus() == 't') {
				reinicioAtiva = false;
			}
			else {
				r->desenha();
			}
		}
		else {
			tela->desenha();
			if (tela->morreu() && tela->gameOver() == false) {
				reinicioAtiva = true;
				r = new Reinicio();
				p1 = tela->getP1();
				p2 = tela->getP2();
				tela = new Tela(1);
				tela->setP1(p1);
				tela->setP2(p2);
			}
			else if (tela->gameOver()) {
				fase1Ativa = false;
				gameOverAtiva = true;
			}
			else if (tela->acabou()) {
				fase1Ativa = false;
				bossFase1Ativa = true;
				p1 = tela->getP1();
				p2 = tela->getP2();
				telaBoss = new TelaChefao(1);
				telaBoss->setP1(p1);
				telaBoss->setP2(p2);
			}
		}
	}
	else if (bossFase1Ativa) {
		telaBoss->desenha();
		if (telaBoss->morreu() && telaBoss->gameOver() == false) {
			reinicioAtiva = true;
			r = new Reinicio();
			p1 = tela->getP1();
			p2 = tela->getP2();
			tela = new Tela(1);
			tela->setP1(p1);
			tela->setP2(p2);
			fase1Ativa = true;
			bossFase1Ativa = false;
		}
		else if (telaBoss->gameOver()) {
			bossFase1Ativa = false;
			gameOverAtiva = true;
		}
		else if (telaBoss->acabou()) {
			bossFase1Ativa = false;
			p1 = tela->getP1();
			p2 = tela->getP2();
			tela = new Tela(2);
			tela->setP1(p1);
			tela->setP2(p2);
			fase2Ativa = true;
			fimDeFase1Ativa = true;
			fimFase = new FimDeFase(1);
		}
	}
	else if (fase2Ativa) {
		if (reinicioAtiva) {
			if (r->getStatus() == 't') {
				reinicioAtiva = false;
				r = new Reinicio();
			}
			else {
				r->desenha();
			}
		}
		else {
			tela->desenha();
			if (tela->morreu() && tela->gameOver() == false) {
				reinicioAtiva = true;
				r = new Reinicio();
				p1 = tela->getP1();
				p2 = tela->getP2();
				tela = new Tela(2);
				tela->setP1(p1);
				tela->setP2(p2);
			}
			else if (tela->gameOver()) {
				fase2Ativa = false;
				gameOverAtiva = true;
			}
			else if (tela->acabou()) {
				fase2Ativa = false;
				bossFase2Ativa = true;
				p1 = tela->getP1();
				p2 = tela->getP2();
				telaBoss = new TelaChefao(2);
				telaBoss->setP1(p1);
				telaBoss->setP2(p2);
			}
		}
	}
	else if (bossFase2Ativa) {
		telaBoss->desenha();
		if (telaBoss->morreu() && telaBoss->gameOver() == false) {
			reinicioAtiva = true;
			r = new Reinicio();
			p1 = tela->getP1();
			p2 = tela->getP2();
			tela = new Tela(2);
			tela->setP1(p1);
			tela->setP2(p2);
			fase2Ativa = true;
			bossFase2Ativa = false;
		}
		else if (telaBoss->gameOver()) {
			bossFase2Ativa = false;
			gameOverAtiva = true;
		}
		else if (telaBoss->acabou()) {
			bossFase2Ativa = false;
			p1 = tela->getP1();
			p2 = tela->getP2();
			tela = new Tela(3);
			tela->setP1(p1);
			tela->setP2(p2);
			fase3Ativa = true;
			fimDeFase2Ativa = true;
			fimFase = new FimDeFase(2);
		}
	}
	else if (fase3Ativa) {
		if (reinicioAtiva) {
			if (r->getStatus() == 't') {
				reinicioAtiva = false;
			}
			else {
				r->desenha();
			}
		}
		else {
			tela->desenha();
			if (tela->morreu() && tela->gameOver() == false) {
				reinicioAtiva = true;
				r = new Reinicio();
				p1 = tela->getP1();
				p2 = tela->getP2();
				tela = new Tela(3);
				tela->setP1(p1);
				tela->setP2(p2);
			}
			else if (tela->gameOver()) {
				fase3Ativa = false;
				gameOverAtiva = true;
			}
			else if (tela->acabou()) {
				fase3Ativa = false;
				bossFase3Ativa = true;
				p1 = tela->getP1();
				p2 = tela->getP2();
				telaBoss = new TelaChefao(3);
				telaBoss->setP1(p1);
				telaBoss->setP2(p2);
			}
		}
	}
	else if (bossFase3Ativa) {
		telaBoss->desenha();
		if (telaBoss->morreu() && telaBoss->gameOver() == false) {
			reinicioAtiva = true;
			r = new Reinicio();
			p1 = tela->getP1();
			p2 = tela->getP2();
			tela = new Tela(3);
			tela->setP1(p1);
			tela->setP2(p2);
			fase3Ativa = true;
			bossFase3Ativa = false;
		}
		else if (telaBoss->gameOver()) {
			bossFase3Ativa = false;
			gameOverAtiva = true;
		}
		else if (telaBoss->acabou()) {
			bossFase3Ativa = false;
			p1 = tela->getP1();
			p2 = tela->getP2();
			fimJogoAtiva = true;
			fimDeFase3Ativa = true;
			fimFase = new FimDeFase(3);
		}
	}
	else if (gameOverAtiva) {
		go->desenha();
		if (go->getStatus() == 't') {
			gameOverAtiva = false;
			menuAtiva = true;
		}
	}
	else if (fimJogoAtiva) {
		f->desenha();
		if (f->getStatus() == 't') {
			fimJogoAtiva = false;
			menuAtiva = true;
		}
	}
	glPopMatrix();
	glFlush();

}
void Inicializa(void) {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
void AlteraTamanhoJanela(GLsizei w, GLsizei h) {

	windowWidth = w;
	windowHeight = h;


	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0f, 360.0f, 0.0f, 252.0f);
	
}
int main(int argc, char **argv) {

	glutInit(&argc, argv);
	glutInitWindowSize(993.6, 690);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Game");
	glutDisplayFunc(Desenha);
	glutKeyboardFunc(keyboardDown);
	glutKeyboardUpFunc(keyboardUp);
	glutMouseFunc(mouseClick);
	glutReshapeFunc(AlteraTamanhoJanela);
	glutTimerFunc(1, Timer, 1);
	Inicializa();
	glutMainLoop();

	return 0;
}


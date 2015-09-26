#include "TiroEspecial.h"
#include <iostream>

using namespace std;
TiroEspecial::TiroEspecial(float x, float y, float ang,float largura) {
	posiX = x;
	posiY = y;
	angulo = ang;
	dimX = largura;
	status = 'a';
	decremento = 8;
	comeco=true;
}

void TiroEspecial::desenhaAng0(float xFinal, float yFinal) {
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2f(posiX - 0.5*dimX, posiY + decremento);
	glVertex2f(posiX - 0.5*dimX, yFinal);
	glColor3f(0, 0, 1);
	glVertex2f(posiX, yFinal);
	glVertex2f(posiX, posiY + decremento);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex2f(posiX, posiY + decremento);
	glVertex2f(posiX, yFinal);
	glColor3f(1, 1, 1);
	glVertex2f(posiX + 0.5*dimX, yFinal);
	glVertex2f(posiX + 0.5*dimX, posiY + decremento);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.9);
	glVertex2f(posiX - 0.5*dimX - 1, yFinal - 1);
	glVertex2f(posiX - 0.5*dimX, yFinal);
	glVertex2f(posiX + 0.5*dimX, yFinal);
	glVertex2f(posiX + 0.5*dimX + 1, yFinal - 1);
	glEnd();
	glPopMatrix();
}
void TiroEspecial::desenhaAng90(float xFinal, float yFinal) {
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2f(posiX - decremento, posiY - 0.5*dimX);
	glVertex2f(xFinal, posiY - 0.5*dimX);
	glColor3f(0, 0, 1);
	glVertex2f(xFinal, posiY);
	glVertex2f(posiX - decremento, posiY);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex2f(posiX - decremento, posiY);
	glVertex2f(xFinal, posiY);
	glColor3f(1, 1, 1);
	glVertex2f(xFinal, posiY + 0.5*dimX);
	glVertex2f(posiX - decremento, posiY + 0.5*dimX);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.9);
	glVertex2f(xFinal + 1, posiY - 0.5*dimX - 1);
	glVertex2f(xFinal, posiY - 0.5*dimX);
	glVertex2f(xFinal, posiY + 0.5*dimX);
	glVertex2f(xFinal + 1, posiY + 0.5*dimX + 1);
	glEnd();
	glPopMatrix();
}
void TiroEspecial::desenhaAngM90(float xFinal, float yFinal) {
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2f(posiX + decremento, posiY + 0.5*dimX);
	glVertex2f(xFinal, posiY + 0.5*dimX);
	glColor3f(0, 0, 1);
	glVertex2f(xFinal, posiY);
	glVertex2f(posiX + decremento, posiY);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex2f(posiX + decremento, posiY);
	glVertex2f(xFinal, posiY);
	glColor3f(1, 1, 1);
	glVertex2f(xFinal, posiY - 0.5*dimX);
	glVertex2f(posiX + decremento, posiY - 0.5*dimX);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.9);
	glVertex2f(xFinal - 1, posiY + 0.5*dimX + 1);
	glVertex2f(xFinal, posiY + 0.5*dimX);
	glVertex2f(xFinal, posiY - 0.5*dimX);
	glVertex2f(xFinal - 1, posiY - 0.5*dimX - 1);
	glEnd();
	glPopMatrix();
}

void TiroEspecial::desenhaAng180(float xFinal, float yFinal) {
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2f(posiX + 0.5*dimX, posiY - decremento);
	glVertex2f(posiX + 0.5*dimX, yFinal);
	glColor3f(0, 0, 1);
	glVertex2f(posiX, yFinal);
	glVertex2f(posiX, posiY - decremento);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex2f(posiX, posiY - decremento);
	glVertex2f(posiX, yFinal);
	glColor3f(1, 1, 1);
	glVertex2f(posiX - 0.5*dimX, yFinal);
	glVertex2f(posiX - 0.5*dimX, posiY - decremento);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.9);
	glVertex2f(posiX + 0.5*dimX + 1, yFinal + 1);
	glVertex2f(posiX + 0.5*dimX, yFinal);
	glVertex2f(posiX - 0.5*dimX, yFinal);
	glVertex2f(posiX - 0.5*dimX - 1, yFinal + 1);
	glEnd();
	glPopMatrix();
}
void TiroEspecial::desenha(float xFinal, float yFinal) {

	glPushMatrix();
	if(comeco){
		glTranslatef(posiX, posiY, 0);
		comeco=false;
	}//glRotatef(angulo, 0, 0, 1);
	//cout << "Xfinal"<<xFinal<<"Yfinal"<<yFinal;
	glColor3f(0, 0, 1);
	if (angulo == 0) {
		desenhaAng0(xFinal, yFinal);
		posiY += decremento;
		if (posiY + decremento >= yFinal) {
			status = 'i';
		}
	}
	else if (angulo == 90) {
		desenhaAng90(xFinal, yFinal);
		posiX -= decremento;
		if (posiX - decremento <= xFinal) {
			status = 'i';
		}
	}
	else if (angulo == -90) {
		desenhaAngM90(xFinal, yFinal);
		posiX += decremento;
		if (posiX + decremento >= xFinal) {
			status = 'i';
		}
	}
	else if (angulo == 180) {
		desenhaAng180(xFinal, yFinal);
		posiY -= decremento;
		if (posiY - decremento <= yFinal) {
			status = 'i';
		}
	}

	glPopMatrix();
}


void  TiroEspecial::setDimX(float tamanho) { dimX = tamanho; }

void  TiroEspecial::setStatus(char stat) { status = stat; }

float  TiroEspecial::getPosiX() { return posiX; }
float  TiroEspecial::getPosiY() { return posiY; }
float  TiroEspecial::getAngulo() { return angulo; }
float  TiroEspecial::getDimX() { return dimX; }
char  TiroEspecial::getStatus() { return status; }



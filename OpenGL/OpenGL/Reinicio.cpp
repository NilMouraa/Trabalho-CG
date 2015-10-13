#include "Reinicio.h"
#include <iostream>
//#define	Reinicio_H
using namespace std;
Reinicio::Reinicio() {
	posiXGuind=2;
    posiYGuind=10;
	posiXBase=156;
    posiYBase=10;
    dimXGuind=150;
    dimYGuind=200;
    dimXBase=200;
    dimYBase=75;
    status='a';
	limiteYGuind=150;
	limiteXGuind=126;
	velocMove=1;
	subiu=false;
}

void Reinicio::desenhaParteGuindaste(float posX,float posY) {
	
		glPushMatrix();
		glTranslatef(posX, posY, 0);

		float pontosX[200];
		float pontosY[200];
		int qtdPontos = 0;
		FILE *arq = NULL;
		arq = fopen("correntefinal.txt", "r");
		float cooX, cooY, corR, corG, corB, corRAnt, corGAnt, corBAnt;
		float yMinEst = -1;
		float yMaxEst = -1;
		char tipoPol;
		if (arq == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
		else {
			char tpAnt = 'z';
			while ((fscanf(arq, "%f %f %f %c %f %f\n", &corR, &corG, &corB, &tipoPol, &cooX, &cooY)) != EOF)
			{
				if (tipoPol == tpAnt || tpAnt == 'z') {
					if (cooX == 0) {
						if (yMinEst == -1) {
							yMinEst = cooY;
						}
						else {
							yMaxEst = cooY;
						}
					}
					pontosX[qtdPontos] = cooX;
					pontosY[qtdPontos] = cooY;
					qtdPontos++;
					tpAnt = tipoPol;
					corRAnt = corR;
					corGAnt = corG;
					corBAnt = corB;

				}
				else {
					glColor3f(corRAnt, corGAnt, corBAnt);
					glBegin(GL_POLYGON);
					for (int i = 0; i < qtdPontos; i++) {
						glVertex2f(pontosX[i] * dimXGuind, pontosY[i] * dimYGuind);
					}
					glEnd();
					glColor3f(1, 1, 1);
					glBegin(GL_LINE_LOOP);
					for (int i = 0; i < qtdPontos; i++) {
						glVertex2f(pontosX[i] * dimXGuind, pontosY[i] * dimYGuind);
					}
					glEnd();
					tpAnt = tipoPol;
					pontosX[0] = cooX;
					pontosY[0] = cooY;
					qtdPontos = 1;
					corRAnt = corR;
					corGAnt = corG;
					corBAnt = corB;
				}
			}
			glColor3f(corRAnt, corGAnt, corBAnt);
			glBegin(GL_POLYGON);
			for (int i = 0; i < qtdPontos; i++) {
				glVertex2f(pontosX[i] * dimXGuind, pontosY[i] * dimYGuind);
			}
			glEnd();
			glColor3f(1, 1, 1);
			glBegin(GL_LINE_LOOP);
			for (int i = 0; i < qtdPontos; i++) {
				glVertex2f(pontosX[i] * dimXGuind, pontosY[i] * dimYGuind);
			}
			glEnd();
			
		}
		fclose(arq);
		glPopMatrix();
}

void Reinicio::desenhaParteBase(float posX,float posY) {
	
		glPushMatrix();
		glTranslatef(posX, posY, 0);

		float pontosX[200];
		float pontosY[200];
		int qtdPontos = 0;
		FILE *arq = NULL;
		arq = fopen("pontosBase.txt", "r");
		float cooX, cooY, corR, corG, corB, corRAnt, corGAnt, corBAnt;
		float yMinEst = -1;
		float yMaxEst = -1;
		char tipoPol;
		if (arq == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
		else {
			char tpAnt = 'z';
			while ((fscanf(arq, "%f %f %f %c %f %f\n", &corR, &corG, &corB, &tipoPol, &cooX, &cooY)) != EOF)
			{
				if (tipoPol == tpAnt || tpAnt == 'z') {
					if (cooX == 0) {
						if (yMinEst == -1) {
							yMinEst = cooY;
						}
						else {
							yMaxEst = cooY;
						}
					}
					pontosX[qtdPontos] = cooX;
					pontosY[qtdPontos] = cooY;
					qtdPontos++;
					tpAnt = tipoPol;
					corRAnt = corR;
					corGAnt = corG;
					corBAnt = corB;

				}
				else {
					glColor3f(corRAnt, corGAnt, corBAnt);
					glBegin(GL_POLYGON);
					for (int i = 0; i < qtdPontos; i++) {
						glVertex2f(pontosX[i] * dimXBase, pontosY[i] * dimYBase);
					}
					glEnd();
					glColor3f(1, 1, 1);
					glBegin(GL_LINE_LOOP);
					for (int i = 0; i < qtdPontos; i++) {
						glVertex2f(pontosX[i] * dimXBase, pontosY[i] * dimYBase);
					}
					glEnd();
					tpAnt = tipoPol;
					pontosX[0] = cooX;
					pontosY[0] = cooY;
					qtdPontos = 1;
					corRAnt = corR;
					corGAnt = corG;
					corBAnt = corB;
				}
			}
			glColor3f(corRAnt, corGAnt, corBAnt);
			glBegin(GL_POLYGON);
			for (int i = 0; i < qtdPontos; i++) {
				glVertex2f(pontosX[i] * dimXBase, pontosY[i] * dimYBase);
			}
			glEnd();
			glColor3f(1, 1, 1);
			glBegin(GL_LINE_LOOP);
			for (int i = 0; i < qtdPontos; i++) {
				glVertex2f(pontosX[i] * dimXBase, pontosY[i] * dimYBase);
			}
			glEnd();
			
		}
		fclose(arq);
		glPopMatrix();
}
void Reinicio::renderBitmapString(float x, float y, void *font, const char *string) {
	const char *c;
	glRasterPos2f(x, y);
	for (c = string; *c != '\0'; c++) {
		glutBitmapCharacter(font, *c);
	}
}
void Reinicio::desenhaPlaca(float posX,float posY){
	glPushMatrix();

	glColor3f(1,1,1);
	int font = (int)GLUT_BITMAP_TIMES_ROMAN_24;
	char *texto = "O F I C I N A";
	renderBitmapString(posX+0.5, posY, (void *)font, texto);
	texto = "O F I C I N A";
	renderBitmapString(posX-0.5, posY, (void *)font, texto);
	texto = "O F I C I N A";
	renderBitmapString(posX, posY+0.5, (void *)font, texto);
	texto = "O F I C I N A";
	renderBitmapString(posX, posY-0.5, (void *)font, texto);
	glColor3f(1, 0, 0);
	texto = "O F I C I N A";
	renderBitmapString(posX, posY, (void *)font, texto);
	texto = "O F I C I N A";
	renderBitmapString(posX+0.2, posY, (void *)font, texto);
	texto = "O F I C I N A";
	renderBitmapString(posX,posY+0.2, (void *)font, texto);

	glPopMatrix();
}
void Reinicio::desenha(){
	desenhaPlaca(180,200);
	desenhaParteGuindaste(posiXGuind,posiYGuind);
	desenhaParteBase(posiXBase,posiYBase);
	if(posiYGuind<limiteYGuind && !subiu){
		posiYGuind+=velocMove;
	}else if(posiXGuind<limiteXGuind){
		posiXGuind+=velocMove;
		subiu=true;
	}else if(posiYGuind>posiYBase+dimYBase){
		posiYGuind-=velocMove;
	}else {
		status='t';
	}
}
/*
void  Reinicio::setDimX(float tamanho) { dimX = tamanho; }

void  Reinicio::setDimY(float tamanho) { dimY = tamanho; }

float  Reinicio::getPosiX() { return posiX; }
float  Reinicio::getPosiY() { return posiY; }
float  Reinicio::getDimX() { return dimX; }
float  Reinicio::getDimY() { return dimY;} */
char  Reinicio::getStatus() { return status; }

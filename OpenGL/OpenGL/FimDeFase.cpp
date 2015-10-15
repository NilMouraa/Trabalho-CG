#include "FimDeFase.h"
#include <iostream>
//#define	FimDeFase_H
using namespace std;
FimDeFase::FimDeFase() {
	posiXTopoP;
    posiYTopoP;
    posiXBaseP;
    posiYBaseP;
    dimXTopoP;
    dimYTopoP;
    dimXBaseP;
    dimYBaseP;
	posiXTopoI;
    posiYTopoI;
    posiXBaseI;
    posiYBaseI;
    dimXTopoI;
    dimYTopoI;
    dimXBaseI;
    dimYBaseI;
    status;
	velocCrescFogoX=2;
	velocCrescFogoY=2;
	limiteSobeFogoX=75;
	limiteDesceFogoX=25;
	limiteSobeFogoY=75;
	limiteDesceFogoY=25;
	dimXFogo=50;
	dimYFogo=50;
	crescendoX=true;
	crescendoY=true;
}

void FimDeFase::desenhaParteGuindaste(float posX,float posY,char qual) {
	
		glPushMatrix();
		glTranslatef(posX, posY, 0);
		
		float pontosX[200];
		float pontosY[200];
		int qtdPontos = 0;
		FILE *arq = NULL;
		float dimXGuind;
		float dimYGuind;
		if(qual=='p'){
			arq = fopen("correntefinal.txt", "r");
			dimXGuind=dimXTopoP;
			dimYGuind=dimYTopoP;
		}else
		if(qual=='i'){
			arq = fopen("correntefinalI.txt", "r");
			dimXGuind=dimXTopoI;
			dimYGuind=dimYTopoI;
			glRotatef(180, 0, 0, 1);
		}		
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

void FimDeFase::desenhaParteBase(float posX,float posY,char qual) {
	
		glPushMatrix();
		glTranslatef(posX, posY, 0);

		float pontosX[200];
		float pontosY[200];
		int qtdPontos = 0;
		FILE *arq = NULL;
		float dimXBase;
		float dimYBase;
		if(qual=='p'){
			arq = fopen("pontosBase.txt", "r");
			dimXBase =dimXTopoP;
			dimYBase =dimYTopoP;
		}else
		if(qual=='i'){
			arq = fopen("pontosBaseI.txt", "r");
			dimXBase =dimXTopoI;
			dimYBase =dimYTopoI;
			glRotatef(180, 0, 0, 1);
		}		
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
void FimDeFase::desenhaFogo(float posX,float posY){
	
	glBegin(GL_POLYGON);
		glColor3f(1,0,0);
		glVertex2f(-0.4*dimXFogo,0.6*dimYFogo);
		glVertex2f(-0.3*dimXFogo,0.4*dimYFogo);
		glColor3f(0.8,0.6,0);
		glVertex2f(-0.3*dimXFogo,0);
		glVertex2f(-0.5*dimXFogo,0);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(1,0,0);
		glVertex2f(-0.3*dimXFogo,0.4*dimYFogo);
		glVertex2f(-0.2*dimXFogo,0.8*dimYFogo);
		glVertex2f(-0.1*dimXFogo,0.6*dimYFogo);
		glColor3f(0.8,0.6,0);
		glVertex2f(-0.1*dimXFogo,0);
		glVertex2f(-0.3*dimXFogo,0);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(1,0,0);
		glVertex2f(-0.1*dimXFogo,0.6*dimYFogo);
		glVertex2f(0,dimYFogo);
		glVertex2f(0.1*dimXFogo,0.6*dimYFogo);
		glColor3f(0.8,0.6,0);
		glVertex2f(0.1*dimXFogo,0);
		glVertex2f(-0.1*dimXFogo,0);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(1,0,0);
		glVertex2f(0.1*dimXFogo,0.6*dimYFogo);
		glVertex2f(0.2*dimXFogo,0.8*dimYFogo);
		glVertex2f(0.3*dimXFogo,0.4*dimYFogo);
		glColor3f(0.8,0.6,0);
		glVertex2f(0.3*dimXFogo,0);
		glVertex2f(0.1*dimXFogo,0);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(1,0,0);
		glVertex2f(0.3*dimXFogo,0.4*dimYFogo);
		glVertex2f(0.4*dimXFogo,0.6*dimYFogo);
		glColor3f(0.8,0.6,0);
		glVertex2f(0.5*dimXFogo,0);
		glVertex2f(0.3*dimXFogo,0);
	glEnd();
	glColor3f(1,1,1);
	glBegin(GL_LINE_LOOP);
		glVertex2f(-0.5*dimXFogo,0);
		glVertex2f(-0.4*dimXFogo,0.6*dimYFogo);
		glVertex2f(-0.3*dimXFogo,0.4*dimYFogo);
		glVertex2f(-0.2*dimXFogo,0.8*dimYFogo);
		glVertex2f(-0.1*dimXFogo,0.6*dimYFogo);
		glVertex2f(0,dimYFogo);
		glVertex2f(0.1*dimXFogo,0.6*dimYFogo);
		glVertex2f(0.2*dimXFogo,0.8*dimYFogo);
		glVertex2f(0.3*dimXFogo,0.4*dimYFogo);
		glVertex2f(0.4*dimXFogo,0.6*dimYFogo);
		glVertex2f(0.5*dimXFogo,0);
	glEnd();	
}	
void FimDeFase::desenha(){
	/*
	desenhaParteGuindaste(posiXTopoP,posiYTopoP,'p');
	desenhaParteBase(posiXBaseP,posiYBaseP,'p');
	desenhaParteGuindaste(posiXTopoI,posiYTopoI,'i');
	desenhaParteBase(posiXBaseI,posiYBaseI,'i');*/
	desenhaFogo(100,100);
	if(crescendoX){
		if(dimXFogo<limiteSobeFogoX){
			dimXFogo+=velocCrescFogoX;
		}else crescendoX=false;
	}else{
		if(dimXFogo>limiteDesceFogoX){
			dimXFogo-=velocCrescFogoX;
		}else crescendoX=true;
	}
	if(crescendoY){
		if(dimYFogo<limiteSobeFogoY){
			dimYFogo+=velocCrescFogoY;
		}else crescendoY=false;
	}else{
		if(dimYFogo>limiteDesceFogoY){
			dimYFogo-=velocCrescFogoY;
		}else crescendoY=true;
	}
}
char  FimDeFase::getStatus() { return status; }

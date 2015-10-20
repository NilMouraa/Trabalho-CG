#include "FimDeFase.h"
#include <iostream>
//#define	FimDeFase_H
using namespace std;
FimDeFase::FimDeFase(int numeroFase) {
	fase=numeroFase;
	posiXTopoP=235;
    posiYTopoP=77.5;
    posiXBaseP=250;
    posiYBaseP=40;
    dimXTopoP=75;
    dimYTopoP=100;
    dimXBaseP=100;
    dimYBaseP=37.5;
	posiXTopoI=5;
    posiYTopoI=85;
    posiXBaseI=35;
    posiYBaseI=10;
    dimXTopoI=150;
    dimYTopoI=200;
    dimXBaseI=200;
    dimYBaseI=75;
    status='a';
	framesMax=1000;
	contFrames=1;
	velocCrescFogoX=0.0;
	velocCrescFogoY=0.4;
	limiteSobeFogoX=60;
	limiteDesceFogoX=40;
	limiteSobeFogoY=100;
	limiteDesceFogoY=80;
	dimXFogo=80;
	dimYFogo=90;
	crescendoX=true;
	crescendoY=true;
	velocCrescFogoX2=0.00;
	velocCrescFogoY2=0.4;
	limiteSobeFogoX2=200;
	limiteDesceFogoX2=180;
	limiteSobeFogoY2=150;
	limiteDesceFogoY2=75;
	dimXFogo2=190;
	dimYFogo2=100;
	crescendoX2=true;
	crescendoY2=true;
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
			arq = fopen("correntefinalP.txt", "r");
			dimXGuind=dimXTopoP;
			dimYGuind=dimYTopoP;
		}else
		if(qual=='i'){
			if(fase==1){
				arq = fopen("correntefinalI1.txt", "r");			
			}else if(fase==2){
				arq = fopen("correntefinalI2.txt", "r");			
			}else if(fase==3){
				arq = fopen("correntefinalI3.txt", "r");			
			}
			dimXGuind=dimXTopoI;
			dimYGuind=dimYTopoI;
			//glRotatef(180, 0, 0, 1);
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
			dimXBase=dimXBaseP;
			dimYBase=dimYBaseP;
		}else
		if(qual=='i'){
			if(fase==1){
				arq = fopen("pontosBaseI.txt", "r");			
			}else if(fase==2){
				arq = fopen("pontosBaseI2.txt", "r");			
			}else if(fase==3){
				arq = fopen("pontosBaseI3.txt", "r");			
			}
			dimXBase=dimXBaseI;
			dimYBase=dimYBaseI;
			//glRotatef(180, 0, 0, 1);
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
	glPushMatrix();
	glTranslatef(posX,posY,0);
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

glPopMatrix();	
}
void FimDeFase::desenhaFogo2(float posX,float posY){
	glPushMatrix();
	glTranslatef(posX,posY,0);
	glBegin(GL_POLYGON);
		glColor3f(1,0,0);
		glVertex2f(-0.4*dimXFogo2,0.6*dimYFogo2);
		glVertex2f(-0.3*dimXFogo2,0.4*dimYFogo2);
		glColor3f(0.8,0.6,0);
		glVertex2f(-0.3*dimXFogo2,0);
		glVertex2f(-0.5*dimXFogo2,0);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(1,0,0);
		glVertex2f(-0.3*dimXFogo2,0.4*dimYFogo2);
		glVertex2f(-0.2*dimXFogo2,0.8*dimYFogo2);
		glVertex2f(-0.1*dimXFogo2,0.6*dimYFogo2);
		glColor3f(0.8,0.6,0);
		glVertex2f(-0.1*dimXFogo2,0);
		glVertex2f(-0.3*dimXFogo2,0);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(1,0,0);
		glVertex2f(-0.1*dimXFogo2,0.6*dimYFogo2);
		glVertex2f(0,dimYFogo2);
		glVertex2f(0.1*dimXFogo2,0.6*dimYFogo2);
		glColor3f(0.8,0.6,0);
		glVertex2f(0.1*dimXFogo2,0);
		glVertex2f(-0.1*dimXFogo2,0);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(1,0,0);
		glVertex2f(0.1*dimXFogo2,0.6*dimYFogo2);
		glVertex2f(0.2*dimXFogo2,0.8*dimYFogo2);
		glVertex2f(0.3*dimXFogo2,0.4*dimYFogo2);
		glColor3f(0.8,0.6,0);
		glVertex2f(0.3*dimXFogo2,0);
		glVertex2f(0.1*dimXFogo2,0);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(1,0,0);
		glVertex2f(0.3*dimXFogo2,0.4*dimYFogo2);
		glVertex2f(0.4*dimXFogo2,0.6*dimYFogo2);
		glColor3f(0.8,0.6,0);
		glVertex2f(0.5*dimXFogo2,0);
		glVertex2f(0.3*dimXFogo2,0);
	glEnd();
	glColor3f(1,1,1);
	glBegin(GL_LINE_LOOP);
		glVertex2f(-0.5*dimXFogo2,0);
		glVertex2f(-0.4*dimXFogo2,0.6*dimYFogo2);
		glVertex2f(-0.3*dimXFogo2,0.4*dimYFogo2);
		glVertex2f(-0.2*dimXFogo2,0.8*dimYFogo2);
		glVertex2f(-0.1*dimXFogo2,0.6*dimYFogo2);
		glVertex2f(0,dimYFogo2);
		glVertex2f(0.1*dimXFogo2,0.6*dimYFogo2);
		glVertex2f(0.2*dimXFogo2,0.8*dimYFogo2);
		glVertex2f(0.3*dimXFogo2,0.4*dimYFogo2);
		glVertex2f(0.4*dimXFogo2,0.6*dimYFogo2);
		glVertex2f(0.5*dimXFogo2,0);
	glEnd();

glPopMatrix();	
}		
void FimDeFase::desenha(){
	
	desenhaParteGuindaste(posiXTopoP,posiYTopoP,'p');
	desenhaParteBase(posiXBaseP,posiYBaseP,'p');
	glPushMatrix();

	desenhaFogo2(104.8,73);
	if(crescendoX2){
		if(dimXFogo2<limiteSobeFogoX2){
			dimXFogo2+=velocCrescFogoX2;
		}else crescendoX2=false;
	}else{
		if(dimXFogo2>limiteDesceFogoX2){
			dimXFogo2-=velocCrescFogoX2;
		}else crescendoX2=true;
	}
	if(crescendoY2){
		if(dimYFogo2<limiteSobeFogoY2){
			dimYFogo2+=velocCrescFogoY2;
		}else crescendoY2=false;
	}else{
		if(dimYFogo2>limiteDesceFogoY2){
			dimYFogo2-=velocCrescFogoY2;
		}else crescendoY2=true;
	}



	glTranslatef(240,126,0);
	glRotatef(180, 0, 0, 1);
	desenhaParteGuindaste(posiXTopoI,posiYTopoI,'i');
	desenhaParteBase(posiXBaseI,posiYBaseI,'i');
	glPopMatrix();
	
	desenhaFogo(70,6);
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

	if(contFrames>=framesMax)status='t';
	contFrames++;
}
char  FimDeFase::getStatus() { return status; }

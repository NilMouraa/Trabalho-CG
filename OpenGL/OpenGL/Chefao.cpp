#include "Chefao.h"
#include <iostream>
#include "TiroEspecial.h"

//#define	Chefao_H
using namespace std;
Chefao::Chefao(float x, float y, float ang, int tip) {
	posiX = x;
	posiY = y;
	angulo = ang;
	dimX = 75;
	dimY = 75;
	status = 'a';
	tipo = tip;
	if (tip == 1) {
		vida = 250;
		velocidade = 2;
		tempoPraAtirar=1000;
	}
	else if (tip == 2) {
		vida = 250;
		velocidade = 2;
		tempoPraAtirar=1000;
	}
	else if (tip == 3) {
		vida = 250;
		velocidade = 3;
		tempoPraAtirar=1000;
	}
	else if (tip == 4) {
		vida = 250;
		velocidade = 3;
		tempoPraAtirar=1000;
	}
}

void Chefao::desenhaChefao1(){
	glPushMatrix();

	// Desenhar aq  os glBegin s - glEnd
	
		//desenhe o corpo
			//Parte de dentro
			glColor3f(0,0,1);
			glBegin(GL_POLYGON);
				glVertex2f(0.125*dimX,0.2*dimY);
				glVertex2f(0.125*dimX,dimY*0.875);
				glVertex2f(dimX*0.25,dimY);
				glVertex2f(dimX*0.375,dimY*0.875);
				glVertex2f(0.375*dimX,0.2*dimY);
			glEnd();
			glBegin(GL_POLYGON);
				glVertex2f(0.375*dimX,0.2*dimY);	
				glVertex2f(dimX*0.375,dimY*0.875);				
				glVertex2f(dimX*0.5,dimY);
				glVertex2f(dimX*0.625,dimY*0.875);
				glVertex2f(0.625*dimX,0.2*dimY);
			glEnd();	
			glBegin(GL_POLYGON);
				glVertex2f(0.625*dimX,0.2*dimY);
				glVertex2f(dimX*0.625,dimY*0.875);				
				glVertex2f(dimX*0.75,dimY);
				glVertex2f(dimX*0.875,dimY*0.875);
				glVertex2f(0.875*dimX,0.2*dimY);
			glEnd();
			glColor3f(1,1,1);
			glBegin(GL_LINE_LOOP);
				glVertex2f(0.125,0.2*dimY);
				glVertex2f(0.125,dimY*0.875);
				glVertex2f(dimX*0.25,dimY);
				glVertex2f(dimX*0.375,dimY*0.875);
				glVertex2f(dimX*0.5,dimY);
				glVertex2f(dimX*0.625,dimY*0.875);
				glVertex2f(dimX*0.75,dimY);
				glVertex2f(dimX*0.875,dimY*0.875);
			glEnd();
			
			// parte de fora
			
			glColor3f(0,1,0);
			glBegin(GL_POLYGON);
				glVertex2f(0,0);
				glVertex2f(0.25*dimX,0.4285*dimY);
				glVertex2f(0.25*dimX,0*dimY);
			glEnd();
			glBegin(GL_POLYGON);
				glVertex2f(0.25*dimX,0.4285*dimY);
				glVertex2f(0*dimX,0.857*dimY);
				glVertex2f(0.125*dimX,0.857*dimY);
				glVertex2f(0.25*dimX,0.714*dimY);
			glEnd();
			glBegin(GL_POLYGON);
				glVertex2f(0.25*dimX,0.1429*dimY);
				glVertex2f(0.25*dimX,0.714*dimY);
				glVertex2f(0.375*dimX,0.857*dimY);
				glVertex2f(0.5*dimX,0.714*dimY);
				glVertex2f(0.5*dimX,0.1429*dimY);
			glEnd();
			glBegin(GL_POLYGON);
				glVertex2f(0.5*dimX,0.1429*dimY);
				glVertex2f(0.5*dimX,0.714*dimY);
				glVertex2f(0.625*dimX,0.857*dimY);
				glVertex2f(0.75*dimX,0.714*dimY);
				glVertex2f(0.75*dimX,0.1429*dimY);
			
			glEnd();
			glBegin(GL_POLYGON);	
				glVertex2f(0.75*dimX,0.714*dimY);
				glVertex2f(0.875*dimX,0.875*dimY);
				glVertex2f(0.875*dimX,1*dimY);
				glVertex2f(0.75*dimX,0.4285*dimY);
			glEnd();
			glBegin(GL_POLYGON);
				glVertex2f(0.75*dimX,0.4285*dimY);
				glVertex2f(1*dimX,0*dimY);
				glVertex2f(0.75*dimX,0*dimY);
			glEnd();
			glBegin(GL_POLYGON);
				glVertex2f(0.625*dimX,0.1429*dimY);
				glVertex2f(0.625*dimX,0*dimY);
				glVertex2f(0.375*dimX,0*dimY);
				glVertex2f(0.375*dimX,0.1429*dimY);
			glEnd();	
			glColor3f(1,1,1);
			glBegin(GL_LINE_LOOP);
				glVertex2f(0,0);
				glVertex2f(0.25*dimX,0.4285*dimY);
				glVertex2f(0*dimX,0.857*dimY);
				glVertex2f(0.125*dimX,0.857*dimY);
				glVertex2f(0.25*dimX,0.714*dimY);
				glVertex2f(0.375*dimX,0.857*dimY);
				glVertex2f(0.5*dimX,0.714*dimY);
				glVertex2f(0.625*dimX,0.857*dimY);
				glVertex2f(0.75*dimX,0.714*dimY);
				glVertex2f(0.875*dimX,0.875*dimY);
				glVertex2f(0.875*dimX,1*dimY);
				glVertex2f(0.75*dimX,0.4285*dimY);
				glVertex2f(1*dimX,0*dimY);
				glVertex2f(0.75*dimX,0*dimY);
				glVertex2f(0.75*dimX,0.1429*dimY);
				glVertex2f(0.625*dimX,0.1429*dimY);
				glVertex2f(0.625*dimX,0*dimY);
				glVertex2f(0.375*dimX,0*dimY);
				glVertex2f(0.375*dimX,0.1429*dimY);
				glVertex2f(0.25*dimX,0.1429*dimY);
				glVertex2f(0.25*dimX,0*dimY);
			glEnd();
			
			// Quadrado no centro
			glColor3f(0,0,1);
			glBegin(GL_QUADS);
				glVertex2f(0.375*dimX,0.2857*dimY);
				glVertex2f(0.375*dimX,0.5715*dimY);
				glVertex2f(0.625*dimX,0.5715*dimY);
				glVertex2f(0.625*dimX,0.2857*dimY);
			glEnd();
			glColor3f(1,1,1);
			glBegin(GL_LINE_LOOP);
				glVertex2f(0.375*dimX,0.2857*dimY);
				glVertex2f(0.375*dimX,0.5715*dimY);
				glVertex2f(0.625*dimX,0.5715*dimY);
				glVertex2f(0.625*dimX,0.2857*dimY);
			glEnd();
				
		//--------
		
		desenhaEsteira(0,1); // os parametros são a altura Min e Max q a esteira vai ser desenhada no tank(de onde até onde, sempre entre 0 e 1)
	
		// Agora desenhe os canos
	
		
		//--------
	
	//----------------
	
	glPopMatrix();
}

void Chefao::desenhaChefao2(){
	glPushMatrix();

	// Desenhar aq  os glBegin s - glEnd
	
		//dois triangulos
			glColor3f(0.5,0.2,0.5);
			glBegin(GL_TRIANGLES);
				glVertex2f(0*dimX,0.625*dimY);	
				glVertex2f(0*dimX,1*dimY);
				glVertex2f(0.375*dimX,0.625*dimY);
				/*
				glVertex2f(*dimX,*dimY);
				glVertex2f(*dimX,*dimY);
				glVertex2f(*dimX,*dimY);
				glVertex2f(*dimX,*dimY);
				glVertex2f(*dimX,*dimY);*/
			glEnd();
			glBegin(GL_TRIANGLES);
				glVertex2f(0.625*dimX,0.625*dimY);
				glVertex2f(dimX,dimY);
				glVertex2f(1*dimX,0.625*dimY);
			glEnd();
			glColor3f(1,1,1);
			glBegin(GL_LINE_LOOP);
				glVertex2f(0*dimX,0.625*dimY);	
				glVertex2f(0*dimX,1*dimY);
				glVertex2f(0.375*dimX,0.625*dimY);
				glVertex2f(0.625*dimX,0.625*dimY);
				glVertex2f(dimX,dimY);
				glVertex2f(1*dimX,0.625*dimY);
			glEnd();
			
			// parte principal
			glColor3f(0.8,0.8,0.9);
			glBegin(GL_POLYGON);
				glVertex2f(0*dimX,0.25*dimY);
				glVertex2f(0*dimX,0.625*dimY);
				glVertex2f(1*dimX,0.625*dimY);
				glVertex2f(1*dimX,0.25*dimY);
				glVertex2f(0.875*dimX,0.125*dimY);
				glVertex2f(0.125*dimX,0.125*dimY);
			glEnd();
			glColor3f(1,1,1);
			glBegin(GL_LINE_LOOP);
				glVertex2f(0*dimX,0.25*dimY);
				glVertex2f(0*dimX,0.625*dimY);
				glVertex2f(1*dimX,0.625*dimY);
				glVertex2f(1*dimX,0.25*dimY);
				glVertex2f(0.875*dimX,0.125*dimY);
				glVertex2f(0.125*dimX,0.125*dimY);
			glEnd();
			//triangulos - parte inferior
			glColor3f(0.5,0.2,0.5);
			glBegin(GL_TRIANGLES);
				glVertex2f(0.125*dimX,0.125*dimY);
				glVertex2f(0.375*dimX,0.125*dimY);
				glVertex2f(0.25*dimX,0*dimY);
			glEnd();
			glBegin(GL_TRIANGLES);
				glVertex2f(0.375*dimX,0.125*dimY);
				glVertex2f(0.625*dimX,0.125*dimY);
				glVertex2f(0.5*dimX,0*dimY);
			glEnd();
			glBegin(GL_TRIANGLES);
				glVertex2f(0.625*dimX,0.125*dimY);
				glVertex2f(0.875*dimX,0.125*dimY);
				glVertex2f(0.75*dimX,0*dimY);
			glEnd();
			glColor3f(1,1,1);
			glBegin(GL_LINE_LOOP);
			glVertex2f(0.125*dimX,0.125*dimY);
			glVertex2f(0.875*dimX,0.125*dimY);
			glVertex2f(0.75*dimX,0*dimY);
			glVertex2f(0.625*dimX,0.125*dimY);
			glVertex2f(0.5*dimX,0*dimY);
			glVertex2f(0.375*dimX,0.125*dimY);
			glVertex2f(0.25*dimX,0*dimY);
			glEnd();
			
			desenhaEsteira(0.125,1);
			
			// detalhe olhos
			glColor3f(0.3,0,0.3);
			glBegin(GL_POLYGON);
				glVertex2f(-0.125*dimX,0.375*dimY);
				glVertex2f(-0.125*dimX,0.5*dimY);
				glVertex2f(0.375*dimX,0.5*dimY);
				glVertex2f(0.375*dimX,0.375*dimY);
			glEnd();
			glBegin(GL_POLYGON);
				glVertex2f(0.375*dimX,0.625*dimY);
				glVertex2f(0.25*dimX,0.5*dimY);
				glVertex2f(0.25*dimX,0.375*dimY);
				glVertex2f(0.375*dimX,0.25*dimY);
			glEnd();

			//olho2
			glBegin(GL_POLYGON);
				glVertex2f(0.625*dimX,0.375*dimY);
				glVertex2f(0.625*dimX,0.5*dimY);
				glVertex2f(1.125*dimX,0.5*dimY);
				glVertex2f(1.125*dimX,0.375*dimY);
			glEnd();
			glBegin(GL_POLYGON);
				glVertex2f(0.625*dimX,0.625*dimY);
				glVertex2f(0.75*dimX,0.5*dimY);
				glVertex2f(0.75*dimX,0.375*dimY);
				glVertex2f(0.625*dimX,0.25*dimY);
			glEnd();

			

			//prabaixo
			glBegin(GL_POLYGON);
				glVertex2f(0.375*dimX,0.25*dimY);
				glVertex2f(0.375*dimX,0.625*dimY);
				glVertex2f(0.625*dimX,0.625*dimY);
				glVertex2f(0.625*dimX,0.25*dimY);
			glEnd();
			glBegin(GL_POLYGON);
				glVertex2f(0.4375*dimX,-0.125*dimY);
				glVertex2f(0.4375*dimX,0.25*dimY);
				glVertex2f(0.5625*dimX,0.25*dimY);
				glVertex2f(0.5625*dimX,-0.125*dimY);
			glEnd();
			
			

			// cano
			
			glBegin(GL_POLYGON);
				glVertex2f(0.4375*dimX,0.625*dimY);
				glVertex2f(0.4375*dimX,1.125*dimY);
				glVertex2f(0.5625*dimX,1.125*dimY);
				glVertex2f(0.5625*dimX,0.625*dimY);
			glEnd();

			glColor3f(1,1,1);

			glBegin(GL_LINE_LOOP);
				glVertex2f(-0.125*dimX,0.375*dimY);
				glVertex2f(-0.125*dimX,0.5*dimY);
				glVertex2f(0.25*dimX,0.5*dimY);
				glVertex2f(0.375*dimX,0.625*dimY);
				glVertex2f(0.4375*dimX,0.625*dimY);
				glVertex2f(0.4375*dimX,1.125*dimY);
				glVertex2f(0.5625*dimX,1.125*dimY);
				glVertex2f(0.5625*dimX,0.625*dimY);
				glVertex2f(0.625*dimX,0.625*dimY);
				glVertex2f(0.75*dimX,0.5*dimY);
				glVertex2f(1.125*dimX,0.5*dimY);
				glVertex2f(1.125*dimX,0.375*dimY);
				glVertex2f(0.75*dimX,0.375*dimY);
				glVertex2f(0.625*dimX,0.25*dimY);
				glVertex2f(0.5625*dimX,0.25*dimY);
				glVertex2f(0.5625*dimX,-0.125*dimY);
				glVertex2f(0.4375*dimX,-0.125*dimY);
				glVertex2f(0.4375*dimX,0.25*dimY);
				glVertex2f(0.375*dimX,0.25*dimY);
				glVertex2f(0.25*dimX,0.375*dimY);
			glEnd();

				
			
		//--------
		
		//desenhaEsteira(0.25,1); // os parametros são a altura Min e Max q a esteira vai ser desenhada no tank(de onde até onde, pode por qualquer numero entre 0 e 1)
	
		// Agora desenhe os canos
	
		
		//--------
	
	//----------------
	
	glPopMatrix();
}

void Chefao::desenhaChefao3(){
	glPushMatrix();

	// Desenhar aq  os glBegin s - glEnd
	
		//desenhe o corpo
		glColor3f(0.2,0.2,1);
		glBegin(GL_POLYGON);
			glVertex2f(0,0);
			glVertex2f(0,dimY);
			glVertex2f(dimX,dimY);
			glVertex2f(dimX,0);
		glEnd();
		glColor3f(1,1,1);
		glBegin(GL_LINE_LOOP);
			glVertex2f(0,0);
			glVertex2f(0,1);
			glVertex2f(1,1);
			glVertex2f(1,0);
		glEnd();		
		//--------
		
		desenhaEsteira(0,1); // os parametros são a altura Min e Max q a esteira vai ser desenhada no tank(de onde até onde, sempre entre 0 e 1)
	
		// Agora desenhe os canos
		glColor3f(0.2,0.2,0.4);
		glBegin(GL_POLYGON);
			glVertex2f(0.125*dimX,0.5*dimY);
			glVertex2f(0.125*dimX,1.1666667*dimY);
			glVertex2f(0.2083333*dimX,1.1666667*dimY);
			glVertex2f(0.2083333*dimX,0.5*dimY);
		glEnd();
		glBegin(GL_POLYGON);
			glVertex2f(0.79166667*dimX,0.5*dimY);
			glVertex2f(0.79166667*dimX,1.1666667*dimY);
			glVertex2f(0.875*dimX,1.1666667*dimY);
			glVertex2f(0.875*dimX,0.5*dimY);
		glEnd();
		glBegin(GL_POLYGON);
			glVertex2f(0.125*dimX,0.5*dimY);
			glVertex2f(0.125*dimX,0.66666667*dimY);
			glVertex2f(0.875*dimX,0.66666667*dimY);
			glVertex2f(0.875*dimX,0.5*dimY);
		glEnd();
		glBegin(GL_POLYGON);
			glVertex2f(0.29166667*dimX,0.66666667*dimY);
			glVertex2f(0.29166667*dimX,1.1083333333*dimY);
			glVertex2f(0.375*dimX,1.1083333333*dimY);
			glVertex2f(0.375*dimX,0.66666667*dimY);
		glEnd();
		glBegin(GL_POLYGON);
			glVertex2f(0.625*dimX,0.66666667*dimY);
			glVertex2f(0.625*dimX,1.1083333333*dimY);
			glVertex2f(0.7083333*dimX,1.1083333333*dimY);
			glVertex2f(0.7083333*dimX,0.66666667*dimY);
		glEnd();
		glBegin(GL_POLYGON);
			glVertex2f(0.29166667*dimX,0.66666667*dimY);
			glVertex2f(0.29166667*dimX,0.75*dimY);
			glVertex2f(0.7083333*dimX,0.75*dimY);
			glVertex2f(0.7083333*dimX,0.66666667*dimY);
		glEnd();
		glBegin(GL_POLYGON);
			glVertex2f(0.4583333*dimX,0.75*dimY);
			glVertex2f(0.4583333*dimX,1.25*dimY);
			glVertex2f(0.54166667*dimX,1.25*dimY);
			glVertex2f(0.54166667*dimX,0.75*dimY);
		glEnd();
		glColor3f(1,1,1);
		glBegin(GL_LINE_LOOP);
			glVertex2f(0.125*dimX,0.5*dimY);
			glVertex2f(0.125*dimX,1.1666667*dimY);
			glVertex2f(0.2083333*dimX,1.1666667*dimY);
			glVertex2f(0.2083333*dimX,0.66666667*dimY);
			glVertex2f(0.29166667*dimX,0.66666667*dimY);
			glVertex2f(0.29166667*dimX,1.1083333333*dimY);
			glVertex2f(0.375*dimX,1.1083333333*dimY);
			glVertex2f(0.375*dimX,0.75*dimY);
			glVertex2f(0.4583333*dimX,0.75*dimY);
			glVertex2f(0.4583333*dimX,1.25*dimY);
			glVertex2f(0.54166667*dimX,1.25*dimY);
			glVertex2f(0.54166667*dimX,0.75*dimY);
			glVertex2f(0.625*dimX,0.75*dimY);
			glVertex2f(0.625*dimX,1.1083333333*dimY);
			glVertex2f(0.7083333*dimX,1.1083333333*dimY);
			glVertex2f(0.7083333*dimX,0.66666667*dimY);
			glVertex2f(0.79166667*dimX,0.66666667*dimY);
			glVertex2f(0.79166667*dimX,1.1666667*dimY);
			glVertex2f(0.875*dimX,1.1666667*dimY);
			glVertex2f(0.875*dimX,0.5*dimY);

		glEnd();
		//--------
	
	//----------------
	
	glPopMatrix();
}
void Chefao::desenhaChefao4(){
	glPushMatrix();

		//cano
			glColor3f(1,0.5,0.3);
			glBegin(GL_POLYGON);
				glVertex2f(0.45*dimX,1.2*dimY);
				glVertex2f(0.55*dimX,1.2*dimY);
				glVertex2f(0.55*dimX,0.7*dimY);
				glVertex2f(0.45*dimX,0.7*dimY);
			glEnd();
			glColor3f(1,1,1);
			glBegin(GL_LINE_LOOP);
				glVertex2f(0.45*dimX,1.2*dimY);
				glVertex2f(0.55*dimX,1.2*dimY);
				glVertex2f(0.55*dimX,0.7*dimY);
				glVertex2f(0.45*dimX,0.7*dimY);
			glEnd();
			
			//detalhe perto do cano
			glColor3f(0.5,0.2,0.5);
			glBegin(GL_TRIANGLES);
				glVertex2f(0.3*dimX,0.7*dimY);
				glVertex2f(0.5*dimX,0.9*dimY);
				glVertex2f(0.7*dimX,0.7*dimY);
				
			glEnd();
			glColor3f(1,1,1);
			glBegin(GL_LINE_LOOP);
				glVertex2f(0.3*dimX,0.7*dimY);
				glVertex2f(0.5*dimX,0.9*dimY);
				glVertex2f(0.7*dimX,0.7*dimY);
			glEnd();

			//parte principal
			glColor3f(0.7,0.5,0.4);
			glBegin(GL_POLYGON);
				glVertex2f(0.1*dimX,0.3*dimY);
				glVertex2f(0.1*dimX,1*dimY);
				glVertex2f(0.5*dimX,0.7*dimY);
				glVertex2f(0.9*dimX,1*dimY);
				glVertex2f(0.9*dimX,0.3*dimY);
				glVertex2f(0.6*dimX,0.1*dimY);
				glVertex2f(0.5*dimX,0.2*dimY);
				glVertex2f(0.4*dimX,0.1*dimY);
			glEnd();
			glColor3f(0,0,0);
			glBegin(GL_TRIANGLES);
				glVertex2f(0.4*dimX,0.1*dimY);
				glVertex2f(0.5*dimX,0.2*dimY);
				glVertex2f(0.6*dimX,0.1*dimY);
			glEnd();
			glColor3f(1,1,1);
			glBegin(GL_LINE_LOOP);
				glVertex2f(0.1*dimX,0.3*dimY);
				glVertex2f(0.1*dimX,1*dimY);
				glVertex2f(0.5*dimX,0.7*dimY);
				glVertex2f(0.9*dimX,1*dimY);
				glVertex2f(0.9*dimX,0.3*dimY);
				glVertex2f(0.6*dimX,0.1*dimY);
				glVertex2f(0.5*dimX,0.2*dimY);
				glVertex2f(0.4*dimX,0.1*dimY);
			glEnd();
			//olho 1
			glColor3f(0.5,0.2,0.5);
			glBegin(GL_POLYGON);
				glVertex2f(0.2*dimX,0.5*dimY);
				glVertex2f(0.2*dimX,0.8*dimY);
				glVertex2f(0.4*dimX,0.6*dimY);
				glVertex2f(0.4*dimX,0.3*dimY);
			glEnd();
			glColor3f(1,1,1);
			glBegin(GL_LINE_LOOP);
				glVertex2f(0.2*dimX,0.5*dimY);
				glVertex2f(0.2*dimX,0.8*dimY);
				glVertex2f(0.4*dimX,0.6*dimY);
				glVertex2f(0.4*dimX,0.3*dimY);
			glEnd();

			//olho 2
			glColor3f(0.5,0.2,0.5);
			glBegin(GL_POLYGON);
				glVertex2f(0.6*dimX,0.3*dimY);
				glVertex2f(0.6*dimX,0.6*dimY);
				glVertex2f(0.8*dimX,0.8*dimY);
				glVertex2f(0.8*dimX,0.5*dimY);
			glEnd();
			glColor3f(1,1,1);
			glBegin(GL_LINE_LOOP);
				glVertex2f(0.6*dimX,0.3*dimY);
				glVertex2f(0.6*dimX,0.6*dimY);
				glVertex2f(0.8*dimX,0.8*dimY);
				glVertex2f(0.8*dimX,0.5*dimY);
			glEnd();
			desenhaEsteira(0.3,1);
			
	
	glPopMatrix();
}


void Chefao::desenhaEsteira(float yMinEst,float yMaxEst){

	glPushMatrix();

			for(float i = yMinEst*dimY/*-0.1*dimY*/; i < yMaxEst*dimY; i += 0.1*dimY) {
				glColor3f(0.4, 0.4, 0.4);
				glBegin(GL_QUADS);
				glVertex2f(0, i);
				glVertex2f(0, i + 0.1*dimY);
				glVertex2f(0.1*dimX, i);
				glVertex2f(0.1*dimX, i + 0.1*dimY);
				//glVertex2f(0.05*dimX,i+0.05*dimY);
				glEnd();
				glBegin(GL_QUADS);
				glVertex2f(0.9*dimX, i);
				glVertex2f(0.9*dimX, i + 0.1*dimY);
				glVertex2f(dimX, i);
				glVertex2f(dimX, i + 0.1*dimY);
				//glVertex2f(0.05*dimX,i+0.05*dimY);
				glEnd();
				glColor3f(1, 1, 1);
				glBegin(GL_LINE_LOOP);
				glVertex2f(0, i);
				glVertex2f(0, i + 0.1*dimY);
				glVertex2f(0.1*dimX, i + 0.1*dimY);
				glVertex2f(0.1*dimX, i);
				glVertex2f(0.05*dimX, i + 0.05*dimY);
				glEnd();
				glBegin(GL_LINE_LOOP);
				glVertex2f(0.9*dimX, i);
				glVertex2f(0.9*dimX, i + 0.1*dimY);
				glVertex2f(dimX, i + 0.1*dimY);
				glVertex2f(dimX, i);
				glVertex2f(0.95*dimX, i + 0.05*dimY);
				glEnd();
			}
			glBegin(GL_LINES);
			glVertex2f(0, yMinEst*dimY/*-0.1*dimY*/);
			glVertex2f(0.1*dimX, yMinEst*dimY/*-0.1*dimY*/);
			glEnd();
			glBegin(GL_LINES);
			glVertex2f(0.9*dimX, yMinEst*dimY/*-0.1*dimY*/);
			glVertex2f(dimX, yMinEst*dimY/*-0.1*dimY*/);
			glEnd();
	
	glPopMatrix();
}

void Chefao::desenha() {
	tempoPraAtirar--;
	
	if ((status != 'm' && status != 'i') || (explosao->getDiminui() == false)) {

		glPushMatrix();
		glTranslatef(posiX, posiY, 0);
		glRotatef(angulo, 0, 0, 1);

		if (tipo == 1) {
			desenhaChefao1();
		}
		else if (tipo == 2) {
			desenhaChefao2();
		}
		else if (tipo == 3) {
			desenhaChefao3();
		}
		else if (tipo == 4) {
			desenhaChefao4();
		}
		
		glPopMatrix();
		if (status == 'm') {
			explosao->desenha();
			explosao->incrementaTamanho(1);
		}
	}
	else {
		explosao->desenha();
		explosao->incrementaTamanho(1);
		if (explosao->getTerminou()) {
			status = 'i';
		}
	}

	
}
void  Chefao::move(float incremento) {
	if (angulo == 0) {
		/*cout<<"\tANDANDO CIMA";*/
		posiY += (velocidade*incremento);
	}
	else if (angulo == -90) {
		/*cout<<"\tANDANDO DIR";*/
		posiX += (velocidade*incremento);
	}
	else if (angulo == 90) {
		//cout<<"\tANDANDO TRAS";
		posiX -= (velocidade*incremento);
	}
	else if (angulo == 180) {
		//cout<<"\tANDANDO ESQ";
		posiY -= (velocidade*incremento);
	}

}
void  Chefao::viraDireita(float incremento, bool podeAndar) {
	if (podeAndar) {
		if (angulo == 0) {
			posiY += dimX;
		}
		else
			if (angulo == 180) {
				posiX -= dimY;
			}
			else if (angulo == 90) {
				posiX -= dimY;
				posiY += dimX;
			}
			else if (angulo == -90 && podeAndar) {
				move(incremento);
			}
			angulo = -90;
	}
}
void  Chefao::viraEsquerda(float incremento, bool podeAndar) {
	//cout << "ANGULO: " << this->getAngulo();
	if (podeAndar) {
		if (angulo == 0) {
			posiX += dimY;
		}
		else if (angulo == 180) {
			posiY -= dimX;
		}
		else if (angulo == -90) {
			posiX += dimY;
			posiY -= dimX;
		}
		else if (angulo == 90 && podeAndar) {
			move(incremento);
		}
		angulo = 90;
	}
}
void  Chefao::viraCima(float incremento, bool podeAndar) {
	//cout << "ANGULO: " << this->getAngulo();
	if (podeAndar) {
		if (angulo == 90) {
			posiX -= dimY;
		}
		else if (angulo == -90) {
			posiY -= dimX;
		}
		else if (angulo == 180) {
			/*posiX+=dimX;
			posiY+=dimY;*/
			posiX -= dimX;
			posiY -= dimY;
		}
		else if (angulo == 0 && podeAndar) {
			move(incremento);
		}
		angulo = 0;
	}
}
void  Chefao::viraBaixo(float incremento, bool podeAndar) {
	//cout << "ANGULO: " << this->getAngulo();
	if (podeAndar) {
		if (angulo == 90) {
			posiY += dimX;
		}
		else if (angulo == -90) {
			posiX += dimY;
		}
		else if (angulo == 0) {
			/*posiX-=dimX;
			posiY-=dimY;*/
			posiX += dimX;
			posiY += dimY;
		}
		else if (angulo == 180 && podeAndar) {
			move(incremento);
		}
		angulo = 180;
	}
}

void  Chefao::recebeDano(float dano) {
	vida -= dano;
	if (vida <= 0) {
		status = 'm';
		if (angulo == 0) {
			explosao = new Explosao(posiX + 0.5*dimX, posiY + 0.5*dimY, 0, 3, 3);
		}
		else if (angulo == 90) {
			explosao = new Explosao(posiX - 0.5*dimY, posiY + 0.5*dimX, 0, 3, 3);
		}
		else if (angulo == -90) {
			explosao = new Explosao(posiX + 0.5*dimY, posiY - 0.5*dimX, 0, 3, 3);
		}
		else if (angulo == 180) {
			explosao = new Explosao(posiX - 0.5*dimX, posiY - 0.5*dimY, 0, 3, 3);
		}
	}

}

void  Chefao::aumentaVida(float incremento) {
	vida += incremento;
}

void  Chefao::setQtdTiroEspec(int qtd) {
	qtdTiroEspec = qtd;
}

void  Chefao::setDimX(float tamanho) { dimX = tamanho; }

void  Chefao::setDimY(float tamanho) { dimY = tamanho; }

void  Chefao::setStatus(char stat) {
	status = stat;
	if (stat == 'm') {
		if (this->angulo == 0) {
			explosao = new Explosao(posiX + 0.5*dimX, posiY + 0.5*dimY, 0, dimY/3, 4);
		}
		else if (this->angulo == 90) {
			explosao = new Explosao(posiX - 0.5*dimY, posiY + 0.5*dimX, 0, dimY/3, 4);
		}
		else if (this->angulo == -90) {
			explosao = new Explosao(posiX + 0.5*dimY, posiY - 0.5*dimX, 0, dimY/3, 4);
		}
		else if (this->angulo == 180) {
			explosao = new Explosao(posiX - 0.5*dimX, posiY - 0.5*dimY, 0, dimY/3,4);
		}
	}
}
float  Chefao::getPosiCentroX() {
	if (this->angulo == 0) {
		return posiX + 0.5*dimX;
	}
	else if (this->angulo == 90) {
		return posiX - 0.5*dimY;
	}
	else if (this->angulo == -90) {
		return posiX + 0.5*dimY;
	}
	else if (this->angulo == 180) {
		return posiX - 0.5*dimX;
	}

}
float  Chefao::getPosiCentroY() {
	if (this->angulo == 0) {
		return posiY + 0.5*dimY;
	}
	else if (this->angulo == 90) {
		return posiY + 0.5*dimX;
	}
	else if (this->angulo == -90) {
		return posiY - 0.5*dimX;
	}
	else if (this->angulo == 180) {
		return posiY - 0.5*dimY;
	}
}
float  Chefao::getPosiOrigemX() {
	if (this->angulo == 0) {
		return posiX;
	}
	else if (this->angulo == 90) {
		return posiX -dimY;
	}
	else if (this->angulo == -90) {
		return posiX;
	}
	else if (this->angulo == 180) {
		return posiX -dimX;
	}

}
float  Chefao::getPosiOrigemY() {
	if (this->angulo == 0) {
		return posiY;
	}
	else if (this->angulo == 90) {
		return posiY;
	}
	else if (this->angulo == -90) {
		return posiY -dimX;
	}
	else if (this->angulo == 180) {
		return posiY -dimY;
	}
}

int Chefao::getTempoPraAtirar(){return tempoPraAtirar;}

float  Chefao::getPosiX() { return posiX; }
float  Chefao::getPosiY() { return posiY; }
float  Chefao::getAngulo() { return angulo; }
float  Chefao::getDimX() { return dimX; }
float  Chefao::getDimY() { return dimY; }
char  Chefao::getStatus() { return status; }
int  Chefao::getTipo() { return tipo; }
int  Chefao::getVida() { return vida; }

TiroEspecial* Chefao::atiraEspecial() {
	//if (qtdTiroEspec > 0) {
		TiroEspecial *te = NULL;
		if (angulo == 90) {
			te = new TiroEspecial(posiX - 1.15*dimY, posiY + 0.5*dimX, 90,dimX*0.2);
		}
		else if (angulo == -90) {
			te = new TiroEspecial(posiX + 1.15*dimY, posiY - 0.5*dimX, -90, dimX*0.2);
		}
		else if (angulo == 0) {
			te = new TiroEspecial(posiX + 0.5*dimX, posiY + 1.15*dimY, 0, dimX*0.2);
		}
		else if (angulo == 180) {
			te = new TiroEspecial(posiX - 0.5*dimX, posiY - 1.15*dimY, 180, dimX*0.2);
		}
		//qtdTiroEspec--;
		//te->desenha(xfinal, yfinal);
		
	//}
	return te;
}

TiroExp* Chefao::atira(char tipo) {
	//if (qtdTiroEspec > 0) {
	TiroExp *te = NULL;

	if(tempoPraAtirar<0){
		if (tipo == 1) {
			tempoPraAtirar=100;
		}
		else if (tipo == 2) {
			tempoPraAtirar=100;
		}
		else if (tipo == 3) {
			tempoPraAtirar=100;
		}
		else if (tipo == 4) {
			tempoPraAtirar=100;
		}
		else if (tipo == 5) {
			tempoPraAtirar=100;
		}	
	}

	if (angulo == 90) {
		te = new TiroExp(posiX - 1.15*dimY, posiY + 0.5*dimX, 'e', dimX*0.2, dimX*0.2,tipo);
	}
	else if (angulo == -90) {
		te = new TiroExp(posiX + 1.15*dimY, posiY - 0.5*dimX, 'd', dimX*0.2, dimX*0.2, tipo);
	}
	else if (angulo == 0) {
		te = new TiroExp(posiX + 0.5*dimX, posiY + 1.15*dimY, 'c', dimX*0.2, dimX*0.2, tipo);
	}
	else if (angulo == 180) {
		te = new TiroExp(posiX - 0.5*dimX, posiY - 1.15*dimY, 'b', dimX*0.2, dimX*0.2, tipo);
	}
	//qtdTiroEspec--;
	//te->desenha(xfinal, yfinal);

	//}
	return te;
}

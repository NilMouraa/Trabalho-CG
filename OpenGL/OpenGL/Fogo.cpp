#include "Fogo.h"
#include <iostream>
//#define	Fogo_H
using namespace std;
Fogo::Fogo(float posiX2,
	float posiY2,
	float angulo2,
	float velocCrescFogoX2,
	float velocCrescFogoY2,
	float limiteSobeFogoX2,
	float limiteDesceFogoX2,
	float limiteSobeFogoY2,
	float limiteDesceFogoY2,
	float dimXFogo2,
	float dimYFogo2) {
	posiX=posiX2;
	posiY=posiY2;
	angulo=angulo2;
	velocCrescFogoX=velocCrescFogoX2;
	velocCrescFogoY=velocCrescFogoY2;
	limiteSobeFogoX=limiteSobeFogoX2;
	limiteDesceFogoX=limiteDesceFogoX2;
	limiteSobeFogoY=limiteSobeFogoY2;
	limiteDesceFogoY=limiteDesceFogoY2;
	dimXFogo=dimXFogo2;
	dimYFogo=dimYFogo2;
	crescendoX=true;
	crescendoY=true;
	
}

void Fogo::desenhaFogo(float posX,float posY,float ang){
	glPushMatrix();
	glTranslatef(posX,posY,0);
	glRotatef(ang,0,0,1);
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

void Fogo::desenha(){
	
	
	desenhaFogo(posiX,posiY,angulo);
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

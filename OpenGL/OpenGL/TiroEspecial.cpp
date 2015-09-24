#include "TiroEspecial.h"
#include <iostream>

using namespace std;
TiroEspecial::TiroEspecial(float x,float y,float ang){
	posiX=x;
	posiY=y;
	angulo=ang;
	dimX=15;
	status='a';
	decremento=15;
}

void TiroEspecial::desenha(float xFinal,float yFinal){
    glPushMatrix();
	glTranslatef(posiX, posiY, 0);
	//glRotatef(angulo, 0, 0, 1);
	
	glColor3f(0,0,1);
	if(angulo==0){
 	    glBegin(GL_POLYGON);
		glVertex2f(posiX-0.5*dimX,posiY+decremento); 
		glVertex2f(posiX-0.5*dimX,yFinal);
		glVertex2f(posiX+0.5*dimX,yFinal);
		glVertex2f(posiX+0.5*dimX,posiY+decremento);
	    glEnd();
	    posiY+=decremento;
	    if(posiY+decremento>=yFinal){
	    	status='i';
	    }
    	}else if(angulo==90){
	    glBegin(GL_POLYGON);
		glVertex2f(posiX-decremento,posiY-0.5*dimX);
		glVertex2f(xFinal,posiY-0.5*dimX);
		glVertex2f(xFinal,posiY+0.5*dimX);
		glVertex2f(posiX-decremento,posiY+0.5*dimX);
	    glEnd();
	    posiX-=decremento;
	    if(posiX-decremento<=xFinal){
	    	status='i';
	    }
    	}else if(angulo==-90){
	    glBegin(GL_POLYGON);
		glVertex2f(posiX+decremento,posiY+0.5*dimX);
		glVertex2f(xFinal,posiY+0.5*dimX);
		glVertex2f(xFinal,posiY-0.5*dimX);
		glVertex2f(posiX+decremento,posiY-0.5*dimX);
	    glEnd();
		posiX += decremento;
	    if(posiX+decremento>=xFinal){
	    	status='i';
	    }
	}else if(angulo==180){
	    glBegin(GL_POLYGON);
		glVertex2f(posiX+0.5*dimX,posiY-decremento);
		glVertex2f(posiX+0.5*dimX,yFinal);
		glVertex2f(posiX-0.5*dimX,yFinal);
		glVertex2f(posiX-0.5*dimX,posiY-decremento);
	    glEnd();
	    posiY-=decremento;
	    if(posiY-decremento<=yFinal){
	    	status='i';
	    }
	}
	
    glPopMatrix();   
}


void  TiroEspecial::setDimX(float tamanho){dimX=tamanho;}

void  TiroEspecial::setStatus(char stat){status=stat;}

float  TiroEspecial::getPosiX(){return posiX;}
float  TiroEspecial::getPosiY(){return posiY;}
float  TiroEspecial::getAngulo(){return angulo;}
float  TiroEspecial::getDimX(){return dimX;}
char  TiroEspecial::getStatus(){return status;}



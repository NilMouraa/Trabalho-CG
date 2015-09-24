#include "Bloco.h"

//Construtores
Bloco::Bloco	(float x,float y,float ang,float dimX,float dimY){
	posiX=x;
	posiY=y;
	angulo=ang;
	this->dimX=dimX;
	this->dimY=dimY;
}
Bloco::Bloco	(){}

void Bloco::desenha	(){ 
	glPushMatrix();
	glTranslatef(posiX, posiY, 0);
	glRotatef(angulo, 0, 0, 1);

	glColor3f(0.5f,0.5f,0.5f);
	glBegin(GL_QUADS); 
	glVertex2f(0,0); 
	glVertex2f(0,dimY); 
	glVertex2f(dimX,dimY); 
	glVertex2f(dimX,0); 
	glEnd(); 
	glColor3f(0.8f,0.8f,0.8f); 
	int incX=dimX/6; 
	glBegin(GL_LINE_LOOP); 
	glVertex2f(0,0); 
	glVertex2f(0,dimY); 
	glVertex2f(dimX,dimY); 
	glVertex2f(dimX,0); 
	glEnd(); 
	for(float c=0;c<dimY;c+=dimY/6){ 
		glBegin(GL_LINES); 
		glVertex2f(0,c); 
		glVertex2f(dimX,c); 
		glEnd(); 
		while(incX<dimX){ 
			glBegin(GL_LINES); 
			glVertex2f(incX,c); 
			glVertex2f(incX,c+dimY/6); 
			glEnd(); 
			incX+=dimX/3; 
		} 
		if(incX==dimX+dimX/6){ 
			incX=dimX/3; 
		}else{ 
			incX=dimX/6; 
		} 
	}

	glPopMatrix();
}
void Bloco::move	(float incrementoX,float incrementoY){
	posiX+=incrementoX;
	posiY+=incrementoY;
}
void Bloco::gira	(float incrementoAngulo){
	angulo+=incrementoAngulo;
}

//***************SETS***************
void Bloco::setDimX	(float tamanho){  dimX=tamanho;  }
void Bloco::setDimY	(float tamanho){  dimY=tamanho;  }

//***************GETS***************
float Bloco::getPosiX	(){  return posiX;  }
float Bloco::getPosiY	(){  return posiY;  }
float Bloco::getAngulo	(){  return angulo; }
float Bloco::getDimX	(){  return dimX;   }
float Bloco::getDimY	(){  return dimY;   }



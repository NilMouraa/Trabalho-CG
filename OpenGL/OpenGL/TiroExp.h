#ifndef TIROEXP_H
#define TIROEXP_H

#include <stdio.h>
#include <string.h>
#include <GL/glut.h>
#include <math.h> 
#include <iostream>
using namespace std;
 
class TiroExp{
private:
	float posiX;
	float posiY;
	float dimX;
	float dimY;
	float angulo;
	float incrementoAngulo;
	char direcao;
	bool terminou;
	char tipo;
	float velocidade;

public:
	//Construtores
	TiroExp(float x,float y, char direc,float dmX,float dmY,int tipoTiro);
	void desenhaContornoTipo1();
	void desenha		();
	void desenhaTipo1();
	void desenhaTipo2();
	void desenhaTipo3();

	//***************SETS***************
	void setDimX		(float tamanho);
	void setDimY		(float tamanho);
	//***************GETS***************
	float getPosiX();
	float getPosiY();
	float getAngulo();
	float getDimX();
	float getDimY();

	bool getTerminou();
	void Gira();
	void Move(float incremento);
	
};
#endif
#ifndef EXPLOSAO_H
#define EXPLOSAO_H

#include <stdio.h>
#include <string.h>
#include <GL/glut.h>
#include <math.h> 
#include <iostream>
using namespace std;
 
class Explosao{
private:
	float posiX;
	float posiY;
	float dimX;
	float dimY;
	float angulo;
	float dimXmedio;
	float dimYmedio;
	float dimXcentro;
	float dimYcentro;
	int incMax;
	int incAtual;
	bool terminou;
	bool diminui;
	float fatorCresc;

public:
	//Construtores
	Explosao(float x,float y,float ang, int incM,float cresc);
	void desenhaContornoParte(char parte);
	void desenhaParte	(char parte);
	void desenha		();

	//***************SETS***************
	void setDimX		(float tamanho);
	void setDimY		(float tamanho);
	void setDimXmedio	(float tamanho);
	void setDimYmedio	(float tamanho);
	void setDimXcentro	(float tamanho);
	void setDimYcentro	(float tamanho);

	//***************GETS***************
	float getPosiX();
	float getPosiY();
	float getAngulo();
	float getDimX();
	float getDimY();

	void incrementaTamanho	(int inc);
	void atualizaTamanhos	();
	bool getDiminui();
	bool getTerminou();

};
#endif
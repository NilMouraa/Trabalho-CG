#ifndef EXPLOSAO_H
#define EXPLOSAO_H

#include <stdio.h>
#include <string.h>
#include <GL/glut.h>
#include <math.h> 
#include <iostream>
#include <vector>
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
	
	vector <float> vetPontosXG;
	vector <float> vetPontosYG;
	vector <char> idObjG;
	vector <float> vetCorRG;
	vector <float> vetCorGG;
	vector <float> vetCorBG;
	int qtdPontosTotalG;
	
	vector <float> vetPontosXM;
	vector <float> vetPontosYM;
	vector <char> idObjM;
	vector <float> vetCorRM;
	vector <float> vetCorGM;
	vector <float> vetCorBM;
	int qtdPontosTotalM;

	vector <float> vetPontosXC;
	vector <float> vetPontosYC;
	vector <char> idObjC;
	vector <float> vetCorRC;
	vector <float> vetCorGC;
	vector <float> vetCorBC;
	int qtdPontosTotalC;
	
	vector <float> vetPontosXL;
	vector <float> vetPontosYL;
	vector <char> idObjL;
	int qtdPontosTotalL;
public:
	//Construtores
	Explosao(float x,float y,float ang, int incM,float cresc);
	void desenhaContornoParte(char parte);
	void leParte(char parte);
	void leContornoLinha();
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
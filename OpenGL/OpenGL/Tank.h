#pragma once
#ifndef TANK_H
#define	TANK_H
#include <stdio.h>
#include <string.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include "Explosao.h" 
#include "TiroEspecial.h"
#include "TiroExp.h"
#include "Fogo.h"
#include <vector>
//#include "TiroComum.h"
using namespace std;

class Tank{
private:
	Fogo *f1;
	Fogo *f2;
	Fogo *f3;
	Fogo *f4;
	Fogo *f5;
	Fogo *f6;
    float posiX;
    float posiY;
    float dimX;
    float dimY;
    float angulo;
    float vida;
	float vidaCheia;
    int qtdTiroEspec;
    char status;
    int tipo;
    float velocidade;
    Explosao *explosao;
	int tempoPraAtirar;
	float 	qtdPontuacao;
	vector <float> vetPontosX;
	vector <float> vetPontosY;
	vector <char> idObj;
	vector <float> vetCorR;
	vector <float> vetCorG;
	vector <float> vetCorB;
	int 	qtdPontosTotal;
	int vidasGanhas;
	int qtdVidas;
	
public:
    
    Tank(float x,float y,float ang,int tip);
	//Tank();
    void desenha();
    
    void move(float incremento);
         
    void viraDireita(float incremento,bool podeAndar);
    
    void viraEsquerda(float incremento,bool podeAndar);
    
    void viraCima(float incremento,bool podeAndar);
    
    void viraBaixo(float incremento,bool podeAndar);
       
    void recebeDano(float dano);
	
	void recebePontos(float p);
    
	void aumentaVida(float incremento);
	/*
    TiroEspec usaTiroEspec();
    
    TiroComum usaTiroComum();*/
	
	int getTempoPraAtirar();
	
    
    void setQtdTiroEspec(int qtd);
	void setDimX(float tamanho);
	void setDimY(float tamanho);
	void setStatus(char stat);
	void setPosiX(float x);
	void setPosiY(float y);
	void reiniciaVida();
	
	float getPosiCentroX();
	float getPosiCentroY();

	float getPosiOrigemX();

	float getPosiOrigemY();
	
	float getPosiX();
	float getPosiY();
	float getAngulo();
	float getDimX();
	float getDimY();
	char getStatus();
	int getTipo();
	float getVida();
	int getQtdVida();
	float getQtdPontuacao();
	TiroEspecial* atiraEspecial();
	TiroExp* atira(char tipo);
    
};


#endif


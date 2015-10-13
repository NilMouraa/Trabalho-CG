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
//#include "TiroComum.h"
using namespace std;

class Tank{
private:
    float posiX;
    float posiY;
    float dimX;
    float dimY;
    float angulo;
    float vida;
    int qtdTiroEspec;
    char status;
    int tipo;
    float velocidade;
    Explosao *explosao;
	int tempoPraAtirar;
public:
    
    Tank(float x,float y,float ang,int tip);
	Tank();
	void Inicializa(float x, float y, float ang, int tip);
    void desenha();
    
    void move(float incremento);
         
    void viraDireita(float incremento,bool podeAndar);
    
    void viraEsquerda(float incremento,bool podeAndar);
    
    void viraCima(float incremento,bool podeAndar);
    
    void viraBaixo(float incremento,bool podeAndar);
       
    void recebeDano(float dano);
    
	void aumentaVida(float incremento);
	/*
    TiroEspec usaTiroEspec();
    
    TiroComum usaTiroComum();*/
	
	int getTempoPraAtirar();
	
    
    void setQtdTiroEspec(int qtd);
	void setDimX(float tamanho);
	void setDimY(float tamanho);
	void setStatus(char stat);
	
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
	int getVida();
	TiroEspecial* atiraEspecial();
	TiroExp* atira(char tipo);
    
};


#endif


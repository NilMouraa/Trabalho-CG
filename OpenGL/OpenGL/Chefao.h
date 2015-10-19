#pragma once
#ifndef Chefao_H
#define	Chefao_H
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

class Chefao{
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
    
    Chefao(float x,float y,float ang,int tip);
	
	void desenhaChefao1();
	void desenhaChefao2();
	void desenhaChefao3();
	void desenhaChefao4();
	void desenhaEsteira(float yMinEst,float yMaxEst);
	
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


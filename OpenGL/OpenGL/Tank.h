#pragma once
#ifndef TANK_H
#define	TANK_H
#include <stdio.h>
#include <string.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include "Explosao.h" 
//#include "TiroEspec.h"
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
public:
    
    Tank(float x,float y,float ang,int tip);
	Tank();
	void Inicializa(float x, float y, float ang, int tip);
    void desenha();
    
    void move(float incremento);
         
    void viraDireita(float incremento);
    
    void viraEsquerda(float incremento);
    
    void viraCima(float incremento);
    
    void viraBaixo(float incremento);
       
    void recebeDano(float dano);
    
	void aumentaVida(float incremento);
	/*
    TiroEspec usaTiroEspec();
    
    TiroComum usaTiroComum();*/
    
    void setQtdTiroEspec(int qtd);
	void setDimX(float tamanho);
	void setDimY(float tamanho);
	void setStatus(char stat);
	float getPosiX();
	float getPosiY();
	float getAngulo();
	float getDimX();
	float getDimY();
	char getStatus();
	int getTipo();
	int getVida();
    
    
};


#endif	/* NAVE_H */


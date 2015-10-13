#pragma once
#ifndef GameOver_H
#define	GameOver_H
#include <stdio.h>
#include <string.h>
#include <GL/glut.h>
#include <math.h>
#include "Explosao.h"
#include <iostream>
using namespace std;

class GameOver{
private:
	Explosao *explosao;
    float posiXGame;
    float posiYGame;
    float posiXOver;
    float posiYOver;
    char status;
	float limiteXGame;
	float limiteXOver;
	float velocMove;
	float DIM_X_TANK;
	float DIM_Y_TANK;
public:
    GameOver();
    void desenha();
	
	void DesenhaG(float posiX, float posiY,float ang,int tipoTank);
	void DesenhaA(float posiX, float posiY,float ang,int tipoTank);
	void DesenhaM(float posiX, float posiY,float ang,int tipoTank);
	void DesenhaE(float posiX, float posiY,float ang,int tipoTank);
	void DesenhaO(float posiX, float posiY,float ang,int tipoTank);
	void DesenhaV(float posiX, float posiY,float ang,int tipoTank);
	void DesenhaR(float posiX, float posiY,float ang,int tipoTank);
	
	
	char getStatus();
    
};


#endif


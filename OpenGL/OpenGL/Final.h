#pragma once
#ifndef Final_H
#define	Final_H
#include <stdio.h>
#include <string.h>
#include <GL/glut.h>
#include <math.h>
#include "Tank.h"
#include "TiroEspecial.h"
#include <vector>
#include <iostream>
using namespace std;

class Final{
private:
    float posiXLengs;
    float posiYLengs;
    char status;
	float limiteXLengs;
	float velocMove;
	float DIM_X_TANK;
	float DIM_Y_TANK;
	Tank *tj;
	vector <Tank*> tanques;
	vector <TiroEspecial*> lasers;
	bool parouNoMeio;
	
public:
    Final();
    void desenha();
	
	void DesenhaL(float posiX, float posiY,float ang,int tipoTank);
	void DesenhaE(float posiX, float posiY,float ang,int tipoTank);
	void DesenhaN(float posiX, float posiY,float ang,int tipoTank);
	void DesenhaG(float posiX, float posiY,float ang,int tipoTank);
	void DesenhaS(float posiX, float posiY,float ang,int tipoTank);
	
	void DesenhaLVet(float posiX, float posiY,float ang,int tipoTank);
	void DesenhaEVet(float posiX, float posiY,float ang,int tipoTank);
	void DesenhaNVet(float posiX, float posiY,float ang,int tipoTank);
	void DesenhaGVet(float posiX, float posiY,float ang,int tipoTank);
	void DesenhaSVet(float posiX, float posiY,float ang,int tipoTank);
	
	char getStatus();
    
};


#endif


#pragma once
//#ifndef INTRODUCAO_H
#define	INTRODUCAO_H
#include <stdio.h>
#pragma once
#include <string.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include "TiroEspecial.h"
#include "Tank.h"
#include <vector>
//#define DIM_X_TANK 15.0 
//#define DIM_Y_TANK 15.0
using namespace std;
class Introducao{
private:
	Tank *tan;
	float DIM_X_TANK;
	float DIM_Y_TANK;
	float incremento;
	vector <Tank*> tanques;
	vector <TiroEspecial*> lasers;
	bool fim;
	
public:
Introducao();
void DesenhaE(float posiX, float posiY,float ang,int tipoTank);
void DesenhaL(float posiX, float posiY,float ang,int tipoTank);
void DesenhaS(float posiX, float posiY,float ang,int tipoTank);
void DesenhaG(float posiX, float posiY,float ang,int tipoTank);
void DesenhaN(float posiX, float posiY,float ang,int tipoTank);
/*
void DesenhaNMeio(float posiX, float posiY,float ang,int tipoTank);
*/
void DesenhaU(float posiX, float posiY,float ang,int tipoTank);

void Desenha(float largura, float altura);
void Incrementa(float inc);
float getIncremento();
bool getFim();

};

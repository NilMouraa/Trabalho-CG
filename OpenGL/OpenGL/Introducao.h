#include <stdio.h>
#include <string.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include "Tank.h"

using namespace std;

class Introducao{
private:
	Tank *tan;
	float DIM_X_TANK;
	float DIM_Y_TANK;
	float incremento;
public:
	//Construtores
	Introducao		();

	void DesenhaE	(float posiX, float posiY,float ang,int tipoTank);
	void DesenhaL	(float posiX, float posiY,float ang,int tipoTank);
	void DesenhaS	(float posiX, float posiY,float ang,int tipoTank);
	void DesenhaG	(float posiX, float posiY,float ang,int tipoTank);
	void DesenhaN	(float posiX, float posiY,float ang,int tipoTank);
	void DesenhaU	(float posiX, float posiY,float ang,int tipoTank);
	void Desenha	();
	void Incrementa	(float inc);

};
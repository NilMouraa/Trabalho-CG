#ifndef TIROESPECIAL_H
#define	TIROESPECIAL_H
#include <stdio.h>
#include <string.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
using namespace std;

class TiroEspecial {
private:
	float posiX;
	float posiY;
	float dimX;
	float angulo;
	char status;
	float decremento;

public:
	TiroEspecial(float x, float y, float ang);
	TiroEspecial();
	void desenha(float xFinal, float yFinal);
	void desenhaAng0(float xFinal, float yFinal);
	void desenhaAng90(float xFinal, float yFinal);
	void desenhaAngM90(float xFinal, float yFinal);
	void desenhaAng180(float xFinal, float yFinal);
	void setDimX(float tamanho);
	void setStatus(char stat);
	float getPosiX();
	float getPosiY();
	float getAngulo();
	float getDimX();
	char getStatus();


};
#endif


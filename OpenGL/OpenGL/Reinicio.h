#pragma once
#ifndef Reinicio_H
#define	Reinicio_H
#include <stdio.h>
#include <string.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
using namespace std;

class Reinicio{
private:
    float posiXGuind;
    float posiYGuind;
    float posiXBase;
    float posiYBase;
    float dimXGuind;
    float dimYGuind;
    float dimXBase;
    float dimYBase;
    char status;
	float limiteYGuind;
	float limiteXGuind;
	float velocMove;
	bool subiu;
public:
    Reinicio();
    void desenha();
	void desenhaParteGuindaste(float posX,float posY);
	void desenhaParteBase(float posX,float posY);	
	void renderBitmapString(float x, float y, void *font, const char *string);
	void desenhaPlaca(float posX,float posY);
	void setDimX(float tamanho);
	void setDimY(float tamanho);	
	
	float getPosiX();
	float getPosiY();
	float getDimX();
	float getDimY();
	char getStatus();
    
};


#endif


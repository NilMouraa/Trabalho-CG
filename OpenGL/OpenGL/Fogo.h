#pragma once
#ifndef Fogo_H
#define	Fogo_H
#include <stdio.h>
#include <string.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>

using namespace std;

class Fogo{
private:
	float posiX;
	float posiY;
	float angulo;
	float velocCrescFogoX;
	float velocCrescFogoY;
	float limiteSobeFogoX;
	float limiteDesceFogoX;
	float limiteSobeFogoY;
	float limiteDesceFogoY;
	float dimXFogo;
	float dimYFogo;
	bool crescendoX;
	bool crescendoY;
public:
    Fogo(float posiX2,
	float posiY2,
	float angulo2,
	float velocCrescFogoX2,
	float velocCrescFogoY2,
	float limiteSobeFogoX2,
	float limiteDesceFogoX2,
	float limiteSobeFogoY2,
	float limiteDesceFogoY2,
	float dimXFogo2,
	float dimYFogo2);
    void desenha();
	void desenhaFogo(float posX,float posY,float ang);
	
    
};


#endif


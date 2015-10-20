#pragma once
#ifndef FimDeFase_H
#define	FimDeFase_H
#include <stdio.h>
#include <string.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
using namespace std;

class FimDeFase{
private:
	int fase;
    float posiXTopoP;
    float posiYTopoP;
    float posiXBaseP;
    float posiYBaseP;
    float dimXTopoP;
    float dimYTopoP;
    float dimXBaseP;
    float dimYBaseP;
	float posiXTopoI;
    float posiYTopoI;
    float posiXBaseI;
    float posiYBaseI;
    float dimXTopoI;
    float dimYTopoI;
    float dimXBaseI;
    float dimYBaseI;
    char status;
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
	float velocCrescFogoX2;
	float velocCrescFogoY2;
	float limiteSobeFogoX2;
	float limiteDesceFogoX2;
	float limiteSobeFogoY2;
	float limiteDesceFogoY2;
	float dimXFogo2;
	float dimYFogo2;
	bool crescendoX2;
	bool crescendoY2;
	int framesMax;
	int contFrames;
public:
    FimDeFase(int numeroFase);
    void desenha();
	void desenhaParteGuindaste(float posX,float posY,char qual);
	void desenhaParteBase(float posX,float posY,char qual);
	void desenhaFogo(float posX,float posY);	
	void desenhaFogo2(float posX,float posY);	
	char getStatus();
    
};


#endif


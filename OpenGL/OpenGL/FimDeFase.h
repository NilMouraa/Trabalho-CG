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
public:
    FimDeFase();
    void desenha();
	void desenhaParteGuindaste(float posX,float posY,char qual);
	void desenhaParteBase(float posX,float posY,char qual);
	void desenhaFogo(float posX,float posY);	
	
	char getStatus();
    
};


#endif


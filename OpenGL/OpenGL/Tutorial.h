#ifndef TUTORIAL_H
#define	TUTORIAL_H
#pragma once
#include <stdio.h>
#include <string.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
using namespace std;

class Tutorial{
private:
	
public:
    
    Tutorial();
    void desenha();
	void desenhaSeta(float posiX,float posiY,float angulo);
	void desenhaTank(float posiX,float posiY,float angulo);
	void desenhaHpExtra(float posiX,float posiY);
	void desenhaArmaEspecial(float posiX,float posiY);
	void desenhaObjetos();
	void desenhaBlocos();
    void renderBitmapString(float x, float y, void *font,const char *string);
    
};


#endif

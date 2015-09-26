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
	void desenhaBlocos();
    void renderBitmapString(float x, float y, void *font,const char *string);
    
};


#endif

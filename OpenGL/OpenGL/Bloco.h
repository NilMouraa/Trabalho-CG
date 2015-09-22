#include <stdio.h>
#include <string.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>

using namespace std;

class Bloco{
private:
    float posiX;
    float posiY;
    float dimX;
    float dimY;
    float angulo;
public:
    //Construtores
    Bloco	(float x,float y,float ang, float dimX,float dimY);
	Bloco	();
    
    void desenha	();
    void move		(float incrementoX,float incrementoY);
    void gira		(float incrementoAngulo);

	//***************SETS***************
    void setDimX	(float tamanho);
    void setDimY	(float tamanho);

	//***************GETS***************
    float getPosiX	();
    float getPosiY	();
    float getAngulo	();
    float getDimX	();
    float getDimY	();
    
    
};

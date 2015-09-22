#include <stdio.h>
#include <string.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>

using namespace std;

class Tank{
private:
	float	posiX;
	float	posiY;
	float	dimX;
	float	dimY;
	float	angulo;
	float	vida;
	int		qtdTiroEspec;
	char	status;
	int		tipo;
	float	velocidade;
public:
	//Construtores
	Tank(double x,double y,double ang,int tip,double dimX,double dimY);
	Tank(double x,double y,double ang,int tip);
	Tank();

	void desenha();

	void move			(float incremento);
	void viraDireita	(float incremento);
	void viraEsquerda	(float incremento);
	void viraCima		(float incremento);
	void viraBaixo		(float incremento);
	void recebeDano		(float dano);
	void aumentaVida	(float incremento);
	
	//***************SETS***************
	void setQtdTiroEspec(int qtd);
	void setDimX		(float tamanho);
	void setDimY		(float tamanho);
	void setStatus		(char stat);

	//***************GETS***************
	float getPosiX	();
	float getPosiY	();
	float getAngulo	();
	float getDimX	();
	float getDimY	();
	char  getStatus	();
	int   getTipo	();
	int   getVida	();

	//Desenho
	void DesenhaTank4	(float posiX, float posiY,float ang);
	void DesenhaTank3	(float posiX, float posiY,float ang);
	void DesenhaTank2	(float posiX, float posiY,float ang);
	void DesenhaTank1	(float posiX, float posiY,float ang);
	void DesenhaTank	(float posiX, float posiY,float ang,int tipo);
};
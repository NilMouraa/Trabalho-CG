#include "TiroExp.h"
#include "Tank.h"
//Construtores
TiroExp::TiroExp(float x,float y, char direc,float dmX,float dmY,int tipoTiro){
	status = 'a';
	posiX=x;
	posiY=y;
	angulo=0;
	direcao=direc;
	dimX=dmX;
	dimY=dmY;
	tipo=tipoTiro;
	terminou=false;
	if (tipo == 3) {
		deInimigo = true;
	}
	else deInimigo = false;
	incrementoAngulo=1;
	if (tipo == 1) {
		velocidade = 1;
	}
	else if (tipo == 2) {
		velocidade = 1;
	}
	else if (tipo == 3) {
		velocidade = 1;
	}
}
void TiroExp::desenhaTipo2(){
	glPushMatrix();
	glTranslatef(posiX, posiY, 0);
	glRotatef(angulo, 0, 0, 1);
	
		glBegin(GL_POLYGON);
			glColor3f(1,1,1);
			glVertex2f(-dimX*0.5,-dimY*0.5);
			glVertex2f(-dimX*0.5,dimY*0.5);
			glColor3f(0,0,1);
			glVertex2f(0,dimY*0.5);
			glVertex2f(0,-dimY*0.5);
		glEnd();
		glBegin(GL_POLYGON);
			glColor3f(0,0,1);
			glVertex2f(0,-dimY*0.5);
			glVertex2f(0,dimY*0.5);
			glColor3f(1,1,1);
			glVertex2f(dimX*0.5,dimY*0.5);
			glVertex2f(dimX*0.5,-dimY*0.5);
		glEnd();
	
	glPopMatrix();
}
void TiroExp::desenhaTipo3(){
	glPushMatrix();
	glTranslatef(posiX, posiY, 0);
	glRotatef(angulo, 0, 0, 1);
	
		glBegin(GL_POLYGON);
			glColor3f(1,1,1);
			glVertex2f(-dimX*0.5,-dimY*0.2);
			glVertex2f(-dimX*0.5,dimY*0.2);
			glColor3f(0,0,1);
			glVertex2f(0,dimY*0.5);
			glVertex2f(0,-dimY*0.5);
		glEnd();
		glBegin(GL_POLYGON);
			glColor3f(0,0,1);
			glVertex2f(0,-dimY*0.5);
			glVertex2f(0,dimY*0.5);
			glColor3f(1,1,1);
			glVertex2f(dimX*0.5,dimY*0.2);
			glVertex2f(dimX*0.5,-dimY*0.2);
		glEnd();
	
	glPopMatrix();
}
void TiroExp::desenhaContornoTipo1() {
	glPushMatrix();
	glTranslatef(posiX, posiY, 0);
	glRotatef(angulo, 0, 0, 1);
	float pontosX[50];
	float pontosY[50];
	int qtdPontos = 0;
	//char url[]="tank1.txt";
	FILE *arq;
	float cooX, cooY;
	float dimXaux=dimX;
	float dimYaux=dimY;
	char tipo;
	arq = fopen("TiroExpLinha.txt", "r");
	if (arq == NULL)
		printf("Erro, nao foi possivel abrir o arquivo\n");
	else {
		char tpAnt = 'z';
		while ((fscanf(arq, "%c %f %f\n", &tipo, &cooX, &cooY)) != EOF)
		{
			if (tipo == tpAnt || tpAnt == 'z') {
				pontosX[qtdPontos] = cooX-0.5;
				pontosY[qtdPontos] = cooY-0.5;
				qtdPontos++;
				tpAnt = tipo;

			}
			else {
				
				glColor3f(1, 1, 1);
				glBegin(GL_LINE_LOOP);
				for (int i = 0; i<qtdPontos; i++) {
					glVertex2f(pontosX[i] * dimXaux, pontosY[i] * dimYaux);
				}
				glEnd();
				tpAnt = tipo;
				pontosX[0] = cooX-0.5;
				pontosY[0] = cooY-0.5;
				qtdPontos = 1;
			}
		}
		glEnd();
		glColor3f(1, 1, 1);
		glBegin(GL_LINE_LOOP);
		for (int i = 0; i<qtdPontos; i++) {
			glVertex2f(pontosX[i] * dimXaux, pontosY[i] * dimYaux);
		}
		glEnd();

	}
	fclose(arq);

	glPopMatrix();
}
void TiroExp::desenhaTipo1(){
	glPushMatrix();
	glTranslatef(posiX, posiY, 0);
	glRotatef(angulo, 0, 0, 1);
	float pontosX[50];
	float pontosY[50];
	int qtdPontos=0;
	//char url[]="tank1.txt";
	FILE *arq;
	float cooX,cooY,corR,corG,corB,corRAnt,corGAnt,corBAnt;
	float dimXaux=dimX;
	float dimYaux=dimY;
	char tipo;
	arq = fopen("TiroExp.txt", "r");
	if(arq == NULL)
		printf("Erro, nao foi possivel abrir o arquivo\n");
	else{
		char tpAnt='z';
		while( (fscanf(arq,"%f %f %f %c %f %f\n", &corR,&corG,&corB,&tipo, &cooX, &cooY))!=EOF )
		{
			if(tipo==tpAnt || tpAnt=='z'){
				pontosX[qtdPontos]=cooX-0.5;
				pontosY[qtdPontos]=cooY-0.5;
				qtdPontos++;
				tpAnt=tipo;
				corRAnt=corR;
				corGAnt=corG;
				corBAnt=corB;

			}else{
				glColor3f(corRAnt,corGAnt,corBAnt);
				glBegin(GL_POLYGON);	
				for(int i=qtdPontos-1;i>=0;i--){
					glVertex2f(pontosX[i]*dimXaux,pontosY[i]*dimYaux);
				}
				glEnd();
				tpAnt=tipo;
				pontosX[0]=cooX-0.5;
				pontosY[0]=cooY-0.5;
				qtdPontos=1;
				corRAnt=corR;
				corGAnt=corG;
				corBAnt=corB;
			}
		}
		glColor3f(corRAnt,corGAnt,corBAnt);
		glBegin(GL_POLYGON);	
		for(int i=0;i<qtdPontos;i++){
			glVertex2f(pontosX[i]*dimXaux,pontosY[i]*dimYaux);
		}
		glEnd();

	}
	fclose(arq);

	glPopMatrix();
	desenhaContornoTipo1();
	Gira();
}
void TiroExp::desenha(){
	if(tipo==1){
		desenhaTipo1();
	}else if(tipo==2){
		desenhaTipo2();
	}else if(tipo==3){
		desenhaTipo3();
	}
}

void TiroExp::Move(float incremento){
	if(direcao=='d'){
		posiX+=(incremento*velocidade);
	}if(direcao=='e'){
		posiX-=(incremento*velocidade);
	}if(direcao=='c'){
		posiY+=(incremento*velocidade);
	}if(direcao=='b'){
		posiY-=(incremento*velocidade);
	}
}

void TiroExp::Gira(){
	angulo+=incrementoAngulo;
}

//***************SETS***************
void TiroExp::setDimX			(float tamanho){  dimX      = tamanho;  }
void TiroExp::setDimY			(float tamanho){  dimY      = tamanho;  }
void TiroExp::setStatus(char s)				   {  status = s; }

//***************GETS***************
float TiroExp::getPosiX	(){  return posiX;  }
float TiroExp::getPosiY	(){  return posiY;  }
float TiroExp::getAngulo	(){  return angulo;		}
float TiroExp::getDimX		(){  return dimX;		}
float TiroExp::getDimY		(){  return dimY;		}
float TiroExp::getEdeInimigo(){  return deInimigo;	}

bool TiroExp::getTerminou() { return terminou; }
char TiroExp::getStatus()	{ return status; }
char TiroExp::getDirecao() { return direcao; }

float  TiroExp::getPosiCentroX() {
	/*if (this->angulo == 0) {
		return posiX;
	}
	else if (this->angulo == 90) {
		return posiX - 0.5*dimY;
	}
	else if (this->angulo == -90) {
		return posiX + 0.5*dimY;
	}
	else if (this->angulo == 180) {
		return posiX;
	}*/
	return posiX;

}

float  TiroExp::getPosiCentroY() {
	/*if (this->angulo == 0) {
		return posiY + 0.5*dimY;
	}
	else if (this->angulo == 90) {
		return posiY;
	}
	else if (this->angulo == -90) {
		return posiY;
	}
	else if (this->angulo == 180) {
		return posiY - 0.5*dimY;
	}*/
	return posiY;
}

float  TiroExp::getPosiOrigemX() {
	if (this->angulo == 0) {
		return ( posiX - 0.5*dimX );
	}
	else if (this->angulo == 90) {
		return posiX - dimY;
	}
	else if (this->angulo == -90) {
		return posiX;
	}
	else if (this->angulo == 180) {
		return posiX - 0.5*dimX;
	}

}
float  TiroExp::getPosiOrigemY() {
	if (this->angulo == 0) {
		return posiY;
	}
	else if (this->angulo == 90) {
		return (posiY - 0.5*dimX);
	}
	else if (this->angulo == -90) {
		return (posiY - 0.5*dimX);
	}
	else if (this->angulo == 180) {
		return posiY - dimY;
	}
}
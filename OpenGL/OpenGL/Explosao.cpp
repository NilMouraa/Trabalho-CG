#include "Explosao.h"
#include "Tank.h"
//Construtores
Explosao::Explosao(float x,float y,float ang,int incM,float cresc){
	posiX=x;
	posiY=y;
	angulo=ang;
	incMax=incM;
	incAtual=0;
	atualizaTamanhos();
	terminou=false;
	diminui=false;
	fatorCresc=cresc; 
	leParte('g');
	leParte('m');
	leParte('c');
	leContornoLinha();
}
void Explosao::desenhaContornoParte(char parte) {
	glPushMatrix();
	glTranslatef(posiX, posiY, 0);
	glRotatef(angulo, 0, 0, 1);
	float pontosX[50];
	float pontosY[50];
	int qtdPontos = 0;
	float cooX, cooY;
	float dimXaux;
	float dimYaux;
	char tipoPol;
	if (parte == 'g') {
		dimXaux = dimX;
		dimYaux = dimY;/*
					   glTranslatef(posiX, posiY, 0);
					   glRotatef(angulo, 0, 0, 1);*/
	}
	else if (parte == 'm') {
		dimXaux = dimXmedio;
		dimYaux = dimYmedio;/*
							glTranslatef(posiX+(dimX/2)-dimXaux/2, posiY+(dimY/2)-dimYaux/2, 0);
							glRotatef(angulo, 0, 0, 1);*/
	}
	else if (parte == 'c') {
		dimXaux = dimXcentro;
		dimYaux = dimYcentro;/*
							 glTranslatef(posiX+(dimX/2)-dimXaux/2, posiY+(dimY/2)-dimYaux/2, 0);
							 glRotatef(angulo, 0, 0, 1);*/
	}
	
		char tpAnt='z';
		for(int cont=0;cont<qtdPontosTotalL;cont++)
		{
			tipoPol=idObjL[cont];
			cooX=vetPontosXL[cont];
			cooY=vetPontosYL[cont];
			if (tipoPol == tpAnt || tpAnt == 'z') {
				pontosX[qtdPontos] = cooX-0.5;
				pontosY[qtdPontos] = cooY-0.5;
				qtdPontos++;
				tpAnt = tipoPol;

			}
			else {
				
				glColor3f(1, 1, 1);
				glBegin(GL_LINE_LOOP);
				for (int i = 0; i<qtdPontos; i++) {
					glVertex2f(pontosX[i] * dimXaux, pontosY[i] * dimYaux);
				}
				glEnd();
				tpAnt = tipoPol;
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
glPopMatrix();
}
void Explosao::leParte(char parte){
	
	FILE *arq = NULL;
	if(parte=='g'){
		arq = fopen("explosaoG.txt", "r");
		qtdPontosTotalG = 0;
		float cooX, cooY, corR, corG, corB, corRAnt, corGAnt, corBAnt;
		char tipoPol;
		if (arq == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
		else {
			while ((fscanf(arq, "%f %f %f %c %f %f\n", &corR, &corG, &corB, &tipoPol, &cooX, &cooY)) != EOF)
			{
				vetCorRG.push_back(corR);
				vetCorGG.push_back(corG);
				vetCorBG.push_back(corB);
				idObjG.push_back(tipoPol);
				vetPontosXG.push_back(cooX);
				vetPontosYG.push_back(cooY);
				qtdPontosTotalG++;
			}
		}
		fclose(arq);
	}else if(parte=='m'){
		arq = fopen("explosaoM.txt", "r");
		qtdPontosTotalM = 0;
		float cooX, cooY, corR, corG, corB, corRAnt, corGAnt, corBAnt;
		char tipoPol;
		if (arq == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
		else {
			while ((fscanf(arq, "%f %f %f %c %f %f\n", &corR, &corG, &corB, &tipoPol, &cooX, &cooY)) != EOF)
			{
				vetCorRM.push_back(corR);
				vetCorGM.push_back(corG);
				vetCorBM.push_back(corB);
				idObjM.push_back(tipoPol);
				vetPontosXM.push_back(cooX);
				vetPontosYM.push_back(cooY);
				qtdPontosTotalM++;
			}
		}
		fclose(arq);
	}else if(parte=='c'){
		arq = fopen("explosaoC.txt", "r");
		qtdPontosTotalC = 0;
		float cooX, cooY, corR, corG, corB, corRAnt, corGAnt, corBAnt;
		char tipoPol;
		if (arq == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
		else {
			while ((fscanf(arq, "%f %f %f %c %f %f\n", &corR, &corG, &corB, &tipoPol, &cooX, &cooY)) != EOF)
			{
				vetCorRC.push_back(corR);
				vetCorGC.push_back(corG);
				vetCorBC.push_back(corB);
				idObjC.push_back(tipoPol);
				vetPontosXC.push_back(cooX);
				vetPontosYC.push_back(cooY);
				qtdPontosTotalC++;
			}
		}
		fclose(arq);
	}
	
}
void Explosao::leContornoLinha(){
	
	FILE *arq = NULL;
		arq = fopen("explosaoLinha.txt", "r");
		qtdPontosTotalL = 0;
		float cooX, cooY;
		char tipoPol;
		if (arq == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
		else {
			while ((fscanf(arq, "%c %f %f\n", &tipoPol, &cooX, &cooY)) != EOF)
			{
				idObjL.push_back(tipoPol);
				vetPontosXL.push_back(cooX);
				vetPontosYL.push_back(cooY);
				qtdPontosTotalL++;
			}
		}
		fclose(arq);
	
	
}
void Explosao::desenhaParte(char parte){
	glPushMatrix();
	glTranslatef(posiX, posiY, 0);
	//glRotatef(angulo, 0, 0, 1);
	float pontosX[50];
	float pontosY[50];
	int qtdPontos=0;
	float cooX,cooY,corR,corG,corB,corRAnt,corGAnt,corBAnt;
	float dimXaux;
	float dimYaux;
	char tipoPol;
	if(parte=='g'){
		dimXaux=dimX;
		dimYaux=dimY;
		
		char tpAnt='z';
		for(int cont=0;cont<qtdPontosTotalG;cont++)
		{
			corR=vetCorRG[cont];
			corG=vetCorGG[cont];
			corB=vetCorBG[cont];
			tipoPol=idObjG[cont];
			cooX=vetPontosXG[cont];
			cooY=vetPontosYG[cont];
			
			if(tipoPol==tpAnt || tpAnt=='z'){
				pontosX[qtdPontos]=cooX-0.5;
				pontosY[qtdPontos]=cooY-0.5;
				qtdPontos++;
				tpAnt=tipoPol;
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
				tpAnt=tipoPol;
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

		
	}else if(parte=='m'){
		dimXaux=dimXmedio;
		dimYaux=dimYmedio;
		char tpAnt='z';
		for(int cont=0;cont<qtdPontosTotalM;cont++)
		{
			corR=vetCorRM[cont];
			corG=vetCorGM[cont];
			corB=vetCorBM[cont];
			tipoPol=idObjM[cont];
			cooX=vetPontosXM[cont];
			cooY=vetPontosYM[cont];
			
			if(tipoPol==tpAnt || tpAnt=='z'){
				pontosX[qtdPontos]=cooX-0.5;
				pontosY[qtdPontos]=cooY-0.5;
				qtdPontos++;
				tpAnt=tipoPol;
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
				tpAnt=tipoPol;
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
	}else if(parte=='c'){
		dimXaux=dimXcentro;
		dimYaux=dimYcentro;
		char tpAnt='z';
		for(int cont=0;cont<qtdPontosTotalC;cont++)
		{
			corR=vetCorRC[cont];
			corG=vetCorGC[cont];
			corB=vetCorBC[cont];
			tipoPol=idObjC[cont];
			cooX=vetPontosXC[cont];
			cooY=vetPontosYC[cont];
			
			if(tipoPol==tpAnt || tpAnt=='z'){
				pontosX[qtdPontos]=cooX-0.5;
				pontosY[qtdPontos]=cooY-0.5;
				qtdPontos++;
				tpAnt=tipoPol;
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
				tpAnt=tipoPol;
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
	
	glPopMatrix();
	desenhaContornoParte(parte);
}
void Explosao::desenha(){
	desenhaParte('g');
	desenhaParte('m');
	desenhaParte('c');

}

//***************SETS***************
void Explosao::setDimX			(float tamanho){  dimX      = tamanho;  }
void Explosao::setDimY			(float tamanho){  dimY      = tamanho;  }
void Explosao::setDimXmedio		(float tamanho){  dimXmedio = tamanho;  }
void Explosao::setDimYmedio		(float tamanho){  dimYmedio = tamanho;  }
void Explosao::setDimXcentro	(float tamanho){  dimXcentro= tamanho;  }
void Explosao::setDimYcentro	(float tamanho){  dimYcentro= tamanho;  }

//***************GETS***************
float Explosao::getPosiX	(){  return posiX;  }
float Explosao::getPosiY	(){  return posiY;  }
float Explosao::getAngulo	(){  return angulo; }
float Explosao::getDimX		(){  return dimX;   }
float Explosao::getDimY		(){  return dimY;   }


void Explosao::incrementaTamanho (int inc){
	if(incAtual>=incMax){
		diminui=true;
	}
	if(diminui){
		if(incAtual==0){
			terminou=true;
		}else{
			incAtual-=inc;
		}
	}else{
		incAtual+=inc;
	}
	atualizaTamanhos();

}
void Explosao::atualizaTamanhos(){
	dimX = incAtual*fatorCresc;
	dimY = incAtual*fatorCresc;
	dimXmedio=2*dimX/3;
	dimYmedio=2*dimY/3;
	dimXcentro=dimX/3;
	dimYcentro=dimY/3;	

}

bool Explosao::getDiminui() { return diminui; }
bool Explosao::getTerminou() { return terminou; }

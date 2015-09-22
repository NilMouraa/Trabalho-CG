#include "Explosao.h"

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

}

void Explosao::desenhaParte(char parte){
	glPushMatrix();
	glTranslatef(posiX, posiY, 0);
	glRotatef(angulo, 0, 0, 1);
	float pontosX[50];
	float pontosY[50];
	int qtdPontos=0;
	//char url[]="tank1.txt";
	FILE *arq;
	float cooX,cooY,corR,corG,corB,corRAnt,corGAnt,corBAnt;
	float dimXaux;
	float dimYaux;
	char tipo;
	if(parte=='g'){
		arq = fopen("explosaoG.txt", "r");
		dimXaux=dimX;
		dimYaux=dimY;/*
		glTranslatef(posiX, posiY, 0);
		glRotatef(angulo, 0, 0, 1);*/
	}else if(parte=='m'){
		arq = fopen("explosaoM.txt", "r");
		dimXaux=dimXmedio;
		dimYaux=dimYmedio;/*
		glTranslatef(posiX+(dimX/2)-dimXaux/2, posiY+(dimY/2)-dimYaux/2, 0);
		glRotatef(angulo, 0, 0, 1);*/
	}else if(parte=='c'){
		arq = fopen("explosaoC.txt", "r");
		dimXaux=dimXcentro;
		dimYaux=dimYcentro;/*
		glTranslatef(posiX+(dimX/2)-dimXaux/2, posiY+(dimY/2)-dimYaux/2, 0);
		glRotatef(angulo, 0, 0, 1);*/
	}
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
				glColor3f(1,1,1);
				glBegin(GL_LINE_LOOP);	
				for(int i=0;i<qtdPontos;i++){
					glVertex2f(pontosX[i]*dimXaux,pontosY[i]*dimYaux);
				}
				glEnd();
				tpAnt=tipo;
				pontosX[0]=cooX;
				pontosY[0]=cooY;
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
		glColor3f(1,1,1);
		glBegin(GL_LINE_LOOP);	
		for(int i=0;i<qtdPontos;i++){
			glVertex2f(pontosX[i]*dimXaux,pontosY[i]*dimYaux);
		}
		glEnd();

	}
	fclose(arq);

	glPopMatrix();     
}
void Explosao::desenha(){
	cout<<"ENTROU";
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
	if(incAtual==incMax){
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
void Explosao::atualizaTamanhos  (){
	dimX=incAtual*fatorCresc;
	dimY=incAtual*fatorCresc;
	dimXmedio=2*dimX/3;
	dimYmedio=2*dimY/3;
	dimXcentro=dimX/3;
	dimYcentro=dimY/3;	

}
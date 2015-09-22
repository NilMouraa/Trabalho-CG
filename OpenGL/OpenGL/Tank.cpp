#include <iostream>
#include "Tank.h"


using namespace std;

//Construtores
Tank::Tank(double x,double y,double ang,int tip,double dimX,double dimY){
	posiX=x;
	posiY=y;
	angulo=ang;
	dimX=15;
	dimY=15;
	status='i';
	qtdTiroEspec=0;
	tipo=tip;
	if(tip==1){
		vida=250;
		velocidade=1;
	}else if(tip==2){
		vida=250;
		velocidade=2;
	}else if(tip==3){
		vida=250;
		velocidade=3;
	}else if(tip==4){
		vida=250;
		velocidade=2;
	}else if(tip==5){
		vida=250;
		velocidade=1;
	}
}
Tank::Tank(double x,double y,double ang,int tip){
	posiX=x;
	posiY=y;
	angulo=ang;
	dimX=15;
	dimY=15;
	status='i';
	qtdTiroEspec=0;
	tipo=tip;
	if(tip==1){
		vida=250;
		velocidade=1;
	}else if(tip==2){
		vida=250;
		velocidade=2;
	}else if(tip==3){
		vida=250;
		velocidade=3;
	}else if(tip==4){
		vida=250;
		velocidade=2;
	}else if(tip==5){
		vida=250;
		velocidade=1;
	}
}
Tank::Tank(){}

void  Tank::desenha(){
	glPushMatrix();
	glTranslatef(posiX, posiY, 0);
	glRotatef(angulo, 0, 0, 1);

	float pontosX[200];
	float pontosY[200];
	int qtdPontos=0;
	//char url[]="tank1.txt";
	FILE *arq;
	float cooX,cooY,corR,corG,corB,corRAnt,corGAnt,corBAnt;
	float yMinEst=-1;
	float yMaxEst=-1;
	char tipoPol;
	if(tipo==1){
		arq = fopen("tank1.txt", "r");
	}else if(tipo==2){
		arq = fopen("tank2.txt", "r");
	}else if(tipo==3){
		arq = fopen("tank3.txt", "r");
	}else if(tipo==4){
		arq = fopen("tank4.txt", "r");
	}else if(tipo==5){
		arq = fopen("tank5.txt", "r");
	}else if(tipo==6){
		arq = fopen("tankPlayer.txt", "r");
	}
	if(arq == NULL)
		printf("Erro, nao foi possivel abrir o arquivo\n");
	else{
		
		char tpAnt='z';
		while( (fscanf(arq,"%f %f %f %c %f %f\n", &corR,&corG,&corB,&tipoPol, &cooX, &cooY))!=EOF )
		{
			if(tipoPol==tpAnt || tpAnt=='z'){
				if(cooX==0){
					if(yMinEst==-1){
						yMinEst=cooY;
					}else{
						yMaxEst=cooY;
					}
				}
				pontosX[qtdPontos]=cooX;
				pontosY[qtdPontos]=cooY;
				qtdPontos++;
				tpAnt=tipoPol;
				corRAnt=corR;
				corGAnt=corG;
				corBAnt=corB;

			}else{
				glColor3f(corRAnt,corGAnt,corBAnt);
				glBegin(GL_POLYGON);	
				for(int i=0;i<qtdPontos;i++){
					glVertex2f(pontosX[i]*dimX,pontosY[i]*dimY);
				}
				glEnd();
				glColor3f(1,1,1);
				glBegin(GL_LINE_LOOP);	
				for(int i=0;i<qtdPontos;i++){
					glVertex2f(pontosX[i]*dimX,pontosY[i]*dimY);
				}
				glEnd();
				tpAnt=tipoPol;
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
			glVertex2f(pontosX[i]*dimX,pontosY[i]*dimY);
		}
		glEnd();
		glColor3f(1,1,1);
		glBegin(GL_LINE_LOOP);	
		for(int i=0;i<qtdPontos;i++){
			glVertex2f(pontosX[i]*dimX,pontosY[i]*dimY);
		}
		glEnd();
		//ESTEIRA ______________________________________________________________

		for(float i=yMinEst*dimY/*-0.1*dimY*/;i<yMaxEst*dimY;i+=0.1*dimY){
			glColor3f(0.4,0.4,0.4);
			glBegin(GL_QUADS);	
			glVertex2f(0,i);
			glVertex2f(0,i+0.1*dimY);
			glVertex2f(0.1*dimX,i);
			glVertex2f(0.1*dimX,i+0.1*dimY);
			//glVertex2f(0.05*dimX,i+0.05*dimY);
			glEnd();
			glBegin(GL_QUADS);	
			glVertex2f(0.9*dimX,i);
			glVertex2f(0.9*dimX,i+0.1*dimY);
			glVertex2f(dimX,i);
			glVertex2f(dimX,i+0.1*dimY);
			//glVertex2f(0.05*dimX,i+0.05*dimY);
			glEnd();
			glColor3f(1,1,1);
			glBegin(GL_LINE_LOOP);	
			glVertex2f(0,i);
			glVertex2f(0,i+0.1*dimY);
			glVertex2f(0.1*dimX,i+0.1*dimY);
			glVertex2f(0.1*dimX,i);
			glVertex2f(0.05*dimX,i+0.05*dimY);
			glEnd();
			glBegin(GL_LINE_LOOP);	
			glVertex2f(0.9*dimX,i);
			glVertex2f(0.9*dimX,i+0.1*dimY);
			glVertex2f(dimX,i+0.1*dimY);
			glVertex2f(dimX,i);
			glVertex2f(0.95*dimX,i+0.05*dimY);
			glEnd();
		}
		glBegin(GL_LINES);
		glVertex2f(0,yMinEst*dimY/*-0.1*dimY*/);
		glVertex2f(0.1*dimX,yMinEst*dimY/*-0.1*dimY*/);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(0.9*dimX,yMinEst*dimY/*-0.1*dimY*/);
		glVertex2f(dimX,yMinEst*dimY/*-0.1*dimY*/);
		glEnd();
		//_________________________________________________________________
		
	}
	fclose(arq);

	glPopMatrix();

}
void  Tank::move		(float incremento){
	if(angulo==0){
		/*cout<<"\tANDANDO CIMA";*/
		posiY+=(velocidade*incremento);
	}else if(angulo==-90){
		/*cout<<"\tANDANDO DIR";*/
		posiX+=(velocidade*incremento);
	}else if(angulo==90){
		//cout<<"\tANDANDO TRAS";
		posiX-=(velocidade*incremento);
	}else if(angulo==180){
		//cout<<"\tANDANDO ESQ";
		posiY-=(velocidade*incremento);
	}

}
void  Tank::viraDireita	(float incremento){
	cout<<"ANGULO: "<<this->getAngulo();
	if(angulo==0){
		posiY+=dimX;
	}else 
		if(angulo==180){
		posiX-=dimY;
	}else if(angulo==90){
		posiX-=dimY;
		posiY+=dimX;
	}else if(angulo==-90){
		move(incremento);
	}
	angulo=-90;
}
void  Tank::viraEsquerda(float incremento){
	cout<<"ANGULO: "<<this->getAngulo();
	if(angulo==0){
		posiX+=dimY;
	}else if(angulo==180){
		posiY-=dimX;
	}else if(angulo==-90){
		posiX+=dimY;
		posiY-=dimX;
	}else if(angulo==90){
		move(incremento);
	}
	angulo=90;
}
void  Tank::viraCima	(float incremento){
	cout<<"ANGULO: "<<this->getAngulo();
	if(angulo==90){
		posiX-=dimY;
	}else if(angulo==-90){
		posiY-=dimX;
	}else if(angulo==180){
		/*posiX+=dimX;
		posiY+=dimY;*/
		posiX-=dimX;
		posiY-=dimY;
	}else if(angulo==0){
		move(incremento);
	}
	angulo=0;
}
void  Tank::viraBaixo	(float incremento){
	cout<<"ANGULO: "<<this->getAngulo();
	if(angulo==90){
		posiY+=dimX;
	}else if(angulo==-90){
		posiX+=dimY;
	}else if(angulo==0){
		/*posiX-=dimX;
		posiY-=dimY;*/
		posiX+=dimX;
		posiY+=dimY;
	}else if(angulo==180){
		move(incremento);
	}
	angulo=180;
}
void  Tank::recebeDano	(float dano)	  	  {
	vida-=dano;
	if(vida<=0){
		status='M';
	}
}
void  Tank::aumentaVida	(float incremento){
	vida+=incremento;
}

//***************SETS***************
void  Tank::setQtdTiroEspec(int qtd)		{  qtdTiroEspec=qtd;  }
void  Tank::setDimX        (float tamanho)  {  dimX=tamanho;	  }
void  Tank::setDimY        (float tamanho)	{  dimY=tamanho;      }
void  Tank::setStatus      (char stat)		{  status=stat;       }

//***************GETS***************
float  Tank::getPosiX	(){  return posiX;	}
float  Tank::getPosiY	(){  return posiY;	}
float  Tank::getAngulo	(){  return angulo;	}
float  Tank::getDimX	(){  return dimX;   }
float  Tank::getDimY	(){  return dimY;	}
char   Tank::getStatus	(){  return status;	}
int    Tank::getTipo	(){  return tipo;	}
int    Tank::getVida	(){  return vida;	}

void Tank::DesenhaTank4(float posiX, float posiY,float ang){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(posiX,posiY,0);
	glRotatef(ang,0,0,1);
	//glClear(GL_COLOR_BUFFER_BIT);//limpa a janela de visualização

	glColor3f(0.2f,0.2f,1.0f);
	//corpo
	glBegin(GL_POLYGON);
	glVertex2f(0,10);	
	glVertex2f(0,80);
	glVertex2f(25,100);
	glVertex2f(50,80);		
	glVertex2f(50,10);	
	glVertex2f(25,0);
	glEnd();

	glColor3f(0.0f,0.0f,0.8f);
	//cabine
	glBegin(GL_QUADS);
	glVertex2f(10,75);
	glVertex2f(10,45);			
	glVertex2f(40,45);
	glVertex2f(40,75);
	glEnd();

	glColor3f(0.5f,0.5f,1.0f);
	//cano
	glBegin(GL_QUADS);
	glVertex2f(20,120);
	glVertex2f(30,120);			
	glVertex2f(30,50);
	glVertex2f(20,50);
	glEnd();

	//Esteira
	glColor3f(0.2f,0.2f,0.2f);
	for(float c=10;c<=80;c+=5){
		glBegin(GL_QUADS);
		glVertex2f(0,c);
		glVertex2f(0,5+c);
		glVertex2f(5,c);
		glVertex2f(5,5+c);
		glEnd();
		glBegin(GL_QUADS);
		glVertex2f(45,c);
		glVertex2f(45,5+c);
		glVertex2f(50,c);
		glVertex2f(50,5+c);
		glEnd();
	}

	glFlush();//joga pra tela
}
void Tank::DesenhaTank3(float posiX, float posiY,float ang){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(posiX,posiY,0);
	glRotatef(ang,0,0,1);
	//glClear(GL_COLOR_BUFFER_BIT);//limpa a janela de visualização

	glColor3f(1.0f,0.2f,0.2f);
	//corpo atras
	for(float inc=0;inc<50;inc+=5){
		glBegin(GL_QUADS);
		glVertex2f(inc,0);
		glVertex2f(inc+5,50);
		glVertex2f(inc+5,0);
		glVertex2f(inc,50);
		glEnd();
	}
	//corpo frente
	for(float inc=0;inc<50;inc+=10){
		glBegin(GL_QUADS);
		glVertex2f(inc,100);
		glVertex2f(inc+10,50);
		glVertex2f(inc+10,100);
		glVertex2f(inc,50);
		glEnd();
	}


	glColor3f(0.8f,0.0f,0.0f);
	//cabine
	glBegin(GL_QUADS);
	glVertex2f(10,75);			
	glVertex2f(40,45);
	glVertex2f(40,75);
	glVertex2f(10,45);
	glEnd();

	glColor3f(1.0f,0.5f,0.5f);
	//cano
	glBegin(GL_QUADS);
	glVertex2f(20,120);
	glVertex2f(30,120);			
	glVertex2f(30,50);
	glVertex2f(20,50);
	glEnd();
	glColor3f(0.2f,0.2f,0.2f);
	for(float c=0;c<=100;c+=5){
		glBegin(GL_QUADS);
		glVertex2f(0,c);
		glVertex2f(0,5+c);
		glVertex2f(5,c);
		glVertex2f(5,5+c);
		glEnd();
		glBegin(GL_QUADS);
		glVertex2f(45,c);
		glVertex2f(45,5+c);
		glVertex2f(50,c);
		glVertex2f(50,5+c);
		glEnd();
	}

	glFlush();//joga pra tela
}
void Tank::DesenhaTank2(float posiX, float posiY,float ang){
	glPushMatrix();
	glTranslatef(posiX,posiY,0);
	glRotatef(ang,0,0,1);
	//glClear(GL_COLOR_BUFFER_BIT);//limpa a janela de visualização

	glColor3f(0.2f,1.0f,0.2f);
	//corpo
	glBegin(GL_QUADS);
	glVertex2f(0,100);
	glVertex2f(50,0);
	glVertex2f(50,100);
	glVertex2f(0,0);
	glEnd();

	glColor3f(0.0f,0.8f,0.0f);
	//cabine
	glBegin(GL_QUADS);
	glVertex2f(10,75);			
	glVertex2f(40,45);
	glVertex2f(40,75);
	glVertex2f(10,45);
	glEnd();

	glColor3f(0.5f,1.0f,0.5f);
	//cano
	glBegin(GL_QUADS);
	glVertex2f(20,120);
	glVertex2f(30,120);			
	glVertex2f(30,50);
	glVertex2f(20,50);
	glEnd();
	glColor3f(0.2f,0.2f,0.2f);
	for(float c=0;c<=100;c+=5){
		glBegin(GL_QUADS);
		glVertex2f(0,c);
		glVertex2f(0,5+c);
		glVertex2f(5,c);
		glVertex2f(5,5+c);
		glEnd();
		glBegin(GL_QUADS);
		glVertex2f(45,c);
		glVertex2f(45,5+c);
		glVertex2f(50,c);
		glVertex2f(50,5+c);
		glEnd();
	}

	glPopMatrix();//joga pra tela
}
void Tank::DesenhaTank1(float posiX, float posiY,float ang){
	glPushMatrix();
	glTranslatef(posiX,posiY,0);
	glRotatef(ang,0,0,1);

	glColor3f(0.2f,0.2f,1.0f);
	//corpo
	glBegin(GL_QUADS);
	glVertex2f(0,25);
	glVertex2f(0,0);			
	glVertex2f(12.5,0);
	glVertex2f(12.5,25);
	glEnd();

	glColor3f(0.0f,0.0f,0.8f);
	//cabine
	glBegin(GL_QUADS);
	glVertex2f(2.5,18.75);
	glVertex2f(2.5,11.25);			
	glVertex2f(10,11.25);
	glVertex2f(10,18.75);
	glEnd();

	glColor3f(0.5f,0.5f,1.0f);
	//cano
	glBegin(GL_QUADS);
	glVertex2f(5,30);
	glVertex2f(7.5,30);			
	glVertex2f(7.5,12.5);
	glVertex2f(5,12.5);
	glEnd();
	glColor3f(0.2f,0.2f,0.2f);
	for(float c=0;c<=25;c+=1.25){
		glBegin(GL_QUADS);
		glVertex2f(0,c);
		glVertex2f(0,1.25+c);
		glVertex2f(1.25,c);
		glVertex2f(1.25,1.25+c);
		glEnd();
		glBegin(GL_QUADS);
		glVertex2f(11.25,c);
		glVertex2f(11.25,1.25+c);
		glVertex2f(12.5,c);
		glVertex2f(12.5,1.25+c);
		glEnd();
	}
	glPopMatrix();

}
void Tank::DesenhaTank (float posiX, float posiY,float ang,int tipo){

	if(tipo==1)/*DesenhaTank1(posiX,posiY,ang)*/Tank::desenha();else
		if(tipo==2)DesenhaTank2(posiX,posiY,ang);else
			if(tipo==3)DesenhaTank3(posiX,posiY,ang);else
				if(tipo==4)DesenhaTank4(posiX,posiY,ang);
}
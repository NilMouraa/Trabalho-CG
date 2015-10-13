#include "GameOver.h"
#include "Explosao.h"
#include "Tank.h"
#include <iostream>
//#define	GameOver_H
using namespace std;
GameOver::GameOver() {
	explosao=new Explosao(180,126,0,200,6);
    posiXGame=-260;
    posiYGame=160;
    posiXOver=-260;
    posiYOver=75;
    status='a';
	limiteXGame=52;
	limiteXOver=52;
	velocMove=3;
	DIM_X_TANK=15;
	DIM_Y_TANK=15;
}
void GameOver::DesenhaE(float posiX, float posiY,float ang,int tipoTank){
	glPushMatrix();
	glTranslatef(posiX,posiY,0);
	glRotatef(ang,0,0,1);
	
	for(float incCol=DIM_X_TANK;incCol<=5*DIM_X_TANK;incCol+=DIM_X_TANK){
		//DesenhaTank(0,incCol,-90,tipoTank);
		Tank *t=new Tank(0,incCol,-90,tipoTank);
		t->desenha();
		if(incCol==DIM_X_TANK || incCol==3*DIM_X_TANK || incCol==5*DIM_X_TANK){
				for(float incLin=DIM_Y_TANK;incLin<=2*DIM_Y_TANK;incLin+=DIM_Y_TANK){
					//DesenhaTank(incLin,incCol,-90,tipoTank);
					Tank *t=new Tank(incLin,incCol,-90,tipoTank);
					t->desenha();
				}
		}
	}
	glPopMatrix();
}

void GameOver::DesenhaG(float posiX, float posiY,float ang,int tipoTank){
	glPushMatrix();

	glTranslatef(posiX,posiY,0);
	glRotatef(ang,0,0,1);
	
	for(float incCol=DIM_X_TANK;incCol<=5*DIM_X_TANK;incCol+=DIM_X_TANK){
		//DesenhaTank(0,incCol,-90,tipoTank);
		Tank *t=new Tank(0,incCol,-90,tipoTank);
		t->desenha();
		if(incCol==DIM_X_TANK || incCol==5*DIM_X_TANK){
				for(float incLin=DIM_Y_TANK;incLin<=2*DIM_Y_TANK;incLin+=DIM_Y_TANK){
					//DesenhaTank(incLin,incCol,-90,tipoTank);
					Tank *t=new Tank(incLin,incCol,-90,tipoTank);
					t->desenha();
				}
		}
	}
	//DesenhaTank(2*DIM_Y_TANK,2*DIM_X_TANK,-90,tipoTank);
	Tank *t=new Tank(2*DIM_Y_TANK,2*DIM_X_TANK,-90,tipoTank);
	t->desenha();
	//DesenhaTank(1.5*DIM_Y_TANK,3*DIM_X_TANK,-90,tipoTank);
	Tank *t1=new Tank(1.5*DIM_Y_TANK,3*DIM_X_TANK,-90,tipoTank);
	t1->desenha();
	//DesenhaTank(2.5*DIM_Y_TANK,3*DIM_X_TANK,-90,tipoTank);
	Tank *t2=new Tank(2.5*DIM_Y_TANK,3*DIM_X_TANK,-90,tipoTank);
	t2->desenha();
	
	glPopMatrix();
}

void GameOver::DesenhaA(float posiX, float posiY,float ang,int tipoTank){
	glPushMatrix();
	glTranslatef(posiX,posiY,0);
	glRotatef(ang,0,0,1);
	
	for(float incCol=DIM_X_TANK;incCol<=5*DIM_X_TANK;incCol+=DIM_X_TANK){
		//DesenhaTank(0,incCol,-90,tipoTank);
		Tank *t=new Tank(0,incCol,-90,tipoTank);
		t->desenha();
		if(incCol==5*DIM_X_TANK || incCol==3*DIM_X_TANK){
			Tank *t2=new Tank(DIM_Y_TANK,incCol,-90,tipoTank);
			t2->desenha();
		}
		//DesenhaTank(2*DIM_Y_TANK,incCol,-90,tipoTank);
		Tank *t1=new Tank(2*DIM_Y_TANK,incCol,-90,tipoTank);
		t1->desenha();
	}


	glPopMatrix();
}

void GameOver::DesenhaV(float posiX, float posiY,float ang,int tipoTank){
	glPushMatrix();
	glTranslatef(posiX,posiY,0);
	glRotatef(ang,0,0,1);
	
	Tank *t1=new Tank(0,5*DIM_X_TANK,-90,tipoTank);
	t1->desenha();
	Tank *t2=new Tank(0.5*DIM_Y_TANK,4*DIM_X_TANK,-90,tipoTank);
	t2->desenha();
	Tank *t3=new Tank(DIM_Y_TANK,3*DIM_X_TANK,-90,tipoTank);
	t3->desenha();
	Tank *t4=new Tank(1.5*DIM_Y_TANK,2*DIM_X_TANK,-90,tipoTank);
	t4->desenha();
	Tank *t5=new Tank(2*DIM_Y_TANK,DIM_X_TANK,-90,tipoTank);
	t5->desenha();
	Tank *t6=new Tank(2.5*DIM_Y_TANK,2*DIM_X_TANK,-90,tipoTank);
	t6->desenha();
	Tank *t7=new Tank(3*DIM_Y_TANK,3*DIM_X_TANK,-90,tipoTank);
	t7->desenha();
	Tank *t8=new Tank(3.5*DIM_Y_TANK,4*DIM_X_TANK,-90,tipoTank);
	t8->desenha();
	Tank *t9=new Tank(4*DIM_Y_TANK,5*DIM_X_TANK,-90,tipoTank);
	t9->desenha();


	glPopMatrix();
}
void GameOver::DesenhaO(float posiX, float posiY,float ang,int tipoTank){
	glPushMatrix();
	glTranslatef(posiX,posiY,0);
	glRotatef(ang,0,0,1);
	
	for(float incCol=DIM_X_TANK;incCol<=5*DIM_X_TANK;incCol+=DIM_X_TANK){
		//DesenhaTank(0,incCol,-90,tipoTank);
		Tank *t=new Tank(0,incCol,-90,tipoTank);
		t->desenha();
		if(incCol==DIM_X_TANK || incCol==5*DIM_X_TANK ){
				
			Tank *t2=new Tank(DIM_Y_TANK,incCol,-90,tipoTank);
			t2->desenha();
				
		}
		Tank *t1=new Tank(2*DIM_Y_TANK,incCol,-90,tipoTank);
		t1->desenha();
	}
	glPopMatrix();
}
void GameOver::DesenhaR(float posiX, float posiY,float ang,int tipoTank){
	glPushMatrix();
	glTranslatef(posiX,posiY,0);
	glRotatef(ang,0,0,1);
	
	for(float incCol=DIM_X_TANK;incCol<=5*DIM_X_TANK;incCol+=DIM_X_TANK){
		//DesenhaTank(0,incCol,-90,tipoTank);
		Tank *t=new Tank(0,incCol,-90,tipoTank);
		t->desenha();
		if(incCol==2*DIM_X_TANK || incCol==3*DIM_X_TANK || incCol==5*DIM_X_TANK ){
				
			Tank *t2=new Tank(DIM_Y_TANK,incCol,-90,tipoTank);
			t2->desenha();
				
		}
		if(incCol==DIM_X_TANK || incCol==3*DIM_X_TANK || incCol==4*DIM_X_TANK || incCol==5*DIM_X_TANK )
		{
			Tank *t1=new Tank(2*DIM_Y_TANK,incCol,-90,tipoTank);
			t1->desenha();
		}
	}
	glPopMatrix();
}
void GameOver::DesenhaM(float posiX, float posiY,float ang,int tipoTank){
	glPushMatrix();
	glTranslatef(posiX,posiY,0);
	glRotatef(ang,0,0,1);
	
	for(float incCol=DIM_X_TANK;incCol<=5*DIM_X_TANK;incCol+=DIM_X_TANK){
		//DesenhaTank(0,incCol,-90,tipoTank);
		Tank *t=new Tank(0,incCol,-90,tipoTank);
		t->desenha();
		if(incCol==4*DIM_X_TANK){
			Tank *t2=new Tank(DIM_Y_TANK,incCol+0.5*DIM_X_TANK,-90,tipoTank);
			t2->desenha();
			Tank *t3=new Tank(2*DIM_Y_TANK,incCol-0.5*DIM_X_TANK,-90,tipoTank);
			t3->desenha();
			Tank *t4=new Tank(3*DIM_Y_TANK,incCol+0.5*DIM_X_TANK,-90,tipoTank);
			t4->desenha();
		}
		//DesenhaTank(2*DIM_Y_TANK,incCol,-90,tipoTank);
		Tank *t1=new Tank(4*DIM_Y_TANK,incCol,-90,tipoTank);
		t1->desenha();
	}


	glPopMatrix();
}

void GameOver::desenha(){
	glPushMatrix();
	
	if(explosao->getDiminui()){
		glClear(GL_COLOR_BUFFER_BIT);
	}
	if(explosao->getTerminou()==false){
		explosao->desenha();
		explosao->incrementaTamanho(1);
	}else{
		DesenhaG(posiXGame,posiYGame,0,1);
		DesenhaA(posiXGame+4*DIM_Y_TANK,posiYGame,0,2);
		DesenhaM(posiXGame+8*DIM_Y_TANK,posiYGame,0,3);
		DesenhaE(posiXGame+14*DIM_Y_TANK,posiYGame,0,4);
		DesenhaO(posiXOver,posiYOver,0,5);
		DesenhaV(posiXOver+4*DIM_Y_TANK,posiYOver,0,4);
		DesenhaE(posiXOver+10*DIM_Y_TANK,posiYOver,0,3);
		DesenhaR(posiXOver+14*DIM_Y_TANK,posiYOver,0,2);
		if(posiXGame<=limiteXGame){
			posiXGame+=velocMove;
		}
		if(posiXOver<=limiteXOver){
			posiXOver+=velocMove;
		}
		if(posiXGame>limiteXGame && posiXOver>limiteXOver){
			status='t';
		}
	}
	
	glPopMatrix();
}


char  GameOver::getStatus() { return status; }

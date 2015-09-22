#include "Introducao.h"

Introducao::Introducao(){
	tan = new Tank(0,0,0,1);
	DIM_X_TANK= tan->getDimX();
	DIM_Y_TANK= tan->getDimY();
	incremento=0;
}

void Introducao::DesenhaE(float posiX, float posiY,float ang,int tipoTank){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
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
}
void Introducao::DesenhaL(float posiX, float posiY,float ang,int tipoTank){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(posiX,posiY,0);
	glRotatef(ang,0,0,1);

	for(float incCol=DIM_X_TANK;incCol<=5*DIM_X_TANK;incCol+=DIM_X_TANK){
		//DesenhaTank(0,incCol,-90,tipoTank);
		Tank *t=new Tank(0,incCol,-90,tipoTank);
		t->desenha();
		if(incCol==DIM_X_TANK){
			for(float incLin=DIM_Y_TANK;incLin<=2*DIM_Y_TANK;incLin+=DIM_Y_TANK){
				//DesenhaTank(incLin,incCol,-90,tipoTank);
				Tank *t=new Tank(incLin,incCol,-90,tipoTank);
				t->desenha();
			}
		}
	}
}
void Introducao::DesenhaS(float posiX, float posiY,float ang,int tipoTank){

	glPushMatrix();
	glTranslatef(posiX,posiY,0);
	glRotatef(ang,0,0,1);

	for(float incCol=DIM_X_TANK;incCol<=5*DIM_X_TANK;incCol+=DIM_X_TANK){
		if(incCol!=2*DIM_X_TANK){
			//DesenhaTank(0,incCol,-90,tipoTank);
			Tank *t=new Tank(0,incCol,-90,tipoTank);
			t->desenha();
		}
		if(incCol!=4*DIM_X_TANK){
			//DesenhaTank(2*DIM_Y_TANK,incCol,-90,tipoTank);
			Tank *t=new Tank(2*DIM_Y_TANK,incCol,-90,tipoTank);
			t->desenha();
		}
		if(incCol==DIM_X_TANK || incCol==3*DIM_X_TANK || incCol==5*DIM_X_TANK){
			//DesenhaTank(DIM_Y_TANK,incCol,-90,tipoTank);
			Tank *t=new Tank(DIM_Y_TANK,incCol,-90,tipoTank);
			t->desenha();
		}
	}
	glPopMatrix();
}
void Introducao::DesenhaG(float posiX, float posiY,float ang,int tipoTank){
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
void Introducao::DesenhaN(float posiX, float posiY,float ang,int tipoTank){
	glPushMatrix();
	glTranslatef(posiX,posiY,0);
	glRotatef(ang,0,0,1);

	for(float incCol=DIM_X_TANK;incCol<=5*DIM_X_TANK;incCol+=DIM_X_TANK){
		//DesenhaTank(0,incCol,-90,tipoTank);
		Tank *t=new Tank(0,incCol,-90,tipoTank);
		t->desenha();
		//DesenhaTank(2*DIM_Y_TANK,incCol,-90,tipoTank);
		Tank *t1=new Tank(3*DIM_Y_TANK,incCol,-90,tipoTank);
		t1->desenha();
	}
	Tank *t1=new Tank(1.125*DIM_Y_TANK,4.5*DIM_X_TANK,-90,tipoTank);
	t1->desenha();
	Tank *t2=new Tank(1.375*DIM_Y_TANK,3.5*DIM_X_TANK,-90,tipoTank);
	t2->desenha();
	Tank *t3=new Tank(1.625*DIM_Y_TANK,2.5*DIM_X_TANK,-90,tipoTank);
	t3->desenha();
	Tank *t4=new Tank(1.875*DIM_Y_TANK,1.5*DIM_X_TANK,-90,tipoTank);
	t4->desenha();


	glPopMatrix();
}
void Introducao::DesenhaU(float posiX, float posiY,float ang,int tipoTank){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(posiX,posiY,0);
	glRotatef(ang,0,0,1);

	for(float incCol=DIM_X_TANK;incCol<=5*DIM_X_TANK;incCol+=DIM_X_TANK){
		//DesenhaTank(0,incCol,-90,tipoTank);
		Tank *t=new Tank(0,incCol,-90,tipoTank);
		t->desenha();
		//DesenhaTank(2*DIM_Y_TANK,incCol,-90,tipoTank);
		Tank *t1=new Tank(2*DIM_Y_TANK,incCol,-90,tipoTank);
		t1->desenha();
	}
	//DesenhaTank(DIM_Y_TANK,DIM_X_TANK,-90,tipoTank);
	Tank *t=new Tank(DIM_Y_TANK,DIM_X_TANK,-90,tipoTank);
	t->desenha();
}

void Introducao::Desenha	(){
	DesenhaS(-3*DIM_Y_TANK+incremento,100,0,5);
	DesenhaG(-7*DIM_Y_TANK+incremento,100,0,4);
	DesenhaN(-12*DIM_Y_TANK+incremento,100,0,3);
	DesenhaE(-16*DIM_Y_TANK+incremento,100,0,2);
	DesenhaL(-20*DIM_Y_TANK+incremento,100,0,1);
}
void Introducao::Incrementa	(float inc){
	incremento+=inc;
}
#include "Introducao.h"
#include "Tank.h"
#include "Explosao.h"
#include "TiroEspecial.h"
/*vector<tank> tanks;

Tanks.push_back(tank1); 
iterator it;

vector<Tank> tanks;

it = tanks.begin() */

Introducao::Introducao(){
	fim = false;
    	tan = new Tank(50,50,0,1);
	DIM_X_TANK=tan->getDimX(); 
	DIM_Y_TANK=tan->getDimY();
	incremento=-105;
	int cont=0;
	for(float c=0;c<151;c+=30){
		lasers.push_back(new TiroEspecial(-1,50+c+DIM_X_TANK/2,-90,0.2*DIM_X_TANK));
		for(float l=0;l<151;l+=30){
		    tanques.push_back(new Tank(50+c,50+l,0,6));
			cont++;
		}
	}
}
void Introducao::DesenhaE(float posiX, float posiY,float ang,int tipoTank){
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
void Introducao::DesenhaL(float posiX, float posiY,float ang,int tipoTank){
	glPushMatrix();
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
	glPopMatrix();
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


void Introducao::Desenha(float largura, float altura){
	glPushMatrix();
	if ((-20 * DIM_Y_TANK + incremento < 50)) {
		for (int i = 0; i < tanques.size(); i++) {
			if (tanques[i]->getStatus() != 'i')
				tanques[i]->desenha();
		}
	
		if (incremento > -39) {
			for (int i = 0; i < lasers.size(); i++) {

				if (lasers[i]->getStatus() != 'i')lasers[i]->desenha(350, lasers[i]->getPosiY());
			}
			if (lasers[0]->getStatus() == 'i') {
				for (int i = 0; i < tanques.size(); i++) {
					if (tanques[i]->getStatus() != 'm' && tanques[i]->getStatus() != 'i')tanques[i]->setStatus('m');

				}
			}
		}
		if(tanques[1]->getStatus()=='i' && -20*DIM_Y_TANK+incremento<30){
			DesenhaS(-3*DIM_Y_TANK+incremento, 0.5*altura,0,5);
			DesenhaG(-7*DIM_Y_TANK+incremento, 0.5*altura,0,4);
			DesenhaN(-12*DIM_Y_TANK+incremento, 0.5*altura,0,3);
			DesenhaE(-16*DIM_Y_TANK+incremento, 0.5*altura,0,2);
			DesenhaL(-20*DIM_Y_TANK+incremento, 0.5*altura,0,1);
		}
		
	}
	if (-20 * DIM_Y_TANK + incremento >= 30) {
		DesenhaS(17 * DIM_Y_TANK + 30, 0.5*altura, 0, 5);
		DesenhaG(13 * DIM_Y_TANK + 30, 0.5*altura, 0, 4);
		DesenhaN(8 * DIM_Y_TANK + 30, 0.5*altura, 0, 3);
		DesenhaE(4 * DIM_Y_TANK + 30, 0.5*altura, 0, 2);
		DesenhaL(30, 0.5*altura, 0, 1);
		fim = true;
	}
	glPopMatrix();
	
}
void Introducao::Incrementa(float inc){
	incremento+=inc;
}

float Introducao::getIncremento() { return incremento; }
bool Introducao::getFim() { return fim; }

//Tank Introducao::getIntroducao();

#include "Final.h"
#include <iostream>
//#define	Final_H
using namespace std;
Final::Final() {
    posiXLengs=-315;
    posiYLengs=75;
    status='a';
	limiteXLengs=30;
	velocMove=1;
	DIM_X_TANK=15;
	DIM_Y_TANK=15;
	tj=new Tank(-20,posiYLengs+DIM_X_TANK,-90,6);
	parouNoMeio=false;
	
}
void Final::DesenhaEVet(float posiX, float posiY,float ang,int tipoTank){
	glPushMatrix();
	glTranslatef(posiX,posiY,0);
	glRotatef(ang,0,0,1);
	
	for(float incCol=DIM_X_TANK;incCol<=5*DIM_X_TANK;incCol+=DIM_X_TANK){
		//DesenhaTank(0,incCol,-90,tipoTank);
		//Tank *t=new Tank(0,incCol,-90,tipoTank);
		//t->desenha();
		tanques.push_back(new Tank(posiX,incCol+posiY,-90,tipoTank));
		if(incCol==DIM_X_TANK || incCol==3*DIM_X_TANK || incCol==5*DIM_X_TANK){
				for(float incLin=DIM_Y_TANK;incLin<=2*DIM_Y_TANK;incLin+=DIM_Y_TANK){
					//DesenhaTank(incLin,incCol,-90,tipoTank);
					//Tank *t=new Tank(incLin,incCol,-90,tipoTank);
					//t->desenha();
					tanques.push_back(new Tank(posiX+incLin,incCol+posiY,-90,tipoTank));
				}
		}
	}
	glPopMatrix();
}
void Final::DesenhaGVet(float posiX, float posiY,float ang,int tipoTank){
	glPushMatrix();

	glTranslatef(posiX,posiY,0);
	glRotatef(ang,0,0,1);
	
	for(float incCol=DIM_X_TANK;incCol<=5*DIM_X_TANK;incCol+=DIM_X_TANK){
		//DesenhaTank(0,incCol,-90,tipoTank);
		//Tank *t=new Tank(0,incCol,-90,tipoTank);
		//t->desenha();
		tanques.push_back(new Tank(posiX,incCol+posiY,-90,tipoTank));
		if(incCol==DIM_X_TANK || incCol==5*DIM_X_TANK){
				for(float incLin=DIM_Y_TANK;incLin<=2*DIM_Y_TANK;incLin+=DIM_Y_TANK){
					//DesenhaTank(incLin,incCol,-90,tipoTank);
					//Tank *t=new Tank(incLin,incCol,-90,tipoTank);
					//t->desenha();
					tanques.push_back(new Tank(posiX+incLin,incCol+posiY,-90,tipoTank));
				}
		}
	}
	//DesenhaTank(2*DIM_Y_TANK,2*DIM_X_TANK,-90,tipoTank);
	//Tank *t=new Tank(2*DIM_Y_TANK,2*DIM_X_TANK,-90,tipoTank);
	//t->desenha();
	tanques.push_back(new Tank(posiX+2*DIM_Y_TANK,2*DIM_X_TANK+posiY,-90,tipoTank));
	//DesenhaTank(1.5*DIM_Y_TANK,3*DIM_X_TANK,-90,tipoTank);
	//Tank *t1=new Tank(1.5*DIM_Y_TANK,3*DIM_X_TANK,-90,tipoTank);
	//t1->desenha();
	tanques.push_back(new Tank(posiX+1.5*DIM_Y_TANK,3*DIM_X_TANK+posiY,-90,tipoTank));
	//DesenhaTank(2.5*DIM_Y_TANK,3*DIM_X_TANK,-90,tipoTank);
	//Tank *t2=new Tank(2.5*DIM_Y_TANK,3*DIM_X_TANK,-90,tipoTank);
	//t2->desenha();
	tanques.push_back(new Tank(posiX+2.5*DIM_Y_TANK,3*DIM_X_TANK+posiY,-90,tipoTank));
	
	glPopMatrix();
}
void Final::DesenhaLVet(float posiX, float posiY,float ang,int tipoTank){
	glPushMatrix();
	glTranslatef(posiX,posiY,0);
	glRotatef(ang,0,0,1);
	
	for(float incCol=DIM_X_TANK;incCol<=5*DIM_X_TANK;incCol+=DIM_X_TANK){
		//DesenhaTank(0,incCol,-90,tipoTank);
		//Tank *t=new Tank(0,incCol,-90,tipoTank);
		//t->desenha();
		tanques.push_back(new Tank(posiX,incCol+posiY,-90,tipoTank));

		if(incCol==DIM_X_TANK){
				for(float incLin=DIM_Y_TANK;incLin<=2*DIM_Y_TANK;incLin+=DIM_Y_TANK){
					//DesenhaTank(incLin,incCol,-90,tipoTank);
					//Tank *t=new Tank(incLin,incCol,-90,tipoTank);
						//t->desenha();
					tanques.push_back(new Tank(posiX+incLin,incCol+posiY,-90,tipoTank));
				}
		}
	}
	glPopMatrix();
}
void Final::DesenhaSVet(float posiX, float posiY,float ang,int tipoTank){
	
	glPushMatrix();
	glTranslatef(posiX,posiY,0);
	glRotatef(ang,0,0,1);

	for(float incCol=DIM_X_TANK;incCol<=5*DIM_X_TANK;incCol+=DIM_X_TANK){
		if(incCol!=2*DIM_X_TANK){
			//DesenhaTank(0,incCol,-90,tipoTank);
			//Tank *t=new Tank(0,incCol,-90,tipoTank);
			//t->desenha();
			tanques.push_back(new Tank(posiX,incCol+posiY,-90,tipoTank));
		}
		if(incCol!=4*DIM_X_TANK){
			//DesenhaTank(2*DIM_Y_TANK,incCol,-90,tipoTank);
			//Tank *t=new Tank(2*DIM_Y_TANK,incCol,-90,tipoTank);
			//t->desenha();
			tanques.push_back(new Tank(posiX+2*DIM_Y_TANK,incCol+posiY,-90,tipoTank));
		}
		if(incCol==DIM_X_TANK || incCol==3*DIM_X_TANK || incCol==5*DIM_X_TANK){
			//DesenhaTank(DIM_Y_TANK,incCol,-90,tipoTank);
			//Tank *t=new Tank(DIM_Y_TANK,incCol,-90,tipoTank);
			//t->desenha();
			tanques.push_back(new Tank(posiX+DIM_Y_TANK,incCol+posiY,-90,tipoTank));
		}
	}
	glPopMatrix();
}
void Final::DesenhaNVet(float posiX, float posiY,float ang,int tipoTank){
	glPushMatrix();
	glTranslatef(posiX,posiY,0);
	glRotatef(ang,0,0,1);
	
	for(float incCol=DIM_X_TANK;incCol<=5*DIM_X_TANK;incCol+=DIM_X_TANK){
		//DesenhaTank(0,incCol,-90,tipoTank);
		//Tank *t=new Tank(0,incCol,-90,tipoTank);
		//t->desenha();
			tanques.push_back(new Tank(posiX,incCol+posiY,-90,tipoTank));
		//DesenhaTank(2*DIM_Y_TANK,incCol,-90,tipoTank);
		//Tank *t1=new Tank(3*DIM_Y_TANK,incCol,-90,tipoTank);
		//t1->desenha();
			tanques.push_back(new Tank(posiX+3*DIM_Y_TANK,incCol+posiY,-90,tipoTank));
	}
	//Tank *t1=new Tank(1.125*DIM_Y_TANK,4.5*DIM_X_TANK,-90,tipoTank);
	//t1->desenha();
	tanques.push_back(new Tank(posiX+1.125*DIM_Y_TANK,4.5*DIM_X_TANK+posiY,-90,tipoTank));
	//Tank *t2=new Tank(1.375*DIM_Y_TANK,3.5*DIM_X_TANK,-90,tipoTank);
	//t2->desenha();
	tanques.push_back(new Tank(posiX+1.375*DIM_Y_TANK,3.5*DIM_X_TANK+posiY,-90,tipoTank));
	//Tank *t3=new Tank(1.625*DIM_Y_TANK,2.5*DIM_X_TANK,-90,tipoTank);
	//t3->desenha();
	tanques.push_back(new Tank(posiX+1.625*DIM_Y_TANK,2.5*DIM_X_TANK+posiY,-90,tipoTank));
	//Tank *t4=new Tank(1.875*DIM_Y_TANK,1.5*DIM_X_TANK,-90,tipoTank);
	//t4->desenha();
	tanques.push_back(new Tank(posiX+1.875*DIM_Y_TANK,1.5*DIM_X_TANK+posiY,-90,tipoTank));


	glPopMatrix();
}
void Final::DesenhaE(float posiX, float posiY,float ang,int tipoTank){
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
void Final::DesenhaG(float posiX, float posiY,float ang,int tipoTank){
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
void Final::DesenhaL(float posiX, float posiY,float ang,int tipoTank){
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
void Final::DesenhaS(float posiX, float posiY,float ang,int tipoTank){
	
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
void Final::DesenhaN(float posiX, float posiY,float ang,int tipoTank){
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
void Final::desenha(){
	glPushMatrix();
	
		if(posiXLengs<=limiteXLengs){
			DesenhaL(posiXLengs,posiYLengs,0,1);
			DesenhaE(posiXLengs+4*DIM_Y_TANK,posiYLengs,0,2);
			DesenhaN(posiXLengs+8*DIM_Y_TANK,posiYLengs,0,3);
			DesenhaG(posiXLengs+13*DIM_Y_TANK,posiYLengs,0,4);
			DesenhaS(posiXLengs+17*DIM_Y_TANK,posiYLengs,0,5);
		
			posiXLengs+=velocMove;
		}else{
			if(!parouNoMeio){
				DesenhaLVet(posiXLengs,posiYLengs,0,1);
				DesenhaEVet(posiXLengs+4*DIM_Y_TANK,posiYLengs,0,2);
				DesenhaNVet(posiXLengs+8*DIM_Y_TANK,posiYLengs,0,3);
				DesenhaGVet(posiXLengs+13*DIM_Y_TANK,posiYLengs,0,4);
				DesenhaSVet(posiXLengs+17*DIM_Y_TANK,posiYLengs,0,5);
				parouNoMeio=true;
			}

			tj->desenha();
			
			for (int i = 0; i < tanques.size(); i++) {
				if (tanques[i]->getStatus() != 'i')tanques[i]->desenha();
			}

			if(tj->getPosiX()<5 && tj->getPosiY()==posiYLengs+DIM_X_TANK ){
				tj->viraDireita(0.25,true);
			}else{
				if(tj->getAngulo()==-90){
					lasers.push_back(tj->atiraEspecial());
					for (int i = 0; i < tanques.size(); i++) {
						if (tanques[i]->getStatus() != 'm' && tanques[i]->getStatus() != 'i' && (tanques[i]->getPosiY()==tj->getPosiY() || tanques[i]->getPosiY()==tj->getPosiY()-0.5*DIM_X_TANK) )tanques[i]->setStatus('m');

					}
					
					tj->viraCima(0.5,true);
					tj->viraCima(0.25,true);
				}else if(tj->getPosiY()!=posiYLengs+DIM_X_TANK && tj->getPosiY()!=posiYLengs+2*DIM_X_TANK && tj->getPosiY()!=posiYLengs+3*DIM_X_TANK && tj->getPosiY()!=posiYLengs+4*DIM_X_TANK && tj->getPosiY()!=posiYLengs+5*DIM_X_TANK ){
					Sleep(20);
					tj->viraCima(0.25,true);
				}else{
					tj->viraDireita(0.25,true);
				}
			
			}
			for (int i = 0; i < lasers.size(); i++) {
				if (lasers[i]->getStatus() != 'i')lasers[i]->desenha(355, lasers[i]->getPosiY());
			}
			if(tj->getPosiY()>posiYLengs+5*DIM_X_TANK){
				status='t';
			}
		}
	
	
	glPopMatrix();
}


char  Final::getStatus() { return status; }

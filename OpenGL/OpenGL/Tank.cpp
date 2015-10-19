#include "Tank.h"
#include <iostream>
#include "TiroEspecial.h"

//#define	TANK_H
using namespace std;
Tank::Tank(float x, float y, float ang, int tip) {
	posiX = x;
	posiY = y;
	angulo = ang;
	dimX = 15;
	dimY = 15;
	status = 'a';
	qtdTiroEspec = 100;
	qtdPontosTotal = 0;
	qtdPontuacao = 0;
	vidasGanhas=0;
	tipo = tip;
	qtdVidas = 5;
	FILE *arq = NULL;
	if (tip == 1) {
		vida = 20;
		vidaCheia=vida;
		velocidade = 2;
		tempoPraAtirar=100;
			arq = fopen("tank1.txt", "r");
	}
	else if (tip == 2) {
		vida = 20;
		vidaCheia=vida;
		velocidade = 2;
		tempoPraAtirar=100;
			arq = fopen("tank2.txt", "r");
	}
	else if (tip == 3) {
		vida = 20;
		vidaCheia=vida;
		velocidade = 3;
		tempoPraAtirar=100;
			arq = fopen("tank3.txt", "r");
	}
	else if (tip == 4) {
		vida = 20;
		vidaCheia=vida;
		velocidade = 2;
		tempoPraAtirar=100;
			arq = fopen("tank4.txt", "r");
	}
	else if (tip == 5) {
		vida = 20;
		vidaCheia=vida;
		velocidade = 2;
		tempoPraAtirar=100;
			arq = fopen("tank5.txt", "r");
	}

	else if (tip == 6) {
		vida = 100;
		vidaCheia=vida;
		velocidade = 2;
		tempoPraAtirar=10;
		arq = fopen("tankPlayer.txt", "r");
		qtdVidas=5;
	}
	else if (tip == 7) {
		vida = 20;
		vidaCheia=vida;
		velocidade = 2;
		tempoPraAtirar=100;
			arq = fopen("tankQuad.txt", "r");
			f1=new Fogo(0.0625*dimX, 0.9375*dimY,45,0,0.2,4*(dimY/15),2*(dimY/15),4*(dimY/15),2*(dimY/15),0.125*dimX,3*(dimY/15));
			f2=new Fogo(0.0625*dimX, 0.0625*dimY,135,0,0.2,4*(dimY/15),2*(dimY/15),4*(dimY/15),2*(dimY/15),0.125*dimX,3*(dimY/15));
			f3=new Fogo(0.9375*dimX, 0.9375*dimY,-45,0,0.2,4*(dimY/15),2*(dimY/15),4*(dimY/15),2*(dimY/15),0.125*dimX,3*(dimY/15));
			f4=new Fogo(0.9375*dimX, 0.0625*dimY,225,0,0.2,4*(dimY/15),2*(dimY/15),4*(dimY/15),2*(dimY/15),0.125*dimX,3*(dimY/15));
	}
	else if (tip == 8) {
		vida = 20;
		vidaCheia=vida;
		velocidade = 2;
		tempoPraAtirar=100;
			arq = fopen("tankBruto2.txt", "r");
			f1=new Fogo(0.7425*dimX, dimY,0,0,0.2,4*(dimY/15),2*(dimY/15),4*(dimY/15),2*(dimY/15),0.1*dimX,3*(dimY/15));
			f2=new Fogo(0.2475*dimX,dimY,0,0,0.2,4*(dimY/15),2*(dimY/15),4*(dimY/15),2*(dimY/15),0.1*dimX,3*(dimY/15));
			f3=new Fogo(0.2475*dimX, 0,-180,0,0.2,4*(dimY/15),2*(dimY/15),4*(dimY/15),2*(dimY/15),0.1*dimX,3*(dimY/15));
			f4=new Fogo(0.7425*dimX, 0,-180,0,0.2,4*(dimY/15),2*(dimY/15),4*(dimY/15),2*(dimY/15),0.1*dimX,3*(dimY/15));
			f5=new Fogo(0, 0.495*dimY,90,0,0.2,4*(dimY/15),2*(dimY/15),4*(dimY/15),2,0.1*dimX,3*(dimY/15));
			f6=new Fogo(dimX, 0.495*dimY,-90,0,0.2,4*(dimY/15),2*(dimY/15),4*(dimY/15),2*(dimY/15),0.1*dimX,3*(dimY/15));

	}
		
		float cooX, cooY, corR, corG, corB, corRAnt, corGAnt, corBAnt;
		char tipoPol;
		if (arq == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
		else {
			while ((fscanf(arq, "%f %f %f %c %f %f\n", &corR, &corG, &corB, &tipoPol, &cooX, &cooY)) != EOF)
			{
				vetCorR.push_back(corR);
				vetCorG.push_back(corG);
				vetCorB.push_back(corB);
				idObj.push_back(tipoPol);
				vetPontosX.push_back(cooX);
				vetPontosY.push_back(cooY);
				qtdPontosTotal++;
			}
		}
		fclose(arq);
}
//Tank::Tank() {}


void  Tank::desenha() {
	tempoPraAtirar--;
	
	if ((status != 'm' && status != 'i') || (explosao->getDiminui() == false)) {

		glPushMatrix();
		glTranslatef(posiX, posiY, 0);
		glRotatef(angulo, 0, 0, 1);

		if(tipo==7){
			f1->desenha();
			f2->desenha();
			f3->desenha();
			f4->desenha();
		}else if(tipo==8){
			f1->desenha();
			f2->desenha();
			f3->desenha();
			f4->desenha();
			f5->desenha();
			f6->desenha();
		}



		float pontosX[20];
		float pontosY[20];
		int qtdPontos = 0;
		float cooX, cooY, corR, corG, corB, corRAnt, corGAnt, corBAnt;
		float yMinEst = -1;
		float yMaxEst = -1;
		char tipoPol;
		
		
		
			char tpAnt = 'z';
			for(int cont=0;cont<qtdPontosTotal;cont++)
			{
				corR=vetCorR[cont];
				corG=vetCorG[cont];
				corB=vetCorB[cont];
				tipoPol=idObj[cont];
				cooX=vetPontosX[cont];
				cooY=vetPontosY[cont];
				
				if (tipoPol == tpAnt || tpAnt == 'z') {
					if (cooX == 0) {
						if (yMinEst == -1) {
							yMinEst = cooY;
						}
						else {
							yMaxEst = cooY;
						}
					}
					pontosX[qtdPontos] = cooX;
					pontosY[qtdPontos] = cooY;
					qtdPontos++;
					tpAnt = tipoPol;
					corRAnt = corR;
					corGAnt = corG;
					corBAnt = corB;

				}
				else {
					glColor3f(corRAnt, corGAnt, corBAnt);
					glBegin(GL_POLYGON);
					for (int i = 0; i < qtdPontos; i++) {
						glVertex2f(pontosX[i] * dimX, pontosY[i] * dimY);
					}
					glEnd();
					glColor3f(1, 1, 1);
					glBegin(GL_LINE_LOOP);
					for (int i = 0; i < qtdPontos; i++) {
						glVertex2f(pontosX[i] * dimX, pontosY[i] * dimY);
					}
					glEnd();
					tpAnt = tipoPol;
					pontosX[0] = cooX;
					pontosY[0] = cooY;
					qtdPontos = 1;
					corRAnt = corR;
					corGAnt = corG;
					corBAnt = corB;
				}
			}
			glColor3f(corRAnt, corGAnt, corBAnt);
			glBegin(GL_POLYGON);
			for (int i = 0; i < qtdPontos; i++) {
				glVertex2f(pontosX[i] * dimX, pontosY[i] * dimY);
			}
			glEnd();
			glColor3f(1, 1, 1);
			glBegin(GL_LINE_LOOP);
			for (int i = 0; i < qtdPontos; i++) {
				glVertex2f(pontosX[i] * dimX, pontosY[i] * dimY);
			}
			glEnd();
			//ESTEIRA ______________________________________________________________
			if(tipo!=7 && tipo!=8){
			for (float i = yMinEst*dimY/*-0.1*dimY*/; i < yMaxEst*dimY; i += 0.1*dimY) {
				glColor3f(0.4, 0.4, 0.4);
				glBegin(GL_QUADS);
				glVertex2f(0, i);
				glVertex2f(0, i + 0.1*dimY);
				glVertex2f(0.1*dimX, i);
				glVertex2f(0.1*dimX, i + 0.1*dimY);
				//glVertex2f(0.05*dimX,i+0.05*dimY);
				glEnd();
				glBegin(GL_QUADS);
				glVertex2f(0.9*dimX, i);
				glVertex2f(0.9*dimX, i + 0.1*dimY);
				glVertex2f(dimX, i);
				glVertex2f(dimX, i + 0.1*dimY);
				//glVertex2f(0.05*dimX,i+0.05*dimY);
				glEnd();
				glColor3f(1, 1, 1);
				glBegin(GL_LINE_LOOP);
				glVertex2f(0, i);
				glVertex2f(0, i + 0.1*dimY);
				glVertex2f(0.1*dimX, i + 0.1*dimY);
				glVertex2f(0.1*dimX, i);
				glVertex2f(0.05*dimX, i + 0.05*dimY);
				glEnd();
				glBegin(GL_LINE_LOOP);
				glVertex2f(0.9*dimX, i);
				glVertex2f(0.9*dimX, i + 0.1*dimY);
				glVertex2f(dimX, i + 0.1*dimY);
				glVertex2f(dimX, i);
				glVertex2f(0.95*dimX, i + 0.05*dimY);
				glEnd();
			}
			glBegin(GL_LINES);
			glVertex2f(0, yMinEst*dimY/*-0.1*dimY*/);
			glVertex2f(0.1*dimX, yMinEst*dimY/*-0.1*dimY*/);
			glEnd();
			glBegin(GL_LINES);
			glVertex2f(0.9*dimX, yMinEst*dimY/*-0.1*dimY*/);
			glVertex2f(dimX, yMinEst*dimY/*-0.1*dimY*/);
			glEnd();
			}
			//_________________________________________________________________
			glColor3f(1,0,0);
			glBegin(GL_POLYGON);
				glVertex2f(1,-1);
				glVertex2f(1,-2);
				glVertex2f(dimX-1,-2);
				glVertex2f(dimX-1,-1);
			glEnd();
			glColor3f(0,1,0);
			glBegin(GL_POLYGON);
				glVertex2f(1,-1);
				glVertex2f(1,-2);
				glVertex2f((dimX-1)*(vida/vidaCheia),-2);
				glVertex2f((dimX-1)*(vida/vidaCheia),-1);
			glEnd();
			glColor3f(1,1,1);
		glPopMatrix();
		if (status == 'm') {
			explosao->desenha();
			explosao->incrementaTamanho(1);
		}
	}
	else {
		explosao->desenha();
		explosao->incrementaTamanho(1);
		if (explosao->getTerminou()) {
			status = 'i';
		}
	}

	
}
void  Tank::move(float incremento) {
	if (angulo == 0) {
		/*cout<<"\tANDANDO CIMA";*/
		posiY += (velocidade*incremento);
	}
	else if (angulo == -90) {
		/*cout<<"\tANDANDO DIR";*/
		posiX += (velocidade*incremento);
	}
	else if (angulo == 90) {
		//cout<<"\tANDANDO TRAS";
		posiX -= (velocidade*incremento);
	}
	else if (angulo == 180) {
		//cout<<"\tANDANDO ESQ";
		posiY -= (velocidade*incremento);
	}

}
void  Tank::viraDireita(float incremento, bool podeAndar) {
	//if (podeAndar) {
		if (angulo == 0) {
			posiY += dimX;
		}
		else
			if (angulo == 180) {
				posiX -= dimY;
			}
			else if (angulo == 90) {
				posiX -= dimY;
				posiY += dimX;
			}
			else if (angulo == -90 && podeAndar) {
				move(incremento);
			}
			angulo = -90;
	//}
}
void  Tank::viraEsquerda(float incremento, bool podeAndar) {
	//cout << "ANGULO: " << this->getAngulo();
	//if (podeAndar) {
		if (angulo == 0) {
			posiX += dimY;
		}
		else if (angulo == 180) {
			posiY -= dimX;
		}
		else if (angulo == -90) {
			posiX += dimY;
			posiY -= dimX;
		}
		else if (angulo == 90 && podeAndar) {
			move(incremento);
		}
		angulo = 90;
//	}
}
void  Tank::viraCima(float incremento, bool podeAndar) {
	//cout << "ANGULO: " << this->getAngulo();
	//if (podeAndar) {
		if (angulo == 90) {
			posiX -= dimY;
		}
		else if (angulo == -90) {
			posiY -= dimX;
		}
		else if (angulo == 180) {
			/*posiX+=dimX;
			posiY+=dimY;*/
			posiX -= dimX;
			posiY -= dimY;
		}
		else if (angulo == 0 && podeAndar) {
			move(incremento);
		}
		angulo = 0;
	//}
}
void  Tank::viraBaixo(float incremento, bool podeAndar) {
	//cout << "ANGULO: " << this->getAngulo();
	//if (podeAndar) {
		if (angulo == 90) {
			posiY += dimX;
		}
		else if (angulo == -90) {
			posiX += dimY;
		}
		else if (angulo == 0) {
			/*posiX-=dimX;
			posiY-=dimY;*/
			posiX += dimX;
			posiY += dimY;
		}
		else if (angulo == 180 && podeAndar) {
			move(incremento);
		}
		angulo = 180;
	//}
}

void  Tank::recebeDano(float dano) {
	vida -= dano;
	if (vida <= 0) {
		status = 'm';
		qtdVidas--;
		if (angulo == 0) {
			explosao = new Explosao(posiX + 0.5*dimX, posiY + 0.5*dimY, 0, 3, 3);
		}
		else if (angulo == 90) {
			explosao = new Explosao(posiX - 0.5*dimY, posiY + 0.5*dimX, 0, 3, 3);
		}
		else if (angulo == -90) {
			explosao = new Explosao(posiX + 0.5*dimY, posiY - 0.5*dimX, 0, 3, 3);
		}
		else if (angulo == 180) {
			explosao = new Explosao(posiX - 0.5*dimX, posiY - 0.5*dimY, 0, 3, 3);
		}
	}

}

void Tank::recebePontos(float p){
	qtdPontuacao+=p;
	if(qtdPontuacao>=((vidasGanhas+1)*10000)){
		qtdVidas++;	
		vidasGanhas++;
	}

}

void  Tank::aumentaVida(float incremento) {
	vida += incremento;
}

void  Tank::setQtdTiroEspec(int qtd) {
	qtdTiroEspec = qtd;
}

void  Tank::setDimX(float tamanho) { dimX = tamanho; }

void  Tank::setDimY(float tamanho) { dimY = tamanho; }
void Tank::setPosiX(float x){
	posiX=x;
}
void Tank::setPosiY(float y){
	posiY=y;
}
void Tank::reiniciaVida(){
	vida=vidaCheia;
}

void  Tank::setStatus(char stat) {
	status = stat;
	if (stat == 'm') {
		qtdVidas--;
		if (this->angulo == 0) {
			explosao = new Explosao(posiX + 0.5*dimX, posiY + 0.5*dimY, 0, dimY/3, 4);
		}
		else if (this->angulo == 90) {
			explosao = new Explosao(posiX - 0.5*dimY, posiY + 0.5*dimX, 0, dimY/3, 4);
		}
		else if (this->angulo == -90) {
			explosao = new Explosao(posiX + 0.5*dimY, posiY - 0.5*dimX, 0, dimY/3, 4);
		}
		else if (this->angulo == 180) {
			explosao = new Explosao(posiX - 0.5*dimX, posiY - 0.5*dimY, 0, dimY/3,4);
		}
	}
}
float  Tank::getPosiCentroX() {
	if (this->angulo == 0) {
		return posiX + 0.5*dimX;
	}
	else if (this->angulo == 90) {
		return posiX - 0.5*dimY;
	}
	else if (this->angulo == -90) {
		return posiX + 0.5*dimY;
	}
	else if (this->angulo == 180) {
		return posiX - 0.5*dimX;
	}

}
float  Tank::getPosiCentroY() {
	if (this->angulo == 0) {
		return posiY + 0.5*dimY;
	}
	else if (this->angulo == 90) {
		return posiY + 0.5*dimX;
	}
	else if (this->angulo == -90) {
		return posiY - 0.5*dimX;
	}
	else if (this->angulo == 180) {
		return posiY - 0.5*dimY;
	}
}
float  Tank::getPosiOrigemX() {
	if (this->angulo == 0) {
		return posiX;
	}
	else if (this->angulo == 90) {
		return posiX -dimY;
	}
	else if (this->angulo == -90) {
		return posiX;
	}
	else if (this->angulo == 180) {
		return posiX -dimX;
	}

}
float  Tank::getPosiOrigemY() {
	if (this->angulo == 0) {
		return posiY;
	}
	else if (this->angulo == 90) {
		return posiY;
	}
	else if (this->angulo == -90) {
		return posiY -dimX;
	}
	else if (this->angulo == 180) {
		return posiY -dimY;
	}
}

int Tank::getTempoPraAtirar(){return tempoPraAtirar;}

float  Tank::getPosiX() { return posiX; }
float  Tank::getPosiY() { return posiY; }
float  Tank::getAngulo() { return angulo; }
float  Tank::getDimX() { return dimX; }
float  Tank::getDimY() { return dimY; }
char  Tank::getStatus() { return status; }
int  Tank::getTipo() { return tipo; }
float  Tank::getVida() { return vida; }
int  Tank::getQtdVida() { return qtdVidas; }
float  Tank::getQtdPontuacao() { return qtdPontuacao; }


TiroEspecial* Tank::atiraEspecial() {
	//if (qtdTiroEspec > 0) {
		TiroEspecial *te = NULL;
		if (angulo == 90) {
			te = new TiroEspecial(posiX - 1.15*dimY, posiY + 0.5*dimX, 90,dimX*0.2);
		}
		else if (angulo == -90) {
			te = new TiroEspecial(posiX + 1.15*dimY, posiY - 0.5*dimX, -90, dimX*0.2);
		}
		else if (angulo == 0) {
			te = new TiroEspecial(posiX + 0.5*dimX, posiY + 1.15*dimY, 0, dimX*0.2);
		}
		else if (angulo == 180) {
			te = new TiroEspecial(posiX - 0.5*dimX, posiY - 1.15*dimY, 180, dimX*0.2);
		}
		//qtdTiroEspec--;
		//te->desenha(xfinal, yfinal);
		
	//}
	return te;
}

TiroExp* Tank::atira(char tipo) {
	//if (qtdTiroEspec > 0) {
	TiroExp *te = NULL;

	if(tempoPraAtirar<0){
		if (tipo == 1) {
			tempoPraAtirar=100;
		}
		else if (tipo == 2) {
			tempoPraAtirar=100;
		}
		else if (tipo == 3) {
			tempoPraAtirar=100;
		}
		else if (tipo == 4) {
			tempoPraAtirar=100;
		}
		else if (tipo == 5) {
			tempoPraAtirar=100;
		}	
	}

	if (angulo == 90) {
		te = new TiroExp(posiX - 1.15*dimY, posiY + 0.5*dimX, 'e', dimX*0.3, dimX*0.3,tipo);
	}
	else if (angulo == -90) {
		te = new TiroExp(posiX + 1.15*dimY, posiY - 0.5*dimX, 'd', dimX*0.3, dimX*0.3, tipo);
	}
	else if (angulo == 0) {
		te = new TiroExp(posiX + 0.5*dimX, posiY + 1.15*dimY, 'c', dimX*0.3, dimX*0.3, tipo);
	}
	else if (angulo == 180) {
		te = new TiroExp(posiX - 0.5*dimX, posiY - 1.15*dimY, 'b', dimX*0.3, dimX*0.3, tipo);
	}
	//qtdTiroEspec--;
	//te->desenha(xfinal, yfinal);

	//}
	return te;
}

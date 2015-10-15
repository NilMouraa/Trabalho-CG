#include "Tank.h"
#include <iostream>
#include "TiroEspecial.h"

//#define	TANK_H
using namespace std;
Tank::Tank(float x, float y, float ang, int tip) {
	posiX = x;
	posiY = y;
	angulo = ang;
	dimX = 100;
	dimY = 100;
	status = 'a';
	qtdTiroEspec = 100;
	tipo = tip;
	FILE *arq = NULL;
	if (tip == 1) {
		vida = 250;
		velocidade = 2;
		tempoPraAtirar=100;
			arq = fopen("tank1.txt", "r");
	}
	else if (tip == 2) {
		vida = 250;
		velocidade = 2;
		tempoPraAtirar=100;
			arq = fopen("tank2.txt", "r");
	}
	else if (tip == 3) {
		vida = 250;
		velocidade = 3;
		tempoPraAtirar=100;
			arq = fopen("tank3.txt", "r");
	}
	else if (tip == 4) {
		vida = 250;
		velocidade = 2;
		tempoPraAtirar=100;
			arq = fopen("tank4.txt", "r");
	}
	else if (tip == 5) {
		vida = 250;
		velocidade = 2;
		tempoPraAtirar=100;
			arq = fopen("tank5.txt", "r");
	}

	else if (tip == 6) {
		vida = 250;
		velocidade = 2;
		tempoPraAtirar=100;
			arq = fopen("tankPlayer.txt", "r");
	}
	else if (tip == 7) {
		vida = 250;
		velocidade = 2;
		tempoPraAtirar = 100;
		arq = fopen("tankB.txt", "r");
	}
		qtdPontosTotal = 0;
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
				vetPontosX.push_back((cooX));
				vetPontosY.push_back((cooY));
				qtdPontosTotal++;
			}
		}
		fclose(arq);
}
Tank::Tank() {}

//void Tank::Inicializa(float x, float y, float ang, int tip) {
//	posiX = x;
//	posiY = y;
//	angulo = ang;
//	dimX = 15;
//	dimY = 15;
//	status = 'a';
//	qtdTiroEspec = 100;
//	tipo = tip;
//	FILE *arq = NULL;
//	if (tip == 1) {
//		vida = 250;
//		velocidade = 2;
//		tempoPraAtirar=100;
//			arq = fopen("tank1.txt", "r");
//	}
//	else if (tip == 2) {
//		vida = 250;
//		velocidade = 2;
//		tempoPraAtirar=100;
//			arq = fopen("tank2.txt", "r");
//	}
//	else if (tip == 3) {
//		vida = 250;
//		velocidade = 3;
//		tempoPraAtirar=100;
//			arq = fopen("tank3.txt", "r");
//	}
//	else if (tip == 4) {
//		vida = 250;
//		velocidade = 2;
//		tempoPraAtirar=100;
//			arq = fopen("tank4.txt", "r");
//	}
//	else if (tip == 5) {
//		vida = 250;
//		velocidade = 2;
//		tempoPraAtirar=100;
//			arq = fopen("tank5.txt", "r");
//	}
//
//	else if (tip == 6) {
//		vida = 250;
//		velocidade = 2;
//			arq = fopen("tankPlayer.txt", "r");
//	}
//	else if (tip == 7) {
//		
//		vida = 250;
//		velocidade = 2;
//		arq = fopen("tankB.txt", "r");
//	}
//		qtdPontosTotal = 0;
//		float cooX, cooY, corR, corG, corB, corRAnt, corGAnt, corBAnt;
//		float yMinEst = -1;
//		float yMaxEst = -1;
//		char tipoPol;
//		if (arq == NULL)
//			printf("Erro, nao foi possivel abrir o arquivo\n");
//		else {
//			while ((fscanf(arq, "%f %f %f %c %f %f\n", &corR, &corG, &corB, &tipoPol, &cooX, &cooY)) != EOF)
//			{
//				vetCorR.push_back(corR);
//				vetCorG.push_back(corG);
//				vetCorB.push_back(corB);
//				idObj.push_back(tipoPol);
//				vetPontosX.push_back(cooX);
//				vetPontosY.push_back(cooY);
//				qtdPontosTotal++;
//			}
//		}
//		fclose(arq);
//	
//}

void  Tank::desenha() {
	tempoPraAtirar--;
	
	if ((status != 'm' && status != 'i') || (explosao->getDiminui() == false)) {

		glPushMatrix();
		glTranslatef(posiX, posiY, 0);
		glRotatef(angulo, 0, 0, 1);

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
			//_________________________________________________________________

		
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
	if (podeAndar) {
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
	}
}
void  Tank::viraEsquerda(float incremento, bool podeAndar) {
	//cout << "ANGULO: " << this->getAngulo();
	if (podeAndar) {
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
	}
}
void  Tank::viraCima(float incremento, bool podeAndar) {
	//cout << "ANGULO: " << this->getAngulo();
	if (podeAndar) {
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
	}
}
void  Tank::viraBaixo(float incremento, bool podeAndar) {
	//cout << "ANGULO: " << this->getAngulo();
	if (podeAndar) {
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
	}
}

void  Tank::recebeDano(float dano) {
	vida -= dano;
	if (vida <= 0) {
		status = 'm';
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

void  Tank::aumentaVida(float incremento) {
	vida += incremento;
}

void  Tank::setQtdTiroEspec(int qtd) {
	qtdTiroEspec = qtd;
}

void  Tank::setDimX(float tamanho) { dimX = tamanho; }

void  Tank::setDimY(float tamanho) { dimY = tamanho; }

void  Tank::setStatus(char stat) {
	status = stat;
	if (stat == 'm') {
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
int  Tank::getVida() { return vida; }

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

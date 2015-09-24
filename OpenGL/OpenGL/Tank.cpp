#include "Tank.h"
#include <iostream>
//#define	TANK_H
using namespace std;
Tank::Tank(float x, float y, float ang, int tip) {
	posiX = x;
	posiY = y;
	angulo = ang;
	dimX = 15;
	dimY = 15;
	status = 'a';
	qtdTiroEspec = 0;
	tipo = tip;
	if (tip == 1) {
		vida = 250;
		velocidade = 1;
	} 
	else if (tip == 2) {
		vida = 250;
		velocidade = 2;
	}
	else if (tip == 3) {
		vida = 250;
		velocidade = 3;
	}
	else if (tip == 4) {
		vida = 250;
		velocidade = 2;
	}
	else if (tip == 5) {
		vida = 250;
		velocidade = 1;
	}
}
Tank::Tank() {}

void Tank::Inicializa(float x, float y, float ang, int tip) {
	posiX = x;
	posiY = y;
	angulo = ang;
	dimX = 15;
	dimY = 15;
	status = 'a';
	qtdTiroEspec = 0;
	tipo = tip;
	if (tip == 1) {
		vida = 250;
		velocidade = 2;
	}
	else if (tip == 2) {
		vida = 250;
		velocidade = 2;
	}
	else if (tip == 3) {
		vida = 250;
		velocidade = 3;
	}
	else if (tip == 4) {
		vida = 250;
		velocidade = 2;
	}
	else if (tip == 5) {
		vida = 250;
		velocidade = 2;
	}
}

void Tank::desenha() {
	if ((status != 'm' && status != 'i') || (explosao->getDiminui() == false)) {
		
		glPushMatrix();
		glTranslatef(posiX, posiY, 0);
		glRotatef(angulo, 0, 0, 1);

		float pontosX[20];
		float pontosY[20];
		int qtdPontos = 0;
		//char url[]="tank1.txt";
		FILE *arq;
		float cooX, cooY, corR, corG, corB, corRAnt, corGAnt, corBAnt;
		float yMinEst = -1;
		float yMaxEst = -1;
		char tipoPol;
		if (tipo == 1) {
			arq = fopen("tank1.txt", "r");
		}
		else if (tipo == 2) {
			arq = fopen("tank2.txt", "r");
		}
		else if (tipo == 3) {
			arq = fopen("tank3.txt", "r");
		}
		else if (tipo == 4) {
			arq = fopen("tank4.txt", "r");
		}
		else if (tipo == 5) {
			arq = fopen("tank5.txt", "r");
		}
		else if (tipo == 6) {
			arq = fopen("tankPlayer.txt", "r");
		}
		if (arq == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
		else {
			char tpAnt = 'z';
			while ((fscanf(arq, "%f %f %f %c %f %f\n", &corR, &corG, &corB, &tipoPol, &cooX, &cooY)) != EOF)
			{
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

		}
		fclose(arq);
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
void  Tank::viraDireita(float incremento) {

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
		else if (angulo == -90) {
			move(incremento);
		}
		angulo = -90;
}
void  Tank::viraEsquerda(float incremento) {
	//cout << "ANGULO: " << this->getAngulo();
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
	else if (angulo == 90) {
		move(incremento);
	}
	angulo = 90;
}
void  Tank::viraCima(float incremento) {
	//cout << "ANGULO: " << this->getAngulo();
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
	else if (angulo == 0) {
		move(incremento);
	}
	angulo = 0;
}
void  Tank::viraBaixo(float incremento) {
	//cout << "ANGULO: " << this->getAngulo();
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
	else if (angulo == 180) {
		move(incremento);
	}
	angulo = 180;
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

	if (this->angulo == 0) {
		explosao = new Explosao(posiX + 0.5*dimX, posiY + 0.5*dimY, 0, 50, 3);
	}
	else if (this->angulo == 90) {
		explosao = new Explosao(posiX - 0.5*dimY, posiY + 0.5*dimX, 0, dimY, 1.2);
	}
	else if (this->angulo == -90) {
		explosao = new Explosao(posiX + 0.5*dimY, posiY - 0.5*dimX, 0, dimY, 1.2);
	}
	else if (this->angulo == 180) {
		explosao = new Explosao(posiX - 0.5*dimX, posiY - 0.5*dimY, 0, dimY, 1.2);
	}
}

float  Tank::getPosiX() { return posiX; }
float  Tank::getPosiY() { return posiY; }
float  Tank::getAngulo() { return angulo; }
float  Tank::getDimX() { return dimX; }
float  Tank::getDimY() { return dimY; }
char  Tank::getStatus() { return status; }
int  Tank::getTipo() { return tipo; }
int  Tank::getVida() { return vida; }



#include "TelaChefao.h"
#include <ctime>
#include <vector>
#include <iostream>
#include <sstream>

TelaChefao::TelaChefao(int numFase) {
	numeroFase = numFase;

	Player2 = new Tank(164, 1, 0, 6);
	temP2 = false;

	Player = new Tank(128, 1, 0, 6);

	if (numFase == 1) {
		boss = new Chefao(250, 250, 180, 3);
	}
	else
		if (numFase == 2) {
			boss = new Chefao(172.5, 250, 180, 2);
		
		}
		else
			if (numFase == 3) {
				boss = new Chefao(172.5, 250, 180, 4);
			}
	

	//MoveTankMetodo1(to2, 3, 1);

}
TelaChefao::~TelaChefao()
{
}

void TelaChefao::renderBitmapString(float x, float y, void *font, const char *string) {
	const char *c;
	glRasterPos2f(x, y);
	for (c = string; *c != '\0'; c++) {
		glutBitmapCharacter(font, *c);
	}
}
void TelaChefao::desenhaLateral() {
	glPushMatrix();

	string NomeDoFilme = "";
	
	const char* text;

	glColor3f(1, 1, 1);
	int font = (int)GLUT_BITMAP_HELVETICA_12;
	

	NomeDoFilme = "";
	std::stringstream Result;
	Result << Player->getQtdVida();
	NomeDoFilme = NomeDoFilme + " " + Result.str();
	text = NomeDoFilme.c_str();
	string points = "";
	std::stringstream Result3;
	Result3 << Player->getQtdPontuacao();
	points = points + " " + Result3.str() + "pts";
	const char* text2;
	text2 = points.c_str();
	renderBitmapString(127, 16, (void *)font, "Player1");
	renderBitmapString(127, 11, (void *)font, text2);
	renderBitmapString(128, 6, (void *)font, "Vidas:");
	renderBitmapString(131, 1, (void *)font, text);

	if (temP2) {
		NomeDoFilme = "";
		std::stringstream Result2;
		Result2 << Player2->getQtdVida();
		NomeDoFilme = NomeDoFilme + " " + Result2.str();
		text = NomeDoFilme.c_str();
		renderBitmapString(163, 11, (void *)font, "Player2");
		renderBitmapString(163, 6, (void *)font, "Vidas:");
		renderBitmapString(165, 1, (void *)font, text);
	}
	else {
		renderBitmapString(163, 11, (void *)font, "Player2");
		renderBitmapString(164, 6, (void *)font, "Tecle");
		renderBitmapString(164.5, 1, (void *)font, "Enter");

	}


	glPopMatrix();
}
bool TelaChefao::semColisao(Tank *T, float incremento, char direcao, int indiceT) {


	float posCentroX = T->getPosiCentroX(),
		posCentroY = T->getPosiCentroY(),

		dimXT = T->getDimX(),
		dimYT = T->getDimY();


	if (direcao == 'd') {
		if (posCentroX + 0.5*dimYT + incremento >= 360) {
			return false;
		}
	}
	else if (direcao == 'e') {
		if (posCentroX - 0.5*dimYT - incremento <= 0) {
			return false;
		}
	}
	else if (direcao == 'c') {
		if (posCentroY + 0.5*dimYT + incremento >= 252) {
			return false;
		}
	}
	else if (direcao == 'b') {
		if (posCentroY - 0.5*dimYT - incremento <= 0) {
			return false;
		}
	}



	// FOR PARA TANQUES
	

	
	if ((indiceT == 1 || indiceT ==2)&& Player2->getStatus()!='i' && temP2) {
		float posBlocoX = Player2->getPosiOrigemX(),
			posBlocoY = Player2->getPosiOrigemY(),
			dimXB = Player2->getDimX(),
			dimYB = Player2->getDimY();
		if (direcao == 'd') {
			if ((((((posCentroY - 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY - 0.5*dimYT) >= posBlocoY)) || (((posCentroY + 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY + 0.5*dimYT) >= posBlocoY)))
				&& ((posCentroX + 0.6*dimYT + incremento) > posBlocoX) && ((posCentroX + 0.6*dimYT + incremento) < posBlocoX + dimXB))) {
				return false;

			}
		}
		else if (direcao == 'e') {
			if ((((((posCentroY - 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY - 0.5*dimYT) >= posBlocoY)) || (((posCentroY + 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY + 0.5*dimYT) >= posBlocoY)))
				&& ((posCentroX - 0.6*dimYT - incremento) < posBlocoX + dimXB) && ((posCentroX - 0.6*dimYT - incremento) > posBlocoX))) {
				return false;

			}
		}
		else if (direcao == 'c') {
			if ((((((posCentroX - 0.5*dimXT) <= (posBlocoX + dimXB)) && ((posCentroX - 0.5*dimXT) >= posBlocoX)) ||
				(((posCentroX + 0.5*dimYT) <= (posBlocoX + dimXB)) && ((posCentroX + 0.5*dimXT) >= posBlocoX)))
				&& ((posCentroY + 0.6*dimYT + incremento) > posBlocoY) && ((posCentroY + 0.6*dimYT + incremento) < posBlocoY + dimYB))) {
				return false;

			}
		}
		else if (direcao == 'b') {
			if ((((((posCentroX - 0.5*dimXT) <= (posBlocoX + dimXB)) && ((posCentroX - 0.5*dimXT) >= posBlocoX)) ||
				(((posCentroX + 0.5*dimYT) <= (posBlocoX + dimXB)) && ((posCentroX + 0.5*dimXT) >= posBlocoX)))
				&& ((posCentroY - 0.6*dimYT - incremento) > posBlocoY) && ((posCentroY - 0.6*dimYT - incremento) < posBlocoY + dimYB))) {
				return false;

			}
		}
	} if ((indiceT == 0 || indiceT == 2) && Player->getStatus() != 'i') {
		float posBlocoX = Player->getPosiOrigemX(),
			posBlocoY = Player->getPosiOrigemY(),
			dimXB = Player->getDimX(),
			dimYB = Player->getDimY();
		if (direcao == 'd') {
			if ((((((posCentroY - 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY - 0.5*dimYT) >= posBlocoY)) || (((posCentroY + 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY + 0.5*dimYT) >= posBlocoY)))
				&& ((posCentroX + 0.6*dimYT + incremento) > posBlocoX) && ((posCentroX + 0.6*dimYT + incremento) < posBlocoX + dimXB))) {
				return false;

			}
		}
		else if (direcao == 'e') {
			if ((((((posCentroY - 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY - 0.5*dimYT) >= posBlocoY)) || (((posCentroY + 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY + 0.5*dimYT) >= posBlocoY)))
				&& ((posCentroX - 0.6*dimYT - incremento) < posBlocoX + dimXB) && ((posCentroX - 0.6*dimYT - incremento) > posBlocoX))) {
				return false;

			}
		}
		else if (direcao == 'c') {
			if ((((((posCentroX - 0.5*dimXT) <= (posBlocoX + dimXB)) && ((posCentroX - 0.5*dimXT) >= posBlocoX)) ||
				(((posCentroX + 0.5*dimYT) <= (posBlocoX + dimXB)) && ((posCentroX + 0.5*dimXT) >= posBlocoX)))
				&& ((posCentroY + 0.6*dimYT + incremento) > posBlocoY) && ((posCentroY + 0.6*dimYT + incremento) < posBlocoY + dimYB))) {
				return false;

			}
		}
		else if (direcao == 'b') {
			if ((((((posCentroX - 0.5*dimXT) <= (posBlocoX + dimXB)) && ((posCentroX - 0.5*dimXT) >= posBlocoX)) ||
				(((posCentroX + 0.5*dimYT) <= (posBlocoX + dimXB)) && ((posCentroX + 0.5*dimXT) >= posBlocoX)))
				&& ((posCentroY - 0.6*dimYT - incremento) > posBlocoY) && ((posCentroY - 0.6*dimYT - incremento) < posBlocoY + dimYB))) {
				return false;

			}
		}
	}if ((indiceT == 1 || indiceT == 0) && boss->getStatus() != 'i') {
		float posBlocoX = boss->getPosiOrigemX(),
			posBlocoY = boss->getPosiOrigemY(),
			dimXB = boss->getDimX(),
			dimYB = boss->getDimY();
		if (direcao == 'd') {
			if ((((((posCentroY - 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY - 0.5*dimYT) >= posBlocoY)) || (((posCentroY + 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY + 0.5*dimYT) >= posBlocoY)))
				&& ((posCentroX + 0.6*dimYT + incremento) > posBlocoX) && ((posCentroX + 0.6*dimYT + incremento) < posBlocoX + dimXB))) {
				return false;

			}
		}
		else if (direcao == 'e') {
			if ((((((posCentroY - 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY - 0.5*dimYT) >= posBlocoY)) || (((posCentroY + 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY + 0.5*dimYT) >= posBlocoY)))
				&& ((posCentroX - 0.6*dimYT - incremento) < posBlocoX + dimXB) && ((posCentroX - 0.6*dimYT - incremento) > posBlocoX))) {
				return false;

			}
		}
		else if (direcao == 'c') {
			if ((((((posCentroX - 0.5*dimXT) <= (posBlocoX + dimXB)) && ((posCentroX - 0.5*dimXT) >= posBlocoX)) ||
				(((posCentroX + 0.5*dimYT) <= (posBlocoX + dimXB)) && ((posCentroX + 0.5*dimXT) >= posBlocoX)))
				&& ((posCentroY + 0.6*dimYT + incremento) > posBlocoY) && ((posCentroY + 0.6*dimYT + incremento) < posBlocoY + dimYB))) {
				return false;

			}
		}
		else if (direcao == 'b') {
			if ((((((posCentroX - 0.5*dimXT) <= (posBlocoX + dimXB)) && ((posCentroX - 0.5*dimXT) >= posBlocoX)) ||
				(((posCentroX + 0.5*dimYT) <= (posBlocoX + dimXB)) && ((posCentroX + 0.5*dimXT) >= posBlocoX)))
				&& ((posCentroY - 0.6*dimYT - incremento) > posBlocoY) && ((posCentroY - 0.6*dimYT - incremento) < posBlocoY + dimYB))) {
				return false;

			}
		}
	}
	
	return true;

}
bool TelaChefao::semColisao(TiroExp *T, float incremento, char direcao, int indiceT) {


	float posCentroX = T->getPosiCentroX(),
		posCentroY = T->getPosiCentroY(),

		dimXT = T->getDimX(),
		dimYT = T->getDimY();

	if (direcao == 'd') {
		if (posCentroX + 0.5*dimYT + incremento >= 360) {
			return false;
		}
	}
	else if (direcao == 'e') {
		if (posCentroX - 0.5*dimYT - incremento <= 0) {
			return false;
		}
	}
	else if (direcao == 'c') {
		if (posCentroY + 0.5*dimYT + incremento >= 252) {
			return false;
		}
	}
	else if (direcao == 'b') {
		if (posCentroY - 0.5*dimYT - incremento <= 0) {
			return false;
		}
	}



	
	// FOR PARA TANQUES
	if (Player2->getStatus() != 'i' && temP2 && T->getEdeInimigo()) {
		float posBlocoX = Player2->getPosiOrigemX(),
			posBlocoY = Player2->getPosiOrigemY(),
			dimXB = Player2->getDimX(),
			dimYB = Player2->getDimY();
		if (direcao == 'd') {
			if ((((((posCentroY - 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY - 0.5*dimYT) >= posBlocoY)) || (((posCentroY + 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY + 0.5*dimYT) >= posBlocoY)))
				&& ((posCentroX + 0.6*dimYT + incremento) > posBlocoX) && ((posCentroX + 0.6*dimYT + incremento) < posBlocoX + dimXB))) {
					Player2->recebeDano(T->getPotencia());
					return false;

			}
		}
		else if (direcao == 'e') {
			if ((((((posCentroY - 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY - 0.5*dimYT) >= posBlocoY)) || (((posCentroY + 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY + 0.5*dimYT) >= posBlocoY)))
				&& ((posCentroX - 0.6*dimYT - incremento) < posBlocoX + dimXB) && ((posCentroX - 0.6*dimYT - incremento) > posBlocoX))) {
				Player2->recebeDano(T->getPotencia());
					return false;

			}
		}
		else if (direcao == 'c') {
			if ((((((posCentroX - 0.5*dimXT) <= (posBlocoX + dimXB)) && ((posCentroX - 0.5*dimXT) >= posBlocoX)) ||
				(((posCentroX + 0.5*dimYT) <= (posBlocoX + dimXB)) && ((posCentroX + 0.5*dimXT) >= posBlocoX)))
				&& ((posCentroY + 0.6*dimYT + incremento) > posBlocoY) && ((posCentroY + 0.6*dimYT + incremento) < posBlocoY + dimYB))) {
				Player2->recebeDano(T->getPotencia());
					return false;

			}
		}
		else if (direcao == 'b') {
			if ((((((posCentroX - 0.5*dimXT) <= (posBlocoX + dimXB)) && ((posCentroX - 0.5*dimXT) >= posBlocoX)) ||
				(((posCentroX + 0.5*dimYT) <= (posBlocoX + dimXB)) && ((posCentroX + 0.5*dimXT) >= posBlocoX)))
				&& ((posCentroY - 0.6*dimYT - incremento) > posBlocoY) && ((posCentroY - 0.6*dimYT - incremento) < posBlocoY + dimYB))) {
				Player2->recebeDano(T->getPotencia());
					return false;

			}
		}
	}
	if (Player->getStatus() != 'i' && T->getEdeInimigo()) {
		float posBlocoX = Player->getPosiOrigemX(),
			posBlocoY = Player->getPosiOrigemY(),
			dimXB = Player->getDimX(),
			dimYB = Player->getDimY();
		if (direcao == 'd') {
			if ((((((posCentroY - 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY - 0.5*dimYT) >= posBlocoY)) || (((posCentroY + 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY + 0.5*dimYT) >= posBlocoY)))
				&& ((posCentroX + 0.6*dimYT + incremento) > posBlocoX) && ((posCentroX + 0.6*dimYT + incremento) < posBlocoX + dimXB))) {
				Player->recebeDano(T->getPotencia());
					return false;

			}
		}
		else if (direcao == 'e') {
			if ((((((posCentroY - 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY - 0.5*dimYT) >= posBlocoY)) || (((posCentroY + 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY + 0.5*dimYT) >= posBlocoY)))
				&& ((posCentroX - 0.6*dimYT - incremento) < posBlocoX + dimXB) && ((posCentroX - 0.6*dimYT - incremento) > posBlocoX))) {
				Player->recebeDano(T->getPotencia());
					return false;

			}
		}
		else if (direcao == 'c') {
			if ((((((posCentroX - 0.5*dimXT) <= (posBlocoX + dimXB)) && ((posCentroX - 0.5*dimXT) >= posBlocoX)) ||
				(((posCentroX + 0.5*dimYT) <= (posBlocoX + dimXB)) && ((posCentroX + 0.5*dimXT) >= posBlocoX)))
				&& ((posCentroY + 0.6*dimYT + incremento) > posBlocoY) && ((posCentroY + 0.6*dimYT + incremento) < posBlocoY + dimYB))) {
				Player->recebeDano(T->getPotencia());
					return false;

			}
		}
		else if (direcao == 'b') {
			if ((((((posCentroX - 0.5*dimXT) <= (posBlocoX + dimXB)) && ((posCentroX - 0.5*dimXT) >= posBlocoX)) ||
				(((posCentroX + 0.5*dimYT) <= (posBlocoX + dimXB)) && ((posCentroX + 0.5*dimXT) >= posBlocoX)))
				&& ((posCentroY - 0.6*dimYT - incremento) > posBlocoY) && ((posCentroY - 0.6*dimYT - incremento) < posBlocoY + dimYB))) {
				Player->recebeDano(T->getPotencia());
					return false;

			}
		}
	}
	if (boss->getStatus() != 'i' && T->getEdeInimigo()==false) {
		float posBlocoX = boss->getPosiOrigemX(),
			posBlocoY = boss->getPosiOrigemY(),
			dimXB = boss->getDimX(),
			dimYB = boss->getDimY();
		if (direcao == 'd') {
			if ((((((posCentroY - 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY - 0.5*dimYT) >= posBlocoY)) || (((posCentroY + 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY + 0.5*dimYT) >= posBlocoY)))
				&& ((posCentroX + 0.6*dimYT + incremento) > posBlocoX) && ((posCentroX + 0.6*dimYT + incremento) < posBlocoX + dimXB))) {
				boss->recebeDano(T->getPotencia());
				if(T->getEP1())Player->recebePontos(T->getPotencia());else Player2->recebePontos(T->getPotencia());
					return false;

			}
		}
		else if (direcao == 'e') {
			if ((((((posCentroY - 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY - 0.5*dimYT) >= posBlocoY)) || (((posCentroY + 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY + 0.5*dimYT) >= posBlocoY)))
				&& ((posCentroX - 0.6*dimYT - incremento) < posBlocoX + dimXB) && ((posCentroX - 0.6*dimYT - incremento) > posBlocoX))) {
				boss->recebeDano(T->getPotencia());
				if(T->getEP1())Player->recebePontos(T->getPotencia());else Player2->recebePontos(T->getPotencia());
					return false;

			}
		}
		else if (direcao == 'c') {
			if ((((((posCentroX - 0.5*dimXT) <= (posBlocoX + dimXB)) && ((posCentroX - 0.5*dimXT) >= posBlocoX)) ||
				(((posCentroX + 0.5*dimYT) <= (posBlocoX + dimXB)) && ((posCentroX + 0.5*dimXT) >= posBlocoX)))
				&& ((posCentroY + 0.6*dimYT + incremento) > posBlocoY) && ((posCentroY + 0.6*dimYT + incremento) < posBlocoY + dimYB))) {
				boss->recebeDano(T->getPotencia());
				if(T->getEP1())Player->recebePontos(T->getPotencia());else Player2->recebePontos(T->getPotencia());
					return false;

			}
		}
		else if (direcao == 'b') {
			if ((((((posCentroX - 0.5*dimXT) <= (posBlocoX + dimXB)) && ((posCentroX - 0.5*dimXT) >= posBlocoX)) ||
				(((posCentroX + 0.5*dimYT) <= (posBlocoX + dimXB)) && ((posCentroX + 0.5*dimXT) >= posBlocoX)))
				&& ((posCentroY - 0.6*dimYT - incremento) > posBlocoY) && ((posCentroY - 0.6*dimYT - incremento) < posBlocoY + dimYB))) {
				boss->recebeDano(T->getPotencia());
				if(T->getEP1())Player->recebePontos(T->getPotencia());else Player2->recebePontos(T->getPotencia());
					return false;

			}
		}
	}
	// FOR PARA TIROS


	for (int i = 0; i < tiros.size(); i++) {
		if (i == indiceT)continue;
		if (tiros[i]->getStatus() == 'i')continue;
		float posBlocoX = tiros[i]->getPosiOrigemX(),
			posBlocoY = tiros[i]->getPosiOrigemY(),
			dimXB = tiros[i]->getDimX(),
			dimYB = tiros[i]->getDimY();
		if (direcao == 'd') {
			if ((((((posCentroY - 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY - 0.5*dimYT) >= posBlocoY)) || (((posCentroY + 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY + 0.5*dimYT) >= posBlocoY)))
				&& ((posCentroX + 0.65*dimYT + incremento) > posBlocoX) && ((posCentroX + 0.65*dimYT + incremento) < posBlocoX + dimXB))) {
				tiros[i]->setStatus('i');
				return false;

			}
		}
		else if (direcao == 'e') {
			if ((((((posCentroY - 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY - 0.5*dimYT) >= posBlocoY)) || (((posCentroY + 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY + 0.5*dimYT) >= posBlocoY)))
				&& ((posCentroX - 0.65*dimYT - incremento) < posBlocoX + dimXB) && ((posCentroX - 0.65*dimYT - incremento) > posBlocoX))) {
				tiros[i]->setStatus('i');
				return false;

			}
		}
		else if (direcao == 'c') {
			if ((((((posCentroX - 0.5*dimXT) <= (posBlocoX + dimXB)) && ((posCentroX - 0.5*dimXT) >= posBlocoX)) ||
				(((posCentroX + 0.5*dimYT) <= (posBlocoX + dimXB)) && ((posCentroX + 0.5*dimXT) >= posBlocoX)))
				&& ((posCentroY + 0.65*dimYT + incremento) > posBlocoY) && ((posCentroY + 0.65*dimYT + incremento) < posBlocoY + dimYB))) {
				tiros[i]->setStatus('i');
				return false;

			}
		}
		else if (direcao == 'b') {
			if ((((((posCentroX - 0.5*dimXT) <= (posBlocoX + dimXB)) && ((posCentroX - 0.5*dimXT) >= posBlocoX)) ||
				(((posCentroX + 0.5*dimYT) <= (posBlocoX + dimXB)) && ((posCentroX + 0.5*dimXT) >= posBlocoX)))
				&& ((posCentroY - 0.65*dimYT - incremento) > posBlocoY) && ((posCentroY - 0.65*dimYT - incremento) < posBlocoY + dimYB))) {
				tiros[i]->setStatus('i');
				return false;

			}
		}

	}
	return true;

}
void TelaChefao::desenhaTankes() {
	glPushMatrix();
	MoveTankInimigo(0.1);

	if (temP2 && Player2->getStatus() != 'i')Player2->desenha();
	if (Player->getStatus() != 'i')Player->desenha();
	if (boss->getStatus() != 'i') { boss->desenha(); Atira(2); }
		

	glPopMatrix();
}
void TelaChefao::desenhaTiros() {
	glPushMatrix();
	for (int i = 0; i < tiros.size(); i++) {
		if (tiros[i]->getStatus() != 'i') {

			if (!(semColisao(tiros[i], 1, tiros[i]->getDirecao(), i))) {
				tiros[i]->setStatus('i');

			}
			if (tiros[i]->getStatus() != 'i') {
				tiros[i]->desenha();
				tiros[i]->Move(1);
			}
		}
	}
	glPopMatrix();
}


void TelaChefao::MoveTankMetodo1(Tank *t, float incremento, int indiceTank) {
	float ang = t->getAngulo();
	srand(clock()); //Dê o include lá : #include <ctime>
	if (ang == 0) {
		if (semColisao(t, incremento, 'c', indiceTank)) {
			t->viraCima(incremento, true);
		}
		else {
			//while (true) {
			srand(clock()*indiceTank);
			int r = (rand() % 100) + 1;
			cout << "\n" << r << "\n";
			if (r < 34 && semColisao(t, incremento, 'b', indiceTank)) {
				t->viraBaixo(incremento, true);
				//break;
			}
			else if (r >= 34 && r < 67 && semColisao(t, incremento, 'e', indiceTank)) {
				t->viraEsquerda(incremento, true);
				//break;
			}
			else if (r >= 67 && semColisao(t, incremento, 'd', indiceTank)) {
				t->viraDireita(incremento, true);
				//break;
			}
			//}
		}
	}
	else if (ang == 180) {
		if (semColisao(t, incremento, 'b', indiceTank)) {
			t->viraBaixo(incremento, true);
		}
		else {
			//while (true) {
			int r = (rand() % 100) + 1;
			if (r < 34 && semColisao(t, incremento, 'c', indiceTank)) {
				t->viraCima(incremento, true);
				//break;
			}
			else if (r >= 34 && r < 67 && semColisao(t, incremento, 'e', indiceTank)) {
				t->viraEsquerda(incremento, true);
				//break;
			}
			else if (r >= 67 && semColisao(t, incremento, 'd', indiceTank)) {
				t->viraDireita(incremento, true);
				//break;
			}
			//}
		}
	}
	else if (ang == -90) {
		if (semColisao(t, incremento, 'd', indiceTank)) {
			t->viraDireita(incremento, true);
		}
		else {
			//while (true) {
			int r = (rand() % 100) + 1;
			if (r < 34 && semColisao(t, incremento, 'b', indiceTank)) {
				t->viraBaixo(incremento, true);
				//break;
			}
			else if (r >= 34 && r < 67 && semColisao(t, incremento, 'e', indiceTank)) {
				t->viraEsquerda(incremento, true);
				//break;
			}
			else if (r >= 67 && semColisao(t, incremento, 'c', indiceTank)) {
				t->viraCima(incremento, true);
				//break;
			}
			//}
		}
	}
	else if (ang == 90) {
		if (semColisao(t, incremento, 'e', indiceTank)) {
			t->viraEsquerda(incremento, true);
		}
		else {
			//while (true) {
			int r = (rand() % 100) + 1;
			if (r < 34 && semColisao(t, incremento, 'b', indiceTank)) {
				t->viraBaixo(incremento, true);
				//	break;
			}
			else if (r >= 34 && r < 67 && semColisao(t, incremento, 'c', indiceTank)) {
				t->viraCima(incremento, true);
				//	break;
			}
			else if (r >= 67 && semColisao(t, incremento, 'd', indiceTank)) {
				t->viraDireita(incremento, true);
				//break;
			}
			//}
		}
	}
}

void TelaChefao::MoveTankMetodo2(Tank *t, float incremento, int indiceTank) {
	float pxPlayer = Player->getPosiX();
	float pyPlayer = Player->getPosiX();
	char movimentos[4] = { 'e','d','c','b' };
	int pos = 0;
	bool andei = false;

	float ang = t->getAngulo();

	float deltaVert = t->getPosiCentroY() - Player->getPosiCentroY();
	if (deltaVert<0)deltaVert = -1 * deltaVert;
	float deltaHoriz = t->getPosiCentroX() - Player->getPosiCentroX();
	if (deltaHoriz < 0)deltaHoriz = -1 * deltaHoriz;

	if (deltaHoriz > deltaVert) {
		if (t->getPosiCentroX() > Player->getPosiCentroX() && semColisao(t, incremento, 'e', indiceTank)) {
			cout << "PLAYER MAIS ESQUERDA 0" << endl;
			//if (semColisao(t, incremento, 'e', indiceTank)) {
			t->viraEsquerda(incremento, true);
			//}

		}
		else if (t->getPosiCentroX() < Player->getPosiCentroX() && semColisao(t, incremento, 'd', indiceTank)) {
			cout << "PLAYER MAIS DIREITA 0" << endl;

			t->viraDireita(incremento, true);
			//}

		}
		else
			if (t->getPosiCentroY() < Player->getPosiCentroY() && semColisao(t, incremento, 'c', indiceTank)) {
				cout << "PLAYER MAIS ACIMA 0" << endl;
				/*if () {*/
				t->viraCima(incremento, true);
				//}

			}
			else if (t->getPosiCentroY() > Player->getPosiCentroY() && semColisao(t, incremento, 'b', indiceTank)) {
				cout << "PLAYER MAIS ABAIXO 0" << endl;

				t->viraBaixo(incremento, true);
			}
	}
	else {
		if (t->getPosiCentroY() < Player->getPosiCentroY() && semColisao(t, incremento, 'c', indiceTank)) {
			cout << "PLAYER MAIS ACIMA 0" << endl;
			/*if () {*/
			t->viraCima(incremento, true);
			//}

		}
		else if (t->getPosiCentroY() > Player->getPosiCentroY() && semColisao(t, incremento, 'b', indiceTank)) {
			cout << "PLAYER MAIS ABAIXO 0" << endl;

			t->viraBaixo(incremento, true);
		}
		else
			if (t->getPosiCentroX() > Player->getPosiCentroX() && semColisao(t, incremento, 'e', indiceTank)) {
				cout << "PLAYER MAIS ESQUERDA 0" << endl;
				//if (semColisao(t, incremento, 'e', indiceTank)) {
				t->viraEsquerda(incremento, true);
				//}

			}
			else if (t->getPosiCentroX() < Player->getPosiCentroX() && semColisao(t, incremento, 'd', indiceTank)) {
				cout << "PLAYER MAIS DIREITA 0" << endl;

				t->viraDireita(incremento, true);
				//}

			}
	}
}

void TelaChefao::MoveTankPlayer(char direcao, float incremento) {
	if (direcao == 'c') {
		Player->viraCima(1, semColisao(Player, 1, 'c', 1));
	}
	else if (direcao == 'b') {
		Player->viraBaixo(1, semColisao(Player, 1, 'b', 1));
	}
	else if (direcao == 'd') {
		Player->viraDireita(1, semColisao(Player, 1, 'd', 1));
	}
	else if (direcao == 'e') {
		Player->viraEsquerda(1, semColisao(Player, 1, 'e', 1));
	}
}

void TelaChefao::MoveTankInimigo(float incremento) {

	
}

void TelaChefao::setPlayer2() {
	temP2 = true;
}

void TelaChefao::Atira(int pos) {
	int tempoPraAtirar;
	if (pos == 0)tempoPraAtirar = Player2->getTempoPraAtirar();else
	if (pos == 1)tempoPraAtirar = Player->getTempoPraAtirar(); else
	if (pos == 2)tempoPraAtirar = boss->getTempoPraAtirar();
	if (tempoPraAtirar<0) {
		if(pos==0){
			tiros.push_back(Player2->atira(1));
		}
		else if (pos == 1)
		{
			tiros.push_back(Player->atira(1));
			if (pos == 1)	tiros[tiros.size() - 1]->setEP1(true);
		}
		else if (pos == 2) {
			tiros.push_back(boss->atira(3));
		}
	}
}

void TelaChefao::desenha() {
	desenhaTankes();
	desenhaTiros();
	desenhaLateral();
}

bool TelaChefao::morreu() {
	if (temP2) {
		if (Player->getStatus() == 'i' && Player2->getStatus() == 'i') {
			return true;
		}
		else return false;
	}
	else if (Player->getStatus() == 'i') {
		return true;
	}
	else return false;
}
bool TelaChefao::gameOver() {
	if (temP2) {
		if (Player2->getQtdVida() == 0 && Player->getQtdVida() == 0) {
			return true;
		}
		else return false;
	}
	else if (Player->getQtdVida() == 0) {
		return true;
	}
	else return false;
}
bool TelaChefao::acabou() {
	
		if (boss->getStatus() != 'i') {
			return false;
		}
	
	return true;
}
Tank* TelaChefao::getP1() {
	return Player;
}
Tank* TelaChefao::getP2() {
	return Player2;
}



void TelaChefao::setP1(Tank *t) {
	t->setStatus('a');
	t->viraCima(0, true);
	t->setPosiX(128);
	t->setPosiY(1);
	//t->reiniciaVida();
	Player = t;
}
void TelaChefao::setP2(Tank *t) {
	t->setStatus('a');
	t->viraCima(0, true);
	t->setPosiX(164);
	t->setPosiY(1);
	//t->reiniciaVida();
	Player2 = t;
}

int TelaChefao::escolheTank() {
	srand((int)time(0));

	int r = (rand() % 100) + 1;

	if (numeroFase == 1) {
		if (r <= 30) {
			return 1;
		}
		else if (r <= 60) {
			return 2;
		}
		else if (r <= 80) {
			return 3;
		}
		else if (r <= 90) {
			return 4;
		}
		else if (r <= 100) {
			return 5;
		}
	}
	else if (numeroFase == 2) {
		if (r <= 20) {
			return 1;
		}
		else if (r <= 40) {
			return 2;
		}
		else if (r <= 60) {
			return 3;
		}
		else if (r <= 80) {
			return 4;
		}
		else if (r <= 100) {
			return 5;
		}
	}
	else if (numeroFase == 3) {
		if (r <= 30) {
			return 5;
		}
		else if (r <= 60) {
			return 4;
		}
		else if (r <= 80) {
			return 3;
		}
		else if (r <= 90) {
			return 2;
		}
		else if (r <= 100) {
			return 1;
		}
	}

}


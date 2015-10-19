#include "Tela.h"
#include <ctime>
#include <vector>
#include <iostream>
#include <sstream>

Tela::Tela(int numFase) {
	numeroFase = numFase;
	tankesRestantes = 90;

	Player2 = new Tank(164, 1, 0, 6);
	tankes.push_back(Player2);
	temP2 = false;

	Player = new Tank(128, 1, 0, 6);
	tankes.push_back(Player);
	/*Tank *to = new Tank(290,19,0,3);
	tankes.push_back(to);
	Tank *to2 = new Tank(300,216,0,2);
	tankes.push_back(to2);*/
	if (numFase == 1) {
		for (float i = 16.5; i < 360; i += 36) {
			tankes.push_back(new Tank(i, 250.5, 180, 1));
		}
	}
	else
		if (numFase == 2) {
			for (float i = 16.5; i < 180; i += 36) {
				tankes.push_back(new Tank(i, 250.5, 180, 1));
			}
			for (float i = 196.5; i < 360; i += 36) {
				tankes.push_back(new Tank(i, 250.5, 180, 2));
			}
		}
		else
			if (numFase == 3) {
				for (float i = 16.5; i < 360; i += 36) {
					tankes.push_back(new Tank(i, 250.5, 180, 2));
				}
			}
	float DIM_X_BLOC = 18;
	float DIM_Y_BLOC = 18;

	vector<float> pontoX;
	vector<float> pontoY;
	int qtdBlocos = 0;
	//char url[]="tank1.txt";
	FILE *arq = NULL;
	float cooX, cooY;

	if (numFase == 1) {
		arq = fopen("fase1.txt", "r");
	}
	else if (numFase == 2) {
		arq = fopen("fase2.txt", "r");
	}
	else if (numFase == 3) {
		arq = fopen("lengs.txt", "r");
	}
	if (arq == NULL)
		printf("Erro, nao foi possivel abrir o arquivo\n");
	else {

		while ((fscanf(arq, "%f %f\n", &cooX, &cooY)) != EOF)
		{
			pontoX.push_back(cooX);
			pontoY.push_back(cooY);
			qtdBlocos++;
		}
	}
	fclose(arq);
	for (int j = 0; j < qtdBlocos; j++) {
		blocos.push_back(new Bloco(pontoX[j] * DIM_X_BLOC, pontoY[j] * DIM_Y_BLOC, 0, DIM_X_BLOC, DIM_Y_BLOC));
	}

	//MoveTankMetodo1(to2, 3, 1);

}
Tela::~Tela()
{
}

void Tela::renderBitmapString(float x, float y, void *font, const char *string) {
	const char *c;
	glRasterPos2f(x, y);
	for (c = string; *c != '\0'; c++) {
		glutBitmapCharacter(font, *c);
	}
}
void Tela::desenhaLateral(){
	glPushMatrix();

	string NomeDoFilme = "";
	std::stringstream Resultado;
	Resultado << tankesRestantes;
	NomeDoFilme = NomeDoFilme + " " + Resultado.str();
	const char* text= NomeDoFilme.c_str();

	glColor3f(1,1,1);
	int font = (int)GLUT_BITMAP_HELVETICA_12;
	renderBitmapString(1, 240, (void *)font, "Na Fila:");
	
	renderBitmapString(3, 235, (void *)font,text);

	NomeDoFilme = "";
	std::stringstream Result;
	Result << Player->getQtdVida();
	NomeDoFilme = NomeDoFilme + " " + Result.str();
	text= NomeDoFilme.c_str();
	string points = "";
	std::stringstream Result3;
	Result3 << Player->getQtdPontuacao();
	points = points + " " + Result3.str()+"pts";
	const char* text2;
	text2= points.c_str();
	renderBitmapString(127, 16, (void *)font,"Player1");
	renderBitmapString(127, 11, (void *)font,text2);
	renderBitmapString(128, 6, (void *)font,"Vidas:");
	renderBitmapString(131, 1, (void *)font,text);

	if(temP2){
	NomeDoFilme = "";
	std::stringstream Result2;
	Result2 << Player2->getQtdVida();
	NomeDoFilme = NomeDoFilme + " " + Result2.str();
	text= NomeDoFilme.c_str();
	renderBitmapString(163, 11, (void *)font,"Player2");
	renderBitmapString(163, 6, (void *)font,"Vidas:");
	renderBitmapString(165, 1, (void *)font,text);
	}else{
	renderBitmapString(163, 11, (void *)font,"Player2");
	renderBitmapString(164, 6, (void *)font,"Tecle");	
	renderBitmapString(164.5, 1, (void *)font,"Enter");	
	
	}


	glPopMatrix();
}
void Tela::addBloco(double x, double y, double ang, int dimX, int dimY) {
	blocos.push_back(new Bloco(x, y, ang, dimX, dimY));
}
void Tela::addBloco(Bloco *b) {
	blocos.push_back(b);
}
void Tela::addTankes(double x, double y, double ang, int tipo) {
	tankes.push_back(new Tank(x, y, ang, tipo));
}
void Tela::addTankes(Tank *t) {
	tankes.push_back(t);
}
bool Tela::semColisao(Tank *T, float incremento, char direcao, int indiceT) {


	float posCentroX = T->getPosiCentroX(),
		posCentroY = T->getPosiCentroY(),

		dimXT = T->getDimX(),
		dimYT = T->getDimY(),
		dimXB = blocos[0]->getDimX(),
		dimYB = blocos[0]->getDimY();


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



	for (int i = 0; i < blocos.size(); i++) {
		float posBlocoX = blocos[i]->getPosiX(),
			posBlocoY = blocos[i]->getPosiY();
		if (direcao == 'd') {
			if ((((((posCentroY - 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY - 0.5*dimYT) >= posBlocoY)) || (((posCentroY + 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY + 0.5*dimYT) >= posBlocoY)))
				&& ((posCentroX + 0.6*dimYT + incremento) >= posBlocoX) && ((posCentroX + 0.6*dimYT + incremento) <= posBlocoX + dimXB))) {
				return false;

			}
		}
		else if (direcao == 'e') {
			if ((((((posCentroY - 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY - 0.5*dimYT) >= posBlocoY)) || (((posCentroY + 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY + 0.5*dimYT) >= posBlocoY)))
				&& ((posCentroX - 0.6*dimYT - incremento) <= posBlocoX + dimXB) && ((posCentroX - 0.6*dimYT - incremento) >= posBlocoX))) {
				return false;

			}
		}
		else if (direcao == 'c') {
			if ((((((posCentroX - 0.5*dimXT) <= (posBlocoX + dimXB)) && ((posCentroX - 0.5*dimXT) >= posBlocoX)) ||
				(((posCentroX + 0.5*dimYT) <= (posBlocoX + dimXB)) && ((posCentroX + 0.5*dimXT) >= posBlocoX)))
				&& ((posCentroY + 0.6*dimYT + incremento) >= posBlocoY) && ((posCentroY + 0.6*dimYT + incremento) <= posBlocoY + dimYB))) {
				return false;

			}
		}
		else if (direcao == 'b') {
			if ((((((posCentroX - 0.5*dimXT) <= (posBlocoX + dimXB)) && ((posCentroX - 0.5*dimXT) >= posBlocoX)) ||
				(((posCentroX + 0.5*dimYT) <= (posBlocoX + dimXB)) && ((posCentroX + 0.5*dimXT) >= posBlocoX)))
				&& ((posCentroY - 0.6*dimYT - incremento) >= posBlocoY) && ((posCentroY - 0.6*dimYT - incremento) <= posBlocoY + dimYB))) {
				return false;

			}
		}

	}

	// FOR PARA TANQUES
	int inicio = 0;

	if (!temP2)
		inicio = 1;

	for (int i = inicio; i < tankes.size(); i++) {
		if (i == indiceT)continue;
		if (tankes[i]->getStatus() == 'i')
			continue;
		float posBlocoX = tankes[i]->getPosiOrigemX(),
			posBlocoY = tankes[i]->getPosiOrigemY(),
			dimXB = tankes[i]->getDimX(),
			dimYB = tankes[i]->getDimY();
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
bool Tela::semColisao(TiroExp *T, float incremento, char direcao, int indiceT) {


	float posCentroX = T->getPosiCentroX(),
		posCentroY = T->getPosiCentroY(),

		dimXT = T->getDimX(),
		dimYT = T->getDimY(),
		dimXB = blocos[0]->getDimX(),
		dimYB = blocos[0]->getDimY();


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



	for (int i = 0; i < blocos.size(); i++) {
		float posBlocoX = blocos[i]->getPosiX(),
			posBlocoY = blocos[i]->getPosiY();
		if (direcao == 'd') {
			if ((((((posCentroY - 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY - 0.5*dimYT) >= posBlocoY)) || (((posCentroY + 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY + 0.5*dimYT) >= posBlocoY)))
				&& ((posCentroX + 0.65*dimYT + incremento - 1) > posBlocoX) && ((posCentroX + 0.65*dimYT + incremento - 1) < posBlocoX + dimXB))) {
				return false;

			}
		}
		else if (direcao == 'e') {
			if ((((((posCentroY - 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY - 0.5*dimYT) >= posBlocoY)) || (((posCentroY + 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY + 0.5*dimYT) >= posBlocoY)))
				&& ((posCentroX - 0.65*dimYT - incremento + 1) < posBlocoX + dimXB) && ((posCentroX - 0.65*dimYT - incremento + 1) > posBlocoX))) {
				return false;

			}
		}
		else if (direcao == 'c') {
			if ((((((posCentroX - 0.5*dimXT) <= (posBlocoX + dimXB)) && ((posCentroX - 0.5*dimXT) >= posBlocoX)) ||
				(((posCentroX + 0.5*dimYT) <= (posBlocoX + dimXB)) && ((posCentroX + 0.5*dimXT) >= posBlocoX)))
				&& ((posCentroY + 0.65*dimYT + incremento - 1) > posBlocoY) && ((posCentroY + 0.65*dimYT + incremento - 1) < posBlocoY + dimYB))) {
				return false;

			}
		}
		else if (direcao == 'b') {
			if ((((((posCentroX - 0.5*dimXT) <= (posBlocoX + dimXB)) && ((posCentroX - 0.5*dimXT) >= posBlocoX)) ||
				(((posCentroX + 0.5*dimYT) <= (posBlocoX + dimXB)) && ((posCentroX + 0.5*dimXT) >= posBlocoX)))
				&& ((posCentroY - 0.65*dimYT - incremento + 1) > posBlocoY) && ((posCentroY - 0.65*dimYT - incremento + 1) < posBlocoY + dimYB))) {
				return false;

			}
		}

	}

	// FOR PARA TANQUES
	int inicio = 0;
	int fim = tankes.size();

	if (T->getEdeInimigo()) {
		fim = 2;
	}

	if (!temP2)
		inicio = 1;

	for (int i = inicio; i < fim; i++) {
		//if (i == indiceT)continue;
		if (tankes[i]->getStatus() == 'i')
			continue;
		float posBlocoX = tankes[i]->getPosiOrigemX(),
			posBlocoY = tankes[i]->getPosiOrigemY(),
			dimXB = tankes[i]->getDimX(),
			dimYB = tankes[i]->getDimY()/*1.15*/;
		if (direcao == 'd') {
			if ((((((posCentroY - 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY - 0.5*dimYT) >= posBlocoY)) || (((posCentroY + 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY + 0.5*dimYT) >= posBlocoY)))
				&& ((posCentroX + 0.65*dimYT + incremento) > posBlocoX) && ((posCentroX + 0.65*dimYT + incremento) < posBlocoX + dimXB))) {

				tankes[i]->recebeDano(T->getPotencia());
				if (T->getEdeInimigo() == false) {

					if (T->getEP1())
						Player->recebePontos(T->getPotencia());
					else
						Player2->recebePontos(T->getPotencia());
				}

				return false;

			}
		}
		else if (direcao == 'e') {
			if ((((((posCentroY - 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY - 0.5*dimYT) >= posBlocoY)) || (((posCentroY + 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY + 0.5*dimYT) >= posBlocoY)))
				&& ((posCentroX - 0.65*dimYT - incremento) < posBlocoX + dimXB) && ((posCentroX - 0.65*dimYT - incremento) > posBlocoX))) {

				tankes[i]->recebeDano(T->getPotencia());
				if (T->getEdeInimigo() == false) {

					if (T->getEP1())
						Player->recebePontos(T->getPotencia());
					else
						Player2->recebePontos(T->getPotencia());
				}
				return false;

			}
		}
		else if (direcao == 'c') {
			if ((((((posCentroX - 0.5*dimXT) <= (posBlocoX + dimXB)) && ((posCentroX - 0.5*dimXT) >= posBlocoX)) ||
				(((posCentroX + 0.5*dimYT) <= (posBlocoX + dimXB)) && ((posCentroX + 0.5*dimXT) >= posBlocoX)))
				&& ((posCentroY + 0.65*dimYT + incremento) > posBlocoY) && ((posCentroY + 0.65*dimYT + incremento) < posBlocoY + dimYB))) {

				tankes[i]->recebeDano(T->getPotencia());
				if (T->getEdeInimigo() == false) {

					if (T->getEP1()) { Player->recebePontos(T->getPotencia()); }
					else { Player2->recebePontos(T->getPotencia()); }
				
				}
				return false;

			}
		}
		else if (direcao == 'b') {
			if ((((((posCentroX - 0.5*dimXT) <= (posBlocoX + dimXB)) && ((posCentroX - 0.5*dimXT) >= posBlocoX)) ||
				(((posCentroX + 0.5*dimYT) <= (posBlocoX + dimXB)) && ((posCentroX + 0.5*dimXT) >= posBlocoX)))
				&& ((posCentroY - 0.65*dimYT - incremento) > posBlocoY) && ((posCentroY - 0.65*dimYT - incremento) < posBlocoY + dimYB))) {

				tankes[i]->recebeDano(T->getPotencia());
				if (T->getEdeInimigo() == false) {

					if (T->getEP1())
						Player->recebePontos(T->getPotencia());
					else
						Player2->recebePontos(T->getPotencia());
				}
				return false;

			}
		}

	}
	// FOR PARA TIROS


	for (int i = 0; i < tiros.size(); i++) {
		if (i == indiceT)continue;
		if (tiros[i]->getStatus()=='i')continue;
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
void Tela::desenhaTankes() {
	glPushMatrix();
	MoveTankInimigo(0.1);
	int inicio = 0;

	if (!temP2)
		inicio = 1;

	for (int i = inicio; i < tankes.size(); i++) {
		if (tankes[i]->getStatus() == 'i' && tankesRestantes > 0 && i > 1) {
			tankesRestantes--;
			bool criou = false;
			while (!criou) {
				for (float j = 16.5; j < 360; j += 36) {
					if (entradaDisponivel(j)) {
						tankes[i] = new Tank(j, 250.5, 180, escolheTank());
						criou = true;
						break;
					}
				}
			}

		}
		else if (tankes[i]->getStatus() != 'i'){ 
			tankes[i]->desenha();
			if(i>1)Atira(i);
		}
	}
	glPopMatrix();
}
void Tela::desenhaBlocos() {
	glPushMatrix();
	for (int i = 0; i < blocos.size(); i++) {
		blocos[i]->desenha();
	}
	glPopMatrix();
}
void Tela::desenhaTiros() {
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

int Tela::retornaQtdTanks() {
	return tankes.size();
}
int Tela::retornaQtdBlocos() {
	return blocos.size();
}

void Tela::MoveTankMetodo1(Tank *t, float incremento, int indiceTank) {
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
				cout<<"\n"<<r<<"\n";
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

void Tela::MoveTankMetodo2(Tank *t, float incremento, int indiceTank) {
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

void Tela::MoveTankPlayer(char direcao, float incremento) {
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

void Tela::MoveTankInimigo(float incremento) {

	for (int i = 2; i < tankes.size(); i++) {
		if(tankes[i]->getTipo() == 3 || tankes[i]->getTipo() == 5)
		MoveTankMetodo2(tankes[i], incremento, i);
		else MoveTankMetodo1(tankes[i], incremento, i);
	}
}

void Tela::setPlayer2() {
	temP2 = true;
}

void Tela::Atira(int pos) {
	if (tankes[pos]->getTempoPraAtirar() < 0) {
		int tipo = tankes[pos]->getTipo();
		if (tipo == 1)
		{
			tiros.push_back(tankes[pos]->atira(3));
		}
		else if (tipo == 2)
		{
			tiros.push_back(tankes[pos]->atira(2));
		}
		else if (tipo == 3)
		{
			tiros.push_back(tankes[pos]->atira(2));
		}
		else if (tipo == 4)
		{
			tiros.push_back(tankes[pos]->atira(2));
		}
		else if (tipo == 5)
		{
			tiros.push_back(tankes[pos]->atira(2));
		}
		else if (tipo == 6)
		{
			tiros.push_back(tankes[pos]->atira(1));
			if (pos == 1)	tiros[tiros.size() - 1]->setEP1(true);
		}
	}
}

void Tela::desenha() {
	desenhaTankes();
	desenhaBlocos();
	desenhaTiros();
	desenhaLateral();
}

bool Tela::morreu() {
	if (temP2) {
		if (tankes[0]->getStatus() == 'i' && tankes[1]->getStatus() == 'i') {
			return true;
		}
		else return false;
	}
	else if (tankes[1]->getStatus() == 'i') {
		return true;
	}
	else return false;
}
bool Tela::gameOver() {
	if (temP2) {
		if (tankes[0]->getQtdVida() == 0 && tankes[1]->getQtdVida() == 0) {
			return true;
		}
		else return false;
	}
	else if (tankes[1]->getQtdVida() == 0) {
		return true;
	}
	else return false;
}
bool Tela::acabou() {
	if (tankesRestantes > 0) return false;
	for (int i = 2; i < tankes.size(); i++) {
		if (tankes[i]->getStatus() != 'i') {
			return false;
		}
	}
	return true;
}
bool Tela::entradaDisponivel(float x) {
	int inicio = 0;

	if (!temP2)
		inicio = 1;
	for (int i = inicio; i < tankes.size(); i++) {
		if (tankes[i]->getPosiX() <= x + 1.5 && tankes[i]->getPosiX() >= x + 1.5 -20 && tankes[i]->getPosiY() <= 252 && tankes[i]->getPosiY() >= 222) {
			return false;
		}
	}
	return true;
}

Tank* Tela::getP1() {
	return tankes[1];
}
Tank* Tela::getP2() {
	return tankes[0];
}
void Tela::setP1(Tank *t) {
	tankes[1] = t;
}
void Tela::setP2(Tank *t) {
	tankes[0] = t;
}

int Tela::escolheTank() {
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
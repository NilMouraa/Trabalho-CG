#include "Tela.h"
#include <ctime>
#include <vector>
#include <iostream>

Tela::Tela	(int numFase) {

	Player2 = new Tank(164, 1, 0, 1);
	tankes.push_back(Player2);
	temP2 = false;

	Player= new Tank(128, 1, 0, 6);
    tankes.push_back(Player);
	Tank *to = new Tank(290,25,0,3);
	tankes.push_back(to);
	Tank *to2 = new Tank(300,216,0,2);
	
	tankes.push_back(to2);
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
			
			while ((fscanf(arq, "%f %f\n",&cooX, &cooY)) != EOF)
			{
				pontoX.push_back(cooX);
				pontoY.push_back(cooY);
				qtdBlocos++;
			}
		}
		fclose(arq);
		for(int j=0;j<qtdBlocos;j++){
			blocos.push_back(new Bloco(pontoX[j]*DIM_X_BLOC,pontoY[j]*DIM_Y_BLOC, 0, DIM_X_BLOC, DIM_Y_BLOC));
		}
		
		//MoveTankMetodo1(to2, 3, 1);

}
Tela::~Tela	()
{
}



void Tela::addBloco			(double x, double y, double ang, int dimX, int dimY) {
	blocos.push_back(new Bloco(x, y, ang, dimX, dimY));
}
void Tela::addBloco			(Bloco *b) {
	blocos.push_back(b);
}
void Tela::addTankes		(double x, double y, double ang, int tipo) {
	tankes.push_back(new Tank(x, y, ang, tipo));
}
void Tela::addTankes		(Tank *t) {
	tankes.push_back(t);
}
bool Tela::semColisao		(Tank *T, float incremento, char direcao,int indiceT) {

	
	float posCentroX = T->getPosiCentroX(),
		posCentroY = T->getPosiCentroY(),

		dimXT = T -> getDimX(),
		dimYT = T -> getDimY(),
		dimXB = blocos[0]->getDimX(),
		dimYB = blocos[0]->getDimY();

	
	if (direcao == 'd') {
		if (posCentroX + 0.5*dimYT+incremento>=360) {
			return false;
		}
	}else if (direcao == 'e') {
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
				if ((  ( (    ((posCentroY - 0.5*dimXT) <= (posBlocoY + dimYB) )  &&  ((posCentroY - 0.5*dimYT) >= posBlocoY)     )     ||				  (    ((posCentroY + 0.5*dimXT) <= (posBlocoY + dimYB))   &&  ((posCentroY + 0.5*dimYT) >= posBlocoY)     )  )
					&&  ((posCentroX+0.65*dimYT+incremento-1) > posBlocoX ) && ((posCentroX + 0.65*dimYT + incremento-1) < posBlocoX+dimXB)) ) {
					return false;
					
				}
			}
			else if (direcao == 'e') {
				if ((((((posCentroY - 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY - 0.5*dimYT) >= posBlocoY)) || (((posCentroY + 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY + 0.5*dimYT) >= posBlocoY)))
					&& ((posCentroX - 0.65*dimYT - incremento+1) < posBlocoX+dimXB)&& ((posCentroX - 0.65*dimYT - incremento+1) > posBlocoX))) {
					return false;

				}
			}
			else if (direcao == 'c') {
				if ((((((posCentroX - 0.5*dimXT) <= (posBlocoX + dimXB)) && ((posCentroX - 0.5*dimXT) >= posBlocoX)) ||
					(((posCentroX + 0.5*dimYT) <= (posBlocoX + dimXB)) && ((posCentroX + 0.5*dimXT) >= posBlocoX)))
					&& ((posCentroY + 0.65*dimYT + incremento-1) > posBlocoY) && ((posCentroY + 0.65*dimYT + incremento-1) < posBlocoY+dimYB))) {
					return false;

				}
			}
			else if (direcao == 'b') {
				if ((((((posCentroX - 0.5*dimXT) <= (posBlocoX + dimXB)) && ((posCentroX - 0.5*dimXT) >= posBlocoX)) ||
					(((posCentroX + 0.5*dimYT) <= (posBlocoX + dimXB)) && ((posCentroX + 0.5*dimXT) >= posBlocoX)))
					&& ((posCentroY - 0.65*dimYT - incremento+1) > posBlocoY) && ((posCentroY - 0.65*dimYT - incremento+1) < posBlocoY + dimYB))) {
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
			float posBlocoX = tankes[i]->getPosiOrigemX(),
				posBlocoY = tankes[i]->getPosiOrigemY(),
				dimXB = tankes[i]->getDimX(),
				dimYB = tankes[i]->getDimY()*1.15;
			if (direcao == 'd') {
				if ((((((posCentroY - 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY - 0.5*dimYT) >= posBlocoY)) || (((posCentroY + 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY + 0.5*dimYT) >= posBlocoY)))
					&& ((posCentroX + 0.65*dimYT + incremento) > posBlocoX) && ((posCentroX + 0.65*dimYT + incremento) < posBlocoX + dimXB))) {
					return false;

				}
			}
			else if (direcao == 'e') {
				if ((((((posCentroY - 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY - 0.5*dimYT) >= posBlocoY)) || (((posCentroY + 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY + 0.5*dimYT) >= posBlocoY)))
					&& ((posCentroX - 0.65*dimYT - incremento) < posBlocoX + dimXB) && ((posCentroX - 0.65*dimYT - incremento) > posBlocoX))) {
					return false;

				}
			}
			else if (direcao == 'c') {
				if ((((((posCentroX - 0.5*dimXT) <= (posBlocoX + dimXB)) && ((posCentroX - 0.5*dimXT) >= posBlocoX)) ||
					(((posCentroX + 0.5*dimYT) <= (posBlocoX + dimXB)) && ((posCentroX + 0.5*dimXT) >= posBlocoX)))
					&& ((posCentroY + 0.65*dimYT + incremento) > posBlocoY) && ((posCentroY + 0.65*dimYT + incremento) < posBlocoY + dimYB))) {
					return false;

				}
			}
			else if (direcao == 'b') {
				if ((((((posCentroX - 0.5*dimXT) <= (posBlocoX + dimXB)) && ((posCentroX - 0.5*dimXT) >= posBlocoX)) ||
					(((posCentroX + 0.5*dimYT) <= (posBlocoX + dimXB)) && ((posCentroX + 0.5*dimXT) >= posBlocoX)))
					&& ((posCentroY - 0.65*dimYT - incremento) > posBlocoY) && ((posCentroY - 0.65*dimYT - incremento) < posBlocoY + dimYB))) {
					return false;

				}
			}

		}
		return true;

}

void Tela::desenhaTankes() {
	glPushMatrix();

	int inicio = 0;

	if (!temP2)
		inicio = 1;

	for (int i = inicio; i < tankes.size(); i++) {
		tankes[i]->desenha();
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
		tiros[i]->desenha();
		tiros[i]->Move(1);
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
	srand((int)time(0)); //Dê o include lá : #include <ctime>
	if (ang == 0) {
		if (semColisao(t, incremento, 'c', indiceTank)) {
			t->viraCima(incremento, true);
		}
		else {
			while (true) {
				int r = (rand() % 100) + 1;
				if (r<34 && semColisao(t, incremento, 'b', indiceTank)) {
					t->viraBaixo(incremento, true);
					break;
				}
				else if (r >= 34 && r<67 && semColisao(t, incremento, 'e', indiceTank)) {
					t->viraEsquerda(incremento, true);
					break;
				}
				else if (r >= 67 && semColisao(t, incremento, 'd', indiceTank)) {
					t->viraDireita(incremento, true);
					break;
				}
			}
		}
	}
	else if (ang == 180) {
		if (semColisao(t, incremento, 'b', indiceTank)) {
			t->viraBaixo(incremento, true);
		}
		else {
			while (true) {
				int r = (rand() % 100) + 1;
				if (r<34 && semColisao(t, incremento, 'c', indiceTank)) {
					t->viraCima(incremento, true);
					break;
				}
				else if (r >= 34 && r<67 && semColisao(t, incremento, 'e', indiceTank)) {
					t->viraEsquerda(incremento, true);
					break;
				}
				else if (r >= 67 && semColisao(t, incremento, 'd', indiceTank)) {
					t->viraDireita(incremento, true);
					break;
				}
			}
		}
	}
	else if (ang == -90) {
		if (semColisao(t, incremento, 'd', indiceTank)) {
			t->viraDireita(incremento, true);
		}
		else {
			while (true) {
				int r = (rand() % 100) + 1;
				if (r<34 && semColisao(t, incremento, 'b', indiceTank)) {
					t->viraBaixo(incremento, true);
					break;
				}
				else if (r >= 34 && r<67 && semColisao(t, incremento, 'e', indiceTank)) {
					t->viraEsquerda(incremento, true);
					break;
				}
				else if (r >= 67 && semColisao(t, incremento, 'c', indiceTank)) {
					t->viraCima(incremento, true);
					break;
				}
			}
		}
	}
	else if (ang == 90) {
		if (semColisao(t, incremento, 'e', indiceTank)) {
			t->viraEsquerda(incremento, true);
		}
		else {
			while (true) {
				int r = (rand() % 100) + 1;
				if (r<34 && semColisao(t, incremento, 'b', indiceTank)) {
					t->viraBaixo(incremento, true);
					break;
				}
				else if (r >= 34 && r<67 && semColisao(t, incremento, 'c', indiceTank)) {
					t->viraCima(incremento, true);
					break;
				}
				else if (r >= 67 && semColisao(t, incremento, 'd', indiceTank)) {
					t->viraDireita(incremento, true);
					break;
				}
			}
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

	
	if (ang == 0) {
		if (t->getPosiX() > Player->getPosiX()) {
			
			if (semColisao(t, incremento, 'e', indiceTank)) {
				t->viraEsquerda(incremento, true);
			}
		}
		else if (t->getPosiX() < Player->getPosiX()) {
			if (semColisao(t, incremento, 'd', indiceTank)) {
				t->viraDireita(incremento, true);
			}
		}
		else if (t->getPosiY() < Player->getPosiY()) {
			if (semColisao(t, incremento, 'c', indiceTank)) {
				t->viraCima(incremento, true);
			}
		}
		else if (t->getPosiY() > Player->getPosiY()) {
			if (semColisao(t, incremento, 'b', indiceTank)) {
				t->viraBaixo(incremento, true);
			}
		}
		

	}
	else if (ang == 180) {
		if (t->getPosiX() > Player->getPosiX()) {
			if (semColisao(t, incremento, 'e', indiceTank)) {
				t->viraEsquerda(incremento, true);
			}
		}
		else if (t->getPosiX() < Player->getPosiX()) {
			if (semColisao(t, incremento, 'd', indiceTank)) {
				t->viraDireita(incremento, true);
			}
		}
		else if (t->getPosiY() < Player->getPosiY()) {
			if (semColisao(t, incremento, 'c', indiceTank)) {
				t->viraCima(incremento, true);
			}
		}
		else if (t->getPosiY() > Player->getPosiY()) {
			if (semColisao(t, incremento, 'b', indiceTank)) {
				t->viraBaixo(incremento, true);
			}
		}
		
	}
	else if (ang == -90) {
		if (t->getPosiX() > Player->getPosiX()) {
			if (semColisao(t, incremento, 'e', indiceTank)) {
				t->viraEsquerda(incremento, true);
			}
		}
		else if (t->getPosiX() < Player->getPosiX()) {
			if (semColisao(t, incremento, 'd', indiceTank)) {
				t->viraDireita(incremento, true);
			}
		}
		else if (t->getPosiY() < Player->getPosiY()) {
			if (semColisao(t, incremento, 'c', indiceTank)) {
				t->viraCima(incremento, true);
			}
		}
		else if (t->getPosiY() > Player->getPosiY()) {
			if (semColisao(t, incremento, 'b', indiceTank)) {
				t->viraBaixo(incremento, true);
			}
		}
		 
	}
	else if (ang == 90) {
		if (t->getPosiX() > Player->getPosiX()) {
			if (semColisao(t, incremento, 'e', indiceTank)) {
				t->viraEsquerda(incremento, true);
			}
		}
		else if (t->getPosiX() < Player->getPosiX()) {
			if (semColisao(t, incremento, 'd', indiceTank)) {
				t->viraDireita(incremento, true);
			}
		}
		else if (t->getPosiY() < Player->getPosiY()) {
			if (semColisao(t, incremento, 'c', indiceTank)) {
				t->viraCima(incremento, true);
			}
		}
		else if (t->getPosiY() > Player->getPosiY()) {
			if (semColisao(t, incremento, 'b', indiceTank)) {
				t->viraBaixo(incremento, true);
			}
		}
		
	}
}

void Tela::MoveTankPlayer(char direcao, float incremento){
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

void Tela::MoveTankInimigo(float incremento){

}

void Tela::setPlayer2() {
	temP2 = true;
}

void Tela::Atira(int pos){
	int tipo=tankes[pos]->getTipo();
	if(tipo==1)
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
	}
	
}

void Tela::desenha() {
	desenhaTankes();
	desenhaBlocos();
	desenhaTiros();
}
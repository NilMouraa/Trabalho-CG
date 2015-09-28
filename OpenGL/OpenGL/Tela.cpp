#include "Tela.h"
#include <vector>

Tela::Tela	(int numFase) {
	Tank *to = new Tank(300,25,0,3);
	tankes.push_back(to);
	Tank *to2 = new Tank(300,200,0,2);
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

	cout << "\nANALISA COLISAO";

		
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
		for (int i = 0; i < tankes.size(); i++) {
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
	for (int i = 0; i < tankes.size(); i++) {
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

int Tela::retornaQtdTanks() {
	return tankes.size();
}
int Tela::retornaQtdBlocos() {
	return blocos.size();
}

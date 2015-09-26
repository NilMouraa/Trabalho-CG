#include "Tela.h"

Tela::Tela	() {
	Tank *to = new Tank(150,100,0,3);
	tankes.push_back(to);
	float DIM_X_BLOC = 18;
	float DIM_Y_BLOC = 18;
	blocos.push_back(new Bloco(50, 50, 0, DIM_X_BLOC, DIM_Y_BLOC));
	blocos.push_back (new Bloco(50, 68, 0, DIM_X_BLOC, DIM_Y_BLOC));
	blocos.push_back( new Bloco(50, 86, 0, DIM_X_BLOC, DIM_Y_BLOC));
	blocos.push_back (new Bloco(50, 104, 0, DIM_X_BLOC, DIM_Y_BLOC));
	blocos.push_back (new Bloco(50, 122, 0, DIM_X_BLOC, DIM_Y_BLOC));
	blocos.push_back (new Bloco(50, 140, 0, DIM_X_BLOC, DIM_Y_BLOC));
	blocos.push_back( new Bloco(50, 158, 0, DIM_X_BLOC, DIM_Y_BLOC));



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
					&&  ((posCentroX+0.65*dimYT+incremento) > posBlocoX ) && ((posCentroX + 0.65*dimYT + incremento) < posBlocoX+dimXB)) ) {
					return false;
					
				}
			}
			else if (direcao == 'e') {
				if ((((((posCentroY - 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY - 0.5*dimYT) >= posBlocoY)) || (((posCentroY + 0.5*dimXT) <= (posBlocoY + dimYB)) && ((posCentroY + 0.5*dimYT) >= posBlocoY)))
					&& ((posCentroX - 0.65*dimYT - incremento) < posBlocoX+dimXB)&& ((posCentroX - 0.65*dimYT - incremento) > posBlocoX))) {
					return false;

				}
			}
			else if (direcao == 'c') {
				if ((((((posCentroX - 0.5*dimXT) <= (posBlocoX + dimXB)) && ((posCentroX - 0.5*dimXT) >= posBlocoX)) ||
					(((posCentroX + 0.5*dimYT) <= (posBlocoX + dimXB)) && ((posCentroX + 0.5*dimXT) >= posBlocoX)))
					&& ((posCentroY + 0.65*dimYT + incremento) > posBlocoY) && ((posCentroY + 0.65*dimYT + incremento) < posBlocoY+dimYB))) {
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
	for (int i = 0; i < tankes.size(); i++) {
		tankes[i]->desenha();
	}
}
void Tela::desenhaBlocos() {
	for (int i = 0; i < blocos.size(); i++) {
		blocos[i]->desenha();
	}
}

int Tela::retornaQtdTanks() {
	return tankes.size();
}
int Tela::retornaQtdBlocos() {
	return blocos.size();
}

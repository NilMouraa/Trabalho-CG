#include "Tela.h"

Tela::Tela	() {

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
bool Tela::TemColisao		(Tank T) {

	cout << "\nANALISA COLISAO";

	bool colideTank  = false;
	bool colideBloco = false;

		for (int i = 0; i < tankes.size(); i++) {
			if ((T.getPosiX() == tankes[i]->getPosiX()) || (T.getPosiY() == tankes[i]->getPosiY()))
			{
				cout << "\nColidiu com Tank";
				colideTank = true;
				
				return true;
				break;
			}
		}
	if(!colideTank)
		for (int i = 0; i < blocos.size(); i++) {
			if ((T.getPosiX() == blocos[i]->getPosiX()) || (T.getPosiY() == blocos[i]->getPosiY())) {
				
				cout << "\nColidiu com bloco";
				colideBloco = true;

				return true;
				break;
			}
		}
	if (!(colideBloco && colideTank)) {
		cout << "\nNão Colidiu";
		return false;
	}
}/*
void Tela::aplicaExplosão	(float x, float y, float ang, int incM, float cresc) {
	E = new Explosao(x, y, ang, incM, cresc);
	E->desenha();
}*/
void Tela::desenhaTankes	() {
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

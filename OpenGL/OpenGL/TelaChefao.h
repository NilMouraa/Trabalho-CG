#ifndef TelaChefao_H
#define TelaChefao_H
#include <vector>
#include "Tank.h"
#include "Bloco.h"
#include "Explosao.h"
#include "Chefao.h"
class TelaChefao
{
private:
	Chefao *boss;
	Tank *Player, *Player2;
	vector <TiroExp*> tiros;
	Explosao			*E;
	bool temP2;
	int numeroFase;
public:
	TelaChefao(int numFase);
	void renderBitmapString(float x, float y, void *font, const char *string);
	void desenhaLateral();
	bool semColisao(Tank *tanque, float incremento, char direcao, int indiceT);
	bool semColisao(TiroExp *tExp, float incremento, char direcao, int indiceT);
	bool morreu();
	bool gameOver();
	bool acabou();
	Tank* getP1();
	Tank* getP2();
	void desenhaTankes();
	void desenhaTiros();
	void desenha();
	void MoveTankMetodo1(Tank *t, float incremento, int indiceTank);
	void MoveTankMetodo2(Tank *t, float incremento, int indiceTank);
	void MoveTankPlayer(char direcao, float incremento);
	void MoveTankInimigo(float incremento);
	void setPlayer2();
	void Atira(int pos);
	void setP1(Tank *t);
	void setP2(Tank *t);
	int escolheTank();

	~TelaChefao();
};
#endif

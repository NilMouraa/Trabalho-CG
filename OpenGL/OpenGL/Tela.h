#ifndef TELA_H
#define TELA_H
#include <vector>
#include "Tank.h"
#include "Bloco.h"
#include "Explosao.h"
class Tela
{
private: 
	vector <Tank* > tankes;
	Tank *Player, *Player2;
	vector <Bloco*> blocos;
	vector <TiroExp*> tiros;
	Explosao			*E;
	bool temP2;
	int numeroFase;
	int tankesRestantes;
public:
	Tela(int numFase);
	void renderBitmapString(float x, float y, void *font, const char *string);
	void desenhaLateral();
	void addBloco		(double x, double y, double ang, int dimX, int dimY);
	void addBloco		(Bloco *b);
	void addTankes		(double x, double y, double ang, int tipo);
	void addTankes		(Tank *t);
	void aplicaExplosão	(float x, float y, float ang, int incM, float cresc);
	bool semColisao		(Tank *tanque, float incremento, char direcao,int indiceT);
	bool semColisao		(TiroExp *tExp, float incremento, char direcao, int indiceT);
	bool morreu();
	bool gameOver();
	bool entradaDisponivel(float x);
	bool acabou();
	Tank* getP1();
	Tank* getP2();
	int retornaQtdTanks	();
	int retornaQtdBlocos();
	void desenhaTankes  ();
	void desenhaBlocos	();
	void desenhaTiros	();
	void desenha		();
	void MoveTankMetodo1(Tank *t, float incremento, int indiceTank);
	void MoveTankMetodo2(Tank *t, float incremento, int indiceTank);
	void MoveTankPlayer (char direcao, float incremento);
	void MoveTankInimigo(float incremento);
	void setPlayer2();
	void Atira(int pos);
	void setP1(Tank *t);
	void setP2(Tank *t);
	int escolheTank();
	
	~Tela();
};
#endif

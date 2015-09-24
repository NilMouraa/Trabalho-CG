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
	vector <Bloco*> blocos;
	Explosao			*E;
public:
	Tela();
	 
	void addBloco		(double x, double y, double ang, int dimX, int dimY);
	void addBloco		(Bloco *b);
	void addTankes		(double x, double y, double ang, int tipo);
	void addTankes		(Tank *t);
	void aplicaExplosão	(float x, float y, float ang, int incM, float cresc);
	bool TemColisao		(Tank T);
	int retornaQtdTanks	();
	int retornaQtdBlocos();
	void desenhaTankes  ();
	void desenhaBlocos	();
	
	~Tela();
};
#endif

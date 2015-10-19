#pragma once
class TelaChefao
{
private:
	int numChefao;

public:
	TelaChefao(int numChefao);
	~TelaChefao();

	void desenha();
	bool morreu();
	bool gameOver();
	bool acabou();
	
};


#ifndef BRESENHAM_H
#define BRESENHAM_H

class Bresenham;

#ifdef _WIN32
#include <windows.h>
#endif
#include <gl/glut.h>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

/*
Classe usada para guardar funcoes uteis mas que
nao pertencem a uma classe em especifico
*/


class Bresenham
{
private:
	void static desenha(int ix, int iy);
	void static setPixel(int x, int y);
	

public:
	Bresenham();
	~Bresenham();

	vector<string> static split(const string &s, char delim);
	void static elipsePreenchida(int xc, int yc, int rx, int ry);
	void static elipse(float xc, float yc, float rx, float ry);
	void static linha(int x0, int y0, int x1, int y1);
	void static circulo(int xc, int yc, int r);
	void static retangulo(int x0, int y0, int x1, int y1);
	
};

#endif
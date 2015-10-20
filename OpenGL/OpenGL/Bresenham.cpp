#include "Bresenham.h"



Bresenham::Bresenham()
{
}

Bresenham::~Bresenham()
{
}



//
//vector<string> Bresenham::split(const string &s, char delim)
//{
//	vector<string> elems;
//	stringstream ss(s);
//	string item;
//	while (getline(ss, item, delim)) {
//		elems.push_back(item);
//	}
//	return elems;
//}
//

void Bresenham::setPixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
}

void Bresenham::linha(int x0, int y0, int x1, int y1) {
	int dx = abs(x1 - x0); //diferenca absoluta entre xFinal e xInicial
	int sx = x0<x1 ? 1 : -1; //modificador de sinal de x, denota se x cresce ou descresce

	int dy = abs(y1 - y0); //diferenca absoluta entre yFinal e yInicial
	int sy = y0<y1 ? 1 : -1; //modificador de sinal de y, denota se y cresce ou descresce

	int erro = (dx>dy ? dx : -dy) / 2; //baseando-se na maior diferenca, define-se o erro inicial
	int erroTemp; //erro de cada iteracao

	while (true) {
		Bresenham::setPixel(x0, y0); //imprime ponto

		if ((x0 == x1) && (y0 == y1))
			break; //ponto final atingido, encerra algoritmo

		erroTemp = erro; //atualiza erro

		if (erroTemp > -dx) {
			erro -= dy; //decrementa erro com a diferenca absoluta entre yFinal e yInicial
			x0 += sx; //incrementa (ou decrementa) x
		}

		if (erroTemp < dy) {
			erro += dx; //incrementa erro com a diferenca absoluta entre xFinal e xInicial
			y0 += sy; //incrementa (ou decrementa) y
		}
	}
}


void Bresenham::elipsePreenchida(int xc, int yc, int rx, int ry)
{
	int wx, wy;
	int thresh;
	int asq = rx * rx;
	int bsq = ry * ry;
	int xa, ya;
	linha(xc, yc + ry, xc, yc - ry);
	wx = 0;
	wy = ry;
	xa = 0;
	ya = asq * 2 * ry;
	thresh = asq / 4 - asq * ry;
	while (xa < ya) {
		thresh += xa + bsq;
		if (thresh >= 0) {
			ya -= asq * 2;
			thresh -= ya;
			wy--;
		}
		xa += bsq * 2;
		wx++;
		if (xa >= ya)
			break;
		linha(xc + wx, yc - wy, xc - wx, yc - wy);
		linha(xc + wx, yc + wy, xc - wx, yc + wy);
	}
	linha(xc + rx, yc, xc - rx, yc);
	wx = rx;
	wy = 0;
	xa = bsq * 2 * rx;
	ya = 0;
	thresh = bsq / 4 - bsq * rx;
	while (ya <= xa) {
		thresh += ya + asq;
		if (thresh >= 0) {
			xa -= bsq * 2;
			thresh = thresh - xa;
			wx--;
		}
		ya += asq * 2;
		wy++;
		if (ya > xa)
			break;
		linha(xc + wx, yc - wy, xc - wx, yc - wy);
		linha(xc + wx, yc + wy, xc - wx, yc + wy);
	}
}

void Bresenham::elipse(float xc, float yc, float rx, float ry)
{
	float x, y, rx2, ry2, p1, p2;
	setPixel(xc, yc);
	x = 0;
	y = ry;
	rx2 = pow(rx, 2);
	ry2 = pow(ry, 2);
	p1 = ry2 - (rx2*ry) + (0.25*rx2);
	while ((ry2*x)<(rx2*y))
	{
		if (p1<0)
		{
			x++;
			p1 = p1 + (2 * ry2*x) + ry2;
		}
		else
		{
			x++; y--;
			p1 = p1 + (2 * ry2*x) - (2 * rx2*y) + ry2;
		}
		setPixel(xc + x, yc + y);
		setPixel(xc - x, yc + y);
		setPixel(xc + x, yc - y);
		setPixel(xc - x, yc - y);
	}
	p2 = (ry2)*pow((x + 0.5), 2) + (rx2)*pow((y - 1), 2) - (rx2*ry2);
	while (y>0)
	{
		if (p2>0)
		{
			y--;
			p2 = p2 - (2 * rx2*y) + rx2;
		}
		else
		{
			x++; y--;
			p2 = p2 + (2 * ry2*x) - (2 * rx2*y) + rx2;
		}
		setPixel(xc + x, yc + y);
		setPixel(xc - x, yc + y);
		setPixel(xc + x, yc - y);
		setPixel(xc - x, yc - y);
	}
}

void Bresenham::circulo(int xc, int yc, int r) {

	int x = 0;
	int y = r;

	int p = 1 - r;

	Bresenham::setPixel(xc + x, yc + y);
	Bresenham::setPixel(xc - x, yc + y);
	Bresenham::setPixel(xc + x, yc - y);
	Bresenham::setPixel(xc - x, yc - y);
	Bresenham::setPixel(xc + y, yc + x);
	Bresenham::setPixel(xc - y, yc + x);
	Bresenham::setPixel(xc + y, yc - x);
	Bresenham::setPixel(xc - y, yc - x);

	while (x < y) {
		x++;
		if (p < 0) {
			p = p + 2 * x + 1;
		}
		else {
			y--;
			p = p + 2 * (x - y) + 1;
		}

		Bresenham::setPixel(xc + x, yc + y);
		Bresenham::setPixel(xc - x, yc + y);
		Bresenham::setPixel(xc + x, yc - y);
		Bresenham::setPixel(xc - x, yc - y);
		Bresenham::setPixel(xc + y, yc + x);
		Bresenham::setPixel(xc - y, yc + x);
		Bresenham::setPixel(xc + y, yc - x);
		Bresenham::setPixel(xc - y, yc - x);
	}
	// glEnd();
}

void Bresenham::retangulo(int x0, int y0, int x1, int y1)
{
	linha(x0, y0, x1, y0);
	linha(x1, y0, x1, y1);
	linha(x1, y1, x0, y1);
	linha(x0, y0, x0, y1);
}



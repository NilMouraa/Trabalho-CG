#include "Tutorial.h"
#include "Bloco.h"
Tutorial::Tutorial() {}
void Tutorial::desenhaBlocos() {
	glPushMatrix();

	for (int x = 0; x <= 342; x += 18) {
		for (int y = 0; y <= 198; y += 36) {

			Bloco *b = new Bloco(x, y, 0, 18, 18);
			b->desenha();
			if (x == 0 || x == 18 || x == 324 || x == 126 || x == 342) {
				Bloco *b1 = new Bloco(x, y+18, 0, 18, 18);
				b1->desenha();
			}
		}
		Bloco *b = new Bloco(x, 234, 0, 18, 18);
		b->desenha();

		Bloco *b2 = new Bloco(x, 18, 0, 18, 18);
		b2->desenha();
		if (x == 0 || x == 18 || x == 324 || x == 126 || x == 342) {
			Bloco *b1 = new Bloco(x, 216, 0, 18, 18);
			b1->desenha();
		}

	}
	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(252,18);
	glVertex2f(252,36);
	glVertex2f(324,36);
	glVertex2f(324,18);
	glEnd();
	glPopMatrix();
}
void Tutorial::desenha() {
	desenhaBlocos();
	glPushMatrix();
	glColor3f(1,1,1);
	int font = (int)GLUT_BITMAP_TIMES_ROMAN_24;
	char *texto = "O B J E T I V O";
	renderBitmapString(52.5, 214, (void *)font, texto);
	texto = "O B J E T I V O";
	renderBitmapString(51.5, 214, (void *)font, texto);
	texto = "O B J E T I V O";
	renderBitmapString(52, 214.5, (void *)font, texto);
	texto = "O B J E T I V O";
	renderBitmapString(52, 213.5, (void *)font, texto);
	glColor3f(1, 0, 0);
	texto = "O B J E T I V O";
	renderBitmapString(52, 214, (void *)font, texto);
	texto = "O B J E T I V O";
	renderBitmapString(52.2, 214, (void *)font, texto);
	texto = "O B J E T I V O";
	renderBitmapString(52, 214.2, (void *)font, texto);
	font = (int)GLUT_BITMAP_9_BY_15;
	texto = "O ultimo tanque do batalhao, T.J, quer vencer a ";
	renderBitmapString(154, 226, (void *)font, texto);
	texto = "guerra e vingar seus companheiros destruidos pelos";
	renderBitmapString(154, 220, (void *)font, texto);
	texto = "LENGS. Para honrar a memoria deles, ele tem de";
	renderBitmapString(154, 214, (void *)font, texto);
	texto = "destruir qualquer um que entrar em seu caminho.";
	renderBitmapString(154, 208, (void *)font, texto);
	texto = "Pressione a tecla direcional -> para ir a direita ";
	renderBitmapString(154, 173, (void *)font, texto);
	texto = "Pressione a tecla direcional <- para ir a esquerda ";
	renderBitmapString(154, 167, (void *)font, texto);
	texto = "Pressione a tecla direcional ^ para ir para cima ";
	renderBitmapString(154, 137, (void *)font, texto);
	texto = "Pressione a tecla direcional v para ir para baixo ";
	renderBitmapString(154, 131, (void *)font, texto);
	texto = "Pressione \"1\" para escolher uma arma comum  ";
	renderBitmapString(154, 100, (void *)font, texto);
	texto = "E \"2\" se for uma arma especial";
	renderBitmapString(154, 94, (void *)font, texto);
	texto = "Use a barra de espaco para atirar.";
	renderBitmapString(154, 65, (void *)font, texto);
	texto = "Municao Especial e Vida sao deixadas por inimigos";
	renderBitmapString(154, 59, (void *)font, texto);
	font = (int)GLUT_BITMAP_TIMES_ROMAN_24;
	glColor3f(1, 1, 1);
	texto = "V O L T A R";
	renderBitmapString(264.5, 23, (void *)font, texto);
	texto = "V O L T A R";
	renderBitmapString(263.5, 23, (void *)font, texto);
	texto = "V O L T A R";
	renderBitmapString(264, 23.5, (void *)font, texto);
	texto = "V O L T A R";
	renderBitmapString(264, 22.5, (void *)font, texto);
	glColor3f(1, 0, 0);
	texto = "V O L T A R";
	renderBitmapString(264, 23, (void *)font, texto);
	texto = "V O L T A R";
	renderBitmapString(264.2, 23, (void *)font, texto);
	texto = "V O L T A R";
	renderBitmapString(264, 23.2, (void *)font, texto);
	glPopMatrix();
}
void Tutorial::renderBitmapString(float x, float y, void *font, const char *string) {
	const char *c;
	glRasterPos2f(x, y);
	for (c = string; *c != '\0'; c++) {
		glutBitmapCharacter(font, *c);
	}
}
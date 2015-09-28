#include "Tutorial.h"
#include "Bloco.h"
#include "Tank.h"
Tutorial::Tutorial() {}
void Tutorial::desenhaSeta(float posiX,float posiY,float angulo){
	float altura=10;
	float comprimento=10;
	glPushMatrix();
	glTranslatef(posiX,posiY,0);
	glRotatef(angulo,0,0,1);
	glColor3f(1,1,1);

		glBegin(GL_LINE_LOOP);
			glVertex2f(-0.5*comprimento,0.25*altura);
			glVertex2f(0,0.25*altura);
			glVertex2f(0,0.5*altura);
			glVertex2f(0.5*comprimento,0);
			glVertex2f(0,-0.5*altura);
			glVertex2f(0,-0.25*altura);
			glVertex2f(-0.5*comprimento,-0.25*altura);
		glEnd();
		glBegin(GL_LINE_LOOP);
			glVertex2f(-0.7*comprimento,0.7*altura);
			glVertex2f(0.7*comprimento,0.7*altura);
			glVertex2f(0.7*comprimento,-0.7*altura);
			glVertex2f(-0.7*comprimento,-0.7*altura);
		glEnd();

	glPopMatrix();
}
void Tutorial::desenhaTank(float posiX,float posiY,float angulo){
	glPushMatrix();
		
	Tank *t=new Tank(posiX,posiY,angulo,6);
	t->desenha();

	glPopMatrix();
}
void Tutorial::desenhaHpExtra(float posiX,float posiY){
	float altura=10;
	float comprimento=10;
	glPushMatrix();
	glTranslatef(posiX,posiY,0);
	glColor3f(1,0,0);
	glBegin(GL_POLYGON);
		glVertex2f(-0.7*comprimento,0.35*altura);
		glVertex2f(0.7*comprimento,0.35*altura);
		glVertex2f(0.7*comprimento,-0.35*altura);
		glVertex2f(-0.7*comprimento,-0.35*altura);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(-0.35*comprimento,0.7*altura);
		glVertex2f(0.35*comprimento,0.7*altura);
		glVertex2f(0.35*comprimento,-0.7*altura);
		glVertex2f(-0.35*comprimento,-0.7*altura);
	glEnd();
	glColor3f(1,1,1);
	glBegin(GL_LINE_LOOP);
			glVertex2f(-0.7*comprimento,0.7*altura);
			glVertex2f(0.7*comprimento,0.7*altura);
			glVertex2f(0.7*comprimento,-0.7*altura);
			glVertex2f(-0.7*comprimento,-0.7*altura);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(-0.7*comprimento,0.35*altura);
		glVertex2f(-0.35*comprimento,0.35*altura);
		glVertex2f(-0.35*comprimento,0.7*altura);
		glVertex2f(0.35*comprimento,0.7*altura);
		glVertex2f(0.35*comprimento,0.35*altura);
		glVertex2f(0.7*comprimento,0.35*altura);
		glVertex2f(0.7*comprimento,-0.35*altura);
		glVertex2f(0.35*comprimento,-0.35*altura);
		glVertex2f(0.35*comprimento,-0.7*altura);
		glVertex2f(-0.35*comprimento,-0.7*altura);
		glVertex2f(-0.35*comprimento,-0.35*altura);
		glVertex2f(-0.7*comprimento,-0.35*altura);
	glEnd();
	glPopMatrix();
}
void Tutorial::desenhaArmaEspecial(float posiX,float posiY){
	float altura=10;
	float comprimento=10;
	glPushMatrix();
	glTranslatef(posiX,posiY,0);
	glColor3f(0,0,1);
	glBegin(GL_POLYGON);
		glVertex2f(0,0.4*altura);
		glVertex2f(0.7*comprimento,0.4*altura);
		glVertex2f(0.7*comprimento,-0.4*altura);
		glVertex2f(0,-0.4*altura);
	glEnd();
	glColor3f(0.3,0.3,0.3);
	glBegin(GL_POLYGON);
		glVertex2f(-0.7*comprimento,0.7*altura);
		glVertex2f(-0.4*comprimento,0.7*altura);
		glVertex2f(-0.4*comprimento,0.4*altura);
		glVertex2f(-0.7*comprimento,0.4*altura);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(-0.7*comprimento,-0.4*altura);
		glVertex2f(-0.7*comprimento,0.4*altura);
		glVertex2f(0,0.4*altura);
		glVertex2f(0,-0.4*altura);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(-0.7*comprimento,-0.4*altura);
		glVertex2f(-0.4*comprimento,-0.4*altura);
		glVertex2f(-0.4*comprimento,-0.7*altura);
		glVertex2f(-0.7*comprimento,-0.7*altura);
	glEnd();
	glColor3f(1,1,1);
	glBegin(GL_LINE_LOOP);
			glVertex2f(-0.7*comprimento,0.7*altura);
			glVertex2f(0.7*comprimento,0.7*altura);
			glVertex2f(0.7*comprimento,-0.7*altura);
			glVertex2f(-0.7*comprimento,-0.7*altura);
		glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(-0.7*comprimento,0.7*altura);
		glVertex2f(-0.4*comprimento,0.7*altura);
		glVertex2f(-0.4*comprimento,0.4*altura);
		glVertex2f(0,0.4*altura);
		glVertex2f(0,-0.4*altura);
		glVertex2f(-0.4*comprimento,-0.4*altura);
		glVertex2f(-0.4*comprimento,-0.7*altura);
		glVertex2f(-0.7*comprimento,-0.7*altura);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(0,0.4*altura);
		glVertex2f(0.7*comprimento,0.4*altura);
		glVertex2f(0.7*comprimento,-0.4*altura);
		glVertex2f(0,-0.4*altura);
	glEnd();
	glPopMatrix();
}
void Tutorial::desenhaObjetos(){
	glPushMatrix();
	desenhaSeta(47,171,0);
	desenhaTank(57,178.5,-90);
	desenhaSeta(94,171,180);
	desenhaTank(122,163.5,90);

	desenhaSeta(47,135,90);
	desenhaTank(57,127.5,0);
	desenhaSeta(94,135,-90);
	desenhaTank(122,142.5,180);

	desenhaArmaEspecial(90,63);
	desenhaHpExtra(110,63);
	glPopMatrix();
}
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
	desenhaObjetos();
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
	texto = "Municao Especial, HP extra sao deixados por inimigos";
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
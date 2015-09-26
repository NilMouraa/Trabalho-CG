#include "Tutorial.h"
Tutorial::Tutorial(){}
void Tutorial::desenha(){
	cout << "EMTREI TUTO";
	glPushMatrix();
	int font=(int)GLUT_BITMAP_HELVETICA_18;
	char *texto="Tutorial";
	renderBitmapString(100,180,(void *)font,texto);
	font=(int)GLUT_BITMAP_9_BY_15;
	texto="Como ultimo tanque do batalhao, Jiraia quer vencer a guerra";
	renderBitmapString(100,160,(void *)font,texto);
	texto="e vingar seus companheiros destruidos pelos LENGS. ";
	renderBitmapString(100,150,(void *)font,texto);
	texto="Para honrar a memoria deles, ele terá de destruir todos  ";
	renderBitmapString(100,140,(void *)font,texto);
	texto="e qualquer um que entrar no seu caminho. ";
	renderBitmapString(100,130,(void *)font,texto);
	texto="Para move-lo, utilize as teclas direcionais:";
	renderBitmapString(100,120,(void *)font,texto);
	texto="Pressione a tecla direcional -> para mover-lo para a direita ";
	renderBitmapString(100,110,(void *)font,texto);
	texto="Pressione a tecla direcional <- para mover-lo para a esquerda ";
	renderBitmapString(100,100,(void *)font,texto);
	texto="Pressione a tecla direcional | para mover-lo para cima ";
	renderBitmapString(100,90,(void *)font,texto);
	texto="Pressione a tecla direcional | para mover-lo para baixo ";
	renderBitmapString(100,80,(void *)font,texto);
	texto="Pressione \"1\" para escolher uma arma comum  ";
	renderBitmapString(100,70,(void *)font,texto);
	texto="E \"2\" se for uma arma especial";
	renderBitmapString(100,60,(void *)font,texto);
	texto="Use a tecla de espaco para atirar";
	renderBitmapString(100,50,(void *)font,texto);
	glPopMatrix();
}
void Tutorial::renderBitmapString(float x, float y, void *font,const char *string){
    const char *c;
    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
} 
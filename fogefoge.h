#ifndef FOFEFOGE_H
#define FOFEFOGE_H
#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'


#include "mapa.h"

extern MAPA m; // Declaração da variável global MAPA m

int acabou();
void mover(char direcao);
int ehdirecao(char direcao);
void fantasmas();

#endif

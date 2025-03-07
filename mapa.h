#ifndef MAPA_H
#define MAPA_H

typedef struct mapa {
    char** matriz;
    int linhas;
    int colunas;
} MAPA;

typedef struct posicao
{
    int x;
    int y;
} POSICAO;



void liberarmapa(MAPA* m);
void lermapa(MAPA* m);
void alocarmemoriamapa(MAPA* m);
void imprimirmapa(MAPA* m);
void encontrarmapa(MAPA* m, POSICAO* p, char c);

#endif
#ifndef MAPA_H
#define MAPA_H
#define HEROI '@'
#define FANTASMA 'F'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'

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
int ehvalida(MAPA* m, int x, int y );
int ehvazia(MAPA* m, int x, int y);
void andanomapa(MAPA *m, int x_origem, 
    int y_origem, int x_destino, int y_destino);
    void copiamapa(MAPA* destino, MAPA* origem);
#endif
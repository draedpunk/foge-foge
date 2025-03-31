#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"


void andanomapa(MAPA *m, int x_origem,int y_origem, 
    int x_destino, int y_destino){

    char personagem = m->matriz[x_origem][y_origem];
    m->matriz[x_destino][y_destino] = personagem;
    m->matriz[x_origem][y_origem] = VAZIO;
}

int ehvalida(MAPA* m, int x, int y ){
    if(x < 0 || x >= m->linhas){
        return 0;
    }
    if (y < 0 || y >= m->colunas){
        return 0;
    }
    return 1;
} 

int ehvazia(MAPA* m, int x, int y){
    return m->matriz[x][y] == VAZIO
        || m->matriz[x][y] == ' ';
}

void encontrarmapa(MAPA* m, POSICAO* p, char c){
    for (int i = 0; i < m->linhas; i++) {
        for (int j = 0; j < m->colunas; j++) {
            if (m->matriz[i][j] == c) {
                p->x = i;
                p->y = j; // deve ser 'y = j' e não 'j = i'
                //break;
                return;
            }
        }
    }

}

void alocarmemoriamapa(MAPA* m) {
    // Alocando memória para criar diferentes tamanhos de mapas
    m->matriz = malloc(sizeof(char*) * m->linhas); // Alocando espaço para as linhas
    for (int i = 0; i < m->linhas; i++) {
        m->matriz[i] = malloc(sizeof(char) * (m->colunas + 1)); // Alocando espaço para as colunas
    }
}

void lermapa(MAPA* m) {
    FILE* f;

    f = fopen("mapa.txt", "r+");
    if (f == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    fscanf(f, "%d %d", &m->linhas, &m->colunas); // Lê as dimensões do mapa

    alocarmemoriamapa(m);
    
    for (int i = 0; i < m->linhas; i++) {
        fscanf(f, "%s", m->matriz[i]); // Lê cada linha do mapa
    }

    fclose(f);
}

void liberarmapa(MAPA* m) {
    // Liberando os espaços que foram alocados
    for (int i = 0; i < m->linhas; i++) {
        free(m->matriz[i]);
    }
    free(m->matriz);
}

void imprimirmapa(MAPA* m) {
    for (int i = 0; i < m->linhas; i++) {
        printf("%s\n", m->matriz[i]); // Imprime o mapa
    }
}
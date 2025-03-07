// alocando memoria dinamicamente
#include <stdio.h>
#include <stdlib.h>

int main(){
    int** matriz;
    int linhas = 5;
    int colunas = 10;

    matriz = malloc(sizeof(int*) * linhas);
    for (int i = 0; i < linhas; i++){
        matriz[i] = malloc(sizeof(int) * (colunas));
    }

    for (int i = 0; i<linhas; i++){
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
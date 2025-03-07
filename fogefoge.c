#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"
#include "mapa.h"

MAPA m;  // Definição da variável global, deve ser feita apenas aqui.
POSICAO heroi;

int acabou() {
    return 0; // Altere esta condição de saída conforme a lógica do jogo
}

void mover(char direcao) {
    // Marca a posição antiga como vazio
    m.matriz[heroi.x][heroi.y] = '.';
    
    // Movimentando o herói
    switch (direcao) {
        case 'a': // Esquerda
            if (heroi.y > 0) m.matriz[heroi.x][heroi.y-1] = '@'; // Verifica se está dentro dos limites
            heroi.y--;
            break;
    
        case 'w': // Cima
            if (heroi.x > 0) m.matriz[heroi.x-1][heroi.y] = '@'; // Verifica se está dentro dos limites
            heroi.x--;
            break;

        case 's': // Baixo
            if (heroi.x < m.linhas - 1) m.matriz[heroi.x+1][heroi.y] = '@'; // Verifica se está dentro dos limites
            heroi.x++;
            break;

        case 'd': // Direita
            if (heroi.y < m.colunas - 1) m.matriz[heroi.x][heroi.y+1] = '@'; // Verifica se está dentro dos limites
            heroi.y++;
            break;
    }
}

int main() {
    lermapa(&m);
    encontrarmapa(&m, &heroi, '@');

    do {
        imprimirmapa(&m);
        char comando;
        printf("Informe o proximo comando:\n");
        scanf(" %c", &comando); // Recebe o comando do usuário
        mover(comando); // Move o herói conforme o comando
    } while (!acabou());

    liberarmapa(&m); // Libera a memória após o jogo terminar

    return 0;
}
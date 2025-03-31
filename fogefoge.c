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
    // validar entrada da usuario
    if(direcao != 'a' &&
        direcao != 'w' &&
        direcao != 's' &&
        direcao != 'd') {
            return; // mata a função void
    }

    int proximo_x = heroi.x;
    int proximo_y = heroi.y;
    
    // Movimentando o herói
    switch (direcao) {

        case 'a': // Esquerda
            proximo_y--;
            break;
    
        case 'w': // Cima
            proximo_x--;
            break;

        case 's': // Baixo
            proximo_x++;
            break;

        case 'd': // Direita
            proximo_y++;
            break;
    }

    if(proximo_x >= m.linhas){
        return;
    }
    if (proximo_y >= m.colunas){
        return;
    }
    if (m.matriz[proximo_x][proximo_y] != '.'){
        return;
    }
    m.matriz[proximo_x][proximo_y] = '@';
    // marca a posição antiga como vazio
    m.matriz[heroi.x][heroi.y] = '.';
    heroi.x = proximo_x;
    heroi.y = proximo_y;
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
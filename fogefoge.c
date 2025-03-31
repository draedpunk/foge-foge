#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"
#include "mapa.h"

MAPA m;  // Definição da variável global, deve ser feita apenas aqui.
POSICAO heroi;

int acabou() {
    return 0; // Altere esta condição de saída conforme a lógica do jogo
}

int ehdirecao(char direcao){
    // validar entrada da usuario
    return direcao == 'a' ||
        direcao == 'w' ||
        direcao == 's' ||
        direcao == 'd';
}

void mover(char direcao) {
    
    if(!ehdirecao(direcao)) {
            return; // mata a função void
    }

    int proximo_x = heroi.x;
    int proximo_y = heroi.y;
    
    // Movimentando o herói
    switch (direcao) {

        case ESQUERDA: // Esquerda A
            proximo_y--;
            break;
    
        case CIMA: // Cima W
            proximo_x--;
            break;

        case BAIXO: // Baixo S
            proximo_x++;
            break;

        case DIREITA: // Direita D
            proximo_y++;
            break;
    }

    // saber se esta no limite do mapa
    if (!ehvalida(&m, proximo_x, proximo_y)){
        return;
    }
    if (!ehvazia(&m, proximo_x, proximo_y)){
        return;
    }

    andanomapa(&m, heroi.x, heroi.y, proximo_x, proximo_y);
    heroi.x = proximo_x;
    heroi.y = proximo_y;
    // m.matriz[proximo_x][proximo_y] = '@';
    // // marca a posição antiga como vazio
    // m.matriz[heroi.x][heroi.y] = '.';
    // heroi.x = proximo_x;
    // heroi.y = proximo_y;
}

int main() {
    lermapa(&m);
    encontrarmapa(&m, &heroi, HEROI);

    do {
        imprimirmapa(&m);
        char comando;
        printf("Informe o proximo comando:\n");
        scanf("%c", &comando);
        mover(comando);
    } while (!acabou());

    liberarmapa(&m); // libera a memória após o jogo terminar

    return 0;
}
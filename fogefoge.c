#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"
#include "mapa.h"

MAPA m; 
POSICAO heroi;

void fantasmas(){
    MAPA copia;
    copiamapa(&copia, &m);

    // o loop manda o fantasma pra direita caso ele seja encontrado
    for (int i = 0; i < m.linhas; i++){
        for (int j = 0; j < m.colunas; j++){
            if (copia.matriz[i][j]== FANTASMA){
                if (ehvalida(&m, i, j+1) && ehvazia(&m, i, j+1)) {
                    andanomapa(&m,i, j, i, j+1);
                }
            }
        }
    }

    liberarmapa(&copia);
}

int acabou() {
    return 0;
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
}

int main() {
    lermapa(&m);
    encontrarmapa(&m, &heroi, HEROI);
    imprimirmapa(&m);

    // do {
    //     imprimirmapa(&m);
    //     char comando;
    //     printf("Informe o proximo comando:\n");
    //     scanf("%c", &comando);
    //     mover(comando);
    //     fantasmas();

    // } while (!acabou());
    do {
        char comando;
        printf("Informe o proximo comando:\n");
        scanf(" %c", &comando); // Lê o comando
        mover(comando); // Move o herói
        fantasmas(); // Move os fantasmas
        imprimirmapa(&m); // Agora imprimimos o mapa após todas as movimentações
    
    } while (!acabou());
    

    liberarmapa(&m); // libera a memória após o jogo terminar

    return 0;
}
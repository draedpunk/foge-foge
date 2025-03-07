#include <stdio.h>

int main(){
    // matrix 20x10
    int numbers[20][10];

    for(int i = 0; i <20; i++){
        for(int j = 0; j < 10; j++){
            printf("%d\n", numbers[i][j]);
        }
        printf("\n"); // como nenhum valor foi declarado, apenas saira na tela end de memoria
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>  
#include <ctype.h>
// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {

    int matriz[10][10];

    // esse loop setta o valor de cada posição em ZERO
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++){
            matriz[i][j] = 0;
        }
    }

    printf("Escolha uma posição para posicionar seu navil na horizontal (Exemplo: ""A1"")...\n"); // aceita minuscula

    char posicao[4];

    int linha;
    int coluna;

    do { // Validação da entrada 
        scanf (" %3s", posicao);

        coluna = toupper(posicao[0]) - 'A'; // Eu colocária "+1" para ser o valor da letra no alphabeto, mas eu preciso seja "-1" para a matriz
        // toupper para converter entrada para maiuscula caso nescessário
        linha = atoi(&posicao[1]) - 1; //-1 para ajustar para o indice da matriz

        if (coluna > 10 || linha >10) {
            printf ("Posição inválida.. Tente outra posição\n");
        } else {

            for (int i=0; i<3; i++) {

                matriz[linha][coluna] = 3;

                coluna ++;
            }
        }
        
    } while (coluna > 10 || linha>10); 

    int numeros = 1;
    char letras = 'A';
    printf(" X  ");
    for (int i = 0; i<10; i++) {
        printf ("%c  ", letras);
        letras ++;
    }

    printf ("\n");

    for (int i=0; i<10; i++){
        printf(" %d ", numeros);
        for (int j=0; j<10; j++) {
            printf (" %d ", matriz[i][j]);
        }
        printf("\n");
        numeros+=1;
    }

    printf ("Escolha uma posição na vertical para posicionar seu segundo navil...\n");

    char posicaoVertical[4];

    int numeroLinha;
    int letraColuna;

    do {

        scanf (" %3s", posicaoVertical); //A1

        letraColuna = toupper(posicaoVertical[0]) - 'A';
        numeroLinha = atoi(&posicaoVertical[1])-1;

        if (letraColuna > 10 || numeroLinha > 10) {
            printf ("Posição inválida.. Tente outra posição\n");
        }
 
    } while (numeroLinha > 10 || letraColuna > 10);

    for (int i=0; i<3; i++) {
        
        if (matriz[numeroLinha][letraColuna] == 3) {
            printf("Você sobrepos uma embarcação, saindo do programa...");
            return 0;
        }
        matriz[numeroLinha][letraColuna] = 3;

        numeroLinha ++;
     }

    
    numeros = 1;
    letras = 'A';
    printf(" X  ");
    for (int i=0; i<10; i++) {
        printf("%c  ", letras);
        letras ++;
    }
    printf("\n");
    
    for (int i=0; i<10; i++){
        printf(" %d ", numeros);
        for (int j=0; j<10; j++) {
            printf (" %d ", matriz[i][j]);
        }
        printf("\n");
        numeros+=1;
    }

    


    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}

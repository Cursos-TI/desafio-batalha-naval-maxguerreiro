#include <stdio.h>
#include <stdlib.h>  
#include <ctype.h>
// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define LINHAS 10
#define COLUNAS 10

void printTabuleiro(char matriz[LINHAS][COLUNAS]) {
    printf ("\n   A B C D E F G H I J\n");

    for (int i = 0; i < LINHAS; i++) {
        printf("%2d ", LINHAS - LINHAS + i + 1);

        for (int j =0; j < COLUNAS; j++) {
                printf ("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}

int posicionarNavioHorizontal(char matriz[LINHAS][COLUNAS], int linha, int coluna) {
    if (coluna + 2 >= COLUNAS) {
        return 0;
    }

    for (int i = 0; i < 3; i ++) {
        if (matriz[linha][coluna+i] != '-') {
            return 0;
        }
    }

    for (int i = 0; i < 3; i++) {
        matriz[linha][coluna + i] = '3';
    }
    return 1;
}

int posicionarNavioVertical(char matriz[LINHAS][COLUNAS], int linha, int coluna) {
    if (linha + 2 >= LINHAS) {
        return 0;
    }

    for (int i = 0; i < 3; i ++) {
        if (matriz[linha+i][coluna] != '-') {
            return 0;
        }
    }

    for (int i = 0; i < 3; i++) {
        matriz[linha + i][coluna] = '3';
    }
    return 1;
}

int posicionarNavioDiagonal(char matriz[LINHAS][COLUNAS], int linha, int coluna) {
    if (linha + 2 >= LINHAS || coluna + 2 >= COLUNAS) {
        return 0;
    }

    for (int i = 0; i < 3; i ++) {
        if (matriz[linha+i][coluna+i] != '-') {
            return 0;
        }
    }

    for (int i = 0; i < 3; i++) {
        matriz[linha + i][coluna + i] = '3';
    }
    return 1;
}

int main() {

    char matriz[LINHAS][COLUNAS];

    // esse loop setta o valor de cada posição em ZERO
    for (int i=0; i<LINHAS; i++) {
        for (int j=0; j<COLUNAS; j++){
            matriz[i][j] = '-';
        }
    }

    printf("Escolha uma posição para posicionar seu navil na horizontal (Exemplo: ""A1"")...\n"); // aceita minuscula

    char posicao[4];

    int linha;
    int coluna;

    scanf(" %3s", posicao);
    
    coluna = toupper(posicao[0]) - 'A';
    linha = atoi(&posicao[1]) - 1;

     while (coluna < 0 || coluna > COLUNAS - 3 || linha < 0 || linha >= LINHAS)
    {
        printf ("Posição inválida.. Tente outra posição\n");
        scanf(" %3s", posicao);
        coluna = toupper(posicao[0]) - 'A';
        linha = atoi(&posicao[1]) - 1;
    }

    if (!posicionarNavioHorizontal(matriz, linha, coluna)) {
        printf("Não foi possível posicionar o navio nessa posição.\n");
    } else {
        printTabuleiro(matriz);
    }

        

    //Imprimindo na tela o tabuleiro com a peça posicionada

    //Essas variaveis ajudaram a representar o tabuleiro com o numero das linhas e letras das colunas


    printf("Escolha uma posição para posicionar seu navil na vertical (Exemplo: ""A1"")...\n");

    scanf(" %3s", posicao);

    coluna = toupper(posicao[0]) - 'A';
    linha = atoi(&posicao[1]) - 1;
    
    while (coluna < 0 || coluna > COLUNAS - 3 || linha < 0 || linha >= LINHAS) {
        printf ("Posição inválida.. Tente outra posição\n");
        scanf(" %3s", posicao);
        coluna = toupper(posicao[0]) - 'A';
        linha = atoi(&posicao[1]) - 1;
    }

    if (!posicionarNavioVertical(matriz, linha, coluna)) {
        printf("Não foi possível posicionar o navio nessa posição.\n");
    } else {
        printTabuleiro(matriz);
    }

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    for (int i = 1; i <= 2; i++)
    {
        if (i == 1)
        {
            printf("Escolha uma posição para posicionar seu navil na horizontal (Exemplo: ""D2"")...\n");
        } else {
            printf("Escolha outra posição para posicionar seu navil segundo na horizontal (Exemplo: ""G4"")...\n");
        }

        scanf(" %3s", posicao);

        coluna = toupper(posicao[0]) - 'A';
        linha = atoi(&posicao[1]) - 1;
        
        while (coluna < 0 || coluna > COLUNAS - 3 || linha < 0 || linha >= LINHAS) {
            printf ("Posição inválida.. Tente outra posição\n");
            scanf(" %3s", posicao);
            coluna = toupper(posicao[0]) - 'A';
            linha = atoi(&posicao[1]) - 1;
        }

        if (!posicionarNavioDiagonal(matriz, linha, coluna)) {
            printf("Não foi possível posicionar o navio nessa posição.\n");
        } else {
            printTabuleiro(matriz);
        }
    }


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

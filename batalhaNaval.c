#include <stdio.h>
#include <stdlib.h>  
#include <ctype.h>
// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define LINHAS 10
#define COLUNAS 10

int main() {

    int matriz[LINHAS][COLUNAS];

    // esse loop setta o valor de cada posição em ZERO
    for (int i=0; i<LINHAS; i++) {
        for (int j=0; j<COLUNAS; j++){
            matriz[i][j] = 0;
        }
    }

    printf("Escolha uma posição para posicionar seu navil na horizontal (Exemplo: ""A1"")...\n"); // aceita minuscula

    char posicao[4];

    int linha;
    int coluna;

    do { // Validação da entrada 
        scanf (" %3s", posicao);

        coluna = toupper(posicao[0]) - 'A'; // Eu colocária "+1" para ser o valor da letra no alphabeto, mas eu preciso que seja "-1" para a matriz
        // toupper para converter entrada para maiuscula caso nescessário
        linha = atoi(&posicao[1]) - 1; //-1 para ajustar para o indice da matriz

        if (coluna>=COLUNAS - 2 || linha>10) { // o programa não aceitará peças depois da coluna "i", se não a peça ficaria com parte fora do tabuleiro
            printf ("Posição inválida.. Tente outra posição\n");
        } 

        int soma = coluna;
        for (int i=0; i<3; i++) 
        {
            matriz[linha][soma] = 3;
            soma ++; 
        }
        
    } while (coluna >=COLUNAS - 2 || linha>10 ); 

    //Imprimindo na tela o tabuleiro com a peça posicionada

    //Essas variaveis ajudaram a representar o tabuleiro com o numero das linhas e letras das colunas
    int numeros = 1; 
    char letras = 'A';
    printf(" X  ");
    for (int i = 0; i<COLUNAS; i++) {
        printf ("%c  ", letras);
        letras ++;
    }

    printf ("\n");


    for (int i=0; i<LINHAS; i++){
        printf(" %d ", numeros);
        for (int j=0; j<COLUNAS; j++) {
            printf (" %d ", matriz[i][j]);
        }
        printf("\n");
        numeros+=1;
    }

    printf ("Escolha uma posição na vertical para posicionar seu segundo navil...\n");

    // validando entrada para evtar peças fora do tabuleiro e sobreposições
    do { 
        scanf (" %3s", posicao); //A1

        coluna = toupper(posicao[0]) - 'A';
        linha = atoi(&posicao[1])-1;

        if (coluna > COLUNAS || linha >= COLUNAS - 2) {
            printf ("Posição inválida.. Tente outra posição\n"); 
        } 
 
    } while (linha >= COLUNAS - 2 || coluna > COLUNAS);

    for (int i=0; i<3; i++) {
        
        if (matriz[linha][coluna] == 3) {
            printf("Você sobrepos uma embarcação, saindo do programa...");
            return 0;
        }
        matriz[linha][coluna] = 3;

        linha ++;
     }

    
    numeros = 1;
    letras = 'A';
    printf(" X  ");
    for (int i=0; i<COLUNAS; i++) {
        printf("%c  ", letras);
        letras ++;
    }
    printf("\n");
    
    for (int i=0; i<LINHAS; i++){
        printf(" %d ", numeros);
        for (int j=0; j<COLUNAS; j++) {
            printf (" %d ", matriz[i][j]);
        }
        printf("\n");
        numeros+=1;
    }

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    printf("Escolha duas posições para posicionar suas embarcações (Na diagonal)...\n");

    printf("Digite a primeira posição...\n");

    do { // validando entrada para evitar que o jogador escolha uma posição fora do tabuleiro
        scanf(" %3s", posicao);

        linha = atoi(&posicao[1]) - 1;
        coluna = toupper(posicao[0]) -'A';

        if (linha > LINHAS || coluna >= COLUNAS - 2) {
            printf("Posição inválida, tente novamente...\n");
        }
    } while (linha > LINHAS || coluna >= COLUNAS - 2);

    int somaLinha = linha;
    int somaColuna = coluna;
    for (int i=0; i<3; i++) { // validando se não exixte nenhum outro navil nessa posição
        
        if (matriz[somaLinha][somaColuna] == 3) {
            printf("Já existe um navil nessa posição, encerrando programa...\n");
            return 0;
        }
        somaColuna ++;
        somaLinha ++;
    }

    for (int i=0; i<3; i++) {
        matriz[linha][coluna] = 3;
        linha ++;
        coluna ++;
    }

    numeros = 1;
    letras = 'A';
    printf(" X  ");
    for (int i=0; i<COLUNAS; i++) {
        printf("%c  ", letras);
        letras ++;
    }
    printf("\n");
    
    for (int i=0; i<LINHAS; i++){
        printf(" %d ", numeros);
        for (int j=0; j<COLUNAS; j++) {
            printf (" %d ", matriz[i][j]);
        }
        printf("\n");
        numeros+=1;
    }


    printf("Digite a segunda posição horizontal...\n");

    do { // validando entrada para evitar que o jogador escolha uma posição fora do tabuleiro
        scanf(" %3s", posicao);

        linha = atoi(&posicao[1]) - 1;
        coluna = toupper(posicao[0]) -'A';

        if (linha > 10 || coluna > 10 || coluna < 2) {
            printf("Posição inválida, tente novamente...\n");
        }
        
    } while ((linha > LINHAS || coluna > COLUNAS) || coluna < 2);

    somaColuna = coluna;
    somaLinha = linha;
    for (int i=0; i<3; i++) { // validando se não exixte nenhum outro navil nessa posição
        
        if (matriz[somaLinha][somaColuna] == 3) {
            printf("Já existe um navil nessa posição, encerrando programa...\n");
            return 0;
        }
        somaColuna --;
        somaLinha ++;
    }
    
    for (int i=0; i<3; i++) {
        matriz[linha][coluna] = 3;
        linha ++;
        coluna --;
    }

    numeros = 1;
    letras = 'A';
    printf(" X  ");
    for (int i=0; i<COLUNAS; i++) {
        printf("%c  ", letras);
        letras ++;
    }
    printf("\n");
    
    for (int i=0; i<LINHAS; i++){
        printf(" %d ", numeros);
        for (int j=0; j<COLUNAS; j++) {
            printf (" %d ", matriz[i][j]);
        }
        printf("\n");
        numeros+=1;
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

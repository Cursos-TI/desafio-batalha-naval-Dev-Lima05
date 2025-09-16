#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    int tabuleiro[10][10] = {0}; //inicializa a matriz com 0, sendo 0 água

    int navio1[3] = {3, 3, 3}; // navio horizontal
    int navio2[3] = {3, 3, 3}; // navio vertical

    // coordenadas iniciais (linha, coluna)
    int linhaNavio1 = 2, colunaNavio1 = 1; // horizontal
    int linhaNavio2 = 4, colunaNavio2 = 3; // vertical

    // posicionar navio horizontal
    for(int i = 0; i < 3; i++) {
        tabuleiro[linhaNavio1][colunaNavio1 + i] = navio1[i]; // linha fixa, somente a coluna aumenta
    }

    // posicionar navio vertical
    for(int i = 0; i < 3; i++) {
        tabuleiro[linhaNavio2 + i][colunaNavio2] = navio2[i]; // coluna fixa, somente a linha aumenta

    }

    // EXIBIÇÃO TABULEIRO
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
           char simbolo = (tabuleiro[i][j] == 0) ? '.' : 'N'; // 0 - água = "." e 3 - navio = "N"
           printf("%c ", simbolo);
        }
        printf("\n"); // pula pra linha de baixo

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

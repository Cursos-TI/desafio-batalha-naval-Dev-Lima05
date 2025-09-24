#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.
#define SIZE_N 5 // tamanho tabuleiro Desafio Novato
# define SIZE_A 10 // tamanho tabuleiro Desafio Novato

void Novato() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[SIZE_A_N][SIZE_A_N];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    int tabuleiro[SIZE_N][SIZE_N] = {0}; //inicializa a matriz com 0, sendo 0 água

    int navio1[3] = {3, 3, 3}; // navio horizontal
    int navio2[3] = {3, 3, 3}; // navio vertical

    // coordenadas iniciais (linha, coluna)
    int linhaNavio1 = 1, colunaNavio1 = 1; // horizontal
    int linhaNavio2 = 2, colunaNavio2 = 4; // vertical

    int tamanho = 3; // numero de elementos nos "navios/vetores"
    int valido; // flag

    // ---- NAVIO 1 HORIZONTAL ----
    valido = 1; //enquanto 1 navio cabe
    // Verifica se o tamanho do navio excede o limite do tabuleiro
    if (colunaNavio1 + tamanho > SIZE_N)
        valido = 0;

    // Se válido, posiciona
    if(valido)
        for(int i = 0; i < 3; i++) {
            tabuleiro[linhaNavio1][colunaNavio1 + i] = navio1[i]; // linha fixa, somente a coluna aumenta
        }
    else 
        printf("Navio 1 invalido!\n");

    // ---- NAVIO 2 VERTICAL ----
    valido = 1;
    // Verifica se o tamanho do navio excede o limite do tabuleiro
    if (linhaNavio2 + tamanho > SIZE_N)
        valido = 0;

    // Se válido, posiciona
    if(valido)
        for(int i = 0; i < 3; i++) {
            tabuleiro[linhaNavio2 + i][colunaNavio2] = navio2[i]; // coluna fixa, somente a linha aumenta
        }
    else
        printf("Navio 2 invalido!\n");

    // EXIBIÇÃO TABULEIRO
    for(int i = 0; i < SIZE_N; i++){
        for(int j = 0; j < SIZE_N; j++){
           printf("%d ", tabuleiro[i][j]);
        }
        printf("\n"); // pula pra linha de baixo

    }
}
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.
void Aventureiro(){

    int tabu[SIZE_A][SIZE_A] = {0}; 

    // Inicialização e Coordenadas Navios
    int navio1[3] = {3,3,3};
    int linhaNavio1 = 2, colunaNavio1 = 5;

    int navio2[3] = {3,3,3};
    int linhaNavio2 = 1, colunaNavio2 = 3;

    int navio3[3] = {3,3,3};
    int linhaNavio3 = 5, colunaNavio3 = 6;

    int navio4[3] = {3,3,3};
    int linhaNavio4 = 8, colunaNavio4 = 3;

    int tamanho = 3; // numero de elementos nos "navios/vetores"
    int valido; // flag

    // ---- NAVIO 1 (diagonal - baixo direita) ----
    valido = 1; // enquanto 1 navio cabe

    // Verifica limite
    if (linhaNavio1 + tamanho > SIZE_A || colunaNavio1 + tamanho > SIZE_A)
        valido = 0; // se for verdadeiro navio não cabe 

    // Verifica sobreposição
    for (int i = 0; i < tamanho && valido; i++)
        if (tabu[linhaNavio1+i][colunaNavio1+i] != 0) // se encontrar alguma célula da matriz diferente de 0
            valido = 0;                               // significa que já tem navio nessa posição

    // Se válido, posiciona
    if (valido) // se for verdadeiro = 1
        for (int i = 0; i < tamanho; i++)
            tabu[linhaNavio1+i][colunaNavio1+i] = navio1[i]; // a cada iteração pula para próxima linha depois acrescenta i a coluna 
    else
        printf("Navio 1 invalido!\n");


    // ---- NAVIO 2 (diagonal - baixo esquerda) ----
    valido = 1;

    // Verifica limite
    if (linhaNavio2 + tamanho > SIZE_A || colunaNavio2 - (tamanho-1) < 0)
        valido = 0;

    // Verifica sobreposição    
    for (int i = 0; i < tamanho && valido; i++)
        if (tabu[linhaNavio2+i][colunaNavio2-i] != 0)
            valido = 0;

    // Se válido, posiciona        
    if (valido)
        for (int i = 0; i < tamanho; i++)
            tabu[linhaNavio2+i][colunaNavio2-i] = navio2[i]; // a cada iteração pula para próxima linha depois subtrai i a coluna 
    else
        printf("Navio 2 invalido!\n");


    // ---- NAVIO 3 (vertical) ----
    valido = 1;

    // Verifica limite
    if (linhaNavio3 + tamanho > SIZE_A)
        valido = 0;

    // Verifica sobreposição    
    for (int i = 0; i < tamanho && valido; i++)
        if (tabu[linhaNavio3+i][colunaNavio3] != 0)
            valido = 0;

    // Se válido, posiciona        
    if (valido)
        for (int i = 0; i < tamanho; i++)
            tabu[linhaNavio3+i][colunaNavio3] = navio3[i];
    else
        printf("Navio 3 invalido!\n");


    // ---- NAVIO 4 (horizontal) ----
    valido = 1;

    // Verifica limite
    if (colunaNavio4 + tamanho > SIZE_A)
        valido = 0;

    // Verifica sobreposição    
    for (int i = 0; i < tamanho && valido; i++)
        if (tabu[linhaNavio4][colunaNavio4+i] != 0)
            valido = 0;

    // Se válido, posiciona        
    if (valido)
        for (int i = 0; i < tamanho; i++)
            tabu[linhaNavio4][colunaNavio4+i] = navio4[i];
    else
        printf("Navio 4 invalido!\n");


    // ---- Exibe Tabuleiro ----
    for (int i=0; i<SIZE_A; i++){
        for (int j=0; j<SIZE_A; j++){
            printf("%d ", tabu[i][j]);
        }
        printf("\n");
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

int main(){
    Aventureiro(); // executa o procedimento Aventureiro
    return 0;
}



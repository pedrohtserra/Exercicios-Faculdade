#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define tamanho 15

void iniciarmapa(int mapa1[tamanho][tamanho], int mapa2[tamanho][tamanho]);
void definirmapa(int mapa1[tamanho][tamanho]);
void imprimirmapa(int mapa[tamanho][tamanho], int jogador);

int main(void)
{
    int mapa1[tamanho][tamanho];
    int mapa2[tamanho][tamanho];
    int jogador1 = 1;
    int jogador2 = 2;

    iniciarmapa(mapa1, mapa2); // criando um mapa para cada jogador

    definirmapa(mapa1); // definir mapa do jogador 1
    imprimirmapa(mapa1, jogador1); // teste para ver se os barcos estão nos seus devidos lugares
    
    definirmapa(mapa2); // definir mapa do jogador 2
    imprimirmapa(mapa2, jogador2); // teste para ver se os barcos estão nos seus devidos lugares novamente

    return 0;
}

void iniciarmapa(int mapa1[tamanho][tamanho], int mapa2[tamanho][tamanho])
{
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho; j++)
        {
            mapa1[i][j] = 0;
            mapa2[i][j] = 0;
        }
    }
}

void definirmapa(int mapa1[tamanho][tamanho])
{
    int barcos[4] = {5, 4, 3, 2}; // criando 4 tipos de barco, com seus respectivos tamanhos
    int linha = 0;
    int coluna = 0; 
    int verhor = 0; // resposta se é vertical ou horizontal (0) se for horizontal e (1) se for vertical

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < i + 1; j++) {
            int tamanhoBarco = barcos[i];

            printf("\nEscolha uma posição para o barco %d de tamanho %d:\n", j + 1, tamanhoBarco);
            
            // escolher linha
            do {
                printf("Linha (1 a 15): ");
                scanf("%d", &linha);
            } while (linha < 1 || linha > tamanho);
            
            // escolher coluna
            do {
                printf("Coluna (1 a 15): ");
                scanf("%d", &coluna);
            } while (coluna < 1 || coluna > tamanho);

            // escolher entre vertical e horizontal
            do {
                printf("Se for horizontal digite (0), se for vertical digite (1): ");
                scanf("%d", &verhor);
            } while (verhor != 0 && verhor != 1);

            // ajustando a linha e a coluna para indicar que começa na posição 0
            linha--;
            coluna--;

            // valor booleano em true para indicar que o barco pode ser colocado no mapa
            bool podeColocar = true;

            if (verhor == 0) { // horizontal
                if (coluna + tamanhoBarco > tamanho) {
                    printf("O barco ultrapassa os limites do mapa! Escolha outra posição.\n\n");
                    j--; // repete a pergunta de linha, coluna, vertical ou horizontal
                    continue;
                }

                for (int k = 0; k < tamanhoBarco; k++) {
                    if (mapa1[linha][coluna + k] != 0) {
                        podeColocar = 0; // se existe um barco nessa posição, podeColocar = 0, indicando que não pode colocar o novo barco nessa posição
                        break;
                    }
                }

                if (podeColocar) {
                    for (int k = 0; k < tamanhoBarco; k++) {
                        mapa1[linha][coluna + k] = tamanhoBarco;
                    }
                } else {
                    printf("Posição ocupada, escolha outra posição.\n\n");
                    j--; 
                }
            } else { // vertical
                if (linha + tamanhoBarco > tamanho) {
                    printf("O barco ultrapassa os limites do mapa! Escolha outra posição.\n");
                    j--;
                    continue;
                }

                for (int k = 0; k < tamanhoBarco; k++) {
                    if (mapa1[linha + k][coluna] != 0) {
                        podeColocar = 0; 
                        break;
                    }
                }

                if (podeColocar) {
                    for (int k = 0; k < tamanhoBarco; k++) {
                        mapa1[linha + k][coluna] = tamanhoBarco;
                    }
                } else {
                    printf("Posição ocupada, escolha outra posição.\n\n");
                    j--;
                }
            }
        }
    }
}

void imprimirmapa(int mapa[tamanho][tamanho], int jogador) 
{
    printf("\nMapa Atual do Jogador %d:\n", jogador);
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%d ", mapa[i][j]);
        }
        printf("\n");
    }
}
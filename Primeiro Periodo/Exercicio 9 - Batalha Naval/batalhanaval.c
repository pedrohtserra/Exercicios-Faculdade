#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define tamanho 15

void iniciar_mapa(int mapa1[tamanho][tamanho], int mapa2[tamanho][tamanho]);
void definir_mapa(int mapa1[tamanho][tamanho], int jogador);
int atacar_mapa(int mapa1[tamanho][tamanho], int mapa2[tamanho][tamanho], int jogador1, int jogador2);
void imprimir_mapa(int mapa[tamanho][tamanho]);
void iniciar_mapa_jogo(int mapa_visivel1[tamanho][tamanho], int mapa_visivel2[tamanho][tamanho]);


int main(void)
{
    int mapa1[tamanho][tamanho];
    int mapa2[tamanho][tamanho];
    int jogador1 = 1;
    int jogador2 = 2;

    iniciar_mapa(mapa1, mapa2); // criando um mapa para cada jogador

    definir_mapa(mapa1, jogador1); // definir mapa do jogador 1
    imprimir_mapa(mapa1); // teste para ver se os barcos estão nos seus devidos lugares
    
    definir_mapa(mapa2, jogador2); // definir mapa do jogador 2
    imprimir_mapa(mapa2); // teste para ver se os barcos estão nos seus devidos lugares novamente

    int jogador_vencedor = atacar_mapa(mapa1, mapa2, jogador1, jogador2);

    printf("\n\n\n\n      !.-.-_-=-_-=  Vitória do Jogador %d  =-_-=-_-.-.!\n\n\n\n\n\n", jogador_vencedor);

    return 0;
}

void iniciar_mapa(int mapa1[tamanho][tamanho], int mapa2[tamanho][tamanho])
{
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            mapa1[i][j] = 0;
            mapa2[i][j] = 0;
        }
    }
}

void definir_mapa(int mapa[tamanho][tamanho], int jogador)
{
    int navios[4] = {5, 4, 3, 2}; // criando 4 tipos de navio, com seus respectivos tamanhos
    int linha = 0;
    int coluna = 0; 
    int verhor = 0; // resposta se é vertical ou horizontal (0) se for horizontal e (1) se for vertical

    printf("\n\n==============================================================\n\n                   | Turno do Jogador %d |\n", jogador);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < i + 1; j++) {
            int tamanhoNavio = navios[i];
            imprimir_mapa(mapa);
            printf("\nEscolha uma posição para o navio %d de tamanho %d:\n", j + 1, tamanhoNavio);
            
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

            printf("\n\n==============================================================\n\n");
            
            linha--; // ajustando a linha e a coluna para indicar que começa na posição 0
            coluna--;

            // valor booleano em true para indicar que o barco pode ser colocado no mapa
            bool podeColocar = true;

            if (verhor == 0) { // horizontal
                if (coluna + tamanhoNavio > tamanho) {
                    printf("     O navio está saindo do mapa, escolha outra posição.");
                    j--; // repete a pergunta de linha, coluna, vertical ou horizontal
                    continue;
                }

                for (int k = 0; k < tamanhoNavio; k++) {
                    if (mapa[linha][coluna + k] != 0) {
                        podeColocar = false; // se existe um barco nessa posição, podeColocar = 0, indicando que não pode colocar o novo barco nessa posição
                        break;
                    }
                }

                if (podeColocar) { // se valor de podeColocar for true, o programa irá colocar o navio
                    for (int k = 0; k < tamanhoNavio; k++) {
                        mapa[linha][coluna + k] = tamanhoNavio;
                    }
                } else { // se o valor for false, o programa não ira colocar o navio e irá repetir a pergunta
                    printf("          Posição ocupada, escolha outra posição.");
                    j--; 
                }
            } else { // vertical
                if (linha + tamanhoNavio > tamanho) {
                    printf("     O navio está saindo do mapa, escolha outra posição.");
                    j--;
                    continue;
                }

                for (int k = 0; k < tamanhoNavio; k++) {
                    if (mapa[linha + k][coluna] != 0) {
                        podeColocar = false; 
                        break;
                    }
                }

                if (podeColocar) {
                    for (int k = 0; k < tamanhoNavio; k++) {
                        mapa[linha + k][coluna] = tamanhoNavio;
                    }
                } else {
                    printf("          Posição ocupada, escolha outra posição.");
                    j--;
                }
            }
        }
    }
}

int atacar_mapa(int mapa1[tamanho][tamanho], int mapa2[tamanho][tamanho], int jogador1, int jogador2)
{
    int linha = 0;
    int coluna = 0;
    int acertos1 = 0, acertos2 = 0;
    int total_partes = 30;
    int jogador_atual = jogador1;
    int mapa_visivel1[tamanho][tamanho];
    int mapa_visivel2[tamanho][tamanho];

    iniciar_mapa_jogo(mapa_visivel1, mapa_visivel2);

    while (1)
    {
        int (*mapa_invisivel)[tamanho] = (jogador_atual == jogador1) ? mapa2 : mapa1;
        int (*mapa_visivel)[tamanho] = (jogador_atual == jogador1) ? mapa_visivel1 : mapa_visivel2;
        int *acertos = (jogador_atual == jogador1) ? &acertos1 : &acertos2;

        printf("\n\n==============================================================\n\n                | Turno de Ataque do Jogador %d |\n", jogador_atual);
        imprimir_mapa(mapa_visivel);

        do {
            printf("\nLinha (1 a 15): ");
            scanf("%d", &linha);
        } while (linha < 1 || linha > tamanho);
        
        do {
            printf("Coluna (1 a 15): ");
            scanf("%d", &coluna);
        } while (coluna < 1 || coluna > tamanho);

        linha--;
        coluna--;

        printf("\n\n==============================================================\n\n");

        if (mapa_visivel[linha][coluna] != 0) {
            printf("\nPosição escolhida já atacada, tente outra posição.\n");
            continue;
        }

        if (mapa_invisivel[linha][coluna] > 0) {
            mapa_visivel[linha][coluna] = mapa_invisivel[linha][coluna];
            imprimir_mapa(mapa_visivel);
            printf("\n          | Boom... Jogador %d acertou um navio! |\n\n", jogador_atual);
            (*acertos)++;

            if (*acertos == total_partes)
            {
                printf("\n\n==============================================================\n\n\n\n      Jogador %d derrubou todos os navios, jogo encerrado!\n\n", jogador_atual);
                return jogador_atual;
            }
        } else {
            mapa_visivel[linha][coluna] = -1;
            imprimir_mapa(mapa_visivel);
            printf("\n         | Splash... Jogador %d acertou a água! |\n\n", jogador_atual);
        }
    
        system("pause");
        jogador_atual = (jogador_atual == jogador1) ? jogador2 : jogador1;
    }
}

void imprimir_mapa(int mapa[tamanho][tamanho]) 
{
    printf("\nMapa: \n    ");
    for (int i = 0; i < tamanho; i++) {
        printf("%2d  ", i + 1);
    }
    printf("\n");
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (j == 0)
            {
                printf("%2d  ", i + 1);
            }
            printf("%2d  ", mapa[i][j]);
        }
        printf("\n");
    }
}

void iniciar_mapa_jogo(int mapa_visivel1[tamanho][tamanho], int mapa_visivel2[tamanho][tamanho])
{
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            mapa_visivel1[i][j] = 0;
            mapa_visivel2[i][j] = 0;
        }
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char escolhaLinguagem();
void jockeyPTBR();
void jockeyENG();
void jockeyGER();

int main(){
    int continuar = 1;
    
    while(continuar == 1){
        char linguagem = escolhaLinguagem();
        
        if (linguagem == 'P' || linguagem == 'p'){
            jockeyPTBR();
        } else if (linguagem == 'I' || linguagem == 'i'){
            jockeyENG();
        } else {
            jockeyGER();
        }
        
        printf("\n\nDeseja continuar? (1) para continuar ou (2) para nao continuar.\n");
        scanf("%d", &continuar);
        
        if (continuar == 1){
            printf("\n\nReiniciando o jogo...\n\n\n");
        } else {
            printf("\n\nFinalizando o jogo...\n");
        }
    }
    
    return 0;
}
    
char escolhaLinguagem(){
    char escolha;
    printf("Escolha a linguagem:\n(P) para portugues, (I) para ingles ou (A) para alemao:\n\n");
    do {
        printf("Escolha: ");
        scanf(" %c", &escolha);
    } while (escolha != 'P' && escolha != 'I' && escolha != 'A' && escolha != 'p' && escolha != 'i' && escolha != 'a');
        
    return escolha;
}

void jockeyPTBR(){
    int vencedor = 0;
    int jogador1 = 0;
    int jogador2 = 0;
    
    while (vencedor == 0){
        printf("\n\nEscolha do Jogador:\n\n");
        
        do {
            printf("(1) para pedra, (2) para papel ou (3) para tesoura: ");
            scanf("%d", &jogador1);
        } while (jogador1 != 1 && jogador1 != 2 && jogador1 != 3);

        srand(time(NULL));
        
        jogador2 = (rand() % 3) + 1; 
        
        if (jogador1 == 1 && jogador2 == 3){
            printf("\n\n\nJogador venceu BOT com uma pedra!\n\n");
            vencedor = 1;
        } else if (jogador1 == 2 && jogador2 == 1){
            printf("\n\n\nJogador venceu BOT com um papel!\n\n");
            vencedor = 1;
        } else if (jogador1 == 3 && jogador2 == 2){
            printf("\n\n\nJogador venceu BOT com uma tesoura!\n\n");
            vencedor = 1;
        } else if (jogador2 == 1 && jogador1 == 3){
            printf("\n\n\nBOT venceu Jogador com uma pedra!\n\n");
            vencedor = 1;
        } else if (jogador2 == 2 && jogador1 == 1){
            printf("\n\n\nBOT venceu Jogador com um papel!\n\n");
            vencedor = 1;
        } else if (jogador2 == 3 && jogador1 == 2){
            printf("\n\n\nBOT venceu Jogador com uma tesoura!\n\n");
            vencedor = 1;
        } else {
            printf("\n\nEmpate, mais uma rodada!");
        }
    }
}

void jockeyENG(){
    int vencedor = 0;
    int jogador1 = 0;
    int jogador2 = 0;
    
    while (vencedor == 0) {
        printf("\n\nPlayer's pick:\n\n");
        
        do {
            printf("(1) for rock, (2) for paper, or (3) for scissors: ");
            scanf("%d", &jogador1);
        } while (jogador1 != 1 && jogador1 != 2 && jogador1 != 3);
        
        srand(time(NULL));
        
        jogador2 = (rand() % 3) + 1; 

        
        if (jogador1 == 1 && jogador2 == 3) {
            printf("\n\n\nPlayer defeated BOT with a rock!\n\n");
            vencedor = 1;
        } else if (jogador1 == 2 && jogador2 == 1) {
            printf("\n\n\nPlayer defeated BOT with a paper!\n\n");
            vencedor = 1;
        } else if (jogador1 == 3 && jogador2 == 2) {
            printf("\n\n\nPlayer defeated BOT with scissors!\n\n");
            vencedor = 1;
        } else if (jogador2 == 1 && jogador1 == 3) {
            printf("\n\n\nBOT defeated Player with a rock!\n\n");
            vencedor = 1;
        } else if (jogador2 == 2 && jogador1 == 1) {
            printf("\n\n\nBOT defeated Player with a paper!\n\n");
            vencedor = 1;
        } else if (jogador2 == 3 && jogador1 == 2) {
            printf("\n\n\nBOT defeated Player with scissors!\n\n");
            vencedor = 1;
        } else {
            printf("\n\nIt's a tie, another round!");
        }
    }
}

void jockeyGER(){
    int vencedor = 0;
    int jogador1 = 0;
    int jogador2 = 0;
    
    while (vencedor == 0) {
        printf("\n\nAuswahl des Spielers:\n\n");
        
        do {
            printf("(1) fur Stein, (2) fur Papier oder (3) fur Schere: ");
            scanf("%d", &jogador1);
        } while (jogador1 != 1 && jogador1 != 2 && jogador1 != 3);
        
        srand(time(NULL));
        
        jogador2 = (rand() % 3) + 1; 
        
        if (jogador1 == 1 && jogador2 == 3) {
            printf("\n\n\nSpieler hat BOT mit Stein besiegt!\n\n");
            vencedor = 1;
        } else if (jogador1 == 2 && jogador2 == 1) {
            printf("\n\n\nSpieler hat BOT mit Papier besiegt!\n\n");
            vencedor = 1;
        } else if (jogador1 == 3 && jogador2 == 2) {
            printf("\n\n\nSpieler hat BOT mit Schere besiegt!\n\n");
            vencedor = 1;
        } else if (jogador2 == 1 && jogador1 == 3) {
            printf("\n\n\nBOT hat Spieler mit Stein besiegt!\n\n");
            vencedor = 1;
        } else if (jogador2 == 2 && jogador1 == 1) {
            printf("\n\n\nBOT hat Spieler mit Papier besiegt!\n\n");
            vencedor = 1;
        } else if (jogador2 == 3 && jogador1 == 2) {
            printf("\n\n\nBOT hat Spieler mit Schere besiegt!\n\n");
            vencedor = 1;
        } else {
            printf("\n\n\nUnentschieden, noch eine Runde!");
        }
    }
}
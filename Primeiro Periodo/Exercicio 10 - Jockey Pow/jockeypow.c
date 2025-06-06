#include <stdio.h>

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
        printf("\n\nVez do Jogador 1:\n\n");
        
        do {
            printf("(1) para pedra, (2) para papel ou (3) para tesoura: ");
            scanf("%d", &jogador1);
        } while (jogador1 != 1 && jogador1 != 2 && jogador1 != 3);
        
        printf("\n\nVez do Jogador 2:\n\n");
        
        do {
            printf("(1) para pedra, (2) para papel ou (3) para tesoura: ");
            scanf("%d", &jogador2);
        } while (jogador2 != 1 && jogador2 != 2 && jogador2 != 3);
        
        if (jogador1 == 1 && jogador2 == 3){
            printf("\n\n\nJogador 1 venceu Jogador 2 com uma pedra!\n\n");
            vencedor = 1;
        } else if (jogador1 == 2 && jogador2 == 1){
            printf("\n\n\nJogador 1 venceu Jogador 2 com um papel!\n\n");
            vencedor = 1;
        } else if (jogador1 == 3 && jogador2 == 2){
            printf("\n\n\nJogador 1 venceu Jogador 2 com uma tesoura!\n\n");
            vencedor = 1;
        } else if (jogador2 == 1 && jogador1 == 3){
            printf("\n\n\nJogador 2 venceu Jogador 1 com uma pedra!\n\n");
            vencedor = 1;
        } else if (jogador2 == 2 && jogador1 == 1){
            printf("\n\n\nJogador 2 venceu Jogador 1 com um papel!\n\n");
            vencedor = 1;
        } else if (jogador2 == 3 && jogador1 == 2){
            printf("\n\n\nJogador 2 venceu Jogador 1 com uma tesoura!\n\n");
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
        printf("\n\nPlayer 1's turn:\n\n");
        
        do {
            printf("(1) for rock, (2) for paper, or (3) for scissors: ");
            scanf("%d", &jogador1);
        } while (jogador1 != 1 && jogador1 != 2 && jogador1 != 3);
        
        printf("\n\nPlayer 2's turn:\n\n");
        
        do {
            printf("(1) for rock, (2) for paper, or (3) for scissors: ");
            scanf("%d", &jogador2);
        } while (jogador2 != 1 && jogador2 != 2 && jogador2 != 3);
        
        if (jogador1 == 1 && jogador2 == 3) {
            printf("\n\n\nPlayer 1 defeated Player 2 with a rock!\n\n");
            vencedor = 1;
        } else if (jogador1 == 2 && jogador2 == 1) {
            printf("\n\n\nPlayer 1 defeated Player 2 with a paper!\n\n");
            vencedor = 1;
        } else if (jogador1 == 3 && jogador2 == 2) {
            printf("\n\n\nPlayer 1 defeated Player 2 with scissors!\n\n");
            vencedor = 1;
        } else if (jogador2 == 1 && jogador1 == 3) {
            printf("\n\n\nPlayer 2 defeated Player 1 with a rock!\n\n");
            vencedor = 1;
        } else if (jogador2 == 2 && jogador1 == 1) {
            printf("\n\n\nPlayer 2 defeated Player 1 with a paper!\n\n");
            vencedor = 1;
        } else if (jogador2 == 3 && jogador1 == 2) {
            printf("\n\n\nPlayer 2 defeated Player 1 with scissors!\n\n");
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
        printf("\n\nZug von Spieler 1:\n\n");
        
        do {
            printf("(1) fur Stein, (2) fur Papier oder (3) fur Schere: ");
            scanf("%d", &jogador1);
        } while (jogador1 != 1 && jogador1 != 2 && jogador1 != 3);
        
        printf("\n\nZug von Spieler 2:\n\n");
        
        do {
            printf("(1) fur Stein, (2) fur Papier oder (3) fur Schere: ");
            scanf("%d", &jogador2);
        } while (jogador2 != 1 && jogador2 != 2 && jogador2 != 3);
        
        if (jogador1 == 1 && jogador2 == 3) {
            printf("\n\n\nSpieler 1 hat Spieler 2 mit Stein besiegt!\n\n");
            vencedor = 1;
        } else if (jogador1 == 2 && jogador2 == 1) {
            printf("\n\n\nSpieler 1 hat Spieler 2 mit Papier besiegt!\n\n");
            vencedor = 1;
        } else if (jogador1 == 3 && jogador2 == 2) {
            printf("\n\n\nSpieler 1 hat Spieler 2 mit Schere besiegt!\n\n");
            vencedor = 1;
        } else if (jogador2 == 1 && jogador1 == 3) {
            printf("\n\n\nSpieler 2 hat Spieler 1 mit Stein besiegt!\n\n");
            vencedor = 1;
        } else if (jogador2 == 2 && jogador1 == 1) {
            printf("\n\n\nSpieler 2 hat Spieler 1 mit Papier besiegt!\n\n");
            vencedor = 1;
        } else if (jogador2 == 3 && jogador1 == 2) {
            printf("\n\n\nSpieler 2 hat Spieler 1 mit Schere besiegt!\n\n");
            vencedor = 1;
        } else {
            printf("\n\n\nUnentschieden, noch eine Runde!");
        }
    }
}
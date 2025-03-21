#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int tamanho = 0; 
    int contadorsequencia = 1;
    int contadorMaior = 1;
  
    printf("Quantos números na sequência? ");
    
    if (tamanho <= 0)
    {
    scanf("%d", &tamanho);
    }
    
    int *sequencia = (int*) malloc (tamanho * sizeof(int));
    
    for (int i = 0; i < tamanho; i++)
    {
        printf("Numero %d: ", i + 1);
        scanf("%d", &sequencia[i]);
    }
    
    for (int i = 0; i < tamanho - 1; i++)
    {
        if (sequencia[i] < sequencia[i + 1])
        {
            contadorsequencia++;
        }
        else {
            contadorsequencia = 1;
        }
        
        if (contadorsequencia > contadorMaior)
        {
            contadorMaior = contadorsequencia;
        }
    }
    
    printf("Maior sequência: %d", contadorMaior);
}
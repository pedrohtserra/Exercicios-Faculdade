#include <stdio.h>

int calculo(int N);

int main(void)
{
    int N = 0;

    printf("Calculo da Soma de 1 ate N, exemplo: N = 5; Soma = 1 + 2 + 3 + 4 + 5\n");

    while(N < 1) 
    {
    printf("Escolha o N: ");
    scanf("%d", &N);
    }

    printf("Resultado: %d", calculo(N));
}

int calculo(int N)
{
    int resultado = 0;

    for (int i = 1; i < N + 1; i++)
    {
        resultado = resultado + i;
    }
    
    return resultado;
}
#include <stdio.h>

int fazercalculo(int N);

int main(void)
{
    int N = 1;

    printf("Adicione numeros que seja diferente de 0 na conta, ou seja, para encerrar digite '0':\n");
    
    printf("Calculo encerrado\nTotal Final: %d", fazercalculo(N));
}

int fazercalculo(int N)
{
    int resultado = 0;

    while (N != 0)
    {
        printf("Calcular: %d + ", resultado);
        scanf("%d", &N);
        resultado = resultado + N;
        printf("Total Atual: %d\n", resultado);
    }
    
    return resultado;
}
#include <stdio.h>

int main(void)
{
    int numero = 0;
    int sequencia[] = {1 , 2 , 3};
    int resultado = 0;
    
    do{
    printf("Digite um número: ");
    scanf("%d", &numero);
    } while (numero <= 0);
    
    for (int i = 0; i < 10; i++)
    {
        resultado = sequencia[0] * sequencia[1] * sequencia[2];
        if(numero == resultado)
        {
            printf("O número é triangular.\n");
            return 0;
        }
        
        if(numero < resultado)
        {
            printf("O número não é triangular.");
            return 0;
        }
            sequencia[0]++;
            sequencia[1]++;
            sequencia[2]++;
    }
}
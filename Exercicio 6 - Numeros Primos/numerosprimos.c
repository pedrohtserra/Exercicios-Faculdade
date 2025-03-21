#include <stdio.h>

int verificar(int n);

int main(void)
{
    int numero = 0;
    
    printf("Escolha um número: ");
    
    do
    {
    scanf("%d", &numero);
    } while (numero <= 0);
    
    int resultado = verificar(numero);
    
    if(resultado == 1)
    {
        printf("O número não é primo");
    }
    else {
        printf("O número é primo");
    }
}

int verificar(int n)
{
    if (n == 1)
    {
        return 1;
    }
    
    for (int i = 2; i < n - 1; i++)
    {
        if (n % i == 0)
        {
            return 1;
        }
    }
    
    return 0;
}
// O juros é apenas aplicado nos dias úteis, por isso dias = 22

#include <stdio.h>

int main(void)
{
    double valormensal = 0;
    double taxadejuros = 0;
    double valortotal = 0;
    int anos = 0;
    int dias = 22;
    int meses = 12;
    
    printf("Investir por quantos anos? ");
    scanf("%d", &anos);
    printf("Investir quanto mensalmente? ");
    scanf("%lf", &valormensal);
    printf("Qual a taxa de juros? ");
    scanf("%lf", &taxadejuros);

    for (int k = 0; k < anos; k++)
    {
        for (int j = 0; j < meses; j++)
        {   
            valortotal += valormensal;
            for (int i = 0; i < dias; i++)
            {
                if(i > 0 || j > 0)
                {
                valortotal = valortotal * ((double) 1 + taxadejuros / (double) 100);
                }
            }
        }
    }

    printf("\nValor total: %.2lf\n", valortotal);
    return 0;
}
#include <stdio.h>

int main(void)
{
    double valormensal = 0;
    double taxadejuros = 0;
    double valortotal = 0;
    double valorinvestido = 0;
    double totaljuros = 0;
    int periodo;
    
    printf("Investir por quantos meses? ");
    scanf("%d", &periodo);
    printf("Investir quanto mensalmente? ");
    scanf("%lf", &valormensal);
    printf("Qual a taxa de juros? ");
    scanf("%lf", &taxadejuros);
    
        for (int i = 0; i < periodo; i++)
        {
        valorinvestido += valormensal;
        valortotal = valortotal * ((double) 1 + taxadejuros / (double) 100) + valormensal;
        totaljuros = valortotal - valorinvestido;
        }
        
    printf("\nValor total: %.2lf\n", valortotal);
    printf("Valor total dos juros: %.2lf\n", totaljuros);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int aux = 0;
    int len = 0;
    
    printf("Quantas notas? ");
    scanf("%d", &len);
    // Os Arrays notas e notasOrdenadas vão ter o tamanho da quantidade de notas
    int *notas = (int*) malloc (len * sizeof(int)); 
    int *notasOrdenadas = (int*) malloc (len * sizeof(int));
    // Pega as notas de cada aluno
    for(int i = 0; i < len; i++)
    {
        printf("Aluno %d: ", i + 1);
        scanf("%d", &notas[i]);
    }
    // Dando início para o ordenamento das notas
    for(int i = 0; i < len; i++)
    {
        notasOrdenadas[i] = notas[i];
    }
    // Ordenamento iniciado no Array notasOrdenadas
    for(int i = 0; i < len - 1; i++)
    {
        for(int j = 0; j < len - i - 1; j++)
        {
            if(notasOrdenadas[j] < notasOrdenadas[j + 1])
            {
                aux = notasOrdenadas[j];
                notasOrdenadas[j] = notasOrdenadas[j + 1];
                notasOrdenadas[j + 1] = aux;
            }
        }
    }
    // Printa a maior nota
    printf("Indice Maior = %d", notasOrdenadas[0]);
}
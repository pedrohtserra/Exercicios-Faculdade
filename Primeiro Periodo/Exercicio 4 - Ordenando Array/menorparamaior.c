#include <stdio.h>
#include <stdlib.h>

int main()
{
    int quantNotas = 0;
    int aux = 0;
    
    printf("Quantos alunos: ");
    scanf("%d", &quantNotas);
    
    int* notas = (int*)malloc(quantNotas * sizeof(int));
    
    for (int i = 0; i < quantNotas; i++)
    {
    printf("Nota do aluno %d: ", i + 1);
    scanf("%d", &notas[i]);
    }
    // Esse tipo de "sort" se chama "Bubble Sort"
    for (int i = 0; i < quantNotas - 1; i++)
    {
            for (int j = 0; j < quantNotas - i - 1; j++)
            {
                if (notas[j] > notas[j + 1]) // Apenas foi trocado o sinal
                {
                    aux = notas[j];
                    notas[j] = notas[j + 1];
                    notas[j + 1] = aux;
                 }
             }
    }
    
    printf("Ordenando em ordem crescente:\n");
    for (int i = 0; i < quantNotas; i++)
    {
            printf("%d\n", notas[i]);
    }

free(notas);

return 0;
}
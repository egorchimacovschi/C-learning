// vois const *auto
//asignam vu (cats)
//return dam cu cast
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VALUE 200

int cmp(const void * a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int main(void)
{
    int N, i;
    int *v = NULL;
    int x = 0;
    int *gasit  = 0;
    printf("Introduceti dimensiunea vectorului:\n");
    scanf("%d", &N);

    v = calloc(N, sizeof(int));
    if (!v) {
        printf("Nu am putut aloca memorie pentru v!\n");
        return 1;
    }

    srand(time(NULL));
    for (i = 0; i < N; ++i)
        v[i] = (rand() % MAX_VALUE)+1;

    for (i = 0; i < N; ++i)
        printf("%d ", *(v+i));
    printf("\n");

    qsort(v, N, sizeof(int), cmp);

    for (i = 0; i < N; ++i)
        printf("%d ", *(v+i));
    printf("\n");
    printf("Cititi numrul a carei pozitii trebuie sa redau:\n");
    scanf("%d", &x);
    gasit = (int*)bsearch(&x, v, N, sizeof(int), cmp);
    for (i = 0; i < N; i++) {
        if (*gasit == *(v+i)){
            printf("%d\n", i);
            break;
        }
    }
    free(v);
    return 0;
}
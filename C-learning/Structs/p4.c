#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int *v;
    int n;
    int cap;
} vector;
void init_vector(vector *a, int *size, int dim_initiala) {
    a->v=malloc(dim_initiala * sizeof(int));
    a[0].n=0;
    a[0].cap=dim_initiala;
    *size=1;
}
void adauga_vector(vector a[], int size, int x) {
    int temp = 0;
    scanf("%d", &temp);
    if (a[0].n==a[0].cap) {
        a[0].cap++;
        a[0].v=realloc(a[0].v, a[0].cap * sizeof(int));
    }
    a[0].v[a[0].n]=temp;
    a[0].n++;
}
void scrie_vector(vector a[], int size) {
    int i=0;
    for (i=0; i<a[0].n; i++)
        printf("%d ", a[0].v[i]);
    printf("\n");
}
int main() {
    vector a[1];
    int size;
    init_vector(a, &size, 2);
    for (int i = 0; i <= 100; i++) {
        adauga_vector(a, size, i);
        scrie_vector(a, size);
    }
    free(a[0].v);
    return 0;
}

#include <stdio.h>

void spirala(const int A[][100], int n, int m, int *V) {
    int sus = 0, jos = n-1, stanga = 0, dreapta = m-1;
    int k = 0, i=0, j=0;

    while (sus <= jos && stanga <= dreapta) {
        for (i = sus; i <= jos; i++)
            V[k++] = A[i][stanga];
        stanga++;

        for (j = stanga; j <= dreapta; j++)
            V[k++] = A[jos][j];
        jos--;

        if (stanga <= dreapta) {
            for (i = jos; i >= sus; i--)
                V[k++] = A[i][dreapta];
            dreapta--;
        }

        if (sus <= jos) {
            for (j = dreapta; j >= stanga; j--)
                V[k++] = A[sus][j];
            sus++;
        }
    }
}

int main() {
    int n=0, m=0, i=0, j=0;
    scanf("%d %d", &n, &m);

    if (n == m) {
        printf("ati introdus correct");
        return 0;
    }

    int A[n][100], V[n*m];

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &A[i][j]);

    spirala(A, n, m, V);

    for (i = 0; i < n*m; i++)
        printf("%d ", V[i]);
    printf("\n");

    return 0;
}

#include <stdio.h>
int main () {

    int n,m,p,q,k=0,i,j, A[100][100],B[100][100],C[100][100];
    scanf ("%d %d ", &m, &n);
    for ( i = 0; i < m; i++) {
        for ( j = 0; j < n; j++) {
            scanf ("%d", &A[i][j]);
        }
    }
printf ("\n");

for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
        printf ("%d ", A[i][j]);
    }
    printf ("\n");
}
    scanf ("%d %d", &p, &q);
    printf (" ati introdus %d linii si %d coloane \n", p,q);
    for ( i = 0; i < p; i++) {
        for ( j = 0; j < q; j++) {
            scanf ("%d", &B[i][j]);
        }
    }
    for (i = 0; i < p; i++) {
        for (j = 0; j < q; j++) {
            printf ("%d ", B[i][j]);
        }
        printf ("\n");
    }

    if (n<0 || n>100 || m<0 || m>100||p>100||p<0||q>100||q<0) {
        printf ("Ati introdus incorect variabila gresit");
        return 0;
    }
    if (n!=p) {printf ("Imposibil"); return 0;}
    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            C[i][j] = 0;
            for (k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("%d %d\n", m, q);
    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}
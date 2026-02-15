#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int n;
    int m;
    int **a;
}MATRICE;
MATRICE* creeaza_MATRICE(int n, int m) {
    MATRICE *ma = NULL;
    int i = 0, j = 0;
    ma = (MATRICE*)malloc(sizeof(MATRICE));
    if (ma == NULL) {
        printf ("Erro ao alocar memoria\n");
        exit (1);
    }

    ma->n = n;
    ma->m = m;
    ma->a=(int **)malloc((ma->n)*sizeof (int*));
    if (ma->a == NULL) {
        free (ma);
        exit (1);
    }
    for (i = 0; i < ma->n; i++) {
        ma->a[i] = (int *)malloc((ma->m)*sizeof (int));
        if (ma->a[i] == NULL) {
            for (j = 0; j < i; j++) {
                free(ma->a[j]);
            }
            free(ma->a);
            free(ma);
            exit (1);
        }
    }
    return ma;
}
MATRICE* citeste_MATRICE(MATRICE *ma) {
    int i = 0, j = 0;
    for (i = 0; i < ma->n; i++) {
        for (j = 0; j < ma->m; j++) {
            scanf ("%d", &ma->a[i][j]);
        }
    }
    return ma;
}
void scrie_MATRICE(const MATRICE *ma) {
    int i = 0, j = 0;
    for ( i = 0; i< ma->n; i++) {
        for ( j = 0; j < ma->m; j++) {
            printf ("%d ", ma->a[i][j]);
        }
        printf ("\n");
    }
    printf("\n");
}
void freef(MATRICE *ma) {
    int i = 0;
    for ( i = 0; i<ma->n; i++) {
        free(ma->a[i]);
    }
    free(ma->a);
    free(ma);
}
MATRICE* aduna_MATRICE(MATRICE ma, MATRICE mb) {
    int i = 0, j = 0;
    if (ma.n != mb.n || ma.m != mb.m) {
        return NULL;
    }
    MATRICE *mc = NULL;
    mc = creeaza_MATRICE(ma.n,mb.m);
    for (i = 0; i < mc->n; i++) {
        for (j = 0; j < mc->m; j++) {
            mc->a[i][j] = ma.a[i][j] + mb.a[i][j];
        }
    }
    return mc;
}
MATRICE* inmulteste_MATRICE(MATRICE ma , MATRICE mb) {
    if ( ma.m != mb.n ) return NULL;
    MATRICE *md = NULL;
    int i = 0, j = 0, k = 0;
    md = creeaza_MATRICE(ma.n,mb.m);
    for (i = 0; i < md->n; i++) {
        for (j = 0; j < md->m; j++) {
            md->a[i][j]=0;
            for (k = 0; k < ma.m; k++) {
                md->a[i][j] += ma.a[i][k] * mb.a[k][j];
            }
        }
    }
    return md;
}
int main() {
    MATRICE *ma = NULL,*mb = NULL;
    MATRICE *mc = NULL, *md = NULL;
    int i=0, j=0, k=0, l=0;
    scanf ("%d %d %d %d",&i, &j, &k,&l);
    ma = creeaza_MATRICE(i,j);
    mb = creeaza_MATRICE(k,l);
    ma = citeste_MATRICE(ma);
    mb = citeste_MATRICE(mb);
    scrie_MATRICE(ma);
    scrie_MATRICE(mb);
    mc = aduna_MATRICE(*ma,*mb);
    md = inmulteste_MATRICE(*ma,*mb);
    if (mc == NULL) {
        printf ("Nu putem aduna \n");
    }else {
        scrie_MATRICE(mc);
    }
    if (md == NULL) {
        printf ("Nu se pot inmulti\n");
    }else {
        scrie_MATRICE(md);
    }
    if ( md ) freef(md);
    if ( mc ) freef(mc);
    freef(ma);
    freef(mb);
    return 0;
}
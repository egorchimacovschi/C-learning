#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char *sir;
    int aparitii;
}pereche;
int main () {
    pereche *p = NULL, *temp = NULL;
    char cuvant [1000];
    int poz = 0, i = 0;

    while (scanf("%999s", cuvant) == 1 ) {
        temp = (pereche *)realloc(p,  (poz + 1)* sizeof(pereche));
        if (temp == NULL) {
            for ( i = 0; i < poz; i++ ) {
                free (p[i].sir);
            }
            free(p);
            exit (1);
        }
        p = temp;
        p[poz].sir = (char*)malloc(strlen(cuvant)+1);
        if (p[poz].sir == NULL) {
            for ( i = 0; i < poz; i++ ) {
                free (p[i].sir);
            }
            free(p);
            exit (1);
        }
        strcpy(p[poz].sir, cuvant);
        p[poz].aparitii = 1;
        for ( i = 0; i < poz; i++ ) {
            if (strcmp(p[i].sir, cuvant) == 0) {
                p[i].aparitii++;
                p[poz].aparitii++;
            }
        }
        poz++;
    }
    for (i = 0; i < poz; i++ ) {
        printf ("%s ", p[i].sir);
        printf ("%d\n", p[i].aparitii);
    }
    for (i=0; i < poz; i++ ) {
        free (p[i].sir);
    }
    free(p);
    return 0;
}
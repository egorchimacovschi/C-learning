#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int scanare(char ***v) {
    *v = NULL;
    char cuvant[1000];
    int poz = 0, i = 0;

    while (scanf("%999s", cuvant) == 1) {

        char **temp = realloc(*v, (poz + 1) * sizeof(char *));
        if (temp == NULL) {
            printf("Out of memory");
            exit(1);
        }
        *v = temp;

        (*v)[poz] = malloc(strlen(cuvant) + 1);
        if ((*v)[poz] == NULL) {
            printf("Out of memory");
            for (i = 0; i < poz; i++) {
                free((*v)[i]);
            }
            free(*v);
            exit(1);
        }

        strcpy((*v)[poz], cuvant);
        poz++;
    }
    return poz;
}

void printare(char **v, const int *c, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", v[i], c[i]);
    }
}

void freef(char **v, int *c, int n) {
    for (int i = 0; i < n; i++) {
        free(v[i]);
    }
    free(v);
    free(c);
}

int main() {
    char **v = NULL;
    int *c = NULL;
    int n = 0, i = 0, j = 0;

    n = scanare(&v);

    c = malloc(n * sizeof(int));
    if (c == NULL) {
        for (i = 0; i < n; i++)
            free(v[i]);
        free(v);
        exit(1);
    }

    for (i = 0; i < n; i++) {
        c[i] = 1;
        for (j = i + 1; j < n; j++) {
            if (strcmp(v[i], v[j]) == 0) {
                c[i]++;
                c[j]++;
            }
        }
    }

    printare(v, c, n);
    freef(v, c, n);
    return 0;
}

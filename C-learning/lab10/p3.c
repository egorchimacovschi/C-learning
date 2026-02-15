#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 3

typedef enum { C, S, A } TIP_EXAMEN;

typedef struct {
    char nume[15];
    int ore_curs;
    TIP_EXAMEN tip;
} MATERIA;

void citire_MAT(MATERIA *MAT) {
    int i = -1;
    char buffer[100];
    char t = 0;

    fgets(MAT->nume, 15, stdin);
    MAT->nume[strcspn(MAT->nume, "\n")] = '\0';

    while (i < 0) {
        fgets(buffer, 100, stdin);
        i = atoi(buffer);
    }
    MAT->ore_curs = i;

    fgets(buffer, 100, stdin);
    t = buffer[0];

    if (t == 'C') MAT->tip = C;
    else if (t == 'S') MAT->tip = S;
    else if (t == 'A') MAT->tip = A;
}

void citire_PROGRAMA(MATERIA *PROGRAMA) {
    for (int i = 0; i < MAX; i++) {
        citire_MAT(&PROGRAMA[i]);
    }
}

void afisare_PROGRAMA(char c, int i, MATERIA *PROGRAMA) {
    int k = 0;

    if (c == 'C') k = C;
    if (c == 'S') k = S;
    if (c == 'A') k = A;

    for (int j = 0; j < MAX; j++) {
        if (PROGRAMA[j].ore_curs == i && PROGRAMA[j].tip == k) {
            printf("%s %d %d\n",
                   PROGRAMA[j].nume,
                   PROGRAMA[j].ore_curs,
                   PROGRAMA[j].tip);
        }
    }
}

int main(void) {
    char c2[2];
    char c = 0;
    int i;
    MATERIA PROGRAMA[MAX];

    citire_PROGRAMA(PROGRAMA);

    fgets(c2, sizeof(c2), stdin);
    c = c2[0];

    scanf("%d", &i);

    afisare_PROGRAMA(c, i, PROGRAMA);
    return 0;
}

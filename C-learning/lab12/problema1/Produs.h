#ifndef PRODUS_H
#define PRODUS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

typedef struct {
    char nume_produs[20];
    int cantitate;
    float pret_produs;
} Produs;

void crearea_fisier(const char * nume_fisier);
void afisare_ecran(const char* nume_fisier);

#endif

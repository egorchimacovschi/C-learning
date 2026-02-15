#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Structură care reține o pereche (field, value) */
struct pair {
    char *field;
    char *value;
};
/* Alocă dinamic un vector de struct pair */
void alocare(struct pair **p, const int n) {
    *p = malloc(n * sizeof(struct pair));
    if (!*p) {
        printf("Memory allocation failed\n");
        exit(1);
    }
}
/* Citește cele n perechi (field, value) și alocă memorie pentru fiecare */
void citire(struct pair **p, const int n) {
    int i = 0, k = 0;
    char field2[2000], value2[2000];
    for (i = 0; i < n; i++) {
        scanf("%1999s %1999s", field2, value2);
        /* Alocare și copiere pentru field */
        (*p)[i].field = malloc(strlen(field2) + 1);
        if (!(*p)[i].field) {
            printf("Memory allocation failed\n");
            /* Eliberăm ce a fost alocat anterior */
            for (k = 0; k < i; k++) {
                free((*p)[k].field);
                free((*p)[k].value);
            }
            free(*p);
            exit(1);
        }
        strcpy((*p)[i].field, field2);
        /* Alocare și copiere pentru value */
        (*p)[i].value = malloc(strlen(value2) + 1);
        if (!(*p)[i].value) {
            printf("Memory allocation failed\n");
            for (k = 0; k <= i; k++) {
                free((*p)[k].field);
                if (k < i) {
                    free((*p)[k].value);
                }
            }
            free(*p);
            exit(1);
        }
        strcpy((*p)[i].value, value2);
    }
}
/* Citește linia întreagă (formularul) folosind fgets */
void citire2(char **formular) {
    char tmp[11000];
    /* Consumă newline-ul rămas după scanf */
    getchar();
    fgets(tmp, sizeof(tmp), stdin);
    /* Elimină newline-ul de la final */
    if (strlen(tmp) > 0 && tmp[strlen(tmp) - 1] == '\n') {
        tmp[strlen(tmp) - 1] = '\0';
    }
    *formular = (char *)malloc((strlen(tmp) + 1) * sizeof(char));
    if (!*formular) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(*formular, tmp);
}
/* Verifică dacă un caracter este delimitator */
int este_delimitator(const char delim) {
    if (delim == ' '  || delim == '\n' || delim == '\0' ||
        delim == '-'  || delim == '.'  || delim == ','  ||
        delim == ';'  || delim == ':'  || delim == '?'  ||
        delim == '!'  || delim == '"') {
        return 1;
    }
    return 0;
}
/*
Înlocuiește toate aparițiile câmpurilor (field) din formular
cu valorile (value), DOAR dacă sunt cuvinte întregi
*/
void substituire(const struct pair *p, char **formular, const int n) {
    char *tmp = NULL, *field = NULL, *value = NULL, *pos = NULL;
    int i = 0, prefix = 0, dim = 0;
    for (i = 0; i < n; i++) {
        field = p[i].field;
        value = p[i].value;
        /* Caută prima apariție a field-ului */
        pos = strstr(*formular, field);
        /* Parcurge toate aparițiile */
        while (pos) {
            /*
            Verifică dacă field este delimitat corect
            (nu face parte dintr-un cuvânt mai mare)
            */
            if ((pos == *formular || este_delimitator(*(pos - 1))) &&
                este_delimitator(*(pos + strlen(field)))) {
                /* Calculează dimensiunea noului șir */
                dim = strlen(*formular) - strlen(field) + strlen(value) + 1;
                tmp = (char *)malloc(dim * sizeof(char));
                /* Copiază prefixul */
                prefix = pos - *formular;
                strncpy(tmp, *formular, prefix);
                tmp[prefix] = '\0';
                /* Adaugă valoarea și restul șirului */
                strcat(tmp, value);
                strcat(tmp, pos + strlen(field));
                free(*formular);
                *formular = tmp;
                /* Continuă căutarea după zona înlocuită */
                pos = strstr(tmp + prefix + strlen(value), field);
            } else {
                /* Dacă nu e cuvânt întreg, caută mai departe */
                pos = strstr(pos + 1, field);
            }
        }
    }
}
/* Eliberează toată memoria alocată */
void free_pairs(struct pair **p, char **formular, const int n) {
    int i = 0;
    for (i = 0; i < n; i++) {
        free((*p)[i].field);
        free((*p)[i].value);
    }
    free(*p);
    *p = NULL;
    free(*formular);
    *formular = NULL;
}
int main() {
    int n;
    struct pair *p = NULL;
    char *formular = NULL;
    scanf("%d", &n);
    alocare(&p, n);
    citire(&p, n);
    citire2(&formular);
    substituire(p, &formular, n);
    printf("%s\n", formular);
    free_pairs(&p, &formular, n);
    return 0;
}

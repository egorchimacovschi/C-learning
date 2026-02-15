#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*
Generează un șir aleator de lungime len,
folosind caractere ASCII imprimabile (32–125)
 */
char* random_string(const int len)
{
    char *string = NULL;
    int i = 0;
    if (len <= 0) {
        return NULL;
    }
    string = (char *)malloc((len + 1) * sizeof(char));
    if (string == NULL) {
        printf("Memory allocation failed in random_string\n");
        exit(1);
    }
    for (i = 0; i < len; i++) {
        string[i] = 32 + (rand() % 94);
    }
    string[len] = '\0';
    return string;
}
/*
Codificare 1:
- pentru fiecare caracter p, reține de câte ori a apărut
- întoarce p urmat de numărul apariției curente
 */
char* codificare1(const char p)
{
    /* contor apariții pentru fiecare caracter */
    static int v[126] = {0};     
    static int init = 0;
    int copy = 0, count = 0, i = 0, pos = 0;
    char *string = NULL;
    /* inițializare vector static o singură dată */
    if (!init) {
        for (i = 0; i < 126; i++) {
            v[i] = 0;
        }
        init = 1;
    }
    copy = v[(int)p];
    /* determină câte cifre are numărul apariției */
    if (copy == 0) {
        count = 1;
    }
    else {
        while (copy != 0) {
            copy /= 10;
            count++;
        }
    }
    copy = v[(int)p];
    string = (char *)malloc((count + 2) * sizeof(char));
    if (string == NULL) {
        printf("Memory allocation failed in codificare1\n");
        return NULL;
    }
    string[0] = p;
    /* cazul primei apariții */
    if (copy == 0) {
        string[1] = '0';
        string[2] = '\0';
    }
    else {
        /* scrierea cifrelor de la dreapta la stânga */
        pos = count;
        while (copy != 0) {
            string[pos] = (copy % 10) + '0';
            copy /= 10;
            pos--;
        }
        string[count + 1] = '\0';
    }
    v[(int)p]++; /* incrementarea contorului */
    return string;
}
/*
Codificare 2:
- modifică biții caracterului
- calculează numărul de biți de 1
- returnează caracterul modificat + cifra numărului de biți
 */
char* codificare2(char p)
{
    int count = 0;
    char *string = NULL;
    char copy = 0;
    /* inversare biți specifici */
    p ^= (1 << 3);
    p ^= (1 << 6);
    copy = p;
    /* numără biții de 1 */
    while (copy) {
        count += copy & 1;
        copy >>= 1;
    }
    /* setare / resetare biți */
    p |= (1 << 5);
    p &= ~(1 << 0);
    string = (char *)malloc(3 * sizeof(char));
    if (string == NULL) {
        printf("Memory allocation failed in codificare2\n");
        return NULL;
    }
    string[0] = p;
    string[1] = count + '0';
    string[2] = '\0';
    return string;
}
/*
 * Codificare 3:
- transformă literele mici în majuscule
- returnează caracterul rezultat
 */
char* codificare3(char p)
{
    char *string = NULL;
    string = (char *)malloc(2 * sizeof(char));
    if (string == NULL) {
        printf("Memory allocation failed in codificare3\n");
        return NULL;
    }
    if (p >= 'a' && p <= 'z') {
        p -= 32;
    }
    string[0] = p;
    string[1] = '\0';
    return string;
}
/*
Codificare 4:
- parcurge șirul inițial
- pentru fiecare caracter alege ALEATOR o funcție de codificare
- concatenează rezultatele într-un șir final
*/
char* codificare4(const char* string, char* (*transformari[3])(char))
{
    int i = 0, k = 0;
    int sir_len = 0, len_finala = 0, len_codificat = 0;
    char *resultat_final = NULL;
    char *tmp = NULL;
    char *char_codificat = NULL;
    char *(*functia)(char) = NULL;
    if (string == NULL) {
        printf("Memory allocation failed in random_string\n");
        return NULL;
    }
    sir_len = strlen(string);
    /* șir rezultat inițial gol */
    resultat_final = (char *)malloc(1 * sizeof(char));
    if (resultat_final == NULL) {
        printf("Memory allocation failed in codificare4\n");
        return NULL;
    }
    resultat_final[0] = '\0';
    for (i = 0; i < sir_len; i++) {
        /* alege aleator una dintre cele 3 funcții */
        k = rand() % 3;
        functia = transformari[k];
        char_codificat = functia(string[i]);
        if (char_codificat == NULL) {
            printf("Memory allocation failed\n");
            free(resultat_final);
            return NULL;
        }
        len_codificat = strlen(char_codificat);
        /* realocare pentru concatenare */
        tmp = (char *)realloc(
            resultat_final,
            len_codificat + len_finala + 1
        );
        if (tmp == NULL) {
            printf("Memory allocation failed in codificare4\n");
            free(resultat_final);
            free(char_codificat);
            return NULL;
        }
        resultat_final = tmp;
        /* adaugă codificarea la final */
        strcpy(resultat_final + len_finala, char_codificat);
        len_finala += len_codificat;
        free(char_codificat);
    }
    return resultat_final;
}
int main()
{
    int seed = 0, len = 0;
    char *string = NULL;
    char *string_codificat = NULL;
    char* (*transformari[3])(char) = {
        codificare1,
        codificare2,
        codificare3
    };
    scanf("%d %d", &seed, &len);
    srand(seed);
    string = random_string(len);
    if (!string) {
        printf("Memory allocation failed in random_string\n");
        return 1;
    }
    string_codificat = codificare4(string, transformari);
    if (!string_codificat) {
        printf("Memory allocation failed\n");
        free(string);
        return 1;
    }
    printf("%s\n", string_codificat);
    free(string);
    free(string_codificat);
    return 0;
}
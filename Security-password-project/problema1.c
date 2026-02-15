#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Citește cheia și textul.
Limita 13999 previne overflow-ul bufferului.
*/
void citire(char *key, char *text) {
    scanf("%13999s", key);
    scanf("%13999s", text);
}
/*
Verifică dacă șirul conține doar litere (A–Z, a–z).
Returnează 1 dacă există un caracter invalid,
0 dacă șirul este valid.
*/
int test(const char *line) {
    int i = 0;
    int len = 0;
    len = strlen(line);
    for (i = 0; i < len; i++) {
        if ((line[i] < 'A' || line[i] > 'Z') \
        && (line[i] < 'a' || line[i] > 'z')) {
            return 1;
        }
    }
    return 0;
}
/*
Verifică dacă atât cheia cât și textul
conțin exclusiv litere.
Dacă nu, programul se oprește.
*/
void letters(const char *key, const char *text) {
    if (test(key) || test(text)) {
        printf("INVALID\n");
        exit(1);
    }
}
/*
Extinde cheia astfel încât să aibă
aceeași lungime ca textul.
*/
void key_transform(char *key, const char *text) {
    int i = 0, key_len = 0, len_text = 0;
    len_text = strlen(text);
    key_len = strlen(key);
    if (key_len == 0) {
        return;
    }
    i = key_len;
    while (i < len_text) {
        key[i] = key[i % key_len];
        i++;
    }
    key[i] = '\0';
}
/*
Criptarea propriu-zisă (tip Vigenère modificat).
sir conține alfabetul de două ori pentru a evita
ieșirea din index la adunare.
*/
void criptare(char *key, char *text) {
    int k = 0, i = 0, text_len = 0, pos1 = 0, dist = 0;
        char sir[104]=
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    text_len=strlen(text);
    key_transform(key, text);
    for (k = 0; k < text_len; k++) {
        dist = 0;
        /* Găsire poziție caracter text */
        for (i = 0; i < 52; i++) {
            if (text[k] == sir[i]) {
                pos1 = i;
                break;
            }
        }
        /* Găsire deplasare din cheie */
        for (i = 0; i < 52; i++) {
            if (key[k] == sir[i]) {
                dist = i;
                break;
            }
        }
        /*
         Aplicarea criptării:
         poziție text + deplasare cheie
         */
        text[k] = sir[(pos1 + dist) % 52];
    }
}
int main() {
    char key[14000], text[14000];
    citire(key, text);
    letters(key, text);
    criptare(key, text);
    printf("%s\n", text);
    return 0;
}
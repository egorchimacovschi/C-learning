#include <stdio.h>
#include <string.h>
#define MAX 10000
int main (int argc, char **argv) {
    FILE *result = NULL;
    FILE *input = NULL;
    FILE *cod = NULL;
    char c=0;
    char temp[MAX];
    result = fopen("output.txt","w+");
    if (result == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    input = fopen("input2.txt","r");
    if (input == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    cod = fopen("tabela_de_codare.txt","r");
    if (cod == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    while ((c=fgetc(input)) != EOF) {
        rewind (cod);
        while (fgets(temp, MAX, cod ) != NULL) {
            if (c == temp[0]) {
                c = temp[2];
                break;
            }
            else if (c == temp[0] - 32) {
                c = temp[2] - 32;
                break;
            }
        }
        fputc(c, result);
    }
    fclose (input);
    fclose (cod);
    fclose (result);
    return 0;
}
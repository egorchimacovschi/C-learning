#include <stdio.h>
#include <string.h>
#define BUFMAX 10001
#define MAX 100000
int main (int argc, char **argv) {
    int i = 0 ;
    char temp[BUFMAX];
    FILE *fp = NULL;
    char result[MAX];
    result[0]='\0';
    for (i = 1; i < argc; i++ ) {
        fp = fopen(argv[i], "r");
        if (fp == NULL) {
            continue;
        }
            while (fgets(temp, BUFMAX, fp) != NULL) {
                strcat(result, temp);

        }
    }
    printf ("%s\n", result);
    fclose(fp);

    return 0;
}
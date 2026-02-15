#include <stdio.h>
#include <string.h>
#define BUFMAX 10001
int main (int argc, char **argv) {
    int i = 0 ;
    char temp[BUFMAX];
    FILE *fp = NULL, *result = NULL;
    result = fopen(argv[1], "w");
    if (result == NULL) {
        fprintf (stderr,"Error opening file\n");
        return 0;
    }
    for (i = 2; i < argc; i++ ) {
        fp = fopen(argv[i], "r");
        if (fp == NULL) {
            fprintf (stderr,"Error opening file\n");
            return 0;
        }
        while (fgets(temp, BUFMAX, fp) != NULL) {
            fputs(temp, result);
        }
        fclose(fp);
    }
    fclose(result);
    return 0;
}
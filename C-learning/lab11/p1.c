#include <stdio.h>
#include <stdlib.h>
#define BUFMAX 1005
int main ( int argc, char **argv) {
    FILE *pFile = NULL;
    char buffer[BUFMAX];
    pFile = fopen ("myfile.txt", "r");
    if (pFile == NULL) {
        printf ("Nu sa putut deschide fisierul");
        return 1;
    }
    while (fgets(buffer, BUFMAX, pFile) != NULL ) {
        printf ("%s", buffer);
    }
    fclose (pFile);
    return 0;
}
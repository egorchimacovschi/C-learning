#include <stdio.h>
#include <string.h>
#define BUFFMAX 10001
int main(int argc, char *argv[]) {
    char buffer1[BUFFMAX], *buffer2=NULL;
    FILE *input = fopen(argv[1], "r");
    char word[BUFFMAX];
    if (input == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    strcpy(word, argv[2]);
    printf ("%s", word);
    while (fgets(buffer1, BUFFMAX, input) != NULL) {
        buffer2 = strstr(buffer1, word);
        if (buffer2) {
            printf("%s", buffer1);
        }
    }
    fclose(input);
    return 0;
}
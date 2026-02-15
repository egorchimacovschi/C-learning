#include <stdio.h>
#include <string.h>
char *next(char *from, char *word) {
    int i = 0;
    while (*from && (*from < 'a' || *from > 'z')) {
        from++;
    }
    while (*from && (*from >= 'a' && *from <= 'z')) {
        word[i++] = *from++;
    }
    word[i] = '\0';
    return from;
}

int main() {
    char line[256];
    char word[100];
    char *ptr=0;
    printf("Introduceți o linie: ");
    fgets(line, sizeof(line), stdin);
    line[strcspn(line, "\n")] = '\0';
    ptr = line;
    while (*ptr) {
        ptr = next(ptr, word);
        if (strlen(word) > 0) {
            printf("%s ", word);
        }
    }
    return 0;
}

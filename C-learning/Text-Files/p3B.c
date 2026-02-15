#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define BUFMAX 1000

int contains(const char *line ,const char *word, int sensitive) {
    int line_len = 0, word_len = 0;
    int i = 0, j = 0;
    char c1 = 0, c2 = 0;
    line_len = strlen(line);
    word_len = strlen(word);
    for (i = 0; i <= line_len - word_len; i++) {
        for (j = 0; j < word_len; j++) {
            c1 = line[i + j];
            c2 = word[j];
            if (sensitive) {
                c1 = tolower(c1);
                c2 = tolower(c2);
            }
            if (c1 != c2) break;
        }
        if (j == word_len) return 1;
    }
    return 0;
}

int main(const int argc, char **argv) {
    if (argc < 3) return 1;

    char word[BUFMAX];
    FILE *input = NULL;
    int sensitive = 0, show_line_numbers = 0, show_count = 0, i = 0;
    char line[BUFMAX];
    int line_num = 0, found_lines = 0;

    strcpy(word, argv[argc-1]);
    input = fopen(argv[argc-2], "r");
    if (input == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    for (i = 1; i < argc - 2; i++) {
        if (strcmp(argv[i], "i") == 0) sensitive = 1;
        else if (strcmp(argv[i], "n") == 0) show_line_numbers = 1;
        else if (strcmp(argv[i], "c") == 0) show_count = 1;
    }

    while (fgets(line, BUFMAX, input) != NULL) {
        line_num++;
        if (contains(line, word, sensitive)) {
            found_lines++;
            if (!show_count || show_line_numbers) {
                if (show_line_numbers)
                    printf("[%d] ", line_num);
                printf("%s", line);
            }
        }
    }

    if (show_count) {
        printf("Numar total de linii: %d\n", found_lines);
    }

    fclose(input);
    return 0;
}

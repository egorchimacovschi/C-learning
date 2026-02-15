#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_replace(const char *s,const char *s1,const char *s2) {
    int len_s=strlen(s), len_s1=strlen(s1), len_s2=strlen(s2);
    char *temp = strstr(s,s1);
    char *result = NULL;

    if (temp==NULL) {
        result = malloc(len_s+1);
        if (!result) { printf("malloc error\n"); exit(1); }
        strcpy(result, s);
        return result;
    }

    int len_before = temp - s;
    result = malloc(len_s + len_s2 - len_s1 + 1);
    if (!result) { printf("malloc error\n"); exit(1); }

    strncpy(result, s, len_before);
    result[len_before] = '\0';
    strcat(result, s2);
    strcat(result, temp + len_s1);

    return result;
}

void citires(char **s) {
    char temp[100];
    if (!fgets(temp, 100, stdin)) {
        printf("Input error\n");
        exit(1);
    }
    int len = strlen(temp);
    if (len>0 && temp[len-1]=='\n') temp[len-1]='\0';

    *s = malloc(len + 1);
    if (!*s) { printf("malloc error\n"); exit(1); }
    strcpy(*s,temp);
}

int main() {
    char *s=NULL, *s1=NULL, *s2=NULL, *new_sir=NULL;

    citires(&s);
    citires(&s1);
    citires(&s2);

    new_sir = my_replace(s, s1, s2);

    printf("%s\n", new_sir);

    free(s);
    free(s1);
    free(s2);
    free(new_sir);

    return 0;
}

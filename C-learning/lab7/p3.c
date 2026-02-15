#include <stdio.h>
#include <string.h>
char* strdel(char *p, int n) {
    char* aux[100];
    *aux=p;
    strcpy(*aux, p+n);

    return *aux;
}
char *strins(char *p,const char *s1) {
    char aux[3000];
    strcpy(aux, p);
    strcpy(p, s1);
    strcat(p, aux);
    return p;
}

int main () {
    char text[3000], s1[20], s2[20];
    int len2=0;
    fgets(text, 3000, stdin);
    text[strlen(text)-1]='\0';
    char *copy=0;

    fgets(s1, 20, stdin);
    fgets(s2, 20, stdin);
    //s1[strcspn(s1, "\n")]='\0';
    //s2[strcspn(s2, "\n")]='\0';
    s1[strlen(s1)-1]='\0';
    s2[strlen(s2)-1]='\0';

    copy =text;
    len2=strlen(s2);
    while ((copy=strstr(copy, s2))!=NULL){
        strdel(copy, len2);
        strins(copy, s1);
        copy+=strlen(s1);
    }
    printf ("%s", text);

    return 0;
}
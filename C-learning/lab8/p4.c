#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int egal_char(char a, char b) {
    if (a == b) return 1;
    if (a >= 'A' && a <= 'Z') a += 32;
    if (b >= 'A' && b <= 'Z') b += 32;
    return a == b;
}

void citirecuv(char ***v,const int n) {
    int i=0, k=0;
    *v=(char **)malloc(n*sizeof(char *));
    if (*v==NULL) exit(1);
    for (i=0; i<n; i++) {
        (*v)[i]=(char *)malloc(100*sizeof(char));
        if ((*v)[i]==NULL) {
            for (k=0;k<i;k++) free((*v)[k]);
            free(*v);
            exit(1);
        }
        scanf("%s", (*v)[i]);
    }
}

void formaresir(char **v, char **c, const int n) {
    int i=0, size=0;
    for (i=0; i<n; i++) size += strlen(v[i]) + 1;
    *c = (char *)malloc(size * sizeof(char));
    if (*c == NULL) exit(1);
    (*c)[0]='\0';
    strcat(*c, v[0]);
    char *last = v[0];

    for (i=1; i<n; i++) {
        int len_last = strlen(last);
        int len_cur = strlen(v[i]);
        if (len_last >= 2 && len_cur >= 2) {
            if (egal_char(last[len_last-2], v[i][0]) &&
                egal_char(last[len_last-1], v[i][1])) {
                strcat(*c, "-");
                strcat(*c, v[i]);
                last = v[i];
                }
        }
    }
}

void freeall(char **v, char *c, const int n) {
    int i=0;
    for (i=0;i<n;i++) free(v[i]);
    free(v);
    free(c);
}

int main() {
    int n=0;
    char **v=NULL, *c=NULL;
    scanf("%d",&n);
    citirecuv(&v,n);
    formaresir(v,&c,n);
    printf("%s\n", c);
    freeall(v,c,n);
    return 0;
}

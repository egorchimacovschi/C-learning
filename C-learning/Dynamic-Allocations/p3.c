#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void citire_cuvinte(char ***v, const int n) {
int i=0, k=0;
    *v=(char **)malloc(n*sizeof(char *));
    if (*v==NULL) {
        printf("Erreur\n");
        exit(1);
    }
    for (i=0; i<n; i++) {
        (*v)[i]=(char *)malloc(20*sizeof(char));
        if ((*v)[i]==NULL) {
            printf("Erreur\n");
            for (k=0; k<i; k++) {
                free((*v)[k]);
            }
            free(*v);
            exit(1);
        }
        scanf("%19s", (*v)[i]);
        getchar();
    }
}

void num_aparitii(char **v, int **c, const int n) {
    int i=0, k=0, count=0, l=0;
    char *temp=NULL;

    *c=(int*)malloc(n*sizeof(int));
    if ((*c)==NULL) {
        printf("Erreur\n");
        for (k=0; k<n; k++) {
            free(v[k]);
        }
        free(*v);
        exit(1);
    }

    for (i=0; i<n; i++) {
        count=0;
        temp=v[i];
        for (k=0; k<n; k++) {
            if (strcmp(temp, v[k]) == 0) {
                count++;
            }
        }
        (*c)[l++]=count;
    }
    for (i=0; i<n; i++) {
        printf ("%s %d \n", v[i], (*c)[i]);
    }
}

void freeall(char **v,int *c, int n) {
    int i=0;
    for (i=0; i<n; i++) {
        free(v[i]);
    }
    free(c);
    free(v);
}
int main() {
    int n=0;
    char **v=NULL;
    int *c=NULL ;
    scanf("%d",&n);
    getchar();
    citire_cuvinte(&v,n);
    num_aparitii(v,&c, n);
    freeall(v,c,n);
    return 0;
}
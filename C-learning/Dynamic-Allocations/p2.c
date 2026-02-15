#include <stdio.h>
#include <stdlib.h>
void citirev(int **v, int cap, int *n) {
    int temp=0;
    int *tmp=NULL;
    *n=0;
    *v=(int*)malloc(cap*sizeof(int));
    if (*v==NULL) {
        printf("Erreur\n");
        exit(1);
    }
    while(1) {
        scanf("%d",&temp);
        if (temp==0) {
            return;
        }
        if (*n==cap) {
            cap*=2;
            tmp = (int*)realloc(*v, cap*sizeof(int));
            if (tmp==NULL) {
                printf("Erreur\n");
                free(*v);
                exit(1);
            }
            *v=tmp;
        }
        (*v)[(*n)++]=temp;
    }
}
void afisarev(const int *v, const int n) {
    int i=0;
    for (i=0; i<n; i++) {
        printf("%d ",v[i]);
    }
    printf("0 \n");
}
void freev(int *v) {
    free(v);
}
int main() {
    int *v=NULL;
    int cap=5, n=0;
    citirev(&v, cap, &n);
    afisarev(v, n);
    freev(v);
    return 0;
}
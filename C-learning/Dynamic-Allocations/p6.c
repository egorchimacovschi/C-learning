#include <stdio.h>
#include <stdlib.h>
int combinari(const int n,const int k) {
    int *vim_orig=calloc((n+1),sizeof(int));
    int *vi_orig=calloc((n+1),sizeof(int));
    if(vim_orig==NULL ||vi_orig ==NULL) {
        printf("Allocate memory for vim1 failed\n");
        exit(1);
    }
    int *vim1=vim_orig;
    int *vi=vi_orig;
    int *temp=NULL;
    int i=0, j=0, value=0;

    vim1[0]=1;
    for(i=1;i<=n;i++) {
        for(j=0;j<=i;j++) {
            if (j==0||j==i) {
                vi[j]=1;
            }
            else  {
                vi[j]=vim1[j]+vim1[j-1];
            }
        }
        temp=vim1;
        vim1=vi;
        vi = temp;
    }
    value = vim1[k];
    free(vim_orig);
    free(vi_orig);
    return value;
}
int main() {
    int n=0, k=0;
    scanf("%d %d", &n ,&k);
    printf ("C[%d][%d]=%d \n",n,k,combinari(n,k));
    return 0;
}
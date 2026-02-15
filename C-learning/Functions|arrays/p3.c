#include <stdio.h>
int vectornedistinct(int n, int m,const int *a,const int *b, int *c) {
    int i=0, j=0, k=0, aux=0,count=0;
    for (i=0; i<n; i++) {
        count=0;
        aux=a[i];
        for (j=0; j<m; j++) {
            if (aux==b[j]) {
                count=1;
                break;
            }
        }if (count) {
            c[k]=aux;
            k++;
        }
    }
    return k;
}
int main () {
  int n=0,m=0,k=10,i=0;
    scanf("%d", &n);
    int a[n],c[k];
    for (i=0;i<n;i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    int b[m];
    for (i=0;i<m;i++) {
        scanf("%d", &b[i]);
    }
    k=vectornedistinct(n,m,a,b,c);
    for (i=0; i<k; i++) {
        if (c[i]!=0) {
            printf("%d ", c[i]);
        }else {break;}
    }
    return 0;
}
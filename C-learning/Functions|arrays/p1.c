#include <stdio.h>
void bublesort(int n, int *v) {
    int i=0,N=0, aux=0;
    for (N=n;N>0;N--) {
        for (i=0; i<N-1; i++) {
            if (v[i]>v[i+1]) {
                aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
            }
        }
    }
}

int main () {
    int n=0, i=0;
    scanf("%d", &n);
    int a[n];
    for (i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    bublesort(n,a);
    for (i=0; i<n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}

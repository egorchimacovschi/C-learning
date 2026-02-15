#include<stdio.h>
void transform(int v[],const int n,const int* x) {
    int i=0, aux=0,nr=0;
    for (i=0; i<n; i++) {
        if (v[i]<*x) {
            aux=v[nr];
            v[nr]=v[i];
            v[i]=aux;
            nr++;
        }
    }
}
int main() {
    int n=0, x=0, i=0;
    scanf("%d %d", &n, &x);
    int v[n];
    for (i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    transform(v, n, &x);
    for (i=0; i<n; i++) {
        printf("%d ", v[i]);
    }
}
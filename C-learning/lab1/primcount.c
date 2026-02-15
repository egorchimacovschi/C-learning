#include <stdio.h>
int pozMax(const int *v, int n) {
    int i=0, max_ind = 0;
    for (i=1; i<n; i++) {
        if (v[i]>v[max_ind]) {
            max_ind = i;
        }
    }
    return max_ind;
}
void citirevector(int *v, const int n) {
    int i=0;
    for (i=0; i<n; i++) {
        scanf("%d",&v[i]);
    }
}
void afisarevector(const int *v,const int n) {
    for (int i=0; i<n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}
void vectorordonat(int *v,const int n) {
    int i=0,aux=0,max_ind=0;
    for (i=n; i>1; i--) {
        max_ind=pozMax(v,i);
        aux=v[max_ind];
        v[max_ind]=v[i-1];
        v[i-1]=aux;
    }
}
int main () {
    int n=0;
    scanf ("%d", &n);
    int v[n];
    citirevector(v,n);
    afisarevector(v, n);
    vectorordonat(v, n);
    afisarevector(v, n);
    return 0;
}
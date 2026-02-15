#include <stdio.h>
int factorial(int n) {
    int f = 1, i;
    for ( i = 1 ; i <= n ; i ++ ) {
        f *= i;
    }
    return f;
}

int main () {

int n, i, s=0;
    scanf ("%d", &n);
    for (i=1; i<=n; i++) {
        s+=factorial(i);
    }
    printf ("%d", s);
    return 0;
}
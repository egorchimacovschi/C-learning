#include <stdio.h>
#include <math.h>

int prim(int n) {
    int i=0, j=0;
    for (i=2;i<=sqrt(n);i++) {
        if (n%i==0) return 0;
    }
    return 1;
}

int main () {
int n;

    scanf ("%d", &n);
    if (n<=2 || n >=200000) {
        printf("n is too big"); return 0;
    }
    if (prim(n)) {
        printf ("%d is a prime number\n", n);
    } else {
        printf ("%d is not a prime number\n", n);
    }
    for (int i=1; i<(n/2);i++) {
        if (prim(i)) {
            for (int j=1;j<n;j++) {
                if (prim(j)) {
                    if ( (i+j)==n) {
                        printf ("%d + %d\n", i, j);
                    }
                }

            }
        }
    }

    return 0;
}

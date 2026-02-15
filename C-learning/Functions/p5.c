#include <stdio.h>
#include <math.h>
int factorial(int n) {
int f=1, i=0;
    for (i=2; i<=n; i++) {
        f*=i;
    }
    return f;
}
double putere(double x, int n) {
    return pow (x, n);
}
double taylor (double x, int n) {
int i=0;
    double s=0;
    for (i=0; i<=n; i++) {
        s+=putere(x, i)/factorial(i);
    }return s;
}


int main () {
double x;
    int n;

    scanf("%lf", &x);
    scanf ("%d", &n);
    if (n<0 || n>1000) {return 0;}

    printf ("%.4lf",taylor(x, n));

    return 0;
}
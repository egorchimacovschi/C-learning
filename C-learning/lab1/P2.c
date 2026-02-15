#include <math.h>
#include <stdio.h>
int main () {
int a, b, c;
    float x1,x2,d;
    scanf ("%d %d %d", &a, &b, &c);
    d=b*b-4.0*a*c;
    x1=(-b+sqrt(d))/2.0*a;
    x2=(-b-sqrt(d))/2.0*a;
    printf ("%.2f %.2f", x1, x2);
    return 0;
}


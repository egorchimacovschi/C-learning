#include <stdio.h>
int main () {
    int a,b,c;
    scanf ("%d %d %d", &a, &b, &c);
    if (a>b && a>c && b>c) {printf ("%d %d %d", c, b, a); return 0;}
    if (a>b && c>b && a>c) {printf ("%d %d %d", b, c, a); return 0;}
    if (b>a && b>c && a>c) {printf ("%d %d %d", c, a, b); return 0;}
    if (b>a && b>c && c>a) {printf ("%d %d %d", a, c, b); return 0;}
    if (c>a && c>b && b>a) {printf ("%d %d %d", a, b, c); return 0;}
    if (c>a && c>b && b<a) {printf ("%d %d %d", b, a, c); return 0;}
    return 0;
}
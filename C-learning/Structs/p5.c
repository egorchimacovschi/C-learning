#include <stdio.h>
typedef struct {
    float re;
    float img;
}complex;

void citire(complex *x) {
    scanf ("%f", &x->re);
    scanf ("%f", &(*x).img);
}
void adunare (complex a, complex b, complex *c) {
    c->re=a.re+b.re;
    c->img=a.img+b.img;
}
void printare1( complex x) {
    printf ("a = %f + ", x.re);
    printf ("%fi\n", x.img);
}
void printare2( complex x) {
    printf ("b = %f + ", x.re);
    printf ("%fi\n", x.img);
}
void printare3( complex x) {
    printf ("c = %f + ", x.re);
    printf ("%fi\n", x.img);
}
void scadere (complex a, complex b, complex *c) {
    c->re=a.re-b.re;
    c->img=a.img-b.img;
}
void inmultire (complex a, complex b, complex *c) {
    c->re=a.re*b.re+a.img*b.img*(-1);
    c->img=a.re*b.img+a.img*b.re;
}
complex putere(complex a, int n) {
    complex d;
    d.re=a.re*a.re+a.img*a.img*(-1);
    d.img=a.re*a.img+a.img*a.re;
    n -= 2;
    while ( n != 0) {
        d.re=d.re*a.re+d.img*a.img*(-1);
        d.img=d.img*a.re+d.re*a.img;
        n--;
    }
    return d;
}
void scriere(complex a) {
    printf ("(%f, %f)\n)", a.re, a.img);
}
int main () {
    int n = 0;
    complex a,b,c;
    citire(&a);
    citire(&b);
    printare1(a);
    printare2(b);
    adunare (a,b,&c);
    printare3(c);
    scadere(a,b,&c);
    printare3(c);
    inmultire(a,b,&c);
    printare3(c);scanf ("%d", &n);
    if (n==0) {
        c.re=1;
        c.img=0;
        goto continuare;
    }
    if (n == 1) {
        c.re = a.re;
        c.img = a.img;
        goto continuare;
    }
        c=putere(a,n);
    continuare:
    printare3(c);
    scriere(c);
    return 0;
}
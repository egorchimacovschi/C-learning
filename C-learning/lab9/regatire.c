#include <stdio.h>

typedef struct {
    char tipn;
    union {
        int ival;
        long lval;
        float fval;
        double dval;
    } v;
} number;

number citire(char tip) {
    number n;
    n.tipn = tip;

    switch (tip) {
        case 'i': scanf("%d", &n.v.ival); break;
        case 'l': scanf("%ld", &n.v.lval); break;
        case 'f': scanf("%f", &n.v.fval); break;
        case 'd': scanf("%lf", &n.v.dval); break;
        default: break;
    }

    return n;
}

void write(number n) {
    switch (n.tipn) {
        case 'i': printf("%d ", n.v.ival); break;
        case 'l': printf("%ld ", n.v.lval); break;
        case 'f': printf("%f ", n.v.fval); break;
        case 'd': printf("%lf ", n.v.dval); break;
        default: break;
    }
}

int main() {
    number a={0}, b={0}, c={0}, d={0};

    a = citire('i');
    b = citire('l');
    c = citire('f');
    d = citire('d');

    write(a);
    write(b);
    write(c);
    write(d);

    return 0;
}

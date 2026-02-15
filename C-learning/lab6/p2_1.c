#include <stdio.h>
#include <math.h>
void calculareaunghiurilor( const double* a,const double* b,const double* c, double* u1, double* u2, double* u3 ) {
    double i1=0, i2=0, i3=0;
    i1=(*b**b+*c**c-*a**a)/(2**b**c);
    *u1=acos(i1);
    i2=(*a**a+*c**c-*b**b)/(2**a**c);
    *u2=acos(i2);
    i3=(*b**b+*a**a-*c**c)/(2**b**a);
    *u3=acos(i3);
}


int main () {
    double a=0, b=0, c=0;
    double u1=0, u2=0, u3=0;
    scanf("%lf %lf %lf", &a, &b, &c);
    calculareaunghiurilor(&a, &b, &c, &u1, &u2, &u3);
    printf("%.3lf %.3lf %.3lf", (u1*180)/M_PI,(u2*180)/M_PI,(u3*180)/M_PI);

}
#include <stdio.h>
#include <math.h>

int main() {
    double x, EPS, a=0;
    int n, k;
    scanf("%lf %d %lf", &x, &n, &EPS);
    double s1=1.0, s2=1.0, t=1.0;
    for(k=1;k<=n; k++)
        {
        t=t*x/k;
        s1+=t;
        }
    t=1.0;
    k=1;
    while (fabs(t*x/k)>=EPS)
        {
        t=t*x/k;
        s2+=t;
        k++;
        }
    a=pow(2.718, x);
    printf("%.6lf %.6lf %.6lf %.6lf  \n", s1, s2, exp(x), a);
    return 0;
}
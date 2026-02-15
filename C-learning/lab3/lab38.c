#include <stdio.h>
#include <math.h>
int main () {
    double x,eps,r1,r2;
    printf("\n");
    scanf ("%lf %lf", &x, &eps);

        r1=x/2;
        r2=(r1+x/r1)/2;

    while (fabs(r1-r2)>eps)
        {
        r1=r2;
        r2=(r1+x/r1)/2;
    }
printf ("%.6lf %.6lf \n", r2, sqrt(x));

    return 0;
}
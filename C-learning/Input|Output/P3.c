#include <stdio.h>
#include <math.h>

int main()

{
    double x, PI = M_PI;
    for (x = 0; x <= 2 * PI; x = x + PI / 20)
        {
        printf("|%+1.3lf| ", x);
        printf("|%+1.3lf| ", sin(x));
        printf("|%1.3lf| \n", cos(x));
        printf("=========================\n");


    }
    return 0;
}
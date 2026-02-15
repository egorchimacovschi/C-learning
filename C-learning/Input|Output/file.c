#include <stdio.h>
#include <math.h>

int main()
{
    double x, PI = M_PI;
    for (x = 0; x <= 2 * PI; x = x + PI / 20) {
        printf("|%+.3lf| ", x);
        printf("|%+.3lf| ", sin(x));
        printf("|%+.3lf| \n", cos(x));
    }
    return 0;
}
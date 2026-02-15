#include <stdio.h>
int main()
{
    float a, b, c;
    scanf("%f%f%f", &a, &b , &c);
if (a==b&&a==c&&b==c)
    {
    printf("echilateral");
    return 0;;
    }
    if ((a==b&&a==c||a==b&&b==c||c==a&&c==b)&&(a*a+b*b==c*c||b*b+c*c==a*a||c*c+a*a==b*b)) {
        printf("dreptunghic isoscel");
    return 0;;
    }
    if (a*a+b*b==c*c||b*b+c*c==a*a||c*c+a*a==b*b)
    {
        printf("dreptunghic");
    }
    if (a!=b&&b!=c&&c!=a)
    {
        printf("oarecare");
    }
    if (a==b||a==c||b==c)
    {
        printf("isoscel");
    }

    return 0;
}
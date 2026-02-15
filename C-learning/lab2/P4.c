#include <stdio.h>
int main()
    {
    double X, Y;
    printf("Introduceti coordonatele X si Y:");
        scanf("%lf %lf", & X, &Y);
        if (((X>=-1000&&X<=+1000)&&(Y>=-1000&&Y<=+1000))&&(X!=0&&Y!=0)) {
            if (X>0&&Y>0) {
                printf("1");
            }else if (X<0&&Y>0) {
                printf("2");
            }else if (X<0&&Y<0) {
                printf("3");
            }else {
                printf("4");
            }

        }else {
            printf("Punct pe axe");
        }

     return 0;
    }
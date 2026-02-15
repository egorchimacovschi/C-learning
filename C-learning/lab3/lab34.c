#include <stdio.h>

int main() {
    int a, c,s=0,t;
    scanf ("%d ", &a);
    while (a!=0) {

        c=a;
        scanf ("%d", &a);
        if (a==0){break;}
        t=c;
        while (c>0) {
            s+=c%10;
            c=c/10;
        }

        if (a==t%s) {
            printf ("(%d,%d)\n", t,a);
            s=0;
        }
        s=0;



    }
    printf ("Ati introdus 0");

    return 0;
}
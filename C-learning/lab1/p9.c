#include <stdio.h>
int main () {
    int n,i=0;
    scanf("%d",&n);
    /*for (i=1;i<=n;i++) {
            if (n==0) {return 0;}
        if (n%i==0) {
            printf ("%d ", i);
            n=n/i;

        }
    }*/
    i=2;
    while(n>1) {
        while (n%i==0) {
            printf ("%d", i);
            n/=i;
        }
        i++;
    }

    return 0;
}
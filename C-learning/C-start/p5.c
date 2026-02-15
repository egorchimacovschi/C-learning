#include <stdio.h>
int main () {
int s=0, n=0;
    scanf ("%d", &n);
    while (n%10!=0) {
        s+=n%10;
        n=n/10;
    }
    printf ("%d", s);


    return 0;
}
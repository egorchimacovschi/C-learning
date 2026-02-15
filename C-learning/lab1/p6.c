#include <stdio.h>
int main () {
    int n, n1=0;
    scanf ("%d", &n);
    while (n!=0) {
        n1+=n%10;
        n/=10;
        n1*=10;
    }n1/=10;
    printf ("%d", n1);


    return 0;
}
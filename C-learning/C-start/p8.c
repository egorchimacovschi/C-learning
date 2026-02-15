#include <stdio.h>
#include <math.h>
int prim(int n) {
    if (n<2) return 0;
    int i=0;
    for (i = 2; i<=sqrt(n); i++) {
        if (n % i == 0) {
            return 0;}
            }
        return 1;
}

int main () {
    int n,i=0,s=0;
    scanf ("%d", &n);
    while (s<n) {
        if (prim (i)) {
            s++;
            printf ("%d ", i);

        }
        i++;

}
    return 0;
}
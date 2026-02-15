#include <math.h>
#include <stdio.h>



int main() {
    int n;
    scanf("%d", &n);
    if (n<2) return 0;
    int i=0;
    for (i = 2; i<=sqrt(n); i++) {
        if (n % i == 0) {
            printf ("Nu este prim\n");
            return 0;
        }
    }
    printf("Este prim\n");
    return 0;
}
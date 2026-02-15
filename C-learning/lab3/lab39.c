#include <stdio.h>
int main() {
    int n, k, e, i;
    unsigned long long x1=0, x2=1, x3;
    scanf("%d", &n);
    if (n<1||n>10000) {
        printf("nu ati introdus valoarea corect");
        return 0;
    }
    for (k=0; k<n; k++) {
        if (k==0)x3=x1;
        else if(k==1)x3=x2;
        else {
            x3=x1+x2;
            x1=x2;
            x2=x3;
        }
        if(x3>=2) {
            e=1;
            for (i=2; i*i<=x3; i++) {
                if (x3%i==0) {
                    e=0;
                    break;
                }
            }
            if (e) printf("%llu \n", x3);
        }
    }

    return 0;
}
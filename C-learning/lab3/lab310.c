#include <stdio.h>

int main() {
    int n, c=0, l=1, s=1, e;
    scanf("%d", &n);
    if (n!=0) {
        while (s<=n) {
            e=s*10-1;
            if (e>n)e=n;
            c+=(e-s+1)*l;
            s*=10;
            l++;
        }
    } else return 0;
    printf("%d\n", c);
    return 0;
}
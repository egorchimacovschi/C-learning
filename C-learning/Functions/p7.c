#include <stdio.h>
int transforma(int n)
{
    int f[10] = {0};
    int i=0,x = n;
    int areZero = 0;
    if (n == 0) return 0;
    while (x > 0) {
        int c = x % 10;
        f[c]++;
        if (c == 0) areZero = 1;
        x /= 10;
    }
    int nou = 0;
    if (areZero == 1) {
        for (i = 9; i >= 0; i--) {
            while (f[i] > 0) {
                nou = nou * 10 + i;
                f[i]--;
            }
        }
    } else {
        for (i = 0; i <= 9; i++) {
            while (f[i] > 0) {
                nou = nou * 10 + i;
                f[i]--;
            }
        }
    }

    return nou;
}
int main () {
    int n=0,c=0;
    scanf("%d", &n);
    if (n<=0 | n>= 1000000000) {
        printf("error"); return 0;
    }
    c= transforma(n);
    printf("%d", c);
    return 0;
}
#include <stdio.h>
#include <math.h>

int main() {
    double x, rezultat = 0;
    int n, i;
    scanf("%lf %d", &x, &n);
    int c[51];
    for (i = 0; i <= n; i++)
        scanf("%d", &c[i]);

    for (i = 0; i <= n; i++) {
        rezultat += c[i] * pow(x, n - i);
    }

    printf("%.2lf\n", rezultat);
    return 0;
}

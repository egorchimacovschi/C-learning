#include <stdio.h>

int main() {
    double x, rezultat;
    int n, i;
    scanf("%lf %d", &x, &n);
    int c[51];
    for (i = 0; i <= n; i++)
        scanf("%d", &c[i]);

    rezultat = c[0]; // P(x,0) = c[0]
    for (i = 1; i <= n; i++)
        rezultat = rezultat * x + c[i];

    printf("%.2lf\n", rezultat);
    return 0;
}

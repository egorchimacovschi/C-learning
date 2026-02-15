#include <stdio.h>
int main() {
    int i;
    float x, y, n,sx,sy,s,k;
    scanf("%f %f %f", &n, &x, &y);
    s=10/n;
    for (i=1; i<=n; i++) {
        sx+=x;
        sy+=y;

    if (i%s==0) {
    printf("%f %e %f %e \n", sx, sx ,sy,sy);
}
    }
    return 0;
}
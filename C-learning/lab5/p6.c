#include <stdio.h>
#include <math.h>
float dist (int x1, int y1, int x2, int y2) {
return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}
int main () {
    int n=0, i=0,x[10000], y[10000];
    float max=0, d[10000];
    scanf("%d", &n);
for (i=0; i<n; i++) {
    scanf("%d %d", &x[i], &y[i]);
}

    for (i=0; i<n-1; i++) {
        d[i]=dist(x[i], y[i], x[i+1], y[i+1]);
    }
    max=0;
    for (i=0; i<n-1; i++) {
        if (max<d[i]) max=d[i];
    }
printf ("%.3f", max);

    return 0;
}
#include <stdio.h>
int main () {
float min, max;
    int n;
    scanf("%d", &n);
    int v[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    max = v[0];
    min = v[0];
    for (int i = 0; i < n; i++) {
        if (v[i] > max) {max = v[i];}
        if (v[i] < min) {min = v[i];}
    }
printf("%f %f", max, min);

    return 0;
}
#include <stdio.h>
int main() {
    int v[100], n, i = 0,start = 0, beststart = 0, len = 1, bestlen = 1;
    scanf ("%d", &n);
    if (n<0||n>100) {
        printf("Ati introdus incorect variabila");
        return 0;
    }
    for (i=0; i<n; i++) {
        scanf ("%d", &v[i]);
    }
    for (i=1; i<n; i++) {
        if (v[i]>=v[i-1]) {
            len++;
        }else if (len > bestlen) {
            bestlen=len;
            beststart=start;
            start = i;
            len = 1;
        }

    }
    if (len > bestlen) {
        bestlen = len;
        beststart = start;
    }
    for (i = beststart; i < beststart + bestlen; i++) {
        printf ("%d ", v[i]);
    }

    return 0;
}

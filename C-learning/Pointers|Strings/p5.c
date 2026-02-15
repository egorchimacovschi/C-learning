#include <stdio.h>
#include <limits.h>
#include <math.h>

void panta(int x1, int y1, int x2, int y2, float* m, float* n) {
    if (x1 == x2) {
        *m = INT_MAX;
        *n = 0;
    } else {
        *m = (float)(y2 - y1) / (x2 - x1);
        *n = y1 - (*m) * x1;
    }
}

int main() {
    int x1=0, y1=0, x2=0, y2=0, x3=0, y3=0;
    float m=0, n=0, y_calc=0;

    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);
    scanf("%d %d", &x3, &y3);

    panta(x1, y1, x2, y2, &m, &n);

    if (m == INT_MAX) {
        if (x3 == x1)
            printf("DA\n");
        else
            printf("NU\n");
    } else {
        y_calc = m * x3 + n;
        if (fabs(y_calc - y3) < 1e-6)
            printf("DA\n");
        else
            printf("NU\n");
    }

    return 0;
}

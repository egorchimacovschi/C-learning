#include <stdio.h>

int arie_intersectie(int x11, int y11, int x12, int y12, int x21, int y21, int x22, int y22) {
    int i, j, arie=0, t, f[20][20]={0};

    if (x11 > x12) { t=x11; x11=x12; x12=t; }
    if (y11 > y12) { t=y11; y11=y12; y12=t; }
    if (x21 > x22) { t=x21; x21=x22; x22=t; }
    if (y21 > y22) { t=y21; y21=y22; y22=t; }

    for (i = x11; i < x12 && i<20; i++) {
        for (j = y11; j < y12 && j<20; j++) {
            f[i][j]++;
        }
    }

    for (i = x21; i < x22 && i<20; i++) {
        for (j = y21; j < y22 && j<20; j++) {
            f[i][j]++;
        }
    }

    for (i = 0; i < 20; i++) {
        for (j = 0; j < 20; j++) {
            if (f[i][j] == 2) {
                arie++;
            }
        }
    }

    return arie;
}

int main () {
    int x11, y11, x12, y12, x21, y21, x22, y22;
    scanf("%d %d %d %d %d %d %d %d", &x11, &y11, &x12, &y12, &x21, &y21, &x22, &y22);
    printf("Aria intersectiei = %d\n", arie_intersectie(x11, y11, x12, y12, x21, y21, x22, y22));
    return 0;
}

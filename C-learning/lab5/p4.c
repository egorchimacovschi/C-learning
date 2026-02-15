#include <stdio.h>
int cmmc(int a, int b) {
    for (int i = 1; i <=100000; i++) {
        if (i%a==0&&i%b==0) return i;
    }
    return 0;
}

int main() {
int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    printf ("%d %d %d %d", x1*(cmmc(y1,y2)/x2), cmmc(y1, y2), x2*(cmmc(y2,y1)/x1), cmmc(y1, y2));


    return 0;
}
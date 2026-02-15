#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int cnt[n]; // vector pentru număr combinatii
    for (int i = 0; i < n; i++) cnt[i] = 0;

    for (int a = 1; a*a*a < n; a++) {
        for (int b = a; b*b*b < n; b++) {
            int sum = a*a*a + b*b*b;
            if (sum < n) {
                cnt[sum]++;
            }
        }
    }

    for (int x = 1; x < n; x++) {
        if (cnt[x] >= 2) {
            printf("%d ", x);
        }
    }

    return 0;
}
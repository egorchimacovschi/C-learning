#include <stdio.h>

int main() {
    int n, x, i;
    scanf("%d", &n);

    int freq[100] = {0};

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x >= 10 && x <= 99) {
            freq[x] = 1;
        }
    }

    int found = 0;
    for (i = 99; i >= 10 && found < 2; i--) {
        if (freq[i] == 0) {
            printf("%d ", i);
            found++;
        }
    }

    return 0;
}
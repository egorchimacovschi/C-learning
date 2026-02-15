#include <stdio.h>

int main() {
    int n, i;
    scanf("%d", &n);

    int v[n];
    int freq[101] = {0};

    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        freq[v[i]]++;
    }

    int max1 = 0, max2 = 0;

    // găsim frecvența maximă
    for (i = 0; i <= 100; i++) {
        if (freq[i] > max1) max1 = freq[i];
    }

    // găsim a doua frecvență maximă
    for (i = 0; i <= 100; i++) {
        if (freq[i] > max2 && freq[i] < max1) max2 = freq[i];
    }

    printf("Cele mai frecvente valori: ");
    for (i = 0; i <= 100; i++) {
        if (freq[i] == max1) printf("%d ", i);
    }
    for (i = 0; i <= 100; i++) {
        if (freq[i] == max2) printf("%d ", i);
    }

    return 0;
}
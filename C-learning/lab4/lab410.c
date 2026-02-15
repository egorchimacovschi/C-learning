#include <stdio.h>

int main() {
    int n, m, i, j;
    scanf("%d", &n);
    double x[100];
    for (i = 0; i < n; i++)
        scanf("%lf", &x[i]);

    scanf("%d", &m);
    int a[1000];
    for (i = 0; i < m; i++)
        scanf("%d", &a[i]);

    // verificăm dacă a este strict crescător
    for (i = 0; i < m - 1; i++) {
        if (a[i] >= a[i + 1]) {
            printf("Error\n");
            return 0;
        }
    }

    int count[1000] = {0};

    // pentru fiecare interval (a[i], a[i+1])
    for (i = 0; i < m - 1; i++) {
        for (j = 0; j < n; j++) {
            if (x[j] > a[i] && x[j] < a[i + 1])
                count[i]++;
        }
    }

    // afișăm numărul de valori din fiecare interval
    for (i = 0; i < m - 1; i++) {
        printf("%d", count[i]);
        if (i < m - 2) printf(" ");
    }

    return 0;
}

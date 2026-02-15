#include <stdio.h>
int main () {
 int i, n5=0, n;
    float v[100];
    scanf("%d \n", &n);
    for (i=0; i<n; i++) {
        scanf ("%f", &v[i]);
    }
    for (i=0; i<n; i++) {
        if (v[i]<5) {
            n5++;
        }
    }
    printf ("%.2f %% \n", ((float)n5/n)*100);

    return 0;
}
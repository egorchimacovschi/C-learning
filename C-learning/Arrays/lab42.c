#include <stdio.h>
int main () {
    int i, np=0, nn=0, n;
    float v[100];
    scanf("%d", &n);
    if (n>100||n<0){printf ("Ati introdus gresit variabila n"); return 0;}

    for (i=0; i<n; i++) {
        scanf ("%f", &v[i]);
    }
    for (i=0; i<n; i++) {
        if (v[i]<0) {
            nn++;
        }
        else {np++;}
    }
    printf ("%d %d", nn, np);
    return 0;
}
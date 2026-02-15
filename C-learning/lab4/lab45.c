#include <stdio.h>
int main () {
  int n1 ,v1[2000], n2, v2[2000],c[2000], i=0,j=0,l=0;
    scanf ("%d", &n1);

    for (i=0; i<n1; i++) {
        scanf ("%d", &v1[i]);
    }
    for (i=0; i<n1; i++) {
        printf("%d ", v1[i]);
    }
    printf ("\n");
    scanf ("%d", &n2);
    for (j=0; j<n2; j++) {
        scanf ("%d", &v2[j]);
    }
    for (j=0; j<n2; j++) {
        printf("%d ", v2[j]);
    }
    printf ("\n");
    i = 0;
    j = 0;
    while (i < n1 && j < n2) {
        if (v1[i] <= v2[j]) {
            c[l] = v1[i];
            l++;
            i++;

        } else {
            c[l] = v2[j];
            l++;
            j++;
        }
    }
    while (i < n1) {
        c[l] = v1[i];
        l++;
        i++;

    }
    while (j < n2) {
        c[l] = v2[j];
        l++;
        j++;

    }


    for (i = 0; i < l; i++) {
        printf("%d ", c[i]);
    }
    printf("\n");
        return 0;
    }
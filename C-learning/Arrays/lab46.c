#include <stdio.h>
 int main () {
     int i=0,j=0,v[100][100],n;
     scanf ("%d", &n);
     for ( i = 0; i < n; i++) {
         for ( j = 0; j < n; j++) {
             printf("v[%d][%d]", i, j);
             scanf ("%d", &v[i][j]);
         }
     }
     for (j=0; j<n; j++) {
         for (i=0; i<n; i++) {
             if (i + j >n-1) {
                 printf ("%d ", v[i][j]);
             }
         }
     }

     return 0;
 }
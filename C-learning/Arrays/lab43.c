#include <stdio.h>
int main () {
    int n,m,i,j, v[100][100], max=0, min=0;

    scanf ("%d %d", &n, &m);
    if (n<0 || n>100 || m<0 || m>100) {
        printf ("Ati introdus incorect variabila");
        return 0;
    }
    for ( i = 0; i < n; i++) {
        for ( j = 0; j < m; j++) {
            printf("v[%d][%d]", i, j);
            scanf ("%d", &v[i][j]);
        }
    }
    for ( i = 0; i < n; i++) {
        max=v[i][0];
        for ( j = 0; j < m; j++){
            if (v[i][j]>max)
                max=v[i][j];
            printf ("max pe linia %d este egal cu %d", i, max );
        }
        if (i==0) {
            min=max;
        }else if (max<min) {
            min=max;
        }
    }
    printf ("min = %d\n", min);
    return 0;
}
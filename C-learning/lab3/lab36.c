#include <stdio.h>
int main () {
    int m,n,n1=1,m1=1, i, m3=1;
    float c;
    scanf("%d%d",&m,&n);
    for (i=n;i>1;i--) {
        n1*=i;
    }
    for (i=m;i>1;i--) {
        m1*=i;
    }
    for (i=(n-m);i>1;i--) {
        m3*=i;
    }
    c=n1/(m1*m3);
    printf ("%f\n",c);
    return 0;

}
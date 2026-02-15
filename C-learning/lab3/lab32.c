#include <stdio.h>
int main () {
    int m, n, i,count=0,  count2=0;
    printf("introduceti numerele:\n");
    scanf("%d %d",&n,&m);
    for (i=1; i<=n; i++)
    {
        printf ("%d ", i);
        count ++;
        if (count%m==0) {
            printf("\n");
            count2++;
            if (count2>0 && count2%24 == 0)
            {

                printf("\n");
                fflush(stdin); ;
                getchar();
            }
        }
    }
    return 0;
}

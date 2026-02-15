#include <stdio.h>
int main() {
    int P, i, j, k;
    scanf("%d", &P);
    for(i=1;i<=P-2;i++) {
        for(j=i+1;j<=P-i-1;j++) {
            k=P-i-j;
            if((i+k>=j)&&(i+j>=k)&&(k+j>=i))
                {printf("(%d, %d, %d)\n", i, j, k);
            }
        }
    }

    return 0;
}
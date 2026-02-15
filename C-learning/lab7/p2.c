#include <stdio.h>

    void count(const int n,const int *v, int *zero, int *poz, int *neg)
    {
        int i=0;
        for (i=0;i<n;i++) {
            if (v[i]==0) {
                (*zero)++;
            }
            else if (v[i]>0) {
                (*poz)++;
            }
            else {
                (*neg)++;
            }
        }

    }
    int main() {
        int i = 0, n = 0, zero = 0, poz = 0, neg = 0;
        scanf("%d",&n);
        int v[n];
        for (i = 0; i < n; i++)
            scanf("%d",&v[i]);
        count(n, v, &zero, &poz, &neg );
        printf ("%d %d %d", zero, neg, poz);

        return 0;
    }


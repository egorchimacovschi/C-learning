#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int *vim1 = (int *)calloc(k + 1, sizeof(int));
    int *vi   = (int *)calloc(k + 1, sizeof(int));
    int *to_free_vim1 = vim1;
    int *to_free_vi   = vi;

    vim1[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j == 0 || j == i)
                vi[j] = 1;
            else if (j < i)
                vi[j] = vim1[j] + vim1[j - 1];
            else
                vi[j] = 0;
        }
        int *temp = vim1;
        vim1 = vi;
        vi = temp;
    }

    printf("%d\n", vim1[k]);

    free(to_free_vim1);
    free(to_free_vi);

    return 0;
}

#include <stdio.h>

int main() {
    int n, i;
    int v[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &v[i]);

    int cresc = 1, desc = 1, egal = 1;

    for (i = 1; i < n; i++) {
        if (v[i] > v[i - 1])
        {desc = 0;}
        if (v[i] < v[i - 1])
        {cresc = 0;}
        if (v[i] != v[i - 1])
        {egal = 0;}
    }

    if (egal)
        printf("constant");
    else if (cresc && !desc)
        printf("crescator");
    else if (desc && !cresc)
        printf("descrescator");
    else
        printf("neordonat");

    return 0;
}
#include <stdio.h>
int main() {
    int a,b,c, max, mid, min;
    scanf("%d %d %d", &a, &b, &c);
    if (a>b && a>c && b>c) {max=a; mid=b; min=c;}
    if (a>b && a>c && c>b){max=a; mid=c; min=b;}
    if (b>a && b>c && a>c){max=b; mid=a; min=c;}
    if (b>a && b>c && a<c){max=b; mid=c; min=a;}
    if (c>a && c>b && b>a){max=c; mid=b; min=a;}
    if (c>a && c>b && a>b){max=c; mid=a; min=b;}
    printf("%d %d %d", min, mid, max);
    return 0;
}
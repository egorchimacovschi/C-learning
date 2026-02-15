#include <stdio.h>
int main() {
    int a,b,c,d, max, min;
    scanf ("%d %d %d %d", &a, &b, &c, &d);
    max=a;
    if (max<b) {max=b;}
    if(max<c) {max=c;}
    if(max<d) {max=d;}
    min=a;
    if (min>b) {min=b;}
    if(min>c) {min=c;}
    if(min>d) {min=d;}
    printf("%d %d", min, max);
    return 0;
}
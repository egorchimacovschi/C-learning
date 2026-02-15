#include <stdio.h>
typedef struct {
    float x,y;
}punct;
punct citire() {
    punct n;
    scanf("%f %f",&n.x,&n.y);
    return n;
}
void afisare (const punct n) {
    printf("%f %f\n",n.x,n.y);
}
int main() {
    punct n={0};
    afisare(n);
    return 0;
}
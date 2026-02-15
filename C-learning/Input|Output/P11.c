#include <stdio.h>
#include <math.h>
int main() {
    float a, b, c;
    float x1, x2;
    scanf("%f%f%f", &a, &b, &c);
if (b*b-4*a*c<0) {
    printf("Nu exista solutii");

}else if (sqrt(b*b-4*a*c)==0) {
    printf ("%.2f", -b/2*a);
}else {
    x1=(-b+sqrt(b*b-4*a*c))/(2*a);
    x2=(-b-sqrt(b*b-4*a*c))/(2*a);
    printf("%.2f %.2f\n", x2, x1);
}
    return 0;
}
#include <stdio.h>
int cifra(int n, int c){
    if (n==0) return 0;
    while(n)
    {
    if (n%10==c) return 1;
    n=n/10;
    }
    return 0;
}


int main() {
int n, c;
scanf ("%d %d", &n, &c);
if (cifra(n,c))
{
printf ("da");
} else {
printf ("Nu");
}
return 0;
}
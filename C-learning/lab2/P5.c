#include <stdio.h>
int main()
{
 int a, b, c;
    scanf("%d%d%d", &a, &b , &c);
if (a<0||b<0||c<0) {printf("Nu");}
    else if ((a+b)>=c&&(a+c)>=b&&(b+c)>=a)
    {
        printf("Da");
    }else {
        printf("Nu");
    }

    return 0;
}
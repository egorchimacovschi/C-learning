#include <stdio.h>
int main() {
    int H, M,S;
    int n;
    n = scanf("%d %d %d", &H, &M, &S);
    if (n==3&&(H>=0&&H<=23)&&(M>=0&&M<=59)&&(S>=0&&S<=59)) {
        printf("%02d:%02d:%02d", H, M, S);}
    else {
        printf("Date introduse incorect!");
    }
    return 0;

}
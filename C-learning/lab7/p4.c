#include <stdio.h>
#include <string.h>
char* substr(const char* src ,const int n, char* dest) {
    strncpy(dest, src, n);
    return dest;
}
int main () {
    char sir[100], p[100];
    int pozitia=0, numarul=0;
    /*fgets(sir, sizeof(sir), stdin);
    sir[strlen(sir)-1]='\0';*/
    scanf("%s", sir);
    scanf ("%d %d", &pozitia, &numarul);
    substr(sir+pozitia, numarul, p);
    printf ("%s\n", p);
    return 0;
}
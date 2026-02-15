#include <stdio.h>
#include <string.h>

int compararesiruri(const char *sir1,const char *sir2) {
    int i=0;
    for (i=0; i<strlen(sir1); i++) {
         if (sir1[i] != sir2[i]) {
             if (sir1[i]>sir2[i]) {return 1;}
             if (sir1[i]<sir2[i]) {return -1;}

         }
    }
return 0;
}


int main() {
    int k=0;
    char sir1[100];
    char sir2[100];
    scanf("%s", sir1);
    scanf("%s", sir2);
    k=compararesiruri(sir1, sir2);
    if (k>0) printf("%d ", k);
    if (k<0) printf("%d ", k);
    if (k==0) printf("%d ", k);

    return 0;
}

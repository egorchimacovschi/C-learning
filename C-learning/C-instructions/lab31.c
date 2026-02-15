#include <stdio.h>
int main () {
    int ch, count = 0;
    for (ch=32 ; ch<127 ; ch++) {
        printf ("%c=%d ", ch, ch);
        count ++;
        if (count % 10 == 0) printf("\n");
    }
    return 0;
}

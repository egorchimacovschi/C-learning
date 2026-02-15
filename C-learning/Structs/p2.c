#include <stdio.h>
#include <time.h>
int main() {
    time_t t=0;
    struct tm *info={0};
    t=time(NULL);
    info = localtime(&t);
    printf ("Data si ora curenta:\n");
    printf ("%s",asctime(info));
    return 0;
}
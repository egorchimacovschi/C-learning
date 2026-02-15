#include <stdio.h>
#include <time.h>
char* timestr(struct tm t, char* s) {
    s[0] = '0' + t.tm_hour / 10;
    s[1] = '0' + t.tm_hour % 10;
    s[2] = ':';
    s[3] = '0' + t.tm_min / 10;
    s[4] = '0' + t.tm_min % 10;
    s[5] = ':';
    s[6] = '0' + t.tm_sec / 10;
    s[7] = '0' + t.tm_sec % 10;
    s[8] = '\0';
    return s;
}
int main() {
    time_t now = time(NULL);
    struct tm *p = localtime(&now);
    char buffer[20];
    printf("Ora: %s\n", timestr(*p, buffer));
    return 0;
}

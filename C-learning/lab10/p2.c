#include <stdio.h>
struct multime {
    unsigned char a;
};
void init(struct multime *m) {
    m->a = 0;
}
void add(struct multime *m, const int x) {
    if (x >= 0 && x <= 7)
        m->a |= 1 << x;
}
void dell(struct multime *m, const int x) {
    if (x >= 0 && x <= 7)
        m->a &= ~(1 << x);
}
int contains( const struct multime *m, const int x) {
    if (x < 0 || x > 7) return 0;
    return (m->a >> x) & 1;
}
void print(const struct multime *m) {
    int i=0;
    printf("{ ");
    for (i = 0; i < 8; i++) {
        if (contains(m, i))
            printf("%d ", i);
    }
    printf("}\n");
}
int main() {
    struct multime m;
    int x;
    scanf("%d", &x);
    if (x < 0 || x > 7) {return 1;}
    init(&m); add(&m, x); print(&m);
    dell(&m, x); print(&m);
    printf("%d %d", x, contains(&m, x));
    return 0;
}

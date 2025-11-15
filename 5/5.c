#include <stdio.h>
#include <stdlib.h>

struct N {
    int d;
    struct N *l, *r;
};

struct N* nn(int d) {
    struct N* x = (struct N*)malloc(sizeof(struct N));
    x->d = d;
    x->l = x->r = NULL;
    return x;
}

struct N* ins(struct N* rt, int d) {
    if (!rt) return nn(d);
    if (d < rt->d) rt->l = ins(rt->l, d);
    else rt->r = ins(rt->r, d);
    return rt;
}

void pt(struct N* rt, int sp) {
    if (!rt) return;
    sp += 5;
    pt(rt->r, sp);
    printf("\n");
    for (int i = 5; i < sp; i++) printf(" ");
    printf("%d\n", rt->d);
    pt(rt->l, sp);
}

int main() {
    struct N* rt = NULL;
    int d;
    printf("Enter values (-1 to stop):\n");

    while (1) {
        scanf("%d", &d);
        if (d == -1) break;
        rt = ins(rt, d);
        printf("\nTree:\n");
        pt(rt, 0);
        printf("\n");
    }
    return 0;
}

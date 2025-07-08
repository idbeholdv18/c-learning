#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct point {
    double x;
    double y;
};

struct rect {
    struct point min;
    struct point max;
};

double s_sum(struct rect *, struct rect *);
int is_includes(struct rect *, struct point *);
struct rect canon_rect(struct rect *);
struct point min_p(struct rect *, struct rect *);
struct point max_p(struct rect *, struct rect *);

int main() {
    // struct rect r1 = {{1.0, 6.0}, {5.0, 3.0}};
    // struct rect r2 = {{4.0, 5.0}, {7.0, 1.0}};

    // struct rect r1 = {{2.0, 4.0}, {5.0, 3.0}};
    // struct rect r2 = {{1.0, 4.0}, {6.0, 1.0}};

    struct rect r1 = {{1.0, 4.0}, {5.0, 1.0}};
    struct rect r2 = {{4.5, 3.0}, {8.0, 0.0}};

    printf("direct sum is: %.2f\n", s_sum(&r1, &r2));

    return 0;
}

double s_sum(struct rect *f, struct rect *s) {
    struct rect f_c = canon_rect(f);
    struct rect s_c = canon_rect(s);

    struct point min = min_p(&f_c, &s_c);
    struct point max = max_p(&f_c, &s_c);

    if ((f_c.min.x == min.x && f_c.min.y == min.y && f_c.max.x == max.x &&
         f_c.max.y == max.y) ||
        (s_c.min.x == min.x && s_c.min.y == min.y && s_c.max.x == max.x &&
         s_c.max.y == max.y)) {
        return (max.x - min.x) * (max.y - min.y);
    }

    // here is a mistake I will fix later...
    double f_c_w = f_c.max.x - f_c.min.x;
    double s_c_w = s_c.max.x - s_c.min.x;
    double f_c_h = f_c.max.y - f_c.min.y;
    double s_c_h = s_c.max.y - s_c.min.y;

    double straight_w = (f_c_w + s_c_w) - (max.x - min.x);
    double straight_h = (f_c_h + s_c_h) - (max.y - min.y);

    if (straight_h <= 0 || straight_w <= 0)
        return f_c_w * f_c_h + s_c_w * s_c_h;

    return f_c_w * f_c_h + s_c_w * s_c_h - straight_h * straight_w;
}

int is_includes(struct rect *r, struct point *p) {
    if (p->x >= r->min.x && p->x <= r->max.x && p->y >= r->min.y &&
        p->y <= r->max.y)
        return 1;
    return 0;
}

struct rect canon_rect(struct rect *rect) {
    struct rect temp;

    temp.min.x = MIN(rect->min.x, rect->max.x);
    temp.max.x = MAX(rect->min.x, rect->max.x);
    temp.min.y = MIN(rect->min.y, rect->max.y);
    temp.max.y = MAX(rect->min.y, rect->max.y);
    return temp;
}

struct point min_p(struct rect *f, struct rect *s) {
    struct point temp;
    temp.x = MIN(f->min.x, s->min.x);
    temp.y = MIN(f->min.y, s->min.y);
    return temp;
}

struct point max_p(struct rect *f, struct rect *s) {
    struct point temp;
    temp.x = MAX(f->max.x, s->max.x);
    temp.y = MAX(f->max.y, s->max.y);
    return temp;
}

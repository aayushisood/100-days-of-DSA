#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pos;
    int speed;
} Car;

int cmp(const void *a, const void *b) {
    Car *x = (Car *)a;
    Car *y = (Car *)b;
    return y->pos - x->pos; // descending order
}

int main() {
    int n;
    scanf("%d", &n);

    int target;
    scanf("%d", &target);

    Car cars[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &cars[i].pos, &cars[i].speed);
    }

    // sort by position descending
    qsort(cars, n, sizeof(Car), cmp);

    int fleets = 0;
    double currTime = -1;

    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].pos) / cars[i].speed;

        // new fleet if slower (greater time)
        if (time > currTime) {
            fleets++;
            currTime = time;
        }
    }

    printf("%d\n", fleets);

    return 0;
}

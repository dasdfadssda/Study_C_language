#include <stdio.h>
#include <math.h>

// declare a structure 'Point' composed of two integer fields x and y
struct Point {
    int x;
    int y;
};

// define a function Distance(p1, p2) that returns the distance between two Points p1 and p2
// distance = sqrt( (p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y))
double Distance(struct Point p1, struct Point p2) {
    double distance = sqrt((double)(p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
    return distance;
}

int main() {
    struct Point point1 = {3, 4};
    struct Point point2 = {6, 8};

    double dist = Distance(point1, point2);
    printf("Distance between points: %.2f\n", dist);

    return 0;
}

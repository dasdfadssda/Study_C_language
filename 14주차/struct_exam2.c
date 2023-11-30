
// declare a structure 'Point' composed of two integer fields x and y
// struct Point {
//     int x;
//     int y;
// };

typedef struct
{
    int x, y;
} Point;

// define a function Distance(p1, p2) that returns the distance between two Points p1 and p2
// distance = sqrt( (p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y))
// sqrt() is declared in math.h

double Distance(Point p1, Point p2)
{
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

// declare a structure 'Size' to represent horizontal and vertical sizes
// composed of two integer fields width and height

// struct Size {
//     int width, height;
// };

typedef struct
{
    int width, height;
} Size;

// define a function Difference(p1, p2)
// that returns the difference between them in 'Size' type
// e.g., struct Size s = Difference(p1, p2);

Size Difference(Point p1, Point p2)
{
    Size size;

    size.width = p2.x - p1.x;
    size.height = p2.y - p1.y;

    return size;
}
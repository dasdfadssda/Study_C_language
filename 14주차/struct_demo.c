#include <stdio.h>

// a rectangle is represented by four numbers as (left, top, right, bottom).

// custom data type to represent rectangles
struct Rectangle {
    int left;
    int top;
    int right;
    int bottom;
};

int GetRectangleSize(struct Rectangle rect);

int main()
{
    struct Rectangle rect1 = { 1, 1, 20, 10 };

    printf("rect1 = (%d, %d, %d, %d)\n",
            rect1.left, rect1.top, rect1.right, rect1.bottom);
    printf("The size of rect1 = %d\n", GetRectangleSize(rect1));
    
    rect1.left = 5;
    rect1.top = 5;

    printf("rect1 = (%d, %d, %d, %d)\n",
            rect1.left, rect1.top, rect1.right, rect1.bottom);
    printf("The size of rect1 = %d\n", GetRectangleSize(rect1));

    return 0;
}

int GetRectangleSize(struct Rectangle rect)
{
    int size = (rect.right - rect.left + 1) * (rect.bottom - rect.top + 1);

    return size;
}
/*
    Write a program that draws a mesh diamond. (Mesh diamond를 그리는 프로그램을 작성하시오.)                                                                                                          (in python?)
        Read the width of the diamond from the user
        If the width is an even number, make it odd by adding one. (width가 짝수로 입력되면 1을 더해서 홀수로 만드시오.)
        Draw a diamond of the specified width, as following examples. (다음 예제와 같이 지정된 width를 갖는 mesh diamond를 그리시오.)

    Requirements)
        - DO NOT USE Console.c and Console.h.
        - The program should work for all width (e.g., 11, 25, 50, ...) not exceeding the screen width.
         (The boundary check for width is not needed.)
        - DO NOT delete or modify the algorithms

    Example) Input the width of diamond: 5

          *
         * *
        * * *
         * *
          *

    Example) Input the width of diamond: 7
           *
          * *
         * * *
        * * * *
         * * *
          * *
           *

    Example) Input the width of diamond: 9
            *
           * *
          * * *
         * * * *
        * * * * *
         * * * *
          * * *
           * *
            *

*/

#include <stdio.h>

int main() // convert this into python without explanation
{
    int width = 5;

    printf("Input the width of diamond: ");
    scanf("%d", &width);

    if (width % 2 == 0)
        width++;

    int i = 0, j = 0;

    // TO DO: draw the upper part (0 <= i <= width / 2)                                                                                                                                               (write in python?)
    //  repeat for each row i from 0 to width / 2  [0, width / 2]
    //      compute the number of blanks from i (find a conversion formula by yourself)
    //      display blanks
    //      compute the length of the current row from i (find a conversion formula by yourself)
    //      display a row using '*' and the space characters
    //      display a new line character

    // Draw the upper part (0 <= i <= width / 2)
    for (int i = 0; i <= width / 2; i++)
    {
        int num_blanks = width / 2 - i;
        for (int j = 0; j < num_blanks; j++)
        {
            printf(" ");
        }
        int num_stars = 2 * i + 1;
        for (int j = 0; j < num_stars; j++)
        {
            printf("*");
            if (j < num_stars - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Draw the lower part (width / 2 < i < width)
    for (int i = width / 2 + 1; i < width; i++)
    {
        int num_blanks = i - width / 2;
        for (int j = 0; j < num_blanks; j++)
        {
            printf(" ");
        }
        int num_stars = 2 * (width - i) - 1;
        for (int j = 0; j < num_stars; j++)
        {
            printf("*");
            if (j < num_stars - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    // TO DO: draw the lower part (width / 2 < i < width)
    //  repeat for each row i from (width / 2 + 1) to width  (i in range [width / 2 + 1, width))
    //      compute the number of blanks from i (find a conversion formula by yourself)
    //      display blanks
    //      compute the length of the current row from i (find a conversion formula by yourself)
    //      display a row using '*' and the space characters
    //      display a new line character

    return 0;
}

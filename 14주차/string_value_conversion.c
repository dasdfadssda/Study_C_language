#include <stdio.h>
#include <stdlib.h>         // for atoi(), atof(), atol(), etc.
#include <string.h>         // for strcpy(), strlen(), strcmp(), strcat(), etc.

int main()
{
    char buffer[256] = "";
    int a = 10;
    float f = 3.14F;

    // writing into strings
    printf("%d %f\n", a, f);
    sprintf(buffer, "%d %f", a, f);         // print values to string
    printf("buffer = [%s]\n", buffer);


    // reading from strings
    int b = 10;
    float g = 3.14F;
    sscanf(buffer, "%d %f", &b, &g);        // read values from string
    printf("b = %d, g = %f\n");

    
    // converting string into integer
    strcpy(buffer, "256");
    int c = atoi(buffer);                   // string -> integer
    printf("c = %d\n", c);

    strcpy(buffer, "65536");
    long l = atol(buffer);                   // string -> long
    printf("l = %ld\n", l);

    // converting string into float
    strcpy(buffer, "123.456");
    float h = atof(buffer);                 // string -> float
    printf("h = %f\n", h);

    /* Note! Float values are approximations
        float f = 0.F, g = 0.F;
        scanf("%f %f", &f, &g);
        if(f == g){                  // unsafe (float values can differ slightly because they are approximations)
            ...
        }

        if(fabs(f-g) < 0.0001){      // safer  (#include <math.h>)

        }
    */

    return 0;
}
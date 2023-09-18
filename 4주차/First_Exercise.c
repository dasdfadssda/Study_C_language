#include <stdio.h>

int main() {
    int a = 0, b = 0, c = 0, d = 0;
    float avg = 0.0F, var = 0.0F;

    // Read four integer numbers
    printf("Enter four integer numbers: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    // Compute average
    avg = (a + b + c + d) / 4.0;

    // Compute variance
    var = ((a - avg) * (a - avg) + (b - avg) * (b - avg) + (c - avg) * (c - avg) + (d - avg) * (d - avg)) / 4.0;

    // Display the results
    printf("Average = %.6f, Variance = %.6f\n", avg, var);

    return 0;
}

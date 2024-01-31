#include <stdio.h>

int main(void)
{
    double x, average, total, count;
    while (scanf("%lf", &x) == 1) { // pay attention to %lf
        count++;
        total += x;
        average = total / count;
        printf("Total=%f Average=%f\n", total, average); // pay attention to %f
    }

    return 0;
}
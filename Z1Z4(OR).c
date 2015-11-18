#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i = 0, j = 0, x = 0, y = 0, z = 0;
    printf("Unesite brojeve (0 za kraj): \n");

    do
    {
        scanf("%d", &n);
        i++;
        z = y;
        y = x;
        x = n;

        if (i >= 3 && y == z - x)
            j++;
    }
    while (i < 3 || n != 0);
    printf("%d clana niza zadovoljava uslov.", j);
    return 0;
}

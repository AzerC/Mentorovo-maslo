#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j;
    printf("Unesite broj n: ");
    scanf("%d", &n);

    if (n % 2 == 0 || n < 3 || n > 100)
    {
        printf("Broj je van trazenog opsega");
        return 0;
    }

    for (i = 0; i < n/2; i++)
    {
        for (j = 0; j < n; j++)
            if (j == n/2 + i || j == n/2 - i)
            printf("+");
            else
            printf(" ");

        printf("\n");
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            if (j == i || j == n - 1 - i || i == n - 1 || j == n - 1 || i == 0 || j == 0)
            printf("+");
            else
            printf(" ");

        printf("\n");
    }
    return 0;
}

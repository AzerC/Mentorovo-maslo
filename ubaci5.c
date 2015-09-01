#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ubaci5 (int n, int a, int b)
{
    int z, i=0;
    float suma = 0;
    do
    {
        z = n % 10;
        n/=10;
        i++;
        if (i == a || i == b)
            z = 5;
        suma += z * pow(10, i - 1);

    }while (n != 0);
    return suma;
}

int main()
{
    int n, a , b;
    printf("Unesite elemente n, a i b: ");
    scanf("%d %d %d", &n, &a, &b);

    printf("%d", ubaci5(n, a, b));
    return 0;
}

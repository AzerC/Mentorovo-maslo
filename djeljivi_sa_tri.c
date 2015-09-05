#include <stdio.h>
#include <stdlib.h>

int djeljiva_sa_tri(int n)
{
    int z, i = 0;
    float suma = 0;
    do{
    z = n % 10;
    n/=10;
    if (z % 3 != 0)
    {
        suma += z * pow(10, i);
        i++;
    }
    }while(n != 0);
    return suma;
}

int main()
{
    int n;
    printf("Unesite broj n: ");
    scanf("%d", &n);
    printf("%d", djeljiva_sa_tri(n));
    return 0;
}

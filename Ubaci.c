#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float ubaci(int n, int a)
{
    int z, i = 0;
    float suma = 0;
    while(n != 0.0){
       z = n % 10;
       n /= 10;
       i++;
       if (i % 2 == 0)
       {
           z = a;
       }
       suma += z * pow(10, (i-1));
    }
   return suma;
}

int main()
{
    int n;
    int a;
    printf("Unesite n i a: ");
    scanf("%lf %d", &n, &a);
    printf("%f", ubaci(n, a));
    return 0;
}

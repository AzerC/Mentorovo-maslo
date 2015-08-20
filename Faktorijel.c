#include <stdio.h>
#include <math.h>
int faktorijel(int n)
{
    int i;
    if (n > 1)
    return n * faktorijel(n - 1);
    else
        return 1;
}

void dajmid(float f){
if (f>0.1) printf("Velika greska!");
else if (f>=0.01) printf("Srednja greska!");
else
    printf("Mala greska!");
}

float e_na_x(float x, int n)
{
float suma = 0;
int i;
for (i = 0; i <= n; i++)
{
    suma += pow(x, i) / faktorijel(i);
}
return suma;
}

int main()
{
int n;
float x;

printf("Unesite x i n: ");
scanf("%f %d", &x, &n);
dajmid(fabs(e_na_x(x, n) - exp(x)));

 return 0;
}

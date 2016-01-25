#include <stdio.h>
#include <stdlib.h>

int f(int n)
{
    while(n > 99)
        n /= 10;
    if (n % 10 == 7) return 1;
    return 0;
}
float f2(float n)
{
    int a = n;
    int b = (n - a) * 1000;
    int novi_broj = 0;
    while (b != 0)
    {
        novi_broj = novi_broj*10 + b%10;
        b/=10;
    }
    return a + novi_broj/1000.0;
}
void f1(float* niz, int vel)
{
    int i;
    for (i = 0; i < vel; i++)
    {
        if (f(niz[i]) == 1)
            niz[i] = f2(niz[i]);
    }
}
int main()
{
    float niz[10] = {1734.4371, 172.432, 172.213};
    f1(niz, 10);
    int i;
    for (i = 0; i < 10; i++)
        printf("%.3f ", niz[i]);
    return 0;
}

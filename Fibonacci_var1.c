#include <stdio.h>
#include <stdlib.h>

int fibo(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return fibo(n - 1) + fibo(n - 2);
}

int main()
{
    int n;
    printf("Unesite n: ");
    scanf("%d", &n);

    printf("%d-ti element Finacijevog niza je: %d", n, fibo(n - 1));
    return 0;
}

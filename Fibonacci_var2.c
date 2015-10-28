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
    int n, i;
    printf("Unesite n: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("%d ", fibo(i));
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
int prost(int n)
{
    int i;
    if (n == 1)
        return 1;
    for (i = 2; i < n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}
int izbaci_prost(int niz[], int vel)
{
    int i, j;
    for (i = 0; i < vel; i++)
    {
        if (prost(niz[i]) == 1)
        {
        for (j = i; j < vel - 1; j++)
            niz[j] = niz[j+1];
        i--;
        vel--;
    }
}
    return vel;
}
int main()
{
    int niz[10] = {1, 11, 5, 4, 7, 2, 3, 8, 13, 41};
    int vel = 10, i;
    int *p1 = niz;
    int *p2 = p1 + izbaci_prost(niz + 3, vel - 3);
    while (p1 != p2)
        printf("%d ", *p1++);
    printf("\n");
    for (i = 0; i < 10; i++)
    printf("%d, ", niz[i]);
    return 0;
}

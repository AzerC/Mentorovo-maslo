#include <stdio.h>
#include <stdlib.h>
void sortiraj(int niz[], int vel)
{
    int i, j, k, brojac1 = 0, brojac2 = 0;
    for (i = 0; i < vel; i++)
    {
        if (niz[i] % 2 == 0)
            brojac1++;
        else if (niz[i] % 2 == 1)
            brojac2++;
    }
    int niz1[10], niz2[10];
    j = 0, k = 0;
    for (i = 0; i < vel; i++)
    {
        if (niz[i] % 2 == 0)
        {
            niz1[j] = niz[i];
            j++;
        }
        else if (niz[i] % 2 == 1)
        {
            niz2[k] = niz[i];
            k++;
        }

    }
    int temp;
    for (i = 0; i < brojac1; i++)
    {
        for (j = i; j < brojac1; j++)
            if (niz1[i] > niz1[j])
            {
                temp = niz1[j];
                niz1[j] = niz1[i];
                niz1[i] = temp;
            }
    }
    for (i = 0; i < brojac2; i++)
    {
        for (j = i; j < brojac2; j++)
            if (niz2[i] < niz2[j])
            {
                temp = niz2[j];
                niz2[j] = niz2[i];
                niz2[i] = temp;
            }
    }
    i = 0;
    while (i != brojac1)
    {
        niz[i] = niz1[i];
        i++;
    }
    j = 0;
    while (i != vel)
    {
        niz[i] = niz2[j];
        i++;
        j++;
    }
}
int main()
{
    int niz[10] = {1, 7, 2, 6, 8, 9, 7, 5, 4, 3};
    int i;
    sortiraj(niz, 10);
    for (i = 0; i < 10; i++)
      printf("%d ", niz[i]);
    return 0;
}

//Potrebno je napisati funkciju SORTIRAJ koja slaže po veličini niz realnih brojeva, pri čemu
//se dužina niza funkciji prosljeđuje kao argument. Nakon pisanja funkcije, napraviti kratki
//program koji je testira. Primjer algoritma za sortiranje je mogude nadi u tutorijalu 6.
//Za rješavanje je obavezno korištenje pokazivačke aritmetike.

#include <stdio.h>
#include <stdlib.h>
void sort (int *ptr, int n)
{
   int *i, *j, swap;

for(i = ptr; i < (ptr + n); i++)
{
    for(j = i + 1; j < (ptr + n) ; j++)
    {
        if(*j > *i)
        {
            swap = *i;
            *i = *j;
            *j = swap;
        }
    }
}
}

int main()
{
    int n, i;
    int *p;
    int niz[100];

    do
    {
    printf("Unesite n: ");
    scanf("%d", &n);
    }while (n >= 100);


    for (i = 0; i < n; i++)
    {
        scanf("%d", &niz[i]);
    }

    p = &niz[0];
    sort(p, n);

    for (i = 0; i < n; i++)
        printf("%d", *(p+i));
    return 0;
}

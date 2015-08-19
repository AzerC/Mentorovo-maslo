//Potrebno je napisati funkciju SORTIRAJ koja slaže po veličini niz realnih brojeva, pri čemu
//se dužina niza funkciji prosljeđuje kao argument. Nakon pisanja funkcije, napraviti kratki
//program koji je testira. Primjer algoritma za sortiranje je mogude nadi u tutorijalu 6.
//Za rješavanje je obavezno korištenje pokazivačke aritmetike.

#include <stdio.h>
#include <stdlib.h>
void sort (int *pok, int vel)
{
    int *p, *q, help;
    for (p = pok; p < pok + vel; p++)
    {
        for (q = p + 1; q < pok + vel; q++)
        {
            if (*q > *p)
            {
                help = *p;
                *p = *q;
                *q = help;
            }
        }
    }
}

int main()
{
    int n, i, help;
    int *p;

    printf("Unesite n: ");
    scanf("%d", &n);

    int niz [n];

    for (i = 0; i < n; i++)
    {
        scanf("%d", &niz[i]);
    }

    p = niz [0];
    sort(&p, n);

    for (i = 0; i < n; i++)
    {
        printf("%d", niz[i]);
    }

    return 0;
}

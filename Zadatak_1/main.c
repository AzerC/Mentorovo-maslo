#include <stdio.h>
#include <stdlib.h>

void ispisi (int niz[], int br)
{
    int i;
    printf("%d\n", br);
    for (i = 0; i < 3; i++)
        printf("%d, ", niz[i]);
}

void sortiraj (int niz[])
{
    int i, j, br_razlicitih = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = i + 1; j < 3; j++)
        {
            if (niz[j] <= niz[i])
            {
                int temp = niz[j];
                niz[j] = niz[i];
                niz[i] = temp;
            }
            if (niz[j] != niz[i])
                br_razlicitih++;
        }
    }
    ispisi(niz, br_razlicitih);
}

int main ()
{
int niz[3], i;

for(i = 0; i < 3; i++)
{
scanf("%d", &niz[i]);
if (niz[i] < 50 || niz[i] > 200)
{
    printf("Izav opsega!\n");
    i--;
}

}
sortiraj(niz);

return 0;
}

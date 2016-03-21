#include <stdio.h>
#include <stdlib.h>
struct Mjerenja
{
    int dan, mjesec, godina, sati;
    int broj_mjerenja;
    char naziv[20];
    int mjerenja[1000];
}niz[7200];

int main()
{
FILE* ulaz = fopen("mjerenja.txt", "r");
FILE* izlaz = fopen("statistika.txt", "w");
int dan, mjesec, godina, sati, broj_mjerenja;
fscanf(ulaz, "%d%d%d%d%d\n", &dan, &mjesec, &godina, &sati, &broj_mjerenja);
int i = 0, j;
while ((fscanf(ulaz, "%20s", niz[i].naziv) == 1 && i < 7200))
       {
        niz[i].dan = dan;
        niz[i].mjesec = mjesec;
        niz[i].godina = godina;
        niz[i].sati = sati;
        niz[i].broj_mjerenja = broj_mjerenja;
        for (j = 0; j < broj_mjerenja; j++)
            fscanf(ulaz, "%d", &niz[i].mjerenja[j]);
        i++;
       }
       int vel = i;
       for (i = 0; i < vel; i++)
       {
           for (j = 0; j < broj_mjerenja; j++)
           {
               if (niz[i].mjerenja[j] == 350)
               {
                   fprintf(izlaz, "%20s%d%d%d%d%d", niz[i].naziv, niz[i].dan, niz[i].mjesec, niz[i].godina, niz[i].sati + j,
                           niz[i].mjerenja[j]);
               }
           }
       }
    return 0;
}

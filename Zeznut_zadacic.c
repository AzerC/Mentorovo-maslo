#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
    char ime[10];
    char prezime[15];
    int predmet;
    int ocjena;
} student;
int main()
{
    struct student studenti[100];
    FILE *ulaz, *izlaz;
    ulaz = fopen("studenti.txt", "r");
    izlaz = fopen("ispiti.txt", "w");

    if (ulaz == NULL)
    {
        printf("Greska pri otvaranju datoteke.");
        exit(1);
    }

    if (izlaz == NULL)
    {
        printf("Greska pri otvaranju datoteke.");
        close(ulaz);
        exit(2);
    }
    int i;
    int niz_brojaca[10];
    float prosjeci_po_predmetu[10];
    for(i=0; i<10; i++)
    {
    prosjeci_po_predmetu[i]=0;
    niz_brojaca[i]=0;
    }
   for (i = 0; i < 5; i++)
    {
        while(fscanf(ulaz, "%10s%15s%d%d", &studenti[i].ime, &studenti[i].prezime, &studenti[i].predmet, &studenti[i].ocjena) == 4)
       {
       prosjeci_po_predmetu[studenti[i].predmet - 1]+=studenti[i].ocjena;
       niz_brojaca[studenti[i].predmet - 1]++;
       printf("%-10s%-15s%d %d\n", studenti[i].ime, studenti[i].prezime, studenti[i].predmet, studenti[i].ocjena);
       }
       }
    for (i = 0; i < 10; i++)
    {
        if (niz_brojaca[i] != 0)
    fprintf(izlaz, "Prosjek premeta %d je: %.2f\n", i + 1, (prosjeci_po_predmetu[i])/(float)(niz_brojaca[i]));
    }
    close (ulaz);
    close (izlaz);

    return 0;
}

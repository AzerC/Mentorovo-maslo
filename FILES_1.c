#include <stdio.h>
#include <stdlib.h>
struct Covjek
{
    char ime[15];
    char prezime[15];
    char telefon[11];
};
int main()
{
    FILE *ulaz, *izlaz;
    ulaz = fopen("telefon.txt", "r");
    izlaz = fopen("061telefon.txt", "w");

    if (ulaz == NULL)
    {
        printf("GRESKA!");
        exit(1);
    }

    if (izlaz == NULL)
    {
        close(ulaz);
        printf("Greska!");
        exit(2);
    }
    struct Covjek ljudi;
    while(fscanf(ulaz, "%15s%15s%11s", ljudi.prezime, ljudi.ime, ljudi.telefon) == 3)
    {
        if (ljudi.telefon[0] == '0')
        {
            if (ljudi.telefon[1] == '6')
            {
                if (ljudi.telefon[2] == '1')
                    fprintf(izlaz, "%-15s%-15s%-11s\n", ljudi.prezime, ljudi.ime, ljudi.telefon);
            }
        }
    }
    close(ulaz);
    return 0;
}

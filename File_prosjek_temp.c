#include <stdio.h>
#include <stdlib.h>

struct Temperature
{
    char grad[15];
    int JAN, FEB, MAR;
};

int main()
{
    FILE* ulaz, *izlaz;
    char grad[15];
    int JAN, FEB, MAR;
    ulaz = fopen("gradovi.txt", "r");
    izlaz = fopen("prosjeci.txt", "w");

    if (ulaz == NULL)
    {
        printf("Greska!");
        exit(1);
    }
    if (izlaz == NULL)
    {
        close(ulaz);
        printf("Greska!");
        exit(2);
    }
    while(fscanf(ulaz, "%15s%10d%10d%10d", &grad, &JAN, &FEB, &MAR) == 4)
    {
        fprintf(izlaz, "%-15s%-10.2f\n", grad, (float)((JAN + FEB + MAR)/3.));
    }
    close(ulaz);
    close(izlaz);
    return 0;
}

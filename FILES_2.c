#include <stdio.h>
#include <stdlib.h>
int main()
{
    char prezime[15],ime[15],reg[10];
    FILE *fUlaz, *fIzlaz;
    if((fUlaz=fopen("auto.txt","r"))==NULL)
    {
        printf("Greska prilikom otvaranja datoteke");
        exit(1);
    }
    if((fIzlaz=fopen("auto88.txt","w"))==NULL)
    {
        fclose(fUlaz);
        printf("Greska prilikom otvaranja datoteke");
        exit(1);
    }
    while(fscanf(fUlaz,"%15s%15s%9s", prezime, ime, reg) == 3)
    {
        int br8=0,i;
        char *preg = reg;
        for(i=0; i<9; i++)
        {
            if(*preg=='8') br8++;
            preg++;
        }
        if (br8==2)
            fprintf(fIzlaz,"%-15s%-15s%-9s\n",prezime,ime,reg);
    }
    fclose(fUlaz);
    fclose(fIzlaz);
    return 0;
}

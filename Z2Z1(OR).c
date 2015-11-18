#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int br_studenata, i, j, k, max1, suma1_mjeseci = 0, suma11_mjeseci = 0, suma1_dani = 0, suma1_konacna = 0;
    int suma2_mjeseci = 0, suma22_mjeseci = 0, suma2_dani = 0, suma2_konacna = 0;
    int niz_datuma[1000][3];
    do
    {
        printf("Unesite broj studenata: ");
        scanf("%d", &br_studenata);
        if (br_studenata < 1 || br_studenata > 1000)
            printf("Neispravan broj studenata\n");
    }
    while (br_studenata < 1 || br_studenata > 1000);

    for (i = 0; i < br_studenata; i++)
    {
        printf("Unesite datum rodjenja %d. studenta: ", i+1);
        scanf("%d,%d,%d", &niz_datuma[i][0], &niz_datuma[i][1], &niz_datuma[i][2]);
        if ((niz_datuma[i][2] % 4 == 0 && !(niz_datuma[i][2] % 100 == 0)) || niz_datuma[i][2] % 400 == 0)
        {
            int niz_godina[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

            if (niz_datuma[i][1] == 2 && (niz_datuma[i][0] > 29 || niz_datuma[i][0] <= 0))
            {
                printf("Neispravan datum\n");
                i--;
            }
            for (j = 0; j < 12; j++)
                if (niz_datuma[i][1] == j + 1)
                    max1 = niz_godina[j];

            if ((max1 % 31 == 0 && (niz_datuma[i][0] > 31 || niz_datuma[i][0] <= 0)) ||
                    (max1 % 30 == 0 && (niz_datuma[i][0] > 30 || niz_datuma[i][0] <= 0)))
            {
                printf("Neispravan datum\n");
                i--;
            }
        }
        else
        {
            int niz_godina[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

            if (niz_datuma[i][1] == 2 && (niz_datuma[i][0] > 28 || niz_datuma[i][0] <= 0))
            {
                printf("Neispravan datum\n");
                i--;
            }
            for (j = 0; j < 12; j++)
                if (niz_datuma[i][1] == j + 1)
                    max1 = niz_godina[j];

            if ((max1 % 31 == 0 && (niz_datuma[i][0] > 31 || niz_datuma[i][0] <= 0)) ||
                    (max1 % 30 == 0 && (niz_datuma[i][0] > 30 || niz_datuma[i][0] <= 0)))
            {
                printf("Neispravan datum\n");
                i--;
            }
        }

    }
    for (i = 0; i < br_studenata; i ++)
    {
        for (k = i + 1; k < br_studenata; k++)
        {
        if ((niz_datuma[i][2] % 4 == 0 && !(niz_datuma[i][2] % 100 == 0)) || niz_datuma[i][2] % 400 == 0)
        {
            int niz_godina[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if (niz_datuma[i][2] == niz_datuma [k][2])
            {
                suma1_dani = abs(niz_datuma[i][0] - niz_datuma[k][0]);
                for (j = 0; j < niz_datuma[i][1] - 1; j++)
                    suma1_mjeseci += niz_godina[j];
                for (j = 0; j < niz_datuma[k][1] - 1; j++)
                    suma11_mjeseci += niz_godina[j ];
                suma1_konacna = suma1_dani + abs(suma1_mjeseci - suma11_mjeseci);
                if (suma1_konacna == 100)
                {
                    printf("Student %d. je rodjen tacno 100 dana prije studenta %d.\n", i + 1, k + 1);
                    suma1_dani = 0;
                    suma11_mjeseci = 0;
                    suma1_mjeseci = 0;
                    suma1_konacna = 0;
                }
            }
        }
        else
        {
            if (niz_datuma[i][2] == niz_datuma [k][2])
            {
                int niz_godina[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
                suma2_dani = abs(niz_datuma[i][0] - niz_datuma[k][0]);
                for (j = 0; j < niz_datuma[i][1] - 1; j++)
                    suma2_mjeseci += niz_godina[j];
                for (j = 0; j < niz_datuma[k][1] - 1; j++)
                    suma22_mjeseci += niz_godina[j];
                suma2_konacna = suma2_dani + abs(suma2_mjeseci - suma22_mjeseci);
                if (suma2_konacna == 100)
                {
                    printf("Student %d. je rodjen tacno 100 dana prije studenta %d.\n", i + 1, k + 1);
                    suma2_dani = 0;
                    suma22_mjeseci = 0;
                    suma2_mjeseci = 0;
                    suma2_konacna = 0;
                }
            }
        }
    }
    }
    return 0;
}

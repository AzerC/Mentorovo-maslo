#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, prethodni_red = 0, k, p, x = 0;
    float SV_matrice = 0, matrica[100][100], suma_clanova = 0.0, suma_reda= 0.0, nova_matrica[100][100], SV_reda = 0.0;

    printf("Unesite matricu:\n");

    for (i = 0; i < 100; i++)
    {
        for (j = 0; j < 100; j++)
        {
            scanf("%f", &matrica[i][j]);

            if(matrica[i][j] == -1 || matrica[i][j] == -2)
            {
                if (i == 0)
                    prethodni_red = j - 1;
                else if (prethodni_red != j - 1)
                {
                    printf("Ovo nije matrica!");
                    return 0;
                }
                break;
            }
            else if ( matrica[i][j] < -2)
            {
                printf("Greska\n");
                j--;
                continue;
            }
            else
            {
                suma_clanova += matrica[i][j];
            }
        }

        if (matrica[i][j] == -2)
            break;
    }
    SV_matrice = suma_clanova / ((i +1)*(j));
    for (k = 0; k <= i; k++)
    {
        for (p = 0; p < j; p ++)
        {
            if (matrica[k][p] == -1 || matrica[k][p] == -2)
                break;
            suma_reda += matrica[k][p];
        }
        SV_reda = suma_reda / j;
        if (!(SV_matrice - SV_reda < 0.1 && SV_matrice - SV_reda >  -0.1))
        {
            for (p = 0; p < j; p++)
            {
                if (matrica[k][p] == -1 || matrica[k][p] == -2)
                break;
               nova_matrica[x][p] = matrica[k][p];
            }
            x++;
        }
        suma_reda = 0;

    }
    printf("Nakon izbacivanja redova matrica glasi:\n");
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < p; j++)
        {
            printf("%.0f ", nova_matrica[i][j]);
        }
        printf("\n");
    }
    return 0;
}

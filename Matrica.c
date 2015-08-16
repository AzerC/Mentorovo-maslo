//Napisati program koji prima matricu (n x n) brojeva u opsegu od 1 do 9.
//Broj n se unosi na standardnom ulazu.
//Svaki uneseni broj od ukupno n x n brojeva se provjerava da li je u opsegu od 1 do 9 (ukljucivo).
//Ukoliko nije vraca se nazad sve dok se ne unese ispravan broj.
//Nakon unosa treba biti ponudjen izbor za korisnika (1, 2 ili 3) gdje je:

//n=3

//1 2 3
//4 5 6
//7 8 9

//1) ispis sume brojeva po redovima i po kolonama. npr:

//po redovima:
//1+2+3=6, 4+5+6=15, 7+8+9=24
//po kolonama:
//1+4+7=12, 2+5+8=15, 3+6+9=18

//2) ispis suma brojeva po dijagonalama:

//1+5+9=15
//3+5+7=15

//3) ispis sume svakog drugog krecuci se s lijeva na desno, odozgo prema dolje:
//1+3+5+7+9=25 (pozicije 0, 2, 4, 6, 8 odnosno 0,0; 0,2; 1,1; 2,0; 2,2)

#include <stdio.h>
#include <stdlib.h>

int suma_po_kolonama_i_redovima (int niz[][10], int vel)
{
    int i, j, suma1 = 0, suma2 = 0;
    for (i = 0; i < vel; i++)
    {
        for (j = 0; j < vel; j++)
        suma1 += niz[i][j];

        printf("Suma po %d. redu: %d\n", i + 1, suma1);
        suma1 = 0;
    }
    for (j = 0; j < vel; j++)
    {
        for (i = 0; i < vel; i++)
        suma2 += niz[i][j];

        printf("Suma po %d. koloni: %d\n", j + 1, suma2);
        suma2 = 0;
    }
}
int suma_po_dijagonalama (int niz[][10], int vel)
{
    int i, j, suma1 = 0, suma2 = 0;
    for (i = 0; i < vel; i++)
    {
        for (j = 0; j < vel; j++)
        {
            if (j == i)
                suma1 += niz[i][j];

            if (j == vel - 1 - i)
                suma2 += niz[i][j];
        }
    }
    printf("\nSuma po dijagonali: %d\n", suma1);
    printf("Suma po obrnutoj dijagonali: %d\n", suma2);
}
int suma_po_svakom_drugom (int niz[][10], int vel)
{
    int i = 0, j = 0, suma = 0;
    while (i < vel)
    {
        while (j < vel)
    {
        suma += niz[i][j];
        j+=2;
    }
        if (j == vel)
            j = 0;
        else
            j = 1;
        i++;
    }
    printf("\nSuma svakog drugog: %d\n", suma);
}
int matrica (int niz[][10], int vel)
{
    int i, j, choice;
    for (i = 0; i < vel; i++)
    {
        for (j = 0; j < vel; j++)
        {
            do {
            scanf("%d", &niz[i][j]);
            }while(niz[i][j] < 1 || niz[i][j] > 9);
        }
        printf("\n");
    }
    printf("Make your choice: 1, 2 or 3\n");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1 :
        suma_po_kolonama_i_redovima (niz, vel);
        break;
    case 2 :
        suma_po_dijagonalama (niz, vel);
        break;
    case 3 :
        suma_po_svakom_drugom (niz, vel);
        break;
    default :
        printf("Wrong choice!");
    }
}
int main()
{
    int n;
    int niz[10][10];

    printf("Unesite n: ");
    scanf("%d", &n);

    matrica (niz, n);
    return 0;
}

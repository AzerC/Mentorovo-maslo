//Korisnik putem tastature unosi razli�ite znakove: velika i mala slova i cifre. Unos se zavr�ava znakom ta�ka (.)
//Program zatim treba izra�unati i na ekran ispisati sumu svih unesenih cifara, a sve znakove koji nisu cifre zanemariti.
//Savjet: format %c se koristi za vrijednosti tipa char.


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int suma = 0;
    char znakovi;
    printf("Unesite znakove: ");

    do
    {
        scanf("%d", &znakovi);
        if (znakovi >= 0 && znakovi <= 9 )
           suma += znakovi;
           printf("Suma je: %d\n", suma);
    }while (znakovi != '.');

    return 0;
}

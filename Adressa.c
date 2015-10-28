#include <stdio.h>
#include <stdlib.h>

int ispravna(char *adresa)
{
    int i = 0, j = 0;
    do
    {   adresa++;
        if (*adresa == '@')
        i++;
    if ( *adresa == '\0')
    if (*(--adresa) == 'a' && *(--adresa) == 'b' && *(--adresa) == '.')
    {
        j++;
        break;
    }
    }while (*adresa != '\0');
    if (i == 1 && j == 1)
        return 1;
    else
        return 0;

}

int main()
{
    char nizc[100];
    printf("Unesite zeljenu adresu: ");
    scanf("%s", &nizc);
    printf("%d", ispravna(nizc));
    return 0;
}

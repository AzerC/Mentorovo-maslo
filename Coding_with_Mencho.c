#include <stdio.h>
#include <stdlib.h>

int suma(char* p)
{
    int suma1 = 0, i;
    while((*p) != '\0'){
    if ((*p) >= '0' && (*p) <= '9')
    {
    suma1 += (*p - 48);
    }
    p++;
    }
    return suma1;
}

int main()
{
    char niz[20];
    scanf("%20s", &niz);
    printf("%d", suma(&niz));
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k;

    printf("Unesite n: ");
    scanf("%d", &n);

    // Ako ne zelimo da broj pocinje sa 0.
    while (n % 10 == 0)
    {
        n /= 10;
    }

     do
   {
       k = n % 10;
       n/=10;
    //if (k != 0) --> U slucaju da zelimo izbaciti sve nule iz unesenog broja.
       printf("%d", k);

   }while (n != 0);

    return 0;
}

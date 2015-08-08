//romb (nxn) n-neparno, primjer (n=7):
//      *
//    *   *
//  *       *
//*           *
//  *       *
//    *   *
//      *
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, n, k;
    printf("Unesite n: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            k = i;
            if (i == n/2 && j == n - 1 || i == n/2 && j == 0 || i == 0 && j == n/2 || i == n - 1 && j == n/2
                || k == i && (j == n/2 - k || j == n/2 + k) || i ==  && j == )
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}

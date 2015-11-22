#include <stdio.h>
#include <stdlib.h>

int main()
{
    int niz[100], i, k , j = 0, n, temp;
    int niz_pomocni[10] = {0,0,0,0,0,0,0,0,0,0};
    for (i = 0; i < 100; i++)
    {
        scanf("%d", &niz[i]);
        if (niz[i] <= 0)
            break;
        do
        {
            n = niz[i] % 10;
            for (k = 0; k < 10; k++)
            {
                if (niz_pomocni[k] == 0)
                {
                    niz_pomocni[k] = n;
                    j++;
                    break;
                }
                else if (niz_pomocni[k] != 0 && niz_pomocni[k] != n)
                    continue;
                else if (niz_pomocni[k] != 0 && niz_pomocni[k] == n)
                    break;
            }
            niz[i] /= 10;
        }
        while (niz[i] != 0);
    }
    for (i = 0; i < j - 1; i++)
    {
        if (niz_pomocni[i] > niz_pomocni[i + 1])
        {
            temp = niz_pomocni[i];
            niz_pomocni[i] = niz_pomocni[i + 1];
            niz_pomocni[i + 1] = temp;
        }
    }
    for (i = 0; i < j; i++)
    {
        if (i == j - 1)
        printf("%d.", niz_pomocni[i]);
        else printf("%d,", niz_pomocni[i]);
    }
    return 0;
}

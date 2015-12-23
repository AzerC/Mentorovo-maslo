#include <stdio.h>
int main()
{
    int niz[100], i, k, counter = 0, n, temp, ima;
    int niz_pomocni[10] = {};

    for (i = 0; i < 100; i++)
    {
        scanf("%d", &niz[i]);
        if(niz[i] <= 0)
            break;
        do
        {
            if(counter==10) break;
            n = niz[i] % 10;
            niz[i] /= 10;
            ima = 0;

            if (counter == 0)
                niz_pomocni[counter++] = n;
            else
            {
                for (k = 0; k < counter; k++)
                {
                    if (niz_pomocni[k] == n)
                        ima = 1;
                }

            if (ima == 0)
            {
                niz_pomocni[counter++] = n;
            }
            }

        }
        while (niz[i] != 0);
    }

    for (i = 0; i < counter; i++)
    printf("%d ", niz_pomocni[i]);

    return 0;
}

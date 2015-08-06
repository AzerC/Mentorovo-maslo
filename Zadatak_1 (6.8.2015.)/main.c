#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int daj_rekurziju_brate(int x){

if (x==1)
    return x-1;
else
    daj_rekurziju_brate(--x);
}

int[] fibonaci_brat(int stari, int novi, int n){
    if (stari+novi<n)
        fibonaci_brat(novi, stari+novi, n);
    else
        return

}

int main()
{
    int i, j, n, k;
    printf("Unesite n: ");
    scanf("%d", &n);
    /*for (i = 0; i < n; i++){
            for(j = n - 1; j > i; j--)
                printf(" ");
            for(k = 0; k < 2*i + 1; k++)
                printf("|");
            printf("\n");
    }*/
    /*int printao=0, x;
    x=n;
    n=n*n;
    while(n!=0){
        printf("*");
        printao++;
        if (printao%x==0)
            printf("\n");
        n--;

    }*/
    //printf("%d", daj_rekurziju_brate(n));
    fibonaci_brat(1, 1, n);
    return 0;
}

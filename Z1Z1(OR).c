//Napišite program koji omogućuje unos tri realna broja koji čine dužine stranica nekog trougla. Program treba na ekran 
//ispisati sljedeće poruke (bez navodnika):
//“Brojevi moraju biti pozitivni i veci od nule” ako je korisnik unio negativan broj ili nulu kao jednu od stranica.
//“Nije trougao” ako su brojevi veći od nule, ali su takvi da oni ne mogu činiti dužine stranica trougla.
//“Jednakostranicni trougao” ako brojevi opisuju jednakostranični trougao.
//“Jednakokraki trougao” ako brojevi opisuju trougao koji je jednakokraki ali nije jednakostranični.
//“Pravougli trougao” ako brojevi opisuju pravougli trougao.
//“Obicni trougao” ako nijedan od iznad nabrojanih uslova nije ispunjen.

//Obratite pažnju da trougao može biti istovremeno jednakokraki i pravougli,
//pa u tom slučaju treba na ekran ispisati obje poruke 
//(prvo poruku “Jednakokraki trougao” a zatim “Pravougli trougao” u zasebnim redovima).

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    float a, b, c;
    printf("Unesite brojeve a, b i c: ");
    scanf("%f %f %f", &a, &b, &c);

    if (a <= 0 || b <= 0 || c <= 0)
    {
        printf("Brojevi moraju biti pozitivni i veci od nule");
        return 0;
    }

    else if ((a > 0 && b > 0 && c > 0) && !((c > a - b && c < a + b) && (a > c - b && a < c + b) && (b > a - c && b < a + c)))
    {
        printf("Nije trougao");
        return 0;
    }

    else if ((b == c && b == a))
        printf("Jednakostranicni trougao");

    else if ((b == c && b != a) || (a == c && a != b) || (a == b && a != c))
        printf("Jednakokraki trougao\n");

    else if ((c * c == a * a + b * b) || (a * a == c * c + b * b) || (b * b == a * a + c * c))
        printf("Pravougli trougao");

    else
        printf("Obicni trougao");
    return 0;
}

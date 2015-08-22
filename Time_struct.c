//Data je slijedeca struktura:
//struct Vrijeme
//{
//    int sati;
//    int minute;
//    int sekunde;
//};
//Napraviti program koji vrši unos dvije varijable koje su tipa struct Vrijeme, a potom
//odreðuje koliko je sekundi prošlo izmeðu ta dva vremena. Koristiti funkcije unos_vremena () i proteklo(),
//i paziti na sluèaj kada je drugo vrijeme ispred prvog.

#include <stdio.h>
#include <stdlib.h>

struct Vrijeme
{
    int sati;
    int minute;
    int sekunde;
};
int provjera (struct Vrijeme* v1, struct Vrijeme* v2)
{
    if ((*v1).sati < (*v2).sati)
        return 1;
    else if ((*v1).sati == (*v2).sati)
    {
        if ((*v1).minute < (*v2).minute)
            return 1;
        else if ((*v1).minute == (*v2).minute)
        {
            if ((*v1).sekunde < (*v2).sekunde)
                return 1;
            else if ((*v1).sekunde == (*v2).sekunde)
                return 1;

                return 0;
        }
        return 0;
    }
    return 0;
}

int proteklo (struct Vrijeme* v1, struct Vrijeme* v2)
{
    if (provjera(v1, v2) == 1)
    {
    printf("%d\n", provjera(v1, v2));
    return (((*v2).sati - (*v1).sati)*3600 + ((*v2).minute - (*v1).minute)*60 + (*v2).sekunde - (*v1).sekunde);
    }
    else
        return -1;
}

int main()
{
    struct Vrijeme v1, v2;
    printf("Unesite prvo vrijeme: ");
    scanf("%d %d %d", &v1.sati, &v1.minute, &v1.sekunde);

    printf("Unesite drugo vrijeme: ");
    scanf("%d %d %d", &v2.sati, &v2.minute, &v2.sekunde);

    printf("Proteklo vrijeme je: %d", proteklo(&v1, &v2));
    return 0;
}

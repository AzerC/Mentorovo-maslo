#include <stdio.h>
#include <stdlib.h>
//PROGRAM RADI IAKO SE IZMEDJU RIJECI NALAZI VISE RAZMAKA.
void izbaci_rijec (char* s, int n)
{
    int razmak = 1, broj_rijeci = 0;//razmak = 1 osigurava da ce prva rijec biti izbrojana.
    char *poc;
    while (*s != '\0')//prebrojavanje rijeci
    {
        if (*s == ' ')
        razmak = 1;
        else if (razmak == 1)//ulazi u else if ako trenutni znak nije razmak i ispituje da li se prije trenutnog
        {                    //znaka nalazio razmak.
            razmak = 0;
            broj_rijeci++;
        //izbacivanje n-te rijeci iz stringa:
            if (broj_rijeci == n) poc = s;
            if (broj_rijeci == n + 1)
            {
                while (*poc++ = *s++);//ako stavimo '==' umjesto '=' program nema smisla, jer ne ulazi u if.
                return;
            }
        }
        s++;
    }
    if (broj_rijeci == n) *poc = '\0';//u slucaju da zelimo izbaciti posljednju rijec.
}
int main()
{
    char s[] = "Azer voli lijepe cure";
    izbaci_rijec(s, 4);
    printf("%s", s);
    return 0;
}

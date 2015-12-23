#include <stdio.h>
#include <stdlib.h>
//prolazak kroz string:
//while(*s1 != '\0') s1++;

char* spoji(char *s1, char* s2)
{
    char* temp = s1;//pomocna varijabla koja nam je potrebna za uspjesno ispisivanje modifikovanog stringa.
    while(*s1++);
    s1--;//pokazivac iz while-loop nakon zavrsetka loop-a pokazuje na poziciju iza '\0', zato je potrebno s1--;
    while (*s1++ = *s2++);//loop koji vrsi nadovezivanje jednog stringa na drugi.
    return temp;
}
int main()
{
    char s1[] = "Cao, cao, vozdrica";
    char s2[] = " cickovo ulje, kosica.";
    printf("%s", spoji(s1, s2));

    return 0;
}

#include <stdio.h>
char* velika(char *s)
{
    char *p = s;
    while (*s != '\0')
    {
        if(*s >= 'a' && *s <= 'z')
        *s = *s - 32;
        s++;
    }
    return p;
}
int main() {
    char s[] = "Ovo je primjer.";
	printf("%s", velika(s));
    return 0;
}


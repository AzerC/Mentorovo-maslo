#include <stdio.h>
#include <stdlib.h>
void f(char *s, char *c)
{
    char *p = s;
    char *pt = p;
    char *kt = p + 1;
    while (*kt != '\0')
    {
        int br = 0;
        char *pt1 = pt + 1;
        char *kt1 = kt + 1;
        while (*kt1 != '\0')
        {
            if (*pt >= 'A' && *pt <= 'Z' && *kt >= 'A' && *kt <= 'Z' && *pt == *pt1 && *kt == *kt1)
                br++;
            kt1++;
            pt1++;
        }
        if (br > max)
        {
            max = br;
            pm = pt;
            km = kt;
        }
        pt++;
        kt++;
    }
    while (pm <= km)
    {
        *c++=*pm++;
    }
    *c = '\0';
}
int main()
{

    return 0;
}

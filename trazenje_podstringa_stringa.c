#include <stdio.h>
#include <stdlib.h>
char* podstring(char* s1, char* s2)
{
    while(*s1 != '\0')
    {
        char* p = s1;
        char* q = s2;
        while (*p++ == *q++)
            if (q == '/0')//ako ispunjava uslov znaci da je podstring nadjen.
            return s1;
        s1++l
    }
    return NULL;
}
int main()
{
    char s1[] = "aabc";
    char s2[] = "abc";
    printf("%s", podstring(s1, s2));
    return 0;
}

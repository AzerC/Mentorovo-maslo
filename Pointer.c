#include <stdio.h>

int j, k;
int *ptr;
int *kemo;
int main(void)
{
j = 1;
k = 65;
ptr = &k;
kemo = ptr;
printf("\n");
printf("j has the value %d and is stored at %p\n", j, &j);
printf("k has the value %d and is stored at %p\n", k, &k);
printf("ptr has the value %p and is stored at %p\n", ptr, &ptr);
printf("kemo has the value %p and is stored at %p %d\n", kemo, &kemo, *kemo);
printf("The value of the integer pointed to by ptr is %d\n", *ptr);
return 0;
}


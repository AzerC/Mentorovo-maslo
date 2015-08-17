//----------- Program 2.1 -----------------------------------
/* Program 2.1 from PTRTUT10.HTM 6/13/97 */
#include <stdio.h>
#include <stdlib.h>
int my_array[] = {9,23,17,4,-5,100};
int *ptr;
int main(void)
{
//int i;
//ptr = &my_array[0]; /* point our pointer to the first
//element of the array */
int *p = &my_array[0];
int *q = &my_array[0];
int *r = &my_array[0];
int *s = &my_array[0];
printf("*p++ je %d\n", *p++);
printf("%d\n", *p);
printf("*(q++) je %d\n", *(++q));
printf("(*r)++ je %d\n", ++(*r));
printf("++(*s) je %d\n", (*s)++);
printf("++(*s) je %d", (*s));
/*printf("\n\n");
for (i = 0; i < 6; i++)
{
printf("my_array[%d] = %d ",i,my_array[i]);
printf("ptr + %d = %d\n",i, *(ptr + i));
*/
//}
return 0;
}

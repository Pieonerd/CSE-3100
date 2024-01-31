#include <stdio.h>
int main(void)
{
int sum = 0, i = 0;
 
printf("Hello, World!\n");
while(i < 200) {
    sum += i;
    i += 2;
}
printf("%d \n", sum);
return 0;
}
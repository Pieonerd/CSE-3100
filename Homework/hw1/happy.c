#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;

	printf("n = ");
	scanf("%d", &n);

	int m = n;
	//TODO
	//add code below
    int digit, total;
	while(n > 0 && n != 1) {
        total = 0;
        while(n != 0) {
            digit = n % 10;
            total += digit * digit;
            n = n / 10;
        }
        n = total;
        printf("%d\n", n);
        if(n == 4) {
            break;
        }
    }

	if(n==1) printf("%d is a happy number.\n", m);
	else printf("%d is NOT a happy number.\n", m);
	return 0;
}
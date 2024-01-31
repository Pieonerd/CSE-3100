#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i;

	printf("n = ");
	scanf("%d", &n);

	double pi = 0.;
	//TODO
	//add code below
	int j, a=1;
    for(i=0; i<=n; i++) {
		a = 1;
		for(j=1; j<=i; j++) {
			a *= 16;
		}
        pi += ((4./((8*i)+1)) - (2./((8*i)+4)) - (1./((8*i)+5)) - (1./((8*i)+6))) * (1./a);
    }
	
	printf("PI = %.10f\n", pi);
	return 0;
}
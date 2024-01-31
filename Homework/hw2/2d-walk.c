#include <stdio.h>
#include <stdlib.h>

double two_d_random(int n)
{

	//Fill in code below
	//When deciding which way to go for the next step, generate a random number as follows.
	//r = rand() % 4;
	//Treat r = 0, 1, 2, 3 as up, right, down and left respectively.

	//The random walk should stop once the x coordinate or y coordinate reaches $-n$ or $n$. 
	//The function should return the fraction of the visited $(x, y)$ coordinates inside (not including) the square.
	int x=0, y=0, steps=0;
	int visited[2*n+1][2*n+1];

	// Initialize the visited array to mark visited coordinates
	for(int i=0; i<=2*n; i++) {
		for(int j=0; j<=2*n; j++) {
			visited[i][j] = 0;
		}
	}

	// Perform the random walk until reaching the boundaries of the square
	while(x<n && x>-n && y<n && y>-n) {

		if(visited[x+n][y+n] != 1) {
			visited[x+n][y+n] = 1;
			steps++;
		}
	
		// Generate a random number to decide the next step (up, right, down, left)
		int r = rand() % 4;
		switch(r) {
			case 0: y++; break;
			case 1: x++; break;
			case 2: y--; break;
			case 3: x--; break;
		}
	}

	// Calculate and return the fraction of visited coordinates inside the square
	return (double)steps / ((2*n-1)*(2*n-1));
}

//Do not change the code below
int main(int argc, char* argv[])
{
	int trials = 1000;
	int i, n, seed;
	if (argc == 2) seed = atoi(argv[1]);
	else seed = 12345;

	srand(seed);
	for(n=1; n<=64; n*=2)
	{	
		double sum = 0.;
		for(i=0; i < trials; i++)
		{
			double p = two_d_random(n);
			sum += p;
		}
		printf("%d %.3lf\n", n, sum/trials);
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//TODO
//Implement the below function
//Simulate one particle moving n steps in random directions
//Use a random number generator to decide which way to go at every step
//When the particle stops at a final location, use the memory pointed to by grid to 
//record the number of particles that stop at this final location
//Feel free to declare, implement and use other functions when needed

void one_particle(int *grid, int n)
{
	int x=0, y=0, z=0;

	for(int step=0; step<n; step++) {
		
		int r = rand() % 6;
		switch(r) {
			case 0: x--; break;
			case 1: x++; break;
			case 2: y++; break;
			case 3: y--; break;
			case 4: z++; break;
			case 5: z--; break;
		}
	}

	grid[(x+n)+(2*n+1) * ((y+n)+(2*n+1)*(z+n))]++;
}

//TODO
//Implement the following function
//This function returns the fraction of particles that lie within the distance
//r*n from the origin (including particles exactly r*n away)
//The distance used here is Euclidean distance
//Note: you will not have access to math.h when submitting on Mimir
double density(int *grid, int n, double r)
{
	int particles=0, total=0;
	for(int i=-n; i<=n; i++) {
		for(int j=-n; j<=n; j++) {
			for(int k=-n; k<=n; k++) {
				int squared_distance = ((i*i)+(j*j)+(k*k));
				total += grid[(i+n)+(2*n+1) * ((j+n)+(2*n+1)*(k+n))];
				if(squared_distance <= (r*r*n*n)) {
					particles += grid[(i+n)+(2*n+1) * ((j+n)+(2*n+1)*(k+n))];
				}
			}
		}
	}

	return (double)particles / total;
}

//use this function to print results
void print_result(int *grid, int n)
{
    printf("radius density\n");
    for(int k = 1; k <= 20; k++)
    {
        printf("%.2lf   %lf\n", 0.05*k, density(grid, n, 0.05*k));
    }
}

//TODO
//Finish the following function
//See the assignment decription on Piazza for more details
void diffusion(int n, int m)
{
	//fill in a few line of code below
	int *grid = malloc((2*n+1)*(2*n+1)*(2*n+1) * sizeof(int));

	for(int i = 1; i<=m; i++) {
		one_particle(grid, n);
	}

	print_result(grid, n);
	//fill in some code below
	free(grid);
}

int main(int argc, char *argv[])
{
	
	if(argc != 3)
	{
		printf("Usage: %s n m\n", argv[0]);
		return 0; 
	}
	int n = atoi(argv[1]);
	int m = atoi(argv[2]);

	assert(n >= 1 && n <=50);
	assert(m >= 1 && m <= 1000000);
	srand(12345);
	diffusion(n, m);
	return 0;
}
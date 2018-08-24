/* About this algorithm:
 * * Here we use dynamic programming to find a solution to the
 * * travelling salesperson problem. The problem consists of finding
 * * the least-cost cycle in a given set of nodes. */

#include <stdio.h>
#define MAX 100
#define INFINITY 999

int tsp_dp (int c[][MAX], int tour[], int start, int n);

int main() {
	int n; /* Number of cities. */
	int i, j; /* Loop counters. */
	int c[MAX][MAX]; /* Cost matrix. */
	int tour[MAX]; /* Tour matrix. */
	int cost; /* Least cost. */

	printf ("This program demonstrates the TSP problem.");
	printf ("\nHow many cities to traverse? ");
	scanf ("%d", &n);
	printf ("Enter the cost matrix: (999: no connection)\n");
	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
			scanf ("%d", &c[i][j]);

	for (i=0; i<n; i++)
		tour[i] = i;

	cost = tsp_dp (c, tour, 0, n);

	printf ("Minimum cost: %d.\nTour: ", cost);
	for (i=0; i<n; i++)
		printf ("%d ", tour[i]+1);
	printf ("1\n");
}

int tsp_dp (int c[][MAX], int tour[], int start, int n)
{
	int i, j, k; /* Loop counters. */
	int temp[MAX]; /* Temporary during calculations. */
	int mintour[MAX]; /* Minimal tour array. */
	int mincost; /* Minimal cost. */
	int ccost; /* Current cost. */

	/* End of recursion condition. */
	if (start == n - 2)
		return c[tour[n-2]][tour[n-1]] + c[tour[n-1]][0];

		/* Compute the tour starting from the current city. */
	mincost = INFINITY;
	for (i = start+1; i<n; i++) { 
		for (j=0; j<n; j++)
			temp[j] = tour[j];

		/* Adjust positions. */
		temp[start+1] = tour[i];
		temp[i] = tour[start+1];

		/* Found a better cycle? (Recurrence derivable.) */
		if (c[tour[start]][tour[i]] +
			(ccost = tsp_dp (c, temp, start+1, n)) < mincost) {
			mincost = c[tour[start]][tour[i]] + ccost;
			for (k=0; k<n; k++)
				mintour[k] = temp[k];
		}
	}

		/* Set the minimum-tour array. */
	for (i=0; i<n; i++)
		tour[i] = mintour[i];

	return mincost;
}

#include <stdio.h>

const int infty = 100000000;
const int n = 5;
int wagi[n][n] = {
	{ 0, 64,  3,  2, 31},
	{64,  0, 69, 61, 69},
	{ 3, 69,  0, 34,  7},
	{ 2, 61, 34,  0, 78},
	{31, 69,  7, 78,  0},
};

#define min(A, B) A <? B

int dp() {
	int best, prevstate;
	int table[1 << n][n];
	for(int i = 0; i < (1 << n); ++i)
		for(int j = 0; j < n; ++j)
			if(((1 << j) & i) == 0)
				table[i][j] = -2;
			else {
				best = -1;
				prevstate = i ^ (1 << j);
				printf("[%d][%d] = %d\n", i, j, prevstate);
				if(prevstate == 0)
					table[i][j] = 0;
				else {
					for(int k = 0; k < n; ++k)
						if(j != k && table[prevstate][k] > -1 && (best == -1 || table[prevstate][k] + wagi[j][k] < best))
							best = table[prevstate][k] + wagi[j][k];
						if(best == infty)
							table[i][j] = -1;
						else
							table[i][j] = best;
				}
			}
	for(int i = 0; i < (1 << n); ++i) {
		printf("%d: ", i);
		for(int j = 0; j < n; ++j)
			printf("[%d]", table[i][j]);
		printf("\n");
	}
	int answer = infty;
	for(int i = 0; i < n; ++i)
		if(table[(1 << n) - 1][i] > -1)
			answer = min(answer, table[(1 << n) - 1][i]);
	return answer;
}

main() {
	printf("%d\n", dp());
}

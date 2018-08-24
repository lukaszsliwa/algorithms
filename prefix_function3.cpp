#include <cstdio>
#include <cstring>

using namespace std;

const int N_MAX = 100000;
char wzor[N_MAX];
int q, k, pi[N_MAX], pi_prim[N_MAX], n;

void prefix_function() {
	pi[1] = 0;
	k = 0;
	for(q = 2; q < n; ++q) {
		while(k > 0 && wzor[k + 1] != wzor[q])
			k = pi[k];
		if(wzor[k + 1] == wzor[q])
			k++;
		pi[q] = k;
	}
}

int input() {
	char znak;
	q = 1;
	while(scanf("%c", &znak) && znak != '\n')
		wzor[q++] = znak;
	return q;
}

int main() {
	n = input();
	prefix_function();
	/* modification of KMP prefix function */
	for(q = 1; q < n; ++q) {
		pi_prim[q] = pi[q];
		if(wzor[pi[q] + 1] == wzor[q + 1] && pi[q] != 0)
			pi_prim[q] = pi_prim[pi[q]];
	}
	/*for(q = 1; q < n; ++q)
		if(pi[pi[q]] != 0)
			pi[q] = pi[pi[q]];*/
	for(q = 1; q < n; ++q)
		printf("%d ", pi_prim[q]);
	return 0;
}

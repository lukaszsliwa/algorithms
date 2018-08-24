#include <cstdio>
#include <cstring>

using namespace std;

const int M = 1000;
int pi[M];
char wzor[M];

void prefix_function() {
	int k, q;
	k = 0;
	for(q = 1; q < strlen(wzor); ++q) {
		while(k > 0 && wzor[q] != wzor[k])
			k = pi[k];
		if(wzor[k] == wzor[q])
			k++;
		pi[q] = k;	
	}
}

int main() {
	scanf("%s", wzor);
	prefix_function();
	for(int i = 0; i < strlen(wzor); ++i)
		printf("pi[%d] = %d\n", i, pi[i]);
	return 0;
}

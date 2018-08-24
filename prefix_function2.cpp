#include <cstdio>
#include <cstring>

using namespace std;

const int M = 1000;
int pi[M];
char wzor[M];

void prefix() {
	int k, q = 0;
	for(q = 1; q < strlen(wzor); ++q) {
		for(; k > 0 && wzor[k] != wzor[q]; k = pi[k]);
		if(wzor[k] == wzor[q]) k++;
		pi[q] = k;
	}
}

int main() {
	scanf("%s", wzor);
	prefix();
	for(int i = 0; i < strlen(wzor); ++i)
		printf("pi[%d] = %d\n", i, pi[i]);
	return 0;
}

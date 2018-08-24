#include <cstdio>

using namespace std;

const int M = 1000;

int n, q, j;
int s[M], f[M], T[M];

int main() {
	int i;
	scanf("%d", &n);
	for(i = 0; i < n; ++i)
		scanf("%d%d", &s[i], &f[i]);
	j = q = 0;
	T[q++] = 0;
	for(i = 1; i < n; ++i) {
		if(s[i] >= f[j]) {
			T[q++] = i;
			j = i;
		}
	}
	for(i = 0; i < q; ++i)
		printf("%d %d\n", s[T[i]], f[T[i]]);
	return 0;
}

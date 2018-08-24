#include <cstdio>

using namespace std;

int main() {
	int n, m, l = 0, i;
	bool cykle;
	scanf("%d", &n);
	i = n;
	while(i--) {
		scanf("%d", &m);
		l += m;
	}
	l /= 2;
	printf(l < n ? "Nie ma cyklu.\n" : "Jest cykl.\n");
	return 0;
}

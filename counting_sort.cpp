#include <cstdio>

using namespace std;

int n, k;
int *tab, *count;

int main() {
	int i, q;
	scanf("%d", &n);
	tab = new int[n + 1];
	for(i = 0; i < n; ++i) {
		scanf("%d", &tab[i]);
		k = tab[i] > k ? tab[i] : k;
	}
	count = new int[k + 1];
	for(i = 0; i < n; ++i)
		count[tab[i]]++;
	for(i = 0, q = 0; i <= k; ++i)
		while(count[i]-- > 0)
			tab[q++] = i;
	for(i = 0; i < q; ++i)
		printf("%d ", tab[i]);
	printf("\n");
	return 0;
}

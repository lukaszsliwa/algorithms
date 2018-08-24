#include <cstdio>

using namespace std;

int n, i;
int *tab;

void wczytaj() {
	scanf("%d", &n);
	tab = new int[n + 1];
	for(i = 0; i < n; ++i)
		scanf("%d", &tab[i]);
}

void insertion_sort(int p, int q) {
	int r, w;	
	if(p <= q) {
		r = tab[p];
		w = p - 1;
		while(w >= 0 && r < tab[w])
			tab[w + 1] = tab[w--];
		tab[w + 1] = r;
		insertion_sort(p + 1, q);
	}
}

int main() {
	wczytaj();
	insertion_sort(1, n - 1);
	for(i = 0; i < n; ++i)
		printf("%d ", tab[i]);
	printf("\n");
	return 0;
}

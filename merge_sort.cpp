#include <cstdio>

using namespace std;

int n, i;
int *tab, *tmp;

void wczytaj() {
	scanf("%d", &n);
	tab = new int[n+1];
	tmp = new int[n+1];
	for(i = 0; i < n; ++i)
		scanf("%d", &tab[i]);
}

int wybierz(int& a, int q, int& b, int r) {
	if(a <= q && b <= r)
		return tab[a] < tab[b] ? tab[a++] : tab[b++];
	else if(a <= q)
		return tab[a++];
	else return tab[b++];
}

void merge(int p, int q, int k, int r) {
	int a, b, c;
	for(a = p, b = k, c = 0; a <= q || k <= r; ++c)
		tmp[c] = wybierz(a, q, k, r);
	for(c = p, a = 0; c <= r; ++c)
		tab[c] = tmp[a++];
}

void merge_sort(int p, int r) {
	int q = 0;
	if(p < r) {
		q = (p + r)/2;
		merge_sort(p, q);
		merge_sort(q + 1, r);
		merge(p, q, q + 1, r);
	}
}

int main() {
	wczytaj();
	merge_sort(0, n - 1);
	for(i = 0; i < n; ++i)
		printf("%d ", tab[i]);
	printf("\n");
	delete []tab;
	delete []tmp;
	return 0;
}

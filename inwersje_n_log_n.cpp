#include <cstdio>

using namespace std;

int n, i, R;
int *tab, *tmp;

#define text(X) printf("%s\n", X)
#define debug(X, Y) printf("%d %d\n", X, Y)

void wczytaj() {
	scanf("%d", &n);
	tab = new int[n + 1];
	tmp = new int[n + 1];
	for(i = 0; i < n; ++i)
		scanf("%d", &tab[i]);
}

int element(int& a, int b, int& c, int d) {
	if(a <= b && c <= d) {
		R++;
		return tab[a] < tab[c] ? tab[a++] : tab[c++];
	} else if(a <= b)
		return tab[a++];
	else 
		return tab[c++];
}

void merge(int o, int r, int m, int q) {
	int y, z, k;
	k = o;
	for(y = 0; o <= r || m <= q  ; ++y)
		tmp[y] = element(o, r, m, q);
	for(y = 0, z = k; z <= q; ++z)
		tab[z] = tmp[y++];
}

void merge_sort(int p, int q) {
	int r;
	if(p < q) {
		r = (p + q)/2;
		merge_sort(p, r);
		merge_sort(r + 1, q);
		merge(p, r, r + 1, q);
	}	
}

int main() {
	wczytaj();
	merge_sort(0, n - 1);
	printf("%d\n", R);
	return 0;
}

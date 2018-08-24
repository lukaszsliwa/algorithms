#include <cstdio>

using namespace std;

int n, i, j, k;
int *tab;

void wczytaj() {
	scanf("%d", &n);
	tab = new int[n+1];
	for(i = 0; i < n; ++i)
		scanf("%d", &tab[i]);
}
/* insertion_sort wersja (1) */
void insertion_sort() {
	for(i = 1; i < n; ++i) {
		j = i - 1;
		k = tab[i];
		while(j >= 0 && tab[j] > k)
			tab[j + 1] = tab[j--];
		tab[j + 1] = k;
	}
}

/* wersja (2) */
void insertion_sort2() {
	for(i = 1; i < n; ++i) {
		j = i - 1;
		while(j >= 0 && tab[j] > tab[j + 1]) {
			k = tab[j + 1];
			tab[j + 1] = tab[j];
			tab[j--] = k;
		}
	}
}

/* wersja (3) w dwoch liniach miedzy dwiema parami nawiasow petli*/
void insertion_sort3() {
	for(i = 1; i < n; ++i, j = i - 1)
		while(j >= 0 && tab[j] > tab[j + 1] && (k = tab[j], tab[j] = tab[j+1], tab[j + 1] = k) && j--);
}

/* wersja (4) w trzech liniach */
void insertion_sort4() {
	for(i = 1; i < n; ++i, j = i - 1, k = tab[i]) {
		while(j >= 0 && tab[j] > k && ( tab[j + 1] = tab[j--]));
		tab[j + 1] = k;
	}
}

void drukuj() {
	for(i = 0; i < n; ++i)
		printf("%d ", tab[i]);
	printf("\n");
}

int main() {
	wczytaj();
	insertion_sort2();
	drukuj();
	delete []tab;
	return 0;
}


#include <cstdio>

using namespace std;

const int M = 1000000;

int n, m, i, y, x;
int tab1[M], tab2[M], tab[M];

void wczytaj(int t[], int w) {
	int y = 0;
	while(w--)
		scanf("%d", &t[y++]);
}

int wybierz(int& a, int& b) {
	if(a < n && b < m) {
		return tab1[a] < tab2[b] ? tab1[a++] : tab2[b++];
	} else if(a < n) return tab1[a++];
	else return tab2[b++];
}

int main() {
	scanf("%d%d", &n, &m);
	wczytaj(tab1, n);
	wczytaj(tab2, m);
	i = y = 0;
	for(x = 0; x < n + m; ++x)
		tab[x] = wybierz(i, y);
	i = 0;
	while(i < n + m)
		printf("%d ", tab[i++]);
	return 0;
}

#include <cstdio>

using namespace std;

int n, i, liczba;
int  *tab;

bool binary_search(int p, int q) {
	int r;
	while(p <= q) {
		r = (p + q)/2;
		if(liczba == tab[r])
			return true;
		else if(liczba < tab[r])
			q = r - 1;
		else if(liczba > tab[r])
			p = r + 1;
	}
	return false;
}

int main() {
	scanf("%d", &n);
	tab = new int[n+1];
	for(i = 0;i < n; ++i)
		scanf("%d", &tab[i]);
	scanf("%d", &liczba);
	printf(binary_search(0, n - 1) ? "TAK\n" : "NIE\n");
	delete []tab;
	return 0;
}

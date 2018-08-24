#include <cstdio>

using namespace std;

int n, i;
double x, *tab, *tmp;
bool wynik;

void wczytaj_dane() {
	scanf("%d", &n);
	tab = new double[n+1];
	tmp = new double[n+1];
	for(i = 0; i < n; ++i)
		scanf("%lf", &tab[i]);
	scanf("%lf", &x);
}

double wybierz(int& p, int q, int& k, int r) {
	if(p <= q && k <= r)
		return tab[p] < tab[k] ? tab[p++] : tab[k++];
	else if(p <= q)
		return tab[p++];
	else 
		return tab[k++];
}

void merge(int p, int q, int k, int r) {
	int y, z, a, b, c;
	a = p;
	b = k;
	for(y = 0; a <= q || b <= r; ++y)
		tmp[y] = wybierz(a, q, b, r);
	for(y = p, z = 0; y <= r; ++y)
		tab[y] = tmp[z++];
}

void merge_sort(int p, int r) {
	int q;
	if(p < r) {
		q = (p + r)/2;
		merge_sort(p, q);
		merge_sort(q + 1, r);
		merge(p, q, q + 1, r);		
	}
}

bool szukaj(double skladnik, int p, int q) {
	int r;
	while(p <= q) {
		r = (p + q)/2;
		if(skladnik == tab[r])
			return true;
		else if(skladnik < tab[r])
			q = r - 1;
		else if(skladnik > tab[r])
			p = r + 1;
	}
	return false;
}

int main() {
	wczytaj_dane();
	merge_sort(0, n - 1);
	for(i = 0;i < n; ++i) {
		wynik = szukaj(x - tab[i], i + 1, n - 1);
		if(wynik)
			printf("%.2lf + %.2lf = %.2lf\n", x - tab[i], tab[i], x);
	}
	delete []tab;
	delete []tmp;
	return 0;
}

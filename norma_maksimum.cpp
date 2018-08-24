#include <cstdio>
#include <algorithm>
using namespace std;

const int n_max = 1000000;

int n;
float tab[n_max];

float wynik() {
	float m = tab[0], wynik = 0.0;
	for(int i = 0; i < n; ++i) {
		m = max(m, tab[i]);
		wynik = max(wynik, (m - tab[i]) / 2);
	}
	return wynik;
}

main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%f", &tab[i]);
	printf("%f\n", wynik());
}

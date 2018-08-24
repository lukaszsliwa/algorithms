#include <iostream>
#include <cassert>
using namespace std;

const int n_max = 1001;

int n, skojarzony_czarny[n_max], skojarzony_bialy[n_max];
bool graf[n_max][n_max], jest[n_max];

inline void wczytaj() {
	int k, l;
	cin >> n;
	assert(n_max >= n);
	for(int i = 1; i <= n; ++i) {
		cin >> k;
		while(k--) {
			cin >> l;
			graf[i][l] = true;
		}
	}
}

bool sciezka(int v) {
	for(int y = 1; y <= n; ++y)
		if(graf[v][y] == true && jest[y] == false) {
			jest[y] = true;
			if(skojarzony_czarny[y] < 0 || 
				sciezka(skojarzony_czarny[y])) {
				skojarzony_czarny[y] = v;
				skojarzony_bialy[v] = y;
				return true;
			}
		}
	return false;
}

main() {
	int wynik = 0;
	wczytaj();
	for(int i = 0; i <= n; ++i) {
		jest[i] = 0;
		skojarzony_czarny[i] = skojarzony_bialy[i] = -1;
	}
	for(int i = 1; i <= n; ++i) {
		for(int y = 1; y <= n; ++y)
			jest[y] = false;
		if(sciezka(i))
			wynik++;
	}
	for(int i = 1; i <= n; ++i)
		cout << skojarzony_czarny[i] << ' ' << i << endl;
	cout << wynik << endl;
}

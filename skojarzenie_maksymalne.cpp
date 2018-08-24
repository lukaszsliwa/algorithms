#include <iostream>
#include <cassert>
#include <vector>
#include <list>
using namespace std;

const int n_max = 1003;

int n, c[n_max][n_max];
vector<list<int> > graf;

typedef list<int>::iterator list_iter;

inline void wczytaj() {
	int i, l, k;
	cin >> n;
	assert(n < n_max); /* sprawdzamy, czy n jest w granicach stalej n_max */
	graf.resize(n + 2);
	for(i = 1; i <= n; ++i) {
		cin >> k;
		while(k--) {
			cin >> l;
			graf[i].push_back(l);
			c[i][l] = 1;
		}
	}
	for(i = 1; i <= n; ++i)
		c[0][i] = c[i][n + 1] = 1;
}

bool sciezka(int t[]) {
	t[0] = -1;
	for(int i = 1; i <= n; ++i)
		if(c[0][i] != 0) {
			t[i] = 0;
			for(list_iter y = graf[i].begin();
				y != graf[i].end(); ++y)
				if(c[i][*y] != 0 && c[*y][n + 1] != 0) {
					t[*y] = i;
					t[n + 1] = *y;
					return true;
				}
		}
	return false;
}

int skojarzenie_maksymalne() {
	int suma = 0, p[n_max];
	while(sciezka(p)) {
		int v = n + 1;
		while(p[v] != -1) {
			c[p[v]][v] -= 1;
			v = p[v];
		}
		cout << endl;
		suma += 1;
	}
	return suma;
}

main() {
	wczytaj();
	cout << skojarzenie_maksymalne() << endl;
}

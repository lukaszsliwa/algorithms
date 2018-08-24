#include <iostream>
#include <vector>
#include <list>
using namespace std;

const int n_max = 100000;

int n, in[n_max], out[n_max];
vector<list<int> > graf;

inline void wczytaj() {
	int a, b, m;
	cin >> n >> m;
	graf.resize(n + 1);
	while(m--) {
		cin >> a >> b;
		graf[a].push_back(b);
		in[b]++;
		out[a]++;
	}
}

int wierzcholek() {
	for(int i = 1; i <= n; ++i)
		if(in[i] == n - 1 && out[i] == 0)
			return i;
	return -1;
}

main() {
	wczytaj();
	cout << wierzcholek() << endl;
}

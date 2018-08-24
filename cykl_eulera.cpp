#include <iostream>
#include <vector>
#include <list>
using namespace std;

int n;
vector<list<int> > graf;

ostream& operator << (ostream& os, vector<int>& W) {
	for(vector<int>::iterator i = W.begin();
		i != W.end(); ++i)
		os << *i << ' ';
	return os;
}

inline void wczytaj() {
	int a, b, m;
	cin >> n >> m;
	graf.resize(n + 1);
	while(m--) {
		cin >> a >> b;
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
}

inline void euler() {
	int v, u;
	vector<int> stos, wynik;
	stos.push_back(1);
	while(!stos.empty()) {
		v = stos.back();
		if(!graf[v].empty()) {
			u = graf[v].back();
			graf[v].pop_back();
			stos.push_back(u);
			v = u;
		} else {
			v = stos.back();
			stos.pop_back();
			wynik.push_back(v);
		}
	}
	cout << wynik << endl;
}

main() {
	wczytaj();
	euler();
}

#include <iostream>
#include <vector>
#include <list>
#include <utility>
using namespace std;

int n, num = 1, numer[10000], l[10000];

vector<list<int> > graf;
list<list<int> > dwuspojne;
vector<pair<int, int> > stos;

inline void wczytaj() {
	int a, b, m;
	cin >> n >> m;
	graf.resize(n + 1);
	while(m--) {
		cin >> a >> b;
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	int i;
	for(i = 0; i <= n; ++i)
		numer[i] = 0;
}

void dwuspojne_skladowe(int v, int p) {
	l[v] = numer[v] = num++;
	for(list<int>::const_iterator u = graf[v].begin();
		u != graf[v].end(); ++u)
		if(numer[*u] == 0) {
			stos.push_back(make_pair(v, *u));
			dwuspojne_skladowe(*u, v);
			l[v] = l[v] <? l[*u];
			if(l[*u] >= numer[v]) {
				pair<int, int> e = stos.back();;
				stos.pop_back();
				cout << *u << " - " << v << ' ';
				while(e != make_pair(*u, v) && e != make_pair(v, *u)) {
					cout << e.first << " - " << e.second << ' ';
					e = stos.back();
					stos.pop_back();
				}
				cout << endl;
			}
		} else if(*u != p && numer[*u] < numer[v]) {
			stos.push_back(make_pair(*u, v));
			l[v] = l[v] <? numer[*u];
		}
}

main() {
	wczytaj();
	for(int i = 1; i <= n; ++i)
		if(numer[i] == 0)
			dwuspojne_skladowe(i, 0);
}

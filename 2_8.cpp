#include <iostream>
#include <vector>
#include <list>
#include <deque>
using namespace std;

const int n_max = 100000;

int n;
bool nowy[n_max];
vector<list<int> > graf;

inline void wczytaj() {
	int a, b, m;
	cin >> n >> m;
	graf.resize(n + 1);
	while(m--) {
		cin >> a >> b;
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	for(int i = 0; i <= n; ++i)
		nowy[i] = true;
}

deque<int> q;

void przeszukaj(int v) {
	q.push_back(v);
	nowy[v] = false;
	while(!q.empty()) {
		v = q.front();
		q.pop_front();
		for(list<int>::const_iterator y = graf[v].begin();
			y != graf[v].end(); ++y)
			if(nowy[*y] == true) {
				q.push_back(*y);
				nowy[*y] = false;
			}
	}
	
}

main() {
	wczytaj();
	for(int i = 1; i <= n; ++i)
		if(nowy[i]) {
			q.push_back(i);
			przeszukaj(i);
		}
}

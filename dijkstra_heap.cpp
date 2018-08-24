#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>
#include <list>
using namespace std;

class krawedz {
public:
	int w, koszt;
	krawedz(int ww, int kk) {
		w = ww;
		koszt = kk;
	}
	bool operator < (const krawedz& K) const {
		koszt > K.koszt;
	}
};

const int n_max = 1000000;

int n, droga[n_max];
vector<list<krawedz> > graf;

void wczytaj_graf() {
	int a, b, c, m;
	cin >> n >> m;
	assert(n <= n_max);
	graf.resize(n + 1);
	while(m--) {
		cin >> a >> b >> c;
		/* krawdz w postaci a->b o wadze c */
		graf[a].push_back(krawedz(b, c));
	}
}

const int infty = 1000000000;

void dijkstra(int v) {
	vector<krawedz> q;
	for(int i = 1; i <= n; ++i)
		droga[i] = infty; /* ustawiamy na nieskonczonosc */
	droga[1] = 0;
	q.push_back(krawedz(1, 0));
	while(!q.empty()) {
		int v = q[0].w;
		pop_heap(q.begin(), q.end());
		q.pop_back();
		for(list<krawedz>::iterator y = graf[v].begin();
			y != graf[v].end(); ++y)
			if(droga[y->w] > droga[v] + y->koszt) {
				droga[y->w] = droga[v] + y->koszt;
				q.push_back(krawedz(y->w, droga[y->w]));
				push_heap(q.begin(), q.end());
			}
	}
}

main() {
	wczytaj_graf();
	dijkstra(1); /* liczy odleglosc od wierzcholka 1 do kazdego innego */
	for(int i = 1; i <= n; ++i)
		cout << 1 << "->" << i << " koszt = " << droga[i] << endl;
}

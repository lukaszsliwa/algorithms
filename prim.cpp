#include <iostream>
#include <list>
#include <queue>
using namespace std;

const int n_max = 1000001;
const int infty = 10000000;

class k {
public:
	int v, waga;
	k(int vv, int ww) {
		v = vv;
		waga = ww;
	}
	bool operator < (const k& K) const {
		return waga > K.waga;
	}
};

bool jest[n_max];	/* okresla, czy dany wierzcholek jest w kolejce  */
priority_queue<k> q;
vector<list<k> > graf;

main() {
	int i, a, b, c, n, m, r, drzewo[n_max], waga[n_max];
	cin >> n >> m >> r;
	graf.resize(n + 1);
	for(i = 1; i <= n; ++i) {
		drzewo[i] = 0;
		jest[i] = true;
		waga[i] = infty;
	}
	while(m--) {
		cin >> a >> b >> c;
		graf[a].push_back(k(b, c));
		graf[b].push_back(k(a, c));
	}
	waga[r] = 0;
	q.push(k(r, 0));
	while(!q.empty()) {
		/* wyjmujemy wierzcholek o najmniejszej wadze */
		int v = q.top().v;
		q.pop();
		jest[v] = false;
		/* sprawdzamy wszystkich sasiadow v i jesli istnieje
		 * krawedz krotsza od aktualnej to podmieniamy wartosci
		 * i wrzucamy wierzcholek do kolejki */
		for(list<k>::iterator y = graf[v].begin();
			y != graf[v].end(); ++y)
			if(jest[y->v] == true &&
				y->waga < waga[y->v]) {
				drzewo[y->v] = v;
				waga[y->v] = y->waga;
				q.push(k(y->v, y->waga));
			}
	}
	for(i = 1; i <= n; ++i)
		cout << i << "->" << drzewo[i] << endl;
}

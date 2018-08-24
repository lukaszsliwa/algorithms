#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int M = 100;
const int infty = 10000000;

int d[M];
bool jQ[M];

struct k {
	int wierzcholek, waga;
	k(int kk, int ww) {
		wierzcholek = kk;
		waga = ww;
	}
	bool operator < (const k& A) const {
		return waga > A.waga;
	}
};

vector<k>graf[M];
priority_queue<k>Q;

void relax(int wierzcholek, int suma) {
	if(d[wierzcholek] >= suma && jQ[wierzcholek]) {
		d[wierzcholek] = suma;
		Q.push(k(wierzcholek, suma));
	}	
}

int main() {
	int n, m, waga, a, b, s, u;
	scanf("%d", &n);
	m = n;
	while(m--) {
		scanf("%d%d%d", &a, &b, &waga);
		graf[a].push_back(k(b, waga));
		jQ[m] = false;
	}
	scanf("%d", &s);
	Q.push(k(s, 0));
	m = n;
	while(--m)
		if(m != s) {
			Q.push(k(m, infty));
			d[m] = infty;
			jQ[m] = true;
		}
	d[s] = 0;
	jQ[s] = true;
	while(!Q.empty()) {
		u = Q.top().wierzcholek;
		waga = Q.top().waga;
		Q.pop();
		jQ[u] = false;
		for(int v = 0; v < graf[u].size() && waga != infty; ++v)
			relax(graf[u][v].wierzcholek, waga + graf[u][v].waga);
	}
	while(--n)
		printf("%d -> %d [%d]\n", s, n, d[n]);
	return 0;
}

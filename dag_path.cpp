#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

const int M = 1000;
const int infty = 10000000;

int tab[M], queue[M], top[M], d[M], t, q;

vector<int>graf[M];
vector<int>wagi[M];

int main() {
	int m, n, i, a, b, waga, u, v;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= n; ++i) {
		scanf("%d%d%d", &a, &b, &waga);
		graf[a].push_back(b);
		tab[b]++;
		wagi[a].push_back(waga);
		d[i] = infty;
	}
	for(i = 1; i <= m; ++i)
		if(!tab[i])
			queue[q++] = i;
	while(q--) {
		u = queue[q];
		for(int v = 0; v < graf[u].size(); ++v)
			if(--tab[graf[u][v]] == 0)
				queue[q++] = graf[u][v];
		top[t++] = u;
	}
	i = 0;
	d[top[0]] = 0;
	while(i < t) {
		u = top[i++];
		for(int v = 0; v < graf[u].size(); ++v)
			d[graf[u][v]] = min(d[graf[u][v]], d[u] + wagi[u][v]);
	}
	while(--n)
		printf("%d -> %d [%d]\n", top[0], n, d[n]);
	return 0;
}

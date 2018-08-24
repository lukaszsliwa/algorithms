#include <cstdio>
#include <vector>

using namespace std;

const int M = 1000;

int queue[M], tab[M], d[M], q;

vector<int>graf[M];

int main() {
	int n, i, a, b, suma, u, v;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
	}
	/* sortowanie topologiczne */
	for(i = 1; i <= n; ++i)
		if(tab[i] == 0)
			queue[q++] = i;
	while(q--) {
		u = queue[q];
		for(v = 0; v < graf[u].size(); ++v) {
			if(--tab[graf[u][v]] == 0)
				queue[q++] = graf[u][v];
			d[graf[u][v]] += d[u] + 1;
		}
		tab[u] = -1;
	}
	while(--n)
		suma += d[n];
	printf("%d\n", suma);
	return 0;
}

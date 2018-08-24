#include <cstdio>
#include <vector>

using namespace std;

const int M = 1000;

int d[M], pi[M], tab[M], queue[M], q;

vector<int>graf[M];
vector<int>wagi[M];

bool cykle(int n) {
	for(int i = 1; i <= n; ++i)
		if(tab[i] != -1)
			return true;
	return false;
}

int main() {
	int n, i, a, b, waga, u, v, last;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		scanf("%d%d%d", &a, &b, &waga);
		graf[a].push_back(b);
		wagi[a].push_back(waga);
		tab[b]++;
	}
	for(i = 1; i <= n; ++i) {
		if(tab[i] == 0)
			queue[q++] = i;
		d[i] = 0;
		pi[i] = -1;
	}
	while(q--) {
		u = queue[q];
		for(v = 0; v < graf[u].size(); ++v) {
			if(--tab[graf[u][v]] == 0)
				queue[q++] = graf[u][v];
			if(d[graf[u][v]] < d[u] + wagi[u][v]) {
				d[graf[u][v]] = d[u] + wagi[u][v];
				pi[graf[u][v]] = u;
			}
		}
		tab[u] = -1;
		last = u;
	}
	if(cykle(n)) {
		printf("Graf zawiera cykle.");
		return 0;
	}
	printf("[%d]\n", d[last]);
	while(last != -1) {
		printf("%d ", last);
		last = pi[last];
	}
	printf("\n");
	return 0;
}

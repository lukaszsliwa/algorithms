#include <cstdio>
#include <vector>

using namespace std;

const int N_MAX = 10000;
const int infty = 1000000;
int n, time_s = 1;
int low[N_MAX], d[N_MAX];

vector< vector<int> > graf;

void low_dfs(int v, int f) {
	d[v] = time_s++;
	low[v] = d[v];
	for(vector<int>::const_iterator y = graf[v].begin();
			y != graf[v].end(); ++y) {
		if(*y != f) {
			if(d[*y] == 0)
				low_dfs(*y, v);
			low[v] = min(low[v], low[*y]);
		}
	}
	if(low[v] == d[v])
		printf("%d %d\n", f, v);
}

int main() {
	int m, i, a, b;
	scanf("%d%d", &n, &m);
	graf.resize(n + 1);
	while(m--) {
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	for(i = 0; i <= n; ++i) {
		d[i] = 0;
		low[i] = infty;
	}
	printf("\n");
	for(i = 1; i <= n; ++i)
		if(d[i] == 0)
			low_dfs(i, -1);
	return 0;
}

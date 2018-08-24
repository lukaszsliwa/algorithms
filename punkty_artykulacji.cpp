#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

vector< vector<int> > graf;

const int N_MAX = 10000;
const int infty = 1000000;

int n, time_s = 1, low[N_MAX], d[N_MAX], p[N_MAX];
bool jest[N_MAX];

void dfs(int v, int f) {
	bool status = false;
	d[v] = time_s++;
	p[v] = f;
	low[v] = d[v];
	jest[v] = true;
	for(vector<int>::const_iterator y = graf[v].begin();
			y != graf[v].end(); ++y) {
		if(*y != f) {
			if(!jest[*y])
				dfs(*y, v);
			low[v] = min(low[v], low[*y]);
			if(low[*y] >= d[v])
				status = true;
		}
	}
	if(status)
		printf("%d ", v);
}

int main() {
	int i, m, a, b;
	bool status = false;
	scanf("%d%d", &n, &m);
	graf.resize(n + 1);
	while(m--) {
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	for(i = 0; i <= n; ++i) {
		jest[i] = false;
		d[i] = low[i] = infty;
	}
	for(i = 1; i <= n; ++i)
		if(!jest[i])
			dfs(i, -1);
	printf("\n");
	for(i = 1; i <= n; ++i)
		printf("low[%d] = %d d[%d] = %d\n", i, low[i], i, d[i]);
	return 0;
}

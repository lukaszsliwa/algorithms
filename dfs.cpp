#include <cstdio>
#include <vector>

using namespace std;

const int M = 100;

int t[M], d[M], f[M], timeout = 1;
vector<int>graf[M];

void dfs(int u) {
	t[u] = true;
	d[u] = timeout++;
	for(int v = 0; v < graf[u].size(); ++v)
		if(t[graf[u][v]] == false)
			dfs(graf[u][v]);
	f[u] = timeout++;
	printf("%d ", u);
}

int main() {
	int n, m, w, liczba, i;
	scanf("%d", &n);
	for(i = 1; i <= n; ++i) {
		t[i] = false;
		scanf("%d", &m);
		while(m--) {
			scanf("%d", &w);
			graf[i].push_back(w);
		}
	}
	for(i = 1; i <= n; ++i)
		if(t[i] == false)
			dfs(i);
	
	return 0;
}

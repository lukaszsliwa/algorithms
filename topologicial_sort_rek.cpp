#include <cstdio>
#include <vector>

using namespace std;

const int M = 100;

bool num[M];

vector<int>graf[M];

void DFS(int v) {
	num[v] = true;
	for(int u = 0; u < graf[v].size(); ++u)
		if(!num[graf[v][u]])
			DFS(graf[v][u]);
	printf("%d ", v);
}

int main() {
	int n, m, i, w;
	scanf("%d", &n);
	for(i = 1; i <=n; ++i) {
		num[i] = false;
		scanf("%d", &m);
		while(m--) {
			scanf("%d", &w);
			graf[i].push_back(w);
		}
	}
	for(i = 1; i <= n; ++i)
		if(!num[i])
			DFS(i);
	printf("\n");
	return 0;
}

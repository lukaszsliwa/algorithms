#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

const int M = 100;

int t[M];
vector<int>graf[M];
stack<int>S;

int main() {
	int n, m, i, w;
	scanf("%d", &n);
	for(i = 1; i <= n; ++i) {
		scanf("%d", &m);
		while(m--) {
			scanf("%d", &w);
			graf[i].push_back(w);
		}
	}
	for(i = 1; i <= n; ++i)
		S.push(i);
	while(!S.empty()) {
		u = S.top();
		t[u] = true;
		S.pop();
		for(int v = 0; v < graf[u].size(); ++v)
			if(t[graf[u][v]] == false) {
				t[graf[u][v]] = true;
				S.push(graf[u][v]);
			}
	}
	return 0;
}

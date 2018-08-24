#include <cstdio>
#include <vector>

using namespace std;

int n, m, time_s = 1;
int *f, *tmp;
bool *jest;

vector< vector<int> > graf, graf_p;

void wczytaj() {
	int a, b;
	scanf("%d%d", &n, &m);
	graf.resize(n + 1);
	graf_p.resize(n + 1);
	f = new int[n + 1];
	tmp = new int[n + 1];
	jest = new bool[n + 1];
	while(m--) {
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf_p[b].push_back(a);
	}	
}

void DFS(int v) {
	jest[v] = true;
	for(int y = 0; y < graf[v].size(); ++y)
		if(jest[graf[v][y]] == false)
			DFS(graf[v][y]);
	f[v] = time_s++;
}

void DFS2(int v) {
	jest[v] = true;
	printf("%d ", v);
	for(int y = 0; y < graf_p[v].size(); ++y)
		if(jest[graf_p[v][y]] == false) {
			//printf("%d ", graf_p[v][y]);
			DFS2(graf_p[v][y]);
		}
}

int main() {
	int i;
	wczytaj();
	for(i = 1; i <= n; ++i)
		if(jest[i] == false)
			DFS(i);
	for(i = 1; i <= n; ++i) {
		jest[i] = false;
		tmp[f[i]] = i;
	}
	jest[n] = false;
	for(i = n; i >= 1; --i)
		if(jest[tmp[i]] == false) {
			printf("\n");
			DFS2(tmp[i]);
		}
	return 0;
}

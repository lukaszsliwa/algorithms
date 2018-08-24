#include <cstdio>
#include <vector>

using namespace std;

const int infty = 100000000;

int n, m, time_i = 1;
int *low, *d, *p;
bool *byl;

vector< vector<int> > graf;

void dfs(int v, int father) {
	p[v] = father;
	d[v] = time_i++;
	byl[v] = true;
	low[v] = d[v];
	for(vector<int>::iterator y = graf[v].begin(); 
			y < graf[v].end(); ++y)
		if(*y != father) {
			if(byl[*y] == false)
				dfs(*y, v);
			low[v] = min(low[v], low[*y]);
		}
}

int main() {
	int a, b, i;
	scanf("%d%d", &n, &m);
	low = new int[n + 1];
	d = new int[n + 1];
	p = new int[n + 1];
	byl = new bool[n + 1];
	graf.resize(n + 1);
	while(m--) {
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		//graf[b].push_back(a);
	}
	for(i = 0; i <= n; ++i) {
		low[i] = d[i] = infty;
		byl[i] = false;
	}
	for(i = 1; i <= n; ++i)
		if(byl[i] == false)
			dfs(i, -1);
	for(i = 1; i <= n; ++i)
		printf("nr[%d] = %d  low[%d] = %d\n", i, d[i], i, low[i]);
	return 0;
}

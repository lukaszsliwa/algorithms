#include <cstdio>
#include <vector>

using namespace std;

int n, m, id, numer = 0, *c, *nr;
bool *jest;
vector< vector<int> > graf;

typedef vector<int>::const_iterator vec_citer;

void sss_search(int v) {
	jest[v] = true;
	c[v] = id;
	nr[v] = numer++;
	for(vec_citer i = graf[v].begin(); i < graf[v].end(); ++i)
		if(!jest[*i])
			sss_search(*i);
}

main() {
	int m, a, b, i;
	scanf("%d%d", &n, &m);
	graf.resize(n + 1);
	jest = new bool[n + 1];
	c = new int[n + 1];
	nr = new int[n + 1];
	while(m--) {
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	for(i = 1; i <= n; ++i)
		if(!jest[i]) {
			id = i;
			sss_search(i);
		}
	for(i = 1; i <= n; ++i)
		printf("c[%d] = %d, nr[%d] = %d\n", i, c[i], i, nr[i]);
}

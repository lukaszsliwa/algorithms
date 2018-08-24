#include <cstdio>
#include <vector>

using namespace std;

const int M = 1000;
const int infty = 100000000;

int tab[M], queue[M], q;

vector<int>graf[M];

bool cykle(int n) {
	for(int i = 0; i < n; ++i)
		if(tab[i] > 0)
			return true;
	return false;
}

int main() {
	int n, a, b, i, u, v;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		tab[b]++;
	}
	for(i = 1; i <= n; ++i)
		if(!tab[i])
			queue[q++] = i;
	while(q--) {
		u = queue[q];
		for(v = 0; v < graf[u].size(); ++v)
			if(--tab[graf[u][v]] == 0)
				queue[q++] = graf[u][v];
		tab[u] = -1;
		printf("%d ", u);
	}
	printf( cykle(n) ? "Graf posiada cykle.\n" : "Graf nie ma cykli.\n");
	return 0;
}

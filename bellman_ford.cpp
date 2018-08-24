#include <cstdio>
#include <vector>

using namespace std;

const int M = 100;
const int infty = 100000000;

int d[M];

vector<int>graf[M];
vector<int>wagi[M];

void relax(int a, int b, int w) {
	if(d[b] >= d[a] + w)
		d[b] = d[a] + w;
}

int main() {
	int a, b, n, source, waga, i, y;
	scanf("%d%d", &n, &source);
	for(i = 1; i <= n; ++i) {
		scanf("%d%d%d", &a, &b, &waga);
		graf[a].push_back(b);
		wagi[a].push_back(waga);
		d[i] = infty;
	}
	d[source] = 0;
	for(i = 1; i <= n; ++i)
		for(y = 0; y < graf[i].size(); ++y)
			relax(i, graf[i][y], wagi[i][y]);
	while(--n)
		printf("%d -> %d [%d]\n", source, n, d[n]);
	return 0;
}

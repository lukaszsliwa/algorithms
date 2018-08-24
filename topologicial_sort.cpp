#include <cstdio>
#include <vector>

using namespace std;

const int M = 100;

int n, stopien[M], zero[M], q;

vector<int>graf[M];

int main() {
	int m, i, wierzcholek;
	scanf("%d", &n);
	for(i = 1; i <= n; ++i) {
		scanf("%d", &m);
		while(m--) {
			scanf("%d", &wierzcholek);
			stopien[wierzcholek]++;
			graf[i].push_back(wierzcholek);
		}
	}
	for(i = 1; i <= n; ++i)
		if(stopien[i] == 0)
			zero[q++] = i;
	while(q--) {
		wierzcholek = zero[q];
		stopien[wierzcholek]--;
		printf("%d ", wierzcholek);
		while(!graf[wierzcholek].empty()) {
			if(--stopien[graf[wierzcholek].back()] == 0)
				zero[q++] = graf[wierzcholek].back();
			graf[wierzcholek].pop_back();
		}
	}	
	printf("\n");
	return 0;
}

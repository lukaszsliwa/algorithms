#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int M = 100;

bool t[M];
int d[M], pi[M];

vector<int>graf[M];
queue<int>Q;

void drukuj(int a, int b) {
	if(a == b)
		printf("%d ", a);
	else if(pi[b] == 0)
		printf("Sciezka nie istnieje.\n");
	else {
		drukuj(a, pi[b]);
		printf("%d ", b);
	}
}

void drukuj_iter(int a, int b) {
	while(a != b && b != 0) {
		printf("%d ", b);
		b = pi[b];
	}
	if(b == 0)
		printf("Sciezka nie istnieje.");
	else
		printf("%d\n", a);
}

int main () {
	int n, m, w, i, s, u, v;
	scanf("%d", &n);
	for(i = 1; i <= n; ++i) {
		t[i] = false;
		scanf("%d", &m);
		while(m--) {
			scanf("%d", &w);
			graf[i].push_back(w);
		}
	}
	scanf("%d", &s);
	Q.push(s);
	t[s] = true;
	while(!Q.empty()) {
		u = Q.front();
		for(v = 0; v < graf[u].size(); ++v)
			if(t[graf[u][v]] == false) {
				t[graf[u][v]] = true;
				d[graf[u][v]] = d[u] + 1;
				pi[graf[u][v]] = u;
				Q.push(graf[u][v]);
			}
		Q.pop();
	}
	scanf("%d", &v);
	drukuj(s, v);
	printf("\n");
	drukuj_iter(s, v);
	return 0;
}

#include <cstdio>
#include <vector>
#include <queue>
#include <list>
using namespace std;

const int n_max = 100001;

int n, m, droga[n_max], sciezka[n_max];
bool jest[n_max];

vector<list<int> > graf, odwr;

void wczytaj() {
	int a, b;
	scanf("%d%d", &n, &m);
	graf.resize(n + 1);
	odwr.resize(n + 1);
	while(m--) {
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		odwr[b].push_back(a);
	}
}

void bfs(int v) {
	queue<int> q;
	for(int i = 1; i <= n; ++i) {
		jest[i] = false;
		droga[i] = 0;
	}
	jest[v] = true;
	droga[v] = 0;
	sciezka[v] = -1;
	q.push(v);
	while(!q.empty()) {
		v = q.front();
		q.pop();
		for(list<int>::iterator y = graf[v].begin();
			y != graf[v].end(); ++y)
			if(jest[*y] == false) {
				jest[*y] = true;
				droga[*y] = droga[v] + 1;
				sciezka[*y] = v;
				q.push(*y);
			}
	}
	for(int i = 0; i <= n; ++i)
		jest[i] = false;
}

void serwer(int v) {
	queue<int> q;
	q.push(v);
	jest[v] = true;
	while(!q.empty()) {
		v = q.front();
		q.pop();
		for(list<int>::iterator y = odwr[v].begin();
			y != odwr[v].end(); ++y)
			if(droga[*y] + 1 == droga[v] && 
					jest[*y] == false) {
				jest[*y] = true;
				q.push(*y);
			}
	}
}

#define text(X) printf("%s\n", X)

main() {
	wczytaj();
	bfs(1);
	for(int v = n; v != -1; v = sciezka[v])
		if(jest[v] == false) serwer(v);
	int wynik = 0;
	for(int i = 2; i < n; ++i)
		if(jest[i] == true) wynik++;
	printf("%d", wynik);
	for(int i = 2; i < n; ++i)
		if(jest[i] == true)
			printf(" %d", i);
	printf("\n");
}

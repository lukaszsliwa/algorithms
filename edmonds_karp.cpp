#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

const int n_max = 100;

int n, c[n_max][n_max];
vector<list<int> > graf;

typedef list<int>::iterator list_iter;

void wczytaj() {
	int m, a, b, p;
	cin >> n >> m;
	graf.resize(n + 1);
	while(m--) {
		cin >> a >> b >> p;
		graf[a].push_back(b);
		c[a][b] = p;
	}
}

bool sciezka_p(int t[]) {
	int v;
	bool jest[n_max], przeplyw[n_max];
	queue<int> q;
	for(int i = 0; i <= n; ++i)
		t[i] = jest[i] = 0;
	q.push(1);
	t[1] = -1;
	jest[1] = true;
	while(!q.empty()) {
		v = q.front();
		q.pop();
		for(list_iter y = graf[v].begin();
			y != graf[v].end(); ++y)
			if(c[v][*y] != 0 && jest[*y] == false) {
				jest[*y] = true;
				t[*y] = v;
				q.push(*y);
			}
	}
	return t[n] != 0;
}

int find_min_c(int t[], int m) {
	int r = c[t[m]][m];
	while(t[m] != -1) {
		r <?= c[t[m]][m];
		m = t[m];
	}
	return r;
}

int edmonds_karp() {
	int max_f = 0, pi[n_max];
	while(sciezka_p(pi)) {
		int v = n, min_c = find_min_c(pi, n);
		while(pi[v] != -1) {
			cout << v << ' ';
			c[pi[v]][v] -= min_c;
			v = pi[v];
		}
		cout << 1 << '[' << min_c << ']' << endl;
		max_f += min_c;
	}
	return max_f;
}

main() {
	wczytaj();
	cout << edmonds_karp() << endl;
}

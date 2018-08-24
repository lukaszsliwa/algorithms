#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int n_max = 101;
const int infty = 1000000000;

int n, c[n_max][n_max], koszty[n_max][n_max], pot[n_max];

struct k {
	int w, koszt;
	k(int ww, int kk) : w(ww), koszt(kk) {}
	bool operator < (const k& K) const {
		return koszt > K.koszt;
	}
};

vector<vector<int> > graf;

void wczytaj() {
	int a, b, p, d, m;
	cin >> n >> m;
	graf.resize(n + 1);
	while(m--) {
		cin >> a >> b >> p >> d;
		/* a->b, koszt: p, przepustowosc: d */
		graf[a].push_back(b);
		koszty[a][b] = p;
		c[a][b] = d;
	}
}

void push(vector<k>& r, const k& e) {
	r.push_back(e);
	push_heap(r.begin(), r.end());
}

int pop(vector<k>& r) {
	int t = r[0].w;
	pop_heap(r.begin(), r.end());
	r.pop_back();
	return t;
}

bool path(int s, int p[]) {
	vector<k> q;
	int d[n];
	for(int i = 0; i <= n; ++i) {
		d[i] = infty;
		p[i] = -1;
	}
	d[s] = 0;
	push(q, k(s, 0));
	while(!q.empty()) {
		int u = pop(q);
		for(vector<int>::iterator y = graf[u].begin();
			y != graf[u].end(); ++y)
			if(c[u][*y] != 0 && d[*y] > d[u] + pot[u] - pot[*y] - koszty[u][*y]) {
				d[*y] = d[u] + koszty[u][*y];
				p[*y] = u;
				push(q, k(*y, d[*y]));
			}
	}
	int v = n, cp = infty;
	for(int i = 1; i <= n; ++i)
		if(pot[i] < infty)
			pot[i] += d[i];
	while(p[v] != -1) {
		cp = min(cp, c[p[v]][v]);
		v = p[v];
	}
	return d[n] != infty ? cp : 0;
}

int min_cost_max_flow(int s, int t) {
	int sum = 0, flow = 0, m, pi[n_max];
	while((m = path(s, pi))) {
		int v = n;
		while(pi[v] != -1) {
			cout << pi[v] << ' ';
			c[pi[v]][v] -= m;
			sum += (m * koszty[pi[v]][v]);
			v = pi[v];
		}
		cout << '[' << m << ']' << endl;
		flow += m;
	}
	return sum;
}

main() {
	wczytaj();
	printf("%d\n", min_cost_max_flow(1, n));
}

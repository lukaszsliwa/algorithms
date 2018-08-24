#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int M = 100;

int p[M], rank[M];

struct k {
	int a, b, waga;
	k(int aa, int bb, int ww) {
		a = aa;
		b = bb;
		waga = ww;
	}
};

vector<k>krawedzie;

void make_set(int e) {
	if(p[e] != e) {
		p[e] = e;
		rank[e] = 0;
	}
}

int find_set(int e) {
	int t, q = e;
	while(e != p[e])
		e = p[e];
	t = p[e];
	e = q;
	while(e != p[e]) {
		e = p[e];
		p[e] = t;
	}
	return t;
}

void union_(int a, int b) {
	if(rank[a] > rank[b])
		p[b] = a;
	else {
		p[a] = b;
		if(rank[a] == rank[b])
			rank[b] ++;
	}
}

bool compare(const k A, const k B) {
	return A.waga > B.waga;
}

int main() {
	int n, a, b, waga, suma = 0;
	scanf("%d", &n);
	while(n--) {
		scanf("%d%d%d", &a, &b, &waga);
		krawedzie.push_back(k(a, b, waga));
		make_set(a);
		make_set(b);
	}
	sort(krawedzie.begin(), krawedzie.end(), compare);
	while(!krawedzie.empty()) {
		a = krawedzie.back().a;
		b = krawedzie.back().b;
		waga = krawedzie.back().waga;
		if(find_set(a) != find_set(b)) {
			suma += waga;
			union_(find_set(a),find_set(b));
		}
		krawedzie.pop_back();
	}
	printf("%d\n", suma);
	return 0;
}

#include <cstdio>

using namespace std;

const int M = 100;

int n, p[M], rank[M];

void make_set(int e) {
	p[e] = e;
	rank[e] = 0;
}

int find_set(int a) {
	if(a != p[a])
		p[a] = find_set(p[a]);
	return p[a];
}

int find_set_iter(int a) {
	int t, q;
	q = a;
	while(a != p[a]) 
		a = p[a];
	t = p[a];
	a = q;
	while(a != p[a]) {
		a = p[a];
		p[a] = t;
	}
	return t;
}

void link(int a, int b) {
	if(rank[a] > rank[b])
		p[b] = a;
	else {
		p[a] = b;
		if(rank[a] == rank[b])
			rank[b]++;
	}
}

void union_(int a, int b) {
	link(find_set(a), find_set(b));
}

int main() {
	int a, b;
	scanf("%d", &n);
	while(n--) {
		scanf("%d%d", &a, &b);
		if(p[a] != a)
			make_set(a);
		if(p[b] != b)
			make_set(b);
		union_(a, b);
	}
	return 0;
}

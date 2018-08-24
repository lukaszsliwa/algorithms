#include <cstdio>

using namespace std;

int n, q, p, liczba;
int *tab, *next, *prev;

void Insert(int e) {
	tab[q] = e;
	if(p != -1) {
		next[q] = p;
		prev[p] = q;
	}
	p = q++;
}

int Search(int e) {
	int y = p;
	while(y != -1 && tab[y] != e)
		y = next[y];
	return y;
}

void Delete(int i) {
	int nxt, prv;
	nxt = next[i];
	prv = prev[i];
	if(nxt != -1)
		prev[nxt] = prv;
	if(prv != -1)
		next[prv] = nxt;
}

int main() {
	int i, y;
	scanf("%d", &n);
	tab = new int[n + 1];
	next = new int[n + 1];
	prev = new int[n + 1];
	p = -1;
	for(i = 0; i <= n; ++i)
		next[i] = prev[i] = -1;
	while(n--) {
		scanf("%d", &liczba);
		Insert(liczba);
	}
	y = p;
	while(y != -1) {
		printf("%d ", tab[y]);
		y = next[y];
	}
	return 0;
}

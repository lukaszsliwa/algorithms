#include <cstdio>

using namespace std;

int n, q, *tab, *bit, *wsk;

void Insert(int k, int i) {
	wsk[i] = bit[k];
	bit[k] = i;
}

void Delete(int i) {
	int t = bit[tab[i]];
	bit[tab[i]] = wsk[i];
	wsk[i] = t;
}

int Search(int e) {
	return bit[e];
}

int main() {
	int i, x;
	scanf("%d", &n);
	tab = new int[n + 1];
	bit = new int[n + 1];
	wsk = new int[n + 1];
	for(i = 0; i <= n; ++i)
		tab[i] = bit[i] = wsk[i] = -1;
	i = 0;
	while(n--) {
		scanf("%d", &tab[i++]);
		Insert(tab[i - 1], i - 1);
	}
	scanf("%d", &x);
	x = Search(x);
	if(x > 0) {
		printf("Jest na pozycji %d\n", x);
		Delete(x);
	}
	delete []tab;
	delete []bit;
	delete []wsk;
	return 0;
}

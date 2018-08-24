#include <cstdio>

using namespace std;

int n, root;
int *tab, *left, *right, *parent;

void Insert(int i) {
	int x, y;
	x = root;
	y = -1;
	while(x != -1) {
		y = x;
		if(tab[i] < tab[x])
			x = left[x];
		else
			x = right[x];
	}
	parent[i] = y;
	if(y == -1)
		root = i;
	else if(tab[i] < tab[y])
		left[y] = i;
	else
		right[y] = i;
}

int Minimal(int i) {
	while(left[i] != -1)
		i = left[i];
	return i;
}

int Successor(int i) {
	int x, y;
	if(left[i] != -1)
		return Minimal(right[i]);
	y = parent[i];
	x = right[y];
	while(y != -1 && x == right[y]) {
		x = y;
		y = parent[i];
	}
	return y;
}

void Delete(int i) {
	int x, y;
	if(left[i] == -1 && right[i] == -1)
		tab[i] < tab[parent[i]] ? left[parent[i]] = -1 : right[parent[i]] = -1;
	else if(left[i] == -1 || right[i] == -1) {
		left[i] != -1 ? x = left[i] : x = right[i];
		tab[i] < tab[parent[i]] ? left[parent[i]] = x : right[parent[i]] = x;	
	} else {
		y = Successor(i);
		tab[y] < tab[parent[y]] ? left[parent[y]] = right[y] : right[parent[y]] = right[y];
		tab[i] = tab[y];
	}
}

void Show(int i) {
	if(i != -1) {
		Show(left[i]);
		printf("%d ", tab[i]);
		Show(right[i]);
	}
}

int main() {
	int i;
	scanf("%d", &n);
	tab = new int[n + 1];
	left = new int[n + 1];
	right = new int[n + 1];
	parent = new int[n + 1];
	root = -1;
	for(i = 0; i <= n; ++i)
		tab[i] = left[i] = right[i] = parent[i] = -1;
	for(i = 0; i < n; ++i) {
		scanf("%d", &tab[i]);
		Insert(i);
	}
	Show(root);
	scanf("%d", &i);
	Delete(i);
	Show(root);
	return 0;
}

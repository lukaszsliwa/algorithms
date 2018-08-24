#include <cstdio>

using namespace std;

int n;
int *tab, *left, *right, q, root;
int *parent;

void Insert(int i) {
	int y, x;
	y = -1;
	x = root;
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

void Inorder(int i) {
	if(i != -1) {
		Inorder(left[i]);
		printf("%d ", tab[i]);
		Inorder(right[i]);
	}
}

int Maximum(int i) {
	while(right[i] != -1)
		i = right[i];
	return i;
}

int Minimum(int i) {
	while(left[i] != -1)
		i = left[i];
	return i;
}

int Successor(int i) {
	int y;
	if(right[i] != -1)
		return Minimum(right[i]);
	y = parent[i];
	while(y != -1 && i == right[y]) {
		i = y;
		y = parent[y];
	}
	return y;
}

int main() {
	int i;
	scanf("%d", &n);
	tab = new int[n + 1];
	right = new int[n + 1];
	left = new int[n + 1];
	parent = new int[n + 1];
	root = -1;
	for(i = 0; i < n; ++i)
		left[i] = right[i] = tab[i] = -1;
	for(i = 0; i < n; ++i) {
		scanf("%d", &tab[q++]);
		Insert(q - 1);
	}
	Inorder(root);
	printf("\n%d\n%d\n", tab[Maximum(root)], tab[Minimum(root)]);
	delete []tab;
	delete []left;
	delete []right;
	return 0;
}

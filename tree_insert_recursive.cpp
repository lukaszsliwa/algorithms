#include <cstdio>

using namespace std;

int n, root;
int *tab, *left, *right, *parent;

void Insert(int i, int y, int x) {
	if(y != -1) {
		if(tab[i] < tab[y])
			Insert(i, left[y], y);
		else
			Insert(i, right[y], y);
	} else {
		if(root == -1)
			root = i;
		else if(tab[i] < tab[x])
			left[x] = i;
		else
			right[x] = i;
		parent[i] = x;
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
		Insert(i, root, -1);
	}
	Show(root);
	return 0;
}

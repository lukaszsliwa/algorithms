#include <cstdio>

using namespace std;

int n, root;
int *tab, *left, *right, *len;

void Insert(int i) {
	int x, y;
	y = -1;
	x = root;
	while(x != -1) {
		y = x;
		if(tab[i] == tab[y])
			x = -1;
		else if(tab[i] < tab[y])
			x = left[x];
		else
			x = right[x];
	}
	if(y == -1)
		root = i;
	else if(tab[i] == tab[y])
		len[y]++;
	else if(tab[i] < tab[y])
		left[y] = i;
	else
		right[y] = i;
}

void Inorder(int i) {
	if(i != -1) {
		Inorder(left[i]);
		while(len[i]--)
			printf("%d ", tab[i]);
		Inorder(right[i]);
	}
}

int main() {
	int i;
	scanf("%d", &n);
	tab = new int[n + 1];
	left = new int[n + 1];
	right = new int[n + 1];
	len = new int[n + 1];
	root = -1;
	for(i = 0; i < n; ++i) {
		tab[i] = left[i] = right[i] = -1;
		len[i] = 1;
	}
	for(i = 0; i < n; ++i) {
		scanf("%d", &tab[i]);
		Insert(i);
	}
	Inorder(root);
	return 0;
}

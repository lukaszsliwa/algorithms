#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;

vector<int> tab;

struct tree {
	int key;
	tree *right, *left;
	tree() { right = left = 0; }
	tree(int kk, tree *l = 0, tree *r = 0) {
		key = kk;
		left = l;
		right = r;
	}
} *root;

typedef vector<int>::const_iterator Iterator;

void wczytaj() {
	int m, l;
	scanf("%d", &n);
	m = n;
	while(m--) {
		scanf("%d", &l);
		tab.push_back(l);
	}
}

void Insert(int e) {
	tree *tmp = root, *rodzic;
	while(tmp != 0){
		rodzic = tmp;
		if(tmp->key < e)
			tmp = tmp->right;
		else
			tmp = tmp->left;
	}
	if(root == 0)
		root = new tree(e);
	else if(rodzic->key < e)
		rodzic->right = new tree(e);
	else
		rodzic->left = new tree(e);
}

void tree_balance(int x, int y) {
	if(x < y) {
		int mid = (x + y) / 2;
		Insert(tab[mid]);
		tree_balance(x, mid);
		tree_balance(mid + 1, y);
	}
}

void printAll(tree *t) {
	if(t != 0) {
		printAll(t->left);
		printf("%d ", t->key);
		printAll(t->right);
	}
}

int main() {
	wczytaj();
	sort(tab.begin(), tab.end());
	tree_balance(0, n);
	printAll(root);
	return 0;
}

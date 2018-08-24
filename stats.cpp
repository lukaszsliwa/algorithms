#include <cstdio>
#include <cmath>

using namespace std;

struct tree {
	int how;
	tree *left, *right, *parent;
	tree(int k = 0, tree *l = 0, tree *r = 0, tree *p = 0) {
		left = l;
		right = r;
		how = k;
		parent = p;
	}
} *root;

void Maketree(int h, int i, tree*& tmp) {
	if(i > 0) {
		tmp = new tree(h, 0, 0, tmp);
		Maketree(h/2, i - 1, tmp->left);
		Maketree(h/2, i - 1, tmp->right);
	}
}

void Inorder(tree *tmp) {
	if(tmp != 0) {
		Inorder(tmp->left);
		printf("%d ", tmp->how);
		Inorder(tmp->right);
	}
}

int Rank(tree *tmp) {
	int r = tmp->left->how + 1;
	while(tmp != root) {
		if(tmp == tmp->parent->right)
			r += tmp->parent->left->how + 1;
		tmp = tmp->parent;
	}
	return r;
}

tree* Select(tree *tmp, int i) {
	int r = tmp->left->how + 1;
	if(i == r)
		return tmp;
	else if(i > r)
		return Select(tmp->right, i - r);
	else 
		return Select(tmp->left, i);
}

int main() {
	int n;
	scanf("%d", &n);
	Maketree((int)pow((float)2.0, (float)n) - 1, n, root);
	Inorder(root);
	scanf("%d", &n);
	printf("%d\n", Select(n)->how);
	return 0;
}

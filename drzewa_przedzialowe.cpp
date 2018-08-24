#include <cstdio>
#include <cmath>

using namespace std;

struct tree {
	int a, b, max;
	tree *left, *right, *parent;
	tree(int ap = 0, int bp = 0, tree *p = 0) {
		parent = p;
		left = right = 0;
		a = ap;
		b = bp;
	}
} *root;

void Insert(int ap, int bp) {
	tree *syn = root, *ojciec = 0;
	while (syn != 0) {
		ojciec = syn;
		syn->max = max(syn->left, syn->right, bp);
		if(syn->left != 0 && syn->left->max >= ap)
			syn = syn->left;
		else
			syn = syn->right;
	}
	if(ojciec == 0)
		root = new tree();
	else if(ojciec->left->max >= ap)
		ojciec->left = new tree(ap, bp, ojciec);
	else
		ojciec->right = new tree(ap, bp, ojciec);
}

int main() {
	int n, a, b;
	scanf("%d", &n);
	//MakeTree(n, root);
	while(n--) {
		scanf("%d%d", &a, &b);
		Insert(a, b);
	}
	return 0;
}

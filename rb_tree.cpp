#include <cstdio>

using namespace std;

struct tree {
	int key;
	char kolor;
	tree *left, *right, *parent;
	tree(int k, char c = 'R', tree *l = 0, tree *r = 0, tree *p = 0) {
		left = l;
		right = r;
		key = k;
		kolor = c;
		parent = p;
	}
} *root;

tree* NormalInsert(int e) {
	tree *syn = root, *ojciec = 0, *y = 0;
	while(syn != 0) {
		ojciec = syn;
		if(e < syn->key)
			syn = syn->left;
		else
			syn - syn->right;
	}
	if(ojciec == 0) {
		root = new tree(e);
		y = root;
	} else if(e < ojciec->key) {
		ojciec->left = new tree(e, 'R', 0, 0, ojciec);
		y = ojciec->left;
	} else {
		ojciec->right = new tree(e, 'R', 0, 0, ojciec);
		y = ojciec->right;
	}
	return y;
}

void Insert(int e) {
	tree *x = NormalInsert(e);
	while(x != root && x->parent->color == 'R') {
		if(x->parent == x->parent->parent->left) {
			y = x->parent->parent->right;
			if(y->color == 'R') {
				x->parent->color = 'B';
				y->color = 'B';
				x->parent->parent->color = 'R';
				x = x->parent->parent;
			} else if(x == x->parent->right) {
				x = x->parent;
				LeftRotate(x);
				x->parent->color = 'B';
				x->parent->parent->color = 'R';
				RightRotate(x->parent->parent);
			}
		} else {
			y = x->parent->parent->left;
			if(y->color == 'R') {
				x->parent->color = 'B';
				y->color = 'B';
				x->parent->parent->color = 'R';
				x = x->parent->parent;
			} else if(x == x->parent->left) {
				x = x->parent;
				LeftRotate(x);
				x->parent->color = 'B';
				x->parent->parent->color = 'R';
				RightRotate(x->parent->parent);
			}
		}
	}
	root->color = 'B';
}

int main() {
	
}

#include <cstdio>

using namespace std;

struct tree {
	int key;
	bool color;
	tree *left, *right, *parent;
	tree(int k, bool c = true, tree *l = 0, tree *r = 0, tree *p = 0) {
		key = k;
		color = c;
		left = l;
		right = r;
		parent = p;
	}
} *root;

void LeftRotate(tree *tmp) {
	tree *parent = tmp->parent, *tmp2 = tmp->right;
	if(tmp2 != 0) {
		tmp->right = tmp2->left;
		tmp2->left = tmp;
		parent->right = tmp2;
	}
}

void RightRotate(tree *tmp) {
	
}

void Insert(int e) {
	tree *son = root, *father = 0;
	while(son != 0) {
		father = son;
		if(e < son->key)
			son = son->left;
		else
			son = son->right;
	}
	if(father == 0)
		root = new tree(e);
	else if(e < father->key)
		father->left = new tree(e);
	else
		father->right = new tree(e);
}

int main() {
	
	return 0;
}

#include <cstdio>

using namespace std;

struct tree {
	int key, how;
	tree *left, *right, *parent;
	tree(int k = 0, int h = 0, tree *l = 0, tree *r = 0, tree *p = 0) {
		key = k;
		how = h;
		left = l;
		right = r;
		parent = p;
	}
} *root;

tree* SelectIter(int i, tree *tmp) {
	int r = tmp->left->how + 1;
	while(i != r) {
		r = tmp->left->how + 1;
		if(i == r)
			return tmp;
		else if(i > r)
			tmp = tmp->right;
		else
			tmp = tmp->left;
	}
	return 0;
}

int main() {
	
	return 0;
}

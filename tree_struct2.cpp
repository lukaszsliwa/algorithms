#include <cstdio>

using namespace std;

struct tree {
	int key;
	tree *left, *right;
	tree() { left = right = 0; }
	tree(int kk, tree *l = 0, tree *r = 0) {
		key = kk;
		left = l;
		right = r;
	}
} *root;

void Insert(tree*& r, int e) {
	tree *tmp = r, *rodzic = 0;
	while(tmp != 0) {
		rodzic = tmp;
		if(tmp->key < e)
			tmp = tmp->right;
		else 
			tmp = tmp->left;
	}
	if(rodzic == 0)
		r = new tree(e);
	else if(rodzic->key < e)
		rodzic->right = new tree(e);
	else
		rodzic->left = new tree(e);
}

void removeLeaf(tree*&);

tree* findAndDelete(int e) {
	tree *r = root, *p = 0;
	while(r != 0) {
		if(r->key == e) 
			break;
		p = r;
		if(r->key < e)
			r = r->right;
		else
			r = r->left;
	}
	if(p == 0)
		removeLeaf(root);
	else if(p->left == r)
		removeLeaf(p->left);
	else if(p->right == r)
		removeLeaf(p->right);
	return 0;
}

void removeLeaf(tree*& r) {
	tree *tmp = r;
	if(r == 0)
		return ;
	if(r->right == 0)
		r = r->left;
	else if(r->left == 0)
		r = r->right;
	else {
		tmp = r->left;
		while(tmp->right != 0)
			tmp = tmp->right;
		tmp->right = r->right;

		tmp = r;
		r = r->left;		
	}
	delete tmp;
}

void printTree(tree *tmp) {
	if(tmp != 0) {
		printTree(tmp->left);
		printf("%d ", tmp->key);
		printTree(tmp->right);
	}
}

int main() {
	int n, l;
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &l);
		Insert(root, l);
	}
	printf("Drzewo: ");
	printTree(root);
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &l);
		findAndDelete(l);
	}
	printf("Drzewo: ");
	printTree(root);
	return 0;
}

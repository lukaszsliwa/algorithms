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

void Insert(int e) {
	tree *tmp = root, *rodzic;
	while(tmp != 0) {
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

void DeleteByCoping(tree*&);

tree* findIt(int e) {
	tree *tmp = root, *rodzic = 0;
	while(tmp != 0) {
		if(tmp->key == e)
			break;
		rodzic = tmp;
		if(tmp->key < e)
			tmp = tmp->right;
		else
			tmp = tmp->left;
	}
	if(tmp->key == e) {
		if(rodzic->left == tmp)
			DeleteByCoping(rodzic->left);	
		else 
			DeleteByCoping(rodzic->right);
	}
	return 0;
}

void DeleteByCoping(tree*& rodzic) {
	tree *poprzednik = 0, *tmp = rodzic;
	if(rodzic->left == 0)
		rodzic = rodzic->right;
	else if(rodzic->right == 0)
		rodzic = rodzic->left;
	else {
		tmp = rodzic->left;
		poprzednik = rodzic;
		while(tmp->right != 0) {
			poprzednik = tmp;
			tmp = tmp->right;
		}
		rodzic->key = tmp->key;
		if(poprzednik == rodzic)
			poprzednik->left = tmp->left;
		else
			poprzednik->right = tmp->left;
	}
	delete tmp;
}

void print(tree *r) {
	if(r != 0) {
		print(r->left);
		printf("%d ", r->key);
		print(r->right);
	}
}

int main() {
	int n, l;	
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &l);
		Insert(l);
	}
	print(root);
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &l);
		findIt(l);
	}
	print(root);
	return 0;
}

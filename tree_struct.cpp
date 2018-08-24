#include <cstdio>

using namespace std;

int n;

struct tree {
	int key;
	tree *left, *right, *parent;
	tree(int k = 0, tree *l = 0, tree *r = 0, tree *p = 0) {
		key = k;
		left = l;
		right = r;
		parent = p;		
	}
} *root;

void Insert(int e) {
	tree *tmp = root, *father = 0;
	while(tmp != 0) {
		father = tmp;
		if(e < tmp->key)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}
	if(father == 0)
		root = new tree(e);
	else if(e < father->key)
		father->left = new tree(e, 0, 0, father);
	else
		father->right = new tree(e, 0, 0, father);
}

void Inorder(tree *tmp) {
	if(tmp != 0) {
		Inorder(tmp->left);
		printf("%d ", tmp->key);
		Inorder(tmp->right);
	}
}

tree* Minimum(tree *tmp) {
	while(tmp->left != 0)
		tmp = tmp->left;
	return tmp;
}

tree* Maximum(tree *tmp) {
	while(tmp->right != 0) 
		tmp = tmp->right;
	return tmp;
}

tree* Successor(tree *tmp) {
	tree *father = tmp->parent;
	if(tmp->right != 0)
		return Minimum(tmp->right);
	while(tmp != 0 && tmp == father->right) {
		tmp = tmp->parent;
		father = tmp->parent;
	}
	return father;
}

tree* Search(int e) {
	tree *tmp = root;
	while(tmp != 0 && tmp->key != e) {
		if(e < tmp->key)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}
	return tmp;
}

void Delete(tree *tmp) {
	tree *parent = tmp->parent, *successor = 0;
	if(tmp->left == 0 && tmp->right == 0) {
		tmp->key < parent->key ? parent->left = 0 : parent->right = 0;
		delete tmp;
	} else if(tmp->left == 0 || tmp->right == 0) {
		if(tmp->left == 0) {
			tmp->key < parent->key ? parent->left = tmp->right : parent->right = tmp->right;
		} else {
			tmp->key < parent->key ? parent->left = tmp->left : parent->right = tmp->left;
		}
	} else {
		successor = Successor(tmp);
		tmp->key = successor->key;
		parent = successor->parent;
		tmp->key < parent->key ? parent->left = tmp->right : parent->right = tmp->right;
	}
}

int main() {
	int i, liczba;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		scanf("%d", &liczba);
		Insert(liczba);
	}
	Inorder(root);
	return 0;
}

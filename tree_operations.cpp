#include <cstdio>
#include <queue>

using namespace std;

struct tree {
	int key;
	tree *left, *right, *prev;
	tree() {
       		prev = left = right = 0;
	}
	tree(int kk, tree *l = 0, tree *r = 0, tree *p = 0) {
		key = kk;
		left = l;
		right = r;
	}
} *t;

void Insert(int e) {
	tree *rodzic = t, *syn = 0;
	while(rodzic != 0) {
		syn = rodzic;
		if(rodzic->key < e)
			rodzic = rodzic->right;
		else 
			rodzic = rodzic->left;
	}
	if(syn == 0)
		t = new tree(e);
	else if(syn->key < e)
		syn->right = new tree(e, 0, 0, syn);
	else
		syn->left = new tree(e, 0, 0, syn);
}

tree* Search(int e) {
	tree *rodzic = t;
	while(rodzic != 0) {
		if(rodzic->key == e)
			return &rodzic;
		else if(rodzic->key < e)
			rodzic = rodzic->right;
		else
			rodzic = rodzic->left;
	}
	return 0;
}

void BFS() {
	queue<tree> Q;
	tree *rodzic = t, *tmp = 0;
	if(rodzic != 0)
		Q.push(rodzic);
	while(Q.empty() == false) {
		tmp = Q.front();
		printf("%d ", tmp->key);
		if(tmp->right != 0)
			Q.push(tmp->right);
		if(tmp->left != 0)
			Q.push(tmp->left);
		Q.pop();
	}
}

void DFS(tree *tmp) {
	if(tmp != 0) {
		DFS(tmp->left);
		printf("%d ", tmp->key);
		DFS(tmp->right);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	while(n--) {

	}
	return 0;
}

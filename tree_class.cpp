#include <iostream>

template <class T>
class binary_tree {

	class tree_c {
	public:
		tree_c(T e) : left(0), right(0), key(e) {}
		T key;
		tree_c *left, *right;
	} *root;

public:
	binary_tree() : root(0) {}
	void insert(const T& e) {
		if(root == 0)
			root = new tree_c(e);
		else {
			tree_c *tmp = root, *l = 0;
			while(tmp != 0) {
				l = tmp;
				if(tmp->key < e)
					tmp = tmp->right;
				else
					tmp = tmp->left;
			}
			if(l->key < e)
				l->right = new tree_c(e);
			else
				l->left = new tree_c(e);
		}
	}

private:
	void print(tree_c* r) {
		if(r != 0) {
			print(r->left);
			std::cout << r->key << ' ';
			print(r->right);
		}
	}

public:
	void show() {
		print(root);
	}

	
};

binary_tree<int> T;

int main() {
	int h, value;
	std::cin >> h;
	while(h--) {
		std::cin >> value;
		T.insert(value);
	}

	T.show();
}

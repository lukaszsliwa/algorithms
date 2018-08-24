#include <cstdio>

using namespace std;

const int M = 10000;

class Heap {
	int tab[M], heap_size;
	void swap(int& a, int& b) {
		int tamp = a;
		a = b;
		b = tamp;
	}
	inline int Parent(int i) {
		return i/2;	
	}
	inline int Left(int i) {
		return 2*i;
	}
	inline int Right(int i) {
		return 2*i + 1;
	}
	void moveDown(int i) {
		int l, r, t;
		t = 0;
		while(t != i) {
			l = Left(i);
			r = Right(i);
			t = i;
			if(l <= heap_size && tab[l] < tab[i])
				t = l;
			if(r <= heap_size && tab[r] < tab[t])
				t = r;
			if(i != t) {
				swap(tab[t], tab[i]);
				i = t;
				t = 0;
			}
		}
	}
	public:
		Heap() : heap_size(0) { };
		int top() const {
			return tab[1];
		}
		void pop() {
			tab[1] = tab[heap_size--];
			moveDown(1);
		}
		void push(int key) {
			int i = ++heap_size;
			tab[i] = key;
			while(i > 1 && tab[Parent(i)] > tab[i]) {
				swap(tab[Parent(i)], tab[i]);
				i = Parent(i);
			}
		}
		bool empty() {
			return heap_size == 0;
		}
};

Heap heap;

int main() {
	int n, l;
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &l);
		heap.push(l);
	}
	while(!heap.empty()) {
		printf("%d ", heap.top());
		heap.pop();
	}
	printf("\n");
	return 0;
}

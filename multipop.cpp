#include <cstdio>

using namespace std;

struct Stos {
	struct List {
		List *next, *prev;
		int key;
		List(int k, List *n = 0, List *p = 0) {
			next = n;
			prev = p;
			key = k;
		};
	} *head, *tail;
	void push(int e) {
		if(tail == 0)
			head = tail = new List(e);
		else {
			tail->next = new List(e, 0, tail);
			tail = tail->next;
		}
	}
	void pop() {
		tail = tail->prev;
	}
	bool empty() {
		return tail == 0;
	}
	int top() {
		return tail->key;
	}
	void multipop(int k) {
		while(!empty() && k != 0) {
			pop();
			k--;
		}
	}
} S;

int main() {
	int n,k, liczba;
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &liczba);
		S.push(liczba);
	}
	scanf("%d", &k);
	S.multipop(k);
	while(!S.empty()) {
		printf("%d ", S.top());
		S.pop();
	}
	return 0;
}

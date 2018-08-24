#include <cstdio>

using namespace std;

struct S {
	struct L {
		L *next;
		int key;
		L(int k, L *n = 0) {
			next = n;
			key = k;
		}
	} *list;
	S() : list(0) { };
	void push(int e) {
		list = new L(e, list);
	}
	void pop() {
		list = list->next;
	}
	int top() {
		return list->key;
	}
	bool empty() {
		return list == 0;
	}
} Stos;

int main() {
	int n, liczba;
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &liczba);
		Stos.push(liczba);
	}
	while(!Stos.empty()) {
		printf("%d ", Stos.top());
		Stos.pop();
	}
	return 0;
}

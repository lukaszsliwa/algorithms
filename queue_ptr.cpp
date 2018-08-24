#include <cstdio>

using namespace std;

struct queue {
	struct list {
		struct list *next;
		int key;
		list(int k, list *n = 0) {
			key = k;
			next = n;
		}
	} *head, *tail;
	queue() : head(0), tail(0) { };
	void push(int e) {
		if(head == 0)
			head = tail = new list(e);
		else {
			tail->next = new list(e);
			tail = tail->next;
		}
	}
	int front() {
		return head->key;
	}
	void pop() {
		head = head->next;
	}
	bool empty() {
		return head == 0;
	}
} Q;

int main() {
	int n , liczba;
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &liczba);
		Q.push(liczba);
	}
	while(!Q.empty()) {
		printf("%d ", Q.front());
		Q.pop();
	}
	return 0;
}

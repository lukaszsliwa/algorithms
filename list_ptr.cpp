#include <cstdio>

using namespace std;

struct List {
	List *next;
	int key;
	List(int k, List *t = 0) {
		next = t;
		key = k;
	}
} *head, *tail;

void AddToTail(int e) {
	if(tail == 0) 
		head = tail = new List(e);
	else {
		tail->next = new List(e);
		tail = tail->next;
	}
}

void AddToHead(int e) {
	head = new List(e, head);
	if(tail == 0)
		tail = head;
}

int main() {
	int n, liczba;
	List *tmp;
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &liczba);
		AddToTail(liczba);
	}
	tmp = head;
	while(tmp != 0) {
		printf("%d ", tmp->key);
		tmp = tmp->next;
	}
	return 0;
}

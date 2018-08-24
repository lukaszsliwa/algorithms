#include <cstdio>

using namespace std;

int n, liczba, head, tail, how;
int *tab;

void push_back(int e) {
	tab[tail++] = e;
	how++;
	if(tail > n) tail = 1;
}

void push_front(int e) {
	tab[head--] = e;
	how++;
	if(head < 1) head = n;
}

void pop_back() {
	tail--;
	how--;
	if(tail < 1) tail = n;
}

void pop_front() {
	head++;
	how--;
	if(head > n) head = 1;
}

bool empty() {
	return how == 0;
}

int front() {
	return tab[head];
}

int back() {
	return tab[tail];
}

int main() {
	int i;
	scanf("%d", &n);
	tail = 1;
	head = n;
	how = 0;
	tab = new int[n + 1];
	for(i = 0; i < n; ++i) {
		scanf("%d", &liczba);
		push_back(liczba);
	}
	while(!empty()) {
		printf("%d ", front());
		pop_front();	
	}
	return 0;
}

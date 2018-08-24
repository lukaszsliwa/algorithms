#include <cstdio>

using namespace std;

int n, q = -1, liczba;
int *tab;

void push(int e) {
	tab[q++] = e;
}

void pop() {
	q--;
}

bool empty() {
	return q < 0;
}

int top() {
	return tab[q - 1];
}

int main() {
	int i;
	scanf("%d", &n);
	tab = new int[n + 1];
	for(i = 0; i < n; ++i) {
		scanf("%d", &liczba);
		push(liczba);
	}	
	while(!empty()) {
		printf("%d ", top());
		pop();
	}
	delete []tab;
	return 0;
}

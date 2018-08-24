#include <cstdio>

using namespace std;

int n, liczba, p, k;
int *tab;

void enqueue(int e) {
	tab[++k] = e;
}

int dequeue() {
	return tab[p++];
}

bool empty() {
	return p > k;
}

int main() {
	scanf("%d", &n);
	p = 0;
	k = -1;
	tab = new int[n + 1];
	while(n--) {
		scanf("%d", &liczba);
		enqueue(liczba);	
	}
	while(!empty())
		printf("%d ", dequeue());
	printf("\n");
	delete []tab;
	return 0;
}

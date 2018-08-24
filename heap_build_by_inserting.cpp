#include <cstdio>

using namespace std;

int n, *heap;
int heap_size;

int Parent(int i) {
	return i/2;
}

void Insert(int i) {
	int k = ++heap_size;
	while(k > 1 && i > heap[Parent(k)]) {
		heap[k] = heap[Parent(k)];
		k = Parent(k);
	}
	heap[k] = i;
}

int main() {
	int i, liczba;
	scanf("%d", &n);
	heap = new int[n + 1];
	for(i = 0; i < n; ++i) {
		scanf("%d", &liczba);
		Insert(liczba);
	}
	for(i = 1; i <= n; ++i)
		printf("%d ", heap[i]);
	printf("\n");
	return 0;
}

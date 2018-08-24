/* Kopiec d-arny (posiada d-synow) */
#include <cstdio>

using namespace std;

int n, d, heap_size;
int *tab;

inline int Parent(int i) {
	return (i + i%d)/d;
}

inline int Child(int i) {
	return i*d - d/2; 
}

void swap(int& A, int& B) {
	int tmp = A;
	A = B;
	B = tmp;
}

void heap_up(int i) {
	int y, l, r = i;
	l = Child(i);
	for(y = l; y <= l + d && y <= heap_size; ++y)
		if(tab[r] < tab[y])
			r = y;
	if(r != i) {
		swap(tab[i], tab[r]);
		heap_up(r);
	}
}

int ExtractMax() {
	int i = tab[1];
	tab[1] = tab[heap_size--];
	heap_up(1);
	return i;
}

void Insert(int key) {
	int r = ++heap_size;
	while(r > 1 && key > tab[Parent(r)]) {
		tab[r] = tab[Parent(r)];
		r = Parent(r);
	}
	tab[r] = key;
}

void Increase(int i, int key) {
	tab[i] = tab[i] > key ? tab[i] : key;
	heap_up(i);
}

int main() {
	int liczba, i;
	scanf("%d%d", &n, &d);
	tab = new int[n + 1];
	for(i = 1; i <= n; ++i) {
		scanf("%d", &liczba);
		Insert(liczba);
	}
	while(heap_size)
		printf("%d ", ExtractMax());
	printf("\n");
	delete []tab;
	return 0;
}

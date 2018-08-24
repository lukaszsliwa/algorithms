/* Scalanie k tablic z wykorzystaniem kopca O(n lg k)  */
#include <cstdio>

using namespace std;

int n, k, q, heap_size;
int *merge_tab;
int *heap;		/* przechowuje numery list */
int *tab;		/* lista */
int *poczatek, *koniec;	/* poczate i koniec danej listy */

inline int Parent(int i) {
	return i/2;
}

inline int Left(int i) {
	return 2*i;
}

inline int Right(int i) {
	return 2*i + 1;
}

inline void wczytaj() {
	int i, y, l;
	scanf("%d%d", &k, &n);
	n++;
	poczatek = new int[k + 1];
	koniec = new int[k + 1];
	tab = new int[n];
	for(i = 1; i <= k; ++i) {
		scanf("%d", &l);
		poczatek[i] = q;
		for(y = 0; y < l; ++y)
			scanf("%d", &tab[q++]);
		koniec[i] = q - 1;
	}
	heap_size = k;
	heap = new int[k];
	merge_tab = new int[n];
	for(i = 1; i <= k; ++i)
		heap[i] = i;
}

int value(int i) {
	return tab[poczatek[heap[i]]];
}

void swap(int& A, int& B) {
	int tmp = A;
	A = B;
	B = tmp;
}

void Delete(int i) {
	heap[i] = heap[heap_size--];
}

void Heapify(int);

int Extract() {
	int r, g = heap[1]; /* numer listy z najwyzsza pierwsza pozycja  */
	r = value(1);
	poczatek[g]++;
	if(poczatek[g] > koniec[g])
		Delete(1);
	Heapify(1);
	return r;
}

void Heapify(int i) {
	int l, r, g;
	l = Left(i);
	r = Right(i);
	g = i;
	if(l <= heap_size && value(l) < value(i))
		g = l;
	if(r <= heap_size && value(r) < value(g))
		g = r;
	if(g != i) {
		swap(heap[g], heap[i]);
		Heapify(g);
	}
}

inline void Build_heap() {
	int i;
	for(i = heap_size/2; i >= 1; --i)
		Heapify(i);
}

inline void Merge() {
	int i;
	for(i = 0; i < n; ++i)
		merge_tab[i] = Extract();
}

inline void Print() {
	int i;
	for(i = 0; i < n - 1; ++i)
		printf("%d ", merge_tab[i]);
	printf("\n");
}

int main() {
	wczytaj();
	Build_heap();
	Merge();
	Print();
	return 0;
}

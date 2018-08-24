/*
	Algorytm sortowania przez kopcowanie
 */
#include <cstdio>

using namespace std;

int n, i, heap_size = 0;
int *tab;

inline int Parent(int x) {
	return x/2;
}

inline int Left(int x) {
	return 2*x;
}

inline int Right(int x) {
	return 2*x + 1;
}

void swap(int& A, int& B) {
	int tmp = A;
	A = B;
	B = tmp;
}

void Insert(int v) {
	int r = ++heap_size;
	while(r > 1 && v > tab[Parent(r)]) {
		tab[r] = tab[Parent(r)];
		r = Parent(r);
	}
	tab[r] = v;
}

void Heapify(int v) {
	int l, r, najw;
	l = Left(v);
	r = Right(v);
	najw = v;
	if(l <= heap_size && tab[l] > tab[v])
		najw = l;
	if(r <= heap_size && tab[r] > tab[najw])
		najw = r;
	if(najw != v) {
		swap(tab[najw], tab[v]);
		Heapify(najw);
	}
}

int ExtractMax() {
	int v = tab[1];
	tab[1] = tab[heap_size--];
	Heapify(1);
	return v;
}

void Increase(int v, int k) {
	tab[v] = tab[v] > k ? tab[v] : k;
	Heapify(v);
}

void Delete(int v) {
	swap(tab[v], tab[heap_size--]);
	Heapify(v);	
}

void drukuj() {
	for(int x = 1; x <= heap_size; ++x)
		printf("%d ", tab[x]);
	printf("\n");
	while(heap_size > 0)
		printf("%d ", ExtractMax());
	printf("\n");
}

int main() {
	int value;
	scanf("%d", &n);
	tab = new int[n + 1];
	for(i = 1; i <= n; ++i) {
		scanf("%d", &value);
		Insert(value);
	}
	drukuj();
	delete []tab;
	return 0;
}

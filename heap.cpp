#include <cstdio>

using namespace std;

int n, i, heap_size;
int najw;
int *tab;

inline void swap(int& A, int& B) {
	int tmp = A;
	A = B;
	B = tmp;
}

inline int left(int A) {
	return 2*A;
}

inline int right(int A) {
	return 2*A + 1;
}

void heapify(int i) {
	int l, r, ch;
	l = left(i);
	r = right(i);
	ch = i;
	if(l <= heap_size && tab[l] > tab[i])
		ch = l;
	if(r <= heap_size && tab[r] > tab[ch])
		ch = r;
	if(ch != i) {
		swap(tab[ch], tab[i]);
		heapify(ch);
	}	
}

inline void drukuj() {
	for(int i = 1; i <= n; ++i)
		printf("%d ", tab[i]);
	printf("\n");
}

int main() {
	scanf("%d", &n);
	heap_size = n;
	tab = new int[n + 1];
	for(i = 1;i <= n; ++i)
		scanf("%d", &tab[i]);
	/* budowanie kopca */
	for(i = heap_size/2; i >= 1 ; --i)
		heapify(i);
	/* sortowanie kopca */
	for(i = heap_size; i >= 2; --i) {
		swap(tab[1], tab[i]);
		heap_size --;
		heapify(1);
	}
	drukuj();
	return 0;
}

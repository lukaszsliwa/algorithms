#include <cstdio>

using namespace std;

int n, *tab;

#define printfor(X, Y, Z)\
       	for(int i__ = X; i__ <= Y; ++i__){\
		printf("%d ", tab[i__]); \
	}\
	printf(" [%d]\n", Z )
#define wynik(X, Y) printf("%d %d\n", X, Y)

void swap(int& A, int& B) {
	int tmp = A;
	A = B;
	B = tmp;
}

int Lomuto_partition(int p, int r) {
	int i, j, x;
	x = p;
	for(i = p + 1; i <= r; ++i) {
		//printfor(1, n, tab[p]);
		if(tab[i] < tab[p])
			swap(tab[++x], tab[i]);
	}
	swap(tab[p], tab[x]);
	return x;
}

void quicksort(int p, int r) {
	int q;
	if(p < r) {
		q = Lomuto_partition(p, r);
		quicksort(p, q);
		quicksort(q + 1, r);
	}
}

int main() {
	int i;
	scanf("%d", &n);
	tab = new int[n + 1];
	for(i = 1; i <= n; ++i)
		scanf("%d", &tab[i]);
	quicksort(1, n);
	for(i = 1; i <= n; ++i)
		printf("%d ", tab[i]);
	printf("\n");
	return 0;
}

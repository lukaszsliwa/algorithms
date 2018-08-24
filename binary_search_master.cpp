#include <stdio.h>

const int N_MAX = 100;
int n, szukaj, tab[N_MAX];

void wczytaj() {
	int i;
	/* szukamy wartosc "szukaj" 
	 * lub pierwszej mniejszej od "szukaj" */
	scanf("%d %d", &n, &szukaj);
	for(i = 1; i <= n; ++i)
		scanf("%d", &tab[i]);
}

main() {
	wczytaj();
	
	int a, b, mid;
	a = 1; b = n;
	while(a <= b) {
		mid = (a + b) / 2;
		if(tab[mid] == szukaj)
			break;
		else if(tab[mid] < szukaj)
			a = mid + 1;
		else
			b = mid - 1;
	}
	tab[mid] == szukaj ? printf("JEST\n") : printf("%d\n", tab[b]);
}

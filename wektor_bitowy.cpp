#include <cstdio>

using namespace std;

int n, *tab, *bit;

void Insert(int e) {
	bit[e] = 1;
}

void Delete(int e) {
	bit[e] = 0;
}

bool Search(int e) {
	return bit[e];
}

int main() {
	int i, x;
	scanf("%d", &n);
	tab = new int[n + 1];
	bit = new int[n + 1];
	while(n--) {
		scanf("%d", &tab[i++]);
		Insert(tab[i - 1]);
	}
	scanf("%d", &x); //znajdz x w zbiorze;
	if(Search(x)) {
		printf("Jest\n");
		Delete(x);
	} else printf("Nie ma\n");
	return 0;
}

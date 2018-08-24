#include <cstdio>
#include <cstring>

using namespace std;

int n;
char liczba[100][100];

struct drzewo {
	int klucz;
	drzewo *prawy, *lewy;
	drzewo(int k = -1, drzewo *l = 0, drzewo *p = 0) {
		klucz = k;
		prawy = p;
		lewy = l;
	}
} *korzen;

void utworz(int i, drzewo*& t) {
	if(i > 0) {
		t = new drzewo();
		utworz(i - 1, t->lewy);
		utworz(i - 1, t->prawy);
	}
}

void Insert(int i) {
	int x, y;
	drzewo *syn = korzen, *ojciec = 0;
	for(x = 0; x < strlen(liczba[i]); ++x) {
		ojciec = syn;
		if(liczba[i][x] == '0')
			syn = syn->lewy;
		else
			syn = syn->prawy;
	}	
	syn->klucz = i;
}

void Sort(drzewo *t) {
	if(t != 0) {
		if(t->klucz != -1)
			printf("%s ", liczba[t->klucz]);
		Sort(t->lewy);
		Sort(t->prawy);
	}
}

int main() {
	int i;
	korzen = 0;
	scanf("%d", &n);
	utworz(n + 1, korzen);	
	for(i = 0; i < n; ++i) {
		scanf("%s", liczba[i]);
		Insert(i);
	}
	Sort(korzen);
	return 0;
}

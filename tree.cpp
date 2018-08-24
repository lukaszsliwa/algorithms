#include <cstdio>

using namespace std;

int n;

struct drzewo {
	int klucz;
	drzewo *lewe, *prawe;
	drzewo(int k = 0, drzewo *l = 0, drzewo *p = 0) {
		lewe = l;
		prawe = p;
		klucz = k;
	}
} *korzen;

void Insert(int klucz) {
	int i;
	drzewo *syn = korzen, *ojciec = 0;
	while(syn != 0) {
		ojciec = syn;
		if(klucz < syn->klucz)
			syn = syn->lewe;
		else
			syn = syn->prawe;	
	}
	if(ojciec == 0)
		korzen = new drzewo(klucz);
	else if(klucz < ojciec->klucz)
		ojciec->lewe = new drzewo(klucz);
	else
		ojciec->prawe = new drzewo(klucz);
}

void Inorder(drzewo *t) {
	if(t != 0) {
		Inorder(t->lewe);
		printf("%d ", t->klucz);
		Inorder(t->prawe);
	}
}

int main() {
	int i, liczba;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		scanf("%d", &liczba);
		Insert(liczba);
	}
	Inorder(korzen);
	return 0;
}

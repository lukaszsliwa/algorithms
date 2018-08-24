#include <cstdio>
#include <cstring>

using namespace std;

const int M = 10000;
int n, m;
char tekst[M], wzorzec[M];

void wczytaj() {
	scanf("%s%s", tekst, wzorzec);
	n = strlen(tekst);
	m = strlen(wzorzec);
}

void naive_string_matcher() {
	int i, y, z;
	for(i = 0; i < n; ++i) {
		for(y = 0, z = i;
			y < m && z < n && tekst[z] == wzorzec[y];
			y++, z++);
		if(y == m)
			printf("Wzorzec wystepuje na pozycjach %d do %d\n", i, i + m);	
	}
}

int main() {
	wczytaj();
	naive_string_matcher();
	return 0;
}

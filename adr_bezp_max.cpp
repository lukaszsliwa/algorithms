/* Wyszukiwanie maksymalnej warto¶ci w tablicy
   z adresowaniem bezpo¶rednim - O(log n)  */
#include <cstdio>

using namespace std;

int n, i, q, *S, *T;
int liczba;

int Search() {
	int e = S[0];
	while(T[e] != e)
		e = T[e];
	return e;
}

int main() {
	int i;
	scanf("%d", &n);
	S = new int[n + 1];
	T = new int[n + 1];
	q = -1;
	for(i = 0; i <= n; ++i)
		T[i] = -1;
	i = 0;	
	while(n--) {
		scanf("%d", &S[i++]);
		if(q == -1)
			q = S[i - 1];
		else if(q < S[i - 1]) {
			T[q] = S[i - 1];
			q = S[i - 1];
		}
		T[S[i-1]] = q;	
	}	
	printf("%d\n", Search()); 
	delete []S;
	delete []T;
	return 0;
}

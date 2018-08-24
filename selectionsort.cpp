#include <iostream>
using namespace std;

int n, *tab;

void swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}

int main() {
	cin >> n;
	tab = new int[n + 1];
	for(int i = 0; i < n; ++i)
		cin >> tab[i];
	for(int i = 0; i < n; ++i) {
		int j = i;
		for(int a = i; a < n; ++a)
			if(tab[a] < tab[j])
				j = a;
		swap(tab[i], tab[j]);
	}
	for(int i = 0; i < n; ++i)
		cout << tab[i] << " ";
}

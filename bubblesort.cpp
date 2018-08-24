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
	for(int i = 1; i < n; ++i)
		for(int j = 0; j < n - i; ++j)
			if(tab[j] > tab[j + 1])
				swap(tab[j], tab[j + 1]);
	for(int i = 0; i < n; ++i)
		cout << tab[i] << " ";
}

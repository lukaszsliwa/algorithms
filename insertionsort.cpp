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
	for(int val, j, i = 1; i < n; ++i) {
		val = tab[i];
		j = i - 1;
		while(j >= 0 && tab[j] > val) {
			swap(tab[j], tab[j + 1]);
			j--;
		}
		tab[j + 1] = val;
	}
	for(int i = 0; i < n; ++i)
		cout << tab[i] << " ";
}

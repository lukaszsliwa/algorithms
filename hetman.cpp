#include <iostream>
using namespace std;

int length = 0;

int abs(int v) {
	return v < 0 ? -v : v;
}

bool szachuje(int wiersz, int kolumna, int tab[]) {
	for(int k = 1; k < kolumna; ++k)
		if(tab[k] == wiersz || abs(k - kolumna) == abs(tab[k] - wiersz))
			return true;
	return false;
}

void ustaw(int wiersz, int kolumna, int tab[]) {
	tab[kolumna] = wiersz;
}

void hetman(int kolumna, int n, int tab[]) {
	if(kolumna > n) {

		for(int i = 1; i <= n; ++i)
			cout << tab[i] << " ";
		cout << endl;

		length++;

	} else {

		for(int wiersz = 1; wiersz <= n; ++wiersz)

			if(!szachuje(wiersz, kolumna, tab)) {

				ustaw(wiersz, kolumna, tab);
				hetman(kolumna+1, n, tab);

			}

	}
}

int main() {
	int n, *tab;;
	cin >> n;
	tab = new int[n + 1];
	hetman(1, n, tab);
	cout << length << endl;
}

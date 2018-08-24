#include <iostream>

using namespace std;

int c;

void binaryprint(int c) {
	int i;
	for(i = 7; i >= 0; --i)
		cout << ((c & (1 << i)) ? 1 : 0);
	cout << endl;
}

main() {
	cin >> c;
	binaryprint(c);
}

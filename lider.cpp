#include <cstdio>

using namespace std;

int i, len, lider, lider_i;
int* t;

main() {
	scanf("%d", &len);
	t = new int[len + 1];
	for(i = 0; i < len; ++i) {
		scanf("%d", &t[i]);
		if(lider_i == 0) {
			lider = t[i];
			lider_i++;
		} else if(lider == t[i])
			lider_i++;
		else
			lider_i--;
	}
	for(lider_i = 0, i = 0; i < len; ++i)
		if(t[i] == lider)
			lider_i++;
	lider_i > len / 2 ? printf("%d\n", lider) : printf("NIE MA\n");
	delete []t;
}

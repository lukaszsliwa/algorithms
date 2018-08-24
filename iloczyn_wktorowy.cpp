#include <cstdio>

using namespace std;

int x0, x1, x2, y0, y1, y2;

int licz() {
	return (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);
}

int main() {
	scanf("%d%d", &x0, &y0);
	scanf("%d%d", &x1, &y1);
	scanf("%d%d", &x2, &y2);
	printf("%d\n", licz());
	return 0;
}

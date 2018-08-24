#include <cstdio>
#include <cstring>

using namespace std;

const int M = 1000;

int n, m, i, j, c[M][M], b[M][M];
char x[M], y[M];

void drukuj(int i, int j) {
	if(i == 0 || j == 0)
		return;
	if(b[i][j] == 1) {
		drukuj(i - 1, j - 1);
		printf("%c", y[j]);
	} else if(b[i][j] == 2)
		drukuj(i - 1, j);
	else
		drukuj(i, j - 1);
}

void przesun(char p[], char znak, int i, int len) {
	if(i <= len) {
		przesun(p, p[i + 1], i + 1, len);
		p[i] = znak;
	}
}

int main() {
	scanf("%s %s", x, y);
	m = strlen(x) + 1;
	n = strlen(y) + 1;
	przesun(x,'\0', 0, m - 1);
	przesun(y,'\0', 0, n - 1);
	for(i = 0; i <= m; ++i)
		c[i][0] = 0;
	for(i = 0; i <= n; ++i)
		c[0][i] = 0;
	for(i = 1; i <= m; ++i)
		for(j = 1; j <= n; ++j) {
			if(x[i] == y[j]) {
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 1;
			} else if(c[i - 1][j] >= c[i][j - 1]) {
				c[i][j] = c[i - 1][j];
				b[i][j] = 2;	
			} else {
				c[i][j] = c[i][j - 1];
				b[i][j] = 3;
			}
		}
	drukuj(m, n);
	return 0;
}

#include <cstdio>
#include <cmath>
using namespace std;

double a, n, liczba;

int main() {
	scanf("%lf%lf", &liczba, &n);
	a = liczba;
	while(fabs(a - (liczba / a)) > n)
		a = (a + liczba / a) / 2.0;
	printf("%lf\n", a);
}

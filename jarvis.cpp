#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll_int;

struct p {
	ll_int x, y;
	p(ll_int xx, ll_int yy) : x(xx), y(yy) { }
};

vector<p> punkty, stos;
typedef vector<p>::iterator vec_iter;

void wczytaj() {
	int n;
	ll_int x, y;
	scanf("%d", &n);
	while(n--) {
		scanf("%lld%lld", &x, &y);
		punkty.push_back(p(x, y));
	}
}

bool p0_sort(const p& A, const p& B) {
	return A.y < B.y || A.y == B.y && A.x < B.x;
}

ll_int kat(vec_iter a, vec_iter b) {
	return (a->x * b->x) + (a->y * b->y);
}

vec_iter minimum(vec_iter e) {
	vec_iter i, akt = punkty.begin();
	for(i = punkty.begin() + 1; i < punkty.end(); ++i) {
		if(kat(e, akt) < kat(e, i))
			akt = i;
	}
	return akt;
}

void print(vector<p>& g) {
	vec_iter i;
	for(i = g.begin(); i < g.end(); ++i)
		printf("(%lld ; %lld)\n", i->x, i->y);
	printf("\n");
}

int main() {
	vec_iter i, y, last;
	wczytaj();
	sort(punkty.begin(), punkty.end(), p0_sort);
	stos.push_back(punkty[0]);
	last = minimum(punkty.begin());
	stos.push_back(p(last->x, last->y));
	while(last != punkty.begin()) {
		last = minimum(last);
		stos.push_back(p(last->x, last->y));
	}
	print(stos);
	return 0;
}

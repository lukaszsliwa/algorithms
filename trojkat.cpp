#include <iostream>
using namespace std;

struct punkt {
	int x, y;
	punkt() {}
	punkt(int xx, int yy) : x(xx), y(yy) {}
	punkt& operator = (const punkt& P) {
		x = P.x;
		y = P.y;
		return *this;
	}
};

int det(const punkt& a, const punkt& e, const punkt& b) {
	return (a.x - e.x) * (b.y - e.y) - (a.y - e.y) * (b.x - e.x);
}

void wczytaj(punkt& a) {
	int x, y;
	cin >> x >> y;
	a = punkt(x, y);
}

char* w_trojkacie(const punkt& a, const punkt& b, const punkt& c, const punkt& e) {
	int p1 = det(e, a, c), p2 = det(e, b, a), p3 = det(e, c, b);
	if(p1 == 0 || p2 == 0 || p3 == 0)
		return "TAK";
	else if(p1 < 0 && p2 < 0 && p3 < 0)
		return "TAK";
	return "NIE";
}

main() {
	punkt a, b, c, e;
	wczytaj(a); wczytaj(b); wczytaj(c); wczytaj(e);
	puts(w_trojkacie(a, b, c, e));
}

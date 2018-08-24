#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct para {
	int x, y;
	para(int xx, int yy) {
		x = xx;
		y = yy;
	}
};

int n;
vector<para> wektor;

bool operator < (const para& a, const para& b) {
	return a.x*b.y - a.y*b.x > 0;
}

int main() {
	int x, y;
	scanf("%d", &n);
	while(n--) {
		scanf("%d%d", &x, &y);
		wektor.push_back(para(x, y));
	}
	sort(wektor.begin(), wektor.end());
	while(wektor.empty() == false) {
		printf("(%d ; %d)\n", wektor.back().x, wektor.back().y);
		wektor.pop_back();
	}
	return 0;
}

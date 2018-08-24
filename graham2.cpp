#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll_int;

struct p {
	ll_int x, y;
	bool display;
	p() { }
	p(ll_int xx, ll_int yy) : x(xx), y(yy), display(true) { }
};

vector<p> graham, stos;
typedef vector<p>::iterator vec_iter;

vec_iter p0;

void print(vector<p>&);

void wczytaj() {
	int n;
	ll_int x, y;
	scanf("%d", &n);
	while(n--) {
		scanf("%lld%lld", &x, &y);
		graham.push_back(p(x, y));
	}
}

bool cmp_sort(const p& A, const p& B) {
	return A.x * B.y - A.y * B.x > 0;
}

bool wsp_sort(const p& A, const p& B) {
	return (A.x - p0->x) * (B.y - p0->y) - (A.y - p0->y) * (B.x - p0->x) == 0;
}

ll_int skret(vec_iter a, vec_iter b, vec_iter c) {
	return (a->x - b->x) * (c->y - b->y) - (a->y - b->y) * (c->x - b->x);
}

void usun_wspolliniowe() {
	vec_iter i;
	vector<p> tmp;
	//sort(graham.begin() + 1, graham.end(), wsp_sort);
	//print(graham);
	for(i = graham.begin() + 1; i < graham.end(); ++i)
		if(skret(p0, i - 1, i) == 0)
			(i - 1)->display = false;
	for(i = graham.begin(); i < graham.end(); ++i)
		if(i->display == true)
			tmp.push_back(p(i->x, i->y));
	while(!graham.empty())
		graham.pop_back();
	for(i = tmp.begin(); i < tmp.end(); ++i)
		graham.push_back(p(i->x, i->y));
	sort(graham.begin() + 1, graham.end(), cmp_sort);
}

void graham_scan() {
	vec_iter i, y;
	stos.push_back(graham[0]);
	stos.push_back(graham[1]);
	stos.push_back(graham[2]);
	for(i = graham.begin() + 3; i < graham.end(); ++i) {
		y = stos.end() - 1;
		while(skret(y - 1, y, i) > 0) {
			stos.pop_back();
			y = stos.end() - 1;
		}
		stos.push_back(p(i->x, i ->y));
	}
}

void print(vector<p>& g) {
	vec_iter i;
	for(i = g.begin(); i < g.end(); ++i)
		printf("(%lld ; %lld)\n", i->x, i->y);
	printf("\n");
}

int main() {
	wczytaj();
	sort(graham.begin(), graham.end(), cmp_sort);
	p0 = graham.begin();
	usun_wspolliniowe();
	graham_scan();
	print(stos);
	return 0;
}

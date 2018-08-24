/*
 Algorytm Grahama do znajdowania otoczki wypuk³ej
 w wielok±cie foremnym.
 */
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int N_MAX = 100000;

struct para {
	int x, y, wsp;
	para() { }
	para(int a, int b, int ww = 100000000) : x(a), y(b), wsp(ww) { }
};

vector<para> w, S;

typedef vector<para>::iterator vec_iter;

void wczytaj() {
	int n, i, x, y;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		scanf("%d%d", &x, &y);
		w.push_back(para(x, y));
	}
}

int skret(vec_iter p1, vec_iter p0, vec_iter p2) {
	return (p1->x - p0->x) * (p2->y - p0->y) - (p2->x - p0->x) * (p1->y - p0->y);
}

bool cmp(const para& a, const para& b) {
	return a.x*b.y - a.y*b.x > 0;
}

void print(vector<para>& p) {
	for(vec_iter i = p.begin(); i < p.end(); ++i)
		printf("[%d ; %d] wsp_kat = %d\n ", i->x, i->y, i->wsp);
	printf("\n");
}

void wspolrzedna_katowa() {
	vec_iter y;
	w.begin()->wsp = skret(w.end() - 1, w.begin(), w.begin() + 1);
	for(y = w.begin() + 1; y < w.end() - 1; ++y)
		y->wsp = skret(y - 1, y, y + 1);
	(w.end() - 1)->wsp = skret(w.end() - 2, w.end() - 1, w.begin());
	for(y = w.begin() + 1; y < w.end(); ++y) {
		while(w.size() > 1 && (y - 1)->wsp == y->wsp)
			w.erase(y - 1);
	}
}

int main() {
	wczytaj();
	sort(w.begin(), w.end(), cmp);
	wspolrzedna_katowa();
	print(w);
	S.push_back(para(w[0].x, w[0].y, w[0].wsp));
	S.push_back(para(w[1].x, w[1].y, w[1].wsp));
	S.push_back(para(w[2].x, w[2].y, w[2].wsp));
	for(vec_iter i = w.begin() + 3; i < w.end(); ++i) {
		while(skret(S.end() - 2, S.end() - 1, i) > 0)
			S.pop_back();
		S.push_back(para(i->x, i->y, i->wsp));
	}
	print(S);
	return 0;
}

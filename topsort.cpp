#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

const int n_max = 100000;
int n, num = 1, out[n_max], numer[n_max];
vector<list<int> > graf;

inline void wczytaj() {
	int a, b, m, i;
	cin >> n >> m;
	graf.resize(n + 1);
	for(i = 1; i <= n; ++i)
		out[i] = 0;
	while(m--) {
		cin >> a >> b;
		graf[a].push_back(b);
		out[b]++;
	}
}

template <typename T>
T pop(stack<T>& s) {
	T k = s.top();
	s.pop();
	return k;
}

stack<int> s;

main() {
	int v, i;
	wczytaj();
	for(i = 1; i <= n; ++i)
		if(out[i] == 0)
			s.push(i);
	while(!s.empty()) {
		numer[v = pop<int>(s)] = num++;
		cout << v << '[' << numer[v] << ']' << ' ';
		for(list<int>::iterator y = graf[v].begin();
			y != graf[v].end(); ++y)
			if(--out[*y] == 0)
				s.push(*y);
	}
}

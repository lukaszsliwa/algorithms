#include <iostream>
#include <vector>
#include <list>
using namespace std;

class graph {
	int n, num, *numer;
	vector<list<int> > graf;
	list<list<int> > cykle;
	class stack {
		int size, tab[100000];
	public:
		stack() : size(0) {}
		void push(int k) {
			tab[size++] = k;
		}
		int pop() {
			return tab[--size];
		}
		bool empty() {
			return size == 0;
		}
		int top(int index = 0) {
			return tab[size - index - 1];
		}
		int size_of() {
			return size;
		}
	} stos;
public:
	graph() {
		int m, a, b;
		cin >> n >> m;
		graf.resize(n + 1);
		numer = new int[n + 1];
		while(m--) {
			cin >> a >> b;
			graf[a].push_back(b);
			graf[b].push_back(a);
		}
		num = 1;
		for(int i = 1; i <= n; ++i)
			numer[i] = 0;
		for(int i = 1; i <= n; ++i)
			if(numer[i] == 0)
				cykl(i);
	}
	void cykl(int v) {
		numer[v] = num++;
		stos.push(v);
		for(list<int>::iterator i = graf[v].begin(); 
			i != graf[v].end(); ++i)
			if(numer[*i] == 0)
				cykl(*i);
			else if(stos.top(1) != *i && numer[*i] < numer[v]) {
				list<int> cykl_e;
				for(int y = 0; stos.top(y) != *i; ++y)
					cykl_e.push_back(stos.top(y));
				cykl_e.push_back(*i);
				cykle.push_back(cykl_e);
			}
		stos.pop();
	}
	friend ostream& operator << (ostream& os, graph& g) {
		for(list<list<int> >::iterator i = g.cykle.begin();
			i != g.cykle.end(); ++i) {
			for(list<int>::iterator y = i->begin();
				y != i->end(); ++y)
				os << *y << ' ';
			os << endl;
		}
		return os;
	}
};

main() {
	ios_base::sync_with_stdio(0);
	graph g;
	cout << g;
}

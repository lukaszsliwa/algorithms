#include <cstdio>
#include <vector>
#include <list>

using namespace std;

vector< vector<int> > graf;
list<int> cykl;

typedef list<int>::iterator list_iter;

int n, start, *graf_in, *graf_out;

bool wczytaj() {
	int m, a, b, i;
	scanf("%d%d%d", &n, &m, &start);
	graf.resize(n + 1);
	graf_in = new int[n + 1];
	graf_out = new int[n + 1];
	while(m--) {
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf_in[b]++;
		graf_out[a]++;
	}
	for(i = 1; i <= n; ++i)
		if(graf_in[i] != graf_out[i])
			return false;
	delete []graf_in;
	delete []graf_out;
	
	return true;
}

void wypisz(list_iter a, list_iter b) {
	while(a != b)
		printf("%d ", *a++);
}

void cykl_eulera(int v) {
	int t;
	while(!graf[v].empty()) {
		t = graf[v].back();
		graf[v].pop_back();
		cykl_eulera(t);
		cykl.push_back(t);		
	}
}

int main() {
	if(!wczytaj())
		printf("NIE\n");
	else {
		cykl_eulera(start);
		for(list_iter cykl_iter = cykl.begin(); 
				cykl_iter != cykl.end(); ++cykl_iter)
			printf("%d ", *cykl_iter);
		printf("\n");
	}
	return 0;
}

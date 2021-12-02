//Adrian Valdes Zavala
//A01720439 
//Requiere TopologicalSort usando Kahn's
//Referencia para kahn -> GeekForGeeks
//utilizamos priorityqueue para traer la minima solucion
//referencia Para queue min -> https://medium.com/@aastharanjan7/topological-sort-kahns-algorithm-4b844d122e60

#include <iostream>
#include <stdio.h>
#include <list>
#include <vector>
#include <queue>

using namespace std;

vector<int> vec[100005];
vector<int> topoSort;
int cant[100005];


bool topoKahnSort(int n)
{
	int newN;
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 1; i <= n; i++) {
		if (cant[i] == 0){
			pq.push(i);
		}
	}

	while (!pq.empty()){

		int actual = pq.top();
		topoSort.push_back(actual);
		pq.pop();

		for (int hijo : vec[actual]){
			cant[hijo]--;
			if (cant[hijo] == 0) {
				pq.push(hijo);
			}
		}
	}
	newN  = (topoSort.size() == n);
	return newN;
}

int main() {
	int n, m;
	int x, y;
	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		vec[x].push_back(y);
		cant[y]++;
	}

	if (topoKahnSort(n) == NULL) {
		cout << "Sandro fails.";
	}

	else{
		for (int node : topoSort) {
			cout << node << " ";
		}
	}

}

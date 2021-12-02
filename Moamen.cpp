//Adrian Valdes Zavala 
//A01720439
//Momen
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;
//O(n^2)
int main() {
	int n;
	cin >> n;
	while (n--) {
		int a, k, t; //n = cantidad de prob, a = tamaño de prob, k = particiones
		int cont = 0;
		cin >> a >> k;
		vector<int> vec;
		vector<int> nvec;
		vector<int> fvec;
		//llenamos ambos vectores y sorteamos uno 
		for (int i = 0; i < a; i++) {
			cin >> t;
			vec.push_back(t);
			nvec.push_back(t);
		}
		sort(nvec.begin(), nvec.end());
		//Revisamos en que posicion esta el valor en el vector ordenado
		//Nos traemos su posicion
		for (int i = 0; i < a; i++) {
			auto f = find(nvec.begin(), nvec.end(), vec[i]);
			int pos = f - nvec.begin();
			fvec.push_back(pos);
		}
		//Aumentamos el contador si el siguiente numero es mas chico
		for (int i = 0; i < fvec.size() - 1; i++) {
			if (fvec[i] > fvec[i + 1]) {
				cont++;
			}
		}
		// Si el Contador es Menor a las particiones solicitadas entonces es verdad
		if (cont < k) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	//return 0;
}

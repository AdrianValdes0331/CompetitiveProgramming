//Adrian Valdes Zavala A01720439
//Problema A

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

//Agregamos nuevo int que vamos a revisar que sea mayor al valor total dividido en 2
//Al momento que ya sea mayor cortamos el programa, pues no tiene que tener todo el dinero, solo tiene que tener mas.
//Tiene que estar ordenado por si una moneda tiene mas valor que todas las demas, solo te quedas con esa.
void GemeloRatero(int cont, int DTotal, vector<int> VArrMonedas, int monedas) {
	DTotal = DTotal / 2;
	int NDTotal = 0;
	sort(VArrMonedas.begin(), VArrMonedas.end());
	for (int i = monedas - 1; i >= 0; i--) {
		NDTotal += VArrMonedas[i];
		cont++;
		if (NDTotal > DTotal) {
			break;
		}
	}
	cout << cont;
}

//Tenemos monedas, contador y valor total
//usamos un vector donde se acumulan las monedas con sus valores
//Sumamos el valor total de las monedas.
int main() {
	int monedas;
	int cont=0, DTotal=0;
	cin >> monedas;
	vector<int> VArrMonedas(monedas);

	for (int i = 0; i < monedas; i++) {
		cin >> VArrMonedas[i];
		DTotal = DTotal + VArrMonedas[i];
	}
	GemeloRatero(cont, DTotal, VArrMonedas, monedas);
}

//262144
//262144 
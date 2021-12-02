//Adrian Valdes Zavala 
//A01720439 
//Problema C, Football 01
#include <iostream>
#include <stdio.h>

using namespace std;

//Complejidad O(n) Lineal

/*
Mientras que i sea menor al tamaño de jugadores
revisa si el primer caracter es igual al siguiente, si es asi
suma al contador.
Si no resetear contador y solo si es mayor a 7 salir del loop
Si no hay alguna seria mayor a 7 al final le dara el valor de
0 e imprimira un NO, de lo contrario imprimira un YES.
*/
void isDangerous(int cont, string jugadores) {
	for (int i = 0; i < jugadores.size(); i++) {
		if (jugadores[i] == jugadores[i + 1]) {
			cont++;
		}
		else {
			cont = 0;
		}
		if (cont >= 6) {
			break;
		}
	}
	string Result = (cont >= 6) ? "YES" : "NO";
	cout << Result << endl;;
}

//daclaramos valores y los mandamos a nueva funcion
//para que se vea un poco mas limpio
int main() {
	int cont = 0;
	string jugadores;
	cin >> jugadores;

	isDangerous(cont, jugadores);
}
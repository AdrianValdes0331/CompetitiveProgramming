//Adrian Valdes Zavala 
//A01720439
//Problema B, Home & Guest Uniforms
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
//Complejidad O(n) lineal
//Colocamos n como la cantidad de pares que vamos a tener
//creamos un contador igualado a 0;
//creamos 2 vectores, uno para host y uno para guests
//llenamos ambos vectores
//checamos con un dbole loop, si el primer host iguala a un guest, si es asi
//sumamos 1 al contador, sino brincamos al siguiente host

int main()
{
    int n;
    int cont = 0;
    cin >> n;

    vector<int> h(n), g(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        cin >> g[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (h[i]==g[j]) {
                cont++;
            }
        }
    }
    cout << cont << endl;

}
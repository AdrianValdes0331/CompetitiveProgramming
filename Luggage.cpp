//Adrian Valdes Zavala
//A01720439

#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int m;
    cin >> m;
    cin.ignore();
    //vector<string> result;
    for (int i = 1; i <= m; i++) {
        
        int cont = 0;
        int contt = 0;
        int val;

        string n;
        getline(cin, n);
        stringstream nval(n);
        vector<int> suma(1, 0);

        while (nval >> val) {
            if (contt <= 20) {
                cont = cont + val;
                size_t size = suma.size();
                for (size_t i = 0; i < size; ++i) {
                    suma.push_back(suma[i] + val);
                }
                contt++;
            }
            else {
                cout << "Hay mas de la cantidad de personas permitidas" << endl;
                return 0;
            }
        }
        if (cont <= 200) {
            if (cont % 2 == 0 && find(suma.begin(), suma.end(), cont/2) != suma.end()) {
                //result.push_back("YES");
                cout << "YES" << endl;
            }
            else {
                //result.push_back("NO");
                cout << "NO" << endl;
            }
        }
        else {
            cout << "Las maletas estan muy pesadas" << endl;
        }
    }
    /*for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }*/
    return 0;
}

/*
3
1 2 1 2 1
2 3 4 1 2 5 10 50 3 50
3 5 2 7 1 7 5 2 8 9 1 25 15 8 3 1 38 45 8 1

NO
YES
YES
*/
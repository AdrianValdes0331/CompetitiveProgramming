#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool check(char a, char b, vector<char> checked) {
    for (int x = 0; x < checked.size(); x++) {
        if (a == b) {
            return false;
        }
    }
    return true;
}

void stringRes(vector<string> testCases, vector<string>& res) {
    vector<char> checked; //letras que ya fueron checadas
    int cont;

    for (int i = 0; i < testCases.size(); i++) {
        //Itera todos los test cases
        for (int j = 0; j < testCases[i].length(); j++) {
            cont = count(testCases[i].begin(), testCases[i].end(), testCases[i].at(j));

            //Si se repite en número impar, entonces sí funciona.
            if (cont % 2 != 0 && cont != 0) {
                res.push_back("");
                res[i].push_back(testCases[i].at(j));
            }
            cont = 0;

        }
    }
}

int main() {
    int t; //number of test cases
    string word;
    vector<string> testCases;
    vector<string> res;

    cin >> t;
    while(t--) {
        cin >> word;
        testCases.push_back(word);
        stringRes(testCases, res);


        for (int j = 0; j < testCases.size(); j++) {
            //Ordenar vector de res en alfabetico
            sort(res[j].begin(), res[j].end());

            //Remueve letras duplicadas
            for (int k = 0; k < res[j].length(); k++) {

                char current = res[j].at(k);
                int cont = count(res[j].begin(), res[j].end(), current);
                if (cont > 1) {
                    res[j].erase(res[j].begin());
                }
            }
            cout << res[j] << endl;
        }
    }
}
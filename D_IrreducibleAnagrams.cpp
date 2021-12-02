#include <iostream>
#include <stdio.h>

using namespace std;

#define MAX 200005 //maximo tamaño string
int a[MAX][30]; //matriz
int main()
{
    string s;  
    int q;
    cin >> s;
    cin >> q;
    int strlen = s.length();

    for (int i = 0; i < strlen; ++i){
        for (int j = 1; j <= 26; ++j) {
            a[i + 1][j] = a[i][j];
        }
        a[i + 1][s[i] - 'a' + 1]++;
    }
    
    while (q--) {
        int l, r;    
        cin >> l >> r;

        if (l == r) {
            cout << "Yes" << endl;
        }

        else {
            int cont = 0;
            for (int i = 1; i <= 26; ++i) {
                if (a[l - 1][i] - a[r][i]) {
                    cont++;
                }
            }
            if (cont == 1) {
                cout << "No" << endl;
            }
            else {
                if (cont > 2) {
                    cout << "Yes" << endl;
                }
                else {
                    if (s[l - 1] == s[r - 1]) {
                        cout << "No" << endl;
                    }
                    else {
                        cout << "Yes" << endl;
                    }
                }
            }
        }
    }
    return 0;
}
#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string a, b;
        cin >> a >> b;
        int sizea = a.size();
        int sizeb = b.size();
        int cont = 0;
        for (int len = 1; len <= min(sizea, sizeb); len++) {
            for (int i = 0; i + len <= sizea; i++) {
                for (int j = 0; j + len <= sizeb; j++) {
                    if (a.substr(i, len) == b.substr(j, len)) {
                        cont = max(cont, len);
                    }
                }
            }
        }
        cout << a.size() + b.size() - 2 * cont << "\n";
    }
}
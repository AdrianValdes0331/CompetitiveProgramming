//B_SocialDistance

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// n = cantidad, k = separacion
// 1 = ocupado, 0 = vacio
// sin = 8 y k = 2
// "10010001", "10000010", "00000000", "00100000" son Validas
// "10100100", "10011001", "11111111" No son Validas
// Quremos saber que tantas personas mas caben en el restaurante

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, k;
		int espDisp = 0;
		string str;
		cin >> n >> k;
		cin >> str;

		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '0') {
				int j = i + 1;
				while (j < str.size() && str[j] == '0' && j - i <=k){
					++j;
				}
				if (j-i > k || j == str.size()) {
					espDisp++;
					i += k;
				}
				else {
					i = j - 1;
				}
			}
			else{
				i += k;
			}
		}
		cout << espDisp << endl;
	}
}
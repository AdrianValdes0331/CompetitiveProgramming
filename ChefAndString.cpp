//Adrian Valdes Zavala 
//A01720439

#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std;

int arr[100002];
int arr2[100002];
int arr3[100002];
int a[100002];
int b[100002];
const int MAX = 1e9 + 7;

int solve(int val, int pos) {
	if (pos == 0) {
		return 1;
	}
	if (pos == 1) {
		return val % MAX;
	}
	int repeat = solve(val, pos / 2);
	repeat = (repeat * 1ll * repeat) % MAX;
	if (pos % 2 == 1) {
		repeat = (repeat * 1ll * val) % MAX;
	}
	return repeat;
}

//Utilizamos la ZFunction
vector<int> z_function(string texto) {
	int n = texto.length();
	vector<int> z(n);
	for (int i = 1, l = 0, r = 0; i < n; i++) {
		if (i <= r) {
			z[i] = min(r - i + 1, z[i - l]);
		}
		while (i + z[i] < n && texto[z[i]] == texto[i + z[i]]) {
			z[i]++;
		}
		if (i + z[i] - 1 > r) {
			l = i;//L no es necesaria
			r = i + z[i] - 1;
		}
	}
	return z;
}

int Change(int n, int k) {
	int result = 1;
	//Cambiar a Long Long
	result = (result * 1ll * a[n]) % MAX;
	result = (result * 1ll * b[k]) % MAX;
	result = (result * 1ll * b[n - k]) % MAX;

	return result;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, q, x;
		string st;
		cin >> n;
		cin >> q;
		cin >> st;

		a[0] = 1;
		b[0] = 1;
		arr[0] = 0;
		for (int i = 1; i <= n; ++i) {
			a[i] = (a[i - 1] * 1ll * i) % MAX;
			b[i] = solve(a[i], MAX - 2);
			arr[i] = 0;
			arr3[i] = 0;
		}

		for (int i = 0; i < n; ++i) {
			vector<int> zz = z_function(st.substr(i, n - i));
			for (int i = 0; i <= n; ++i) {
				arr2[i] = 0;
			}
			for (auto x : zz) {
				arr2[0]++;
				arr2[x + 1]--;
			}

			for (int i = 1; i <= n; ++i) {
				arr2[i] += arr2[i - 1];
				arr3[arr2[i]]++;
			}
			arr[1] += n - i;
		}

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= i; ++j) {
				arr[j + 1] += (arr3[i] * 1ll * Change(i, j)) % MAX;
				arr[j + 1] %= MAX;
			}
		}

		while (q--) {
			cin >> x;
			if (x > n) {
				cout << "0" << endl;
			}
			else {
				cout << arr[x] << endl;
			}
		}

	}
	return 0;
}
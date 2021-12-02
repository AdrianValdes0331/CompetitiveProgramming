//Adrian Valdes Zavala
//A01720439

#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

#define MAX 100002
char patron[MAX];
int lpsv[MAX];
int psv[MAX];
int cont[MAX];

int main() {
	lpsv[0] = -1;
	cin.getline(patron, sizeof patron);
	int n = strlen(patron);
	int i = -1, j = 0, k = 0;

	while (j < n) {
		if (i == -1 || patron[i] == patron[j]) {
			lpsv[j + 1] = i + 1;
			j++; 
			i++;
		}
		else {
			i = lpsv[i];
		}
	}

	j = n;
	while (j) {
		psv[++k] = j;
		j = lpsv[j];
	}

	for (int i = 0; i <= n; ++i) {
		cont[i]++;
	}
	for (int i = n; i > 0; i--) {
		cont[lpsv[i]] += cont[i];
	}

	cout << k << endl;
	for (int i = k; i > 0; --i) {
		cout << psv[i] << " " << cont[psv[i]] << endl;
	}

	return 0;
}


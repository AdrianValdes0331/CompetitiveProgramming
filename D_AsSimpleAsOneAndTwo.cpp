//D_AsSimpleAsOneAndTwo

#include <iostream>
#include <stdio.h>

using namespace std;
int a[100002];

int main() {
	int t;
	string s;
	int cont, pos;

	cin >> t;
	while (t--) {
		cin >> s;
		cont = 0;
		pos = 0;

		for (int i = 0; i < s.size(); i++) {

			if(s[i]=='o' && s[i+1] == 'n' && s[i+2]=='e'){ //one
				cont++;
				a[pos++] = i + 2;
				i = i + 2;
			}

			else if(s[i]=='t' && s[i+1]=='w' && s[i+2]=='o'){ //two
				cont++;
				a[pos++] = i + 2;
				i = i + 2;			
			}
		}

		cout << cont << endl;

		for (int i = 0; i < pos; i++) {
			cout << a[i];
			if (i != (pos-1)) {
				cout << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
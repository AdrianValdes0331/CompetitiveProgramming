//C_KolyaAndTanya
#include <iostream>
#include <stdio.h>

using namespace std;
#define ll long long
#define MAX 1000000007

void solve(ll res, ll tan, int n) {
	for (int i = 1; i <= n; i++) {
		res = res * 27;
		tan = tan * 7;
		res = res % MAX;
		tan = tan % MAX;
	}
	res = ((res + MAX) - tan) % MAX;
	cout << res << endl;
}

int main() {
	int n;
	cin >> n;
	ll res = 1;
	ll tan = 1;
	solve(res, tan, n);
	return 0;
}
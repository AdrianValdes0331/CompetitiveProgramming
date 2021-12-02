//Adrian Valdes
//A01720439
//C. Flea
#include <iostream>
#include <stdio.h>

using namespace std;

void solve(long long n, long long m, long long s) {
	long long x1 = ((n - 1) % s + 1);
	long long x2 = ((n + s - 1) / s);
	long long y1 = ((m - 1) % s + 1);
	long long y2 = ((m + s - 1) / s);
	long long ans = (x1 * y1) * (x2 * y2);
	cout << ans << endl;
}


int main()
{
	long long n, m, s;
	cin >> n >> m >> s;
	solve(n, m, s);
	return 0;
}
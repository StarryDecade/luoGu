#include <iostream>
using namespace std;
const int maxl = 1e5 + 7;

long long n, c, p, q, a[maxl];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 2; i <= n; i++) {
		c = a[i] - a[i - 1];
		if (c > 0) p += c;
		else q -= c;
	}
	long long ans1 = max(p, q);
	long long ans2 = abs(p - q) + 1;
	cout << ans1 << endl << ans2 << endl;
	return 0;
}

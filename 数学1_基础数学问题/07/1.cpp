#include <iostream>
#include <algorithm>
using namespace std;
const int maxl = 1e4 + 7;

int a[maxl];

int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n >> a[1] >> a[2];
		a[2] /= __gcd(a[1], a[2]);
		for (int i = 3; i <= n; i++) {
			cin >> a[i];
			a[2] /= __gcd(a[2], a[i]);
		}
		if (a[2] == 1) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}

#include <iostream>
using namespace std;
const int maxl = 1e5 + 7;

int n, m, a[maxl];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> m;
		a[i] = a[i - 1] + m;
	}
	cin >> m;
	while (m--) {
		int l, r;
		cin >> l >> r;
		cout << a[r] - a[l - 1] << endl;
	}
	return 0;
}

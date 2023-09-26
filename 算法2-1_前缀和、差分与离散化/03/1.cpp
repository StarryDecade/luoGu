#include <iostream>
using namespace std;
const int maxl = 1e7;

int d[maxl];
int a[maxl];

int main() {
	int n, p, x, y, z, i, ans = 1e9;
	cin >> n >> p;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		d[i] = a[i] - a[i - 1];
	} 

	for (int i = 0; i < p; i++) {
		cin >> x >> y >> z;
		d[x] += z;
		d[y + 1] -= z;
	}

	for (int i = 1; i <= n; i++) {
		a[i] = a[i - 1] + d[i];
		ans = min(ans, a[i]);
	}

	cout << ans << endl;
	return 0;
}

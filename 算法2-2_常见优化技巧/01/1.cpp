#include <iostream>
using namespace std;
const int maxl = 1e6 + 7;

int n, m, a[maxl], b[2007], k, ans, l, r, ll, rr;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];

	l = 1, r = 1, k = 1, b[a[1]] = 1, ans = maxl;
	while (l <= r && r <= n) {
		if (k == m) {
			if (ans > r - l + 1) {
				ans = r - l + 1;
				ll = l;
				rr = r;
			}
			b[a[l]]--;
			if (b[a[l]] == 0) k--;
			l++;
		} else {
			r++;
			b[a[r]]++;
			if (b[a[r]] == 1) k++;
		}
	}
	cout << ll << " " << rr << endl;
	return 0;
}

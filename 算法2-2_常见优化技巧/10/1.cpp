#include <iostream>
#include <algorithm>
using namespace std;
const int maxl = 1e5;

int a[maxl], lef[maxl], rig[maxl];

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);

	int L = 1;
	for (int R = 1; R <= n; R++) {
		while(a[R] - a[L] > k) L++;
		lef[R] = max(R - L + 1, lef[R - 1]);
	}

	int R = n;
	for (int L = n; L >= 1; L--) {
		while(a[R] - a[L] > k) R--;
		rig[L] = max(R - L + 1, rig[L + 1]);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) ans = max(ans, lef[i - 1] + rig[i]);
	cout << ans << endl;
	return 0;
}

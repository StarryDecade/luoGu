#include <iostream>
#include <climits>
#include <cstring>
using namespace std;
const int maxl = 1e6 + 7;

int n, t, cnt[maxl], a[maxl];

int main() {
	cin >> t;
	while (t--) {
		int l = 1, r = 1, repeat = 0, maxans = INT_MIN;
		memset(cnt, 0, sizeof(cnt));
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		cnt[a[1]] = 1;
		while (l <= r && r <= n) {
			if (repeat == 0) {
				maxans = max(maxans, r - l + 1);
				r++;;
				if (++cnt[a[l]] > 1) repeat++;
			} else {
				if (--cnt[a[l]] == 1) repeat--;
				l++;
			}
		}
		cout << maxans << endl;
	}
	return 0;
}

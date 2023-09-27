#include <iostream>
using namespace std;
const int maxl = 2 * 1e5 + 7;

int w[maxl], v[maxl], l[maxl], r[maxl];
long long pre_n[maxl], pre_v[maxl];
long long Y, s, sum;
int n, m, mx = -1, mn = 2147483647;

int main() {
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
		mx = max(mx, w[i]);
		mn = min(mn, w[i]);
	}

	for (int i = 1; i <= m; i++) {
		cin >> l[i] >> r[i];
	}
	

	return 0;
}

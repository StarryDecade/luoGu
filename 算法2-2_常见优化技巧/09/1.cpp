#include <functional>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxl = 1e5 + 7;

int n;
double a[maxl], b[maxl], suma[maxl], sumb[maxl];

int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
	sort(a + 1, a + n + 1, greater<double>());
	sort(b + 1, b + n + 1, greater<double>());
	for (int i = 1; i <= n; i++) {
		suma[i] = suma[i - 1] + a[i];
		sumb[i] = sumb[i - 1] + b[i];
	}
	int L = 0, R = 0;
	double ans = 0;
	while (L < n && R < n) {
		if (suma[L] < sumb[R]) L++;
		else R++;
		ans = max(ans, min(suma[L] - L - R, sumb[R] - L - R));
	}
	while(L < n) {L++;ans = max(ans, min(suma[L] - L - R, sumb[R] - L - R));}
	while(R < n) {R++;ans = max(ans, min(suma[L] - L - R, sumb[R] - L - R));}
	printf("%.4f", ans);
	return 0;
}

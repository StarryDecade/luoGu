#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int a0, a1, b0, b1;
		cin >> a0 >> a1 >> b0 >> b1;
		int p = a0 / a1, q = b1 / b0, ans = 0;
		for (int x = 1; x <= sqrt(b1); x++) {
			if (b1 % x == 0) {
				if (x % a1 == 0 && __gcd(x / a1, p) == 1 && __gcd(q, b1 / x) == 1) ans++;
				
				int y = b1 / x;
				if (x == y) continue;
				if (y % a1 == 0 && __gcd(y / a1, p) == 1 && __gcd(q, b1 / y) == 1) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

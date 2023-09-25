#include <iostream>
#include <cmath>
using namespace std;

long long gcd(long long a, long long b) {
	return (b == 0 ? a : gcd(b, a % b));
}

int main() {
	long long n, m, ans = 0;
	cin >> m >> n;

	if (n == m) ans--;
	n *= m;

	for (long long i = 1; i <= sqrt(n); i++) {
		if (n % i == 0 && gcd(i, n / i) == m) ans += 2;
	}
	
	cout << ans << endl;
	return 0;
}

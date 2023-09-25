#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long n, m, ans;

int main() {
	cin >> m >> n;
	if (m == n)	ans--; // gcd(x,y)=lcm(x,y) 即Q == P 
	n *= m;

	for (long long i = 1; i <= sqrt(n); i++) {
		if (n % i == 0 && __gcd(i, n / i) == m)	ans += 2;
	}

	cout << ans << endl;

	return 0;
}

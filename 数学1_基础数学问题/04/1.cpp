#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int a, b, c, d;

int main() {
	scanf("%d/%d", &a, &b);
	while (scanf("%d/%d", &c, &d) != EOF) {
		int m = __gcd(b, d);
		a *= d / m;
		c *= b / m;
		a += c;
		b *= d / m;
		m = __gcd(a, b);
		a /= m;
		b /= m;
	}
	
	if (b < 0) {
		a = -a;
		b = -b;
	}
	if (b == 1) cout << a << endl;
	else cout << a << '/' << b << endl;
	return 0;
}

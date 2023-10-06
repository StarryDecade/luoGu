#include <iostream>
using namespace std;

int a, b, p;

long long qmi() {
	long long  ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % p;
		b >>= 1;
		a = a * a % p;
	}
	return ans;
}

int main() {
	cin >> a >> b >> p;
	cout << a << "^" << b << " mod " << p << "=" << qmi() << endl;
	return 0;
}

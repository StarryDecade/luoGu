#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxl = 1e3 + 7;

int p;
int a[maxl], b[maxl], c[maxl];

void mutip1() {
	memset(c, 0, sizeof(c));
	for (int i = 1; i <= 500; i++) {
		for (int j = 1; j <= 500; j++) {
			c[i + j - 1] += a[i] * b[j];
		}
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}
	memcpy(b, c, sizeof(c));
}

void mutip2() {
	memset(c, 0, sizeof(c));
	for (int i = 1; i <= 500; i++) {
		for (int j = 1; j <= 500; j++) {
			c[i + j - 1] += a[i] * a[j];
		}
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}
	memcpy(a, c, sizeof(c));
}

int main() {
    cin >> p;
    cout << int(log10(2) * p + 1) << endl;
	b[1] = 1;
	a[1] = 2;
    while (p != 0) {
        if (p % 2) mutip1();
		p >>= 1;
		mutip2();
	}
	b[1] -= 1;
	for (int i = 500; i >= 1; i--) {
		if (i != 500 && i % 50 == 0) cout << endl << b[i];
		else cout << b[i];
	}
	return 0;
}

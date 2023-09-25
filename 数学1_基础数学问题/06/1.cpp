#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
const int maxl = 1e6 + 7;
int n, t = 0, c[maxl]; 

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		t = max(t, x);

		for (int i = 1; i <= sqrt(x); i++) {
			if (x % i == 0) {
				c[i]++;
				if (x != i * i)	c[x / i]++;
			}
		}
	}
	int x = t;
	for (int i = 1; i <= n; i++) {
		while (c[x] < i) x--;
		cout << x << endl;
	}
	return 0;
}

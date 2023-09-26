#include <iostream>
#include <algorithm>
using namespace std;
const int maxl = 1e5;

int main() {
	int n;
	cin >> n;
	long long a[maxl], b[maxl], count = 0;
	for (int i = 0; i < n; i++)	cin >> a[i] >> b[i];
	sort(a, a + n);
	sort(b, b + n);

	for (int i = 0; i < n; i++) {
		count += b[i] - a[i];
		if (i + 1 < n) {
			if (b[i] > a[i + 1]) {
				count -= b[i] - a[i + 1];
			}
		}
	}

	cout << count << endl;
	return 0;
}

#include <algorithm>
#include <iostream>
using namespace std;
const int maxl = 200;

int n, preum[maxl][maxl], a[maxl][maxl], sumMax, sum;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			preum[i][j] = preum[i - 1][j] + preum[i][j - 1] - preum[i - 1][j - 1] + a[i][j];
		}
	}

	sumMax = a[1][1];
	for (int x1 = 1; x1 <= n; x1++) {
		for (int y1 = 1; y1 <= n; y1++) {
			for (int x2 = x1; x2 <= n; x2++) {
				for (int y2 = y1; y2 <= n; y2++) {
					sum = preum[x2][y2] - preum[x1 - 1][y2] - preum[x2][y1 - 1] + preum[x1 - 1][y1 - 1];	
					sumMax = max(sumMax, sum);
				}
			}
		}
	}
	cout << sumMax << endl;
	return 0;
}

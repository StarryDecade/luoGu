#include <iostream>
using namespace std;
const int maxl = 1e4 + 7;

int n, m;
int G[maxl][maxl];
int up[maxl][maxl];
int l[maxl][maxl];
int r[maxl][maxl];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char ch;
			cin >> ch;
			if (ch == 'F') G[i][j] = 1;
		}
	}
	
	// 每个点的左边 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!G[i][j]) continue;
			l[i][j] = l[i][j - 1] + 1;
		}
	}

	// 每个点的右边 
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 1; j--) {
			if (!G[i][j]) continue;
			r[i][j] = r[i][j + 1] + 1;
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i > 1 && G[i][j] && G[i - 1][j]) {
				up[i][j] = up[i - 1][j] + 1;
				l[i][j] = min(l[i][j], l[i - 1][j]);
				r[i][j] = min(r[i][j], r[i - 1][j]);
			}
			ans = max(ans, (up[i][j] + 1) * (l[i][j] + r[i][j] - 1));
		}
	}
	cout << 3 * ans << endl;
	return 0;
}

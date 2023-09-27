#include <iostream>
using namespace std;
const int maxl = 1e3;

int r, c, a, b, map[maxl][maxl], s[maxl][maxl], ans;

bool check(int x) {
	int now = 0, num = 0;
	for (int i = 1; i <= r; i++) {
		int dis = 0, sum = 0;
		for (int j = 1; j <= c; j++) {
			if (dis + (s[i][j] - s[i][j - 1]) - (s[now][j] - s[now][j - 1]) < x)
				dis += (s[i][j] - s[i][j - 1]) - (s[now][j] - s[now][j - 1]);
			else {
				sum++;
				dis = 0;
			}
		}
		if (sum >= b) { // 一行 划 b次
			now = i;
			num++;
		}		
	}
	if (num < a)	return 0;
	return 1;
}

int main() {
	cin >> r >> c >> a >> b;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> map[i][j];
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + map[i][j];
		}
	}
	
	int h = 0, t = s[r][c];
	while (h <= t) {
		int mid = (h + t) / 2;
		if (check(mid)) {
			h = mid + 1;
			ans = mid;
		} else t = mid - 1;
	}
	cout << ans << endl;
	return 0;
}

#include <iostream>
#include <cstring>
using namespace std;
#define int long long 
const int maxl = 1e6 + 7;
int n, m;
int diff[maxl], need[maxl], rest[maxl], r[maxl], l[maxl], d[maxl];

bool isok(int x) {
	memset(diff, 0, sizeof(diff));
	for (int i = 1; i <= x; i++) { // 1 ~ m 次借教室
		diff[l[i]] += d[i]; // 在l开始借
		diff[r[i] + 1] -= d[i]; // 在r开始换
	}
	for (int i = 1; i <= n; i++) {
		need[i] = need[i - 1] + diff[i]; // 到现在借了多少
		if (need[i] > rest[i]) return false;
	}
	return true;
}

signed main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> rest[i];
	for (int i = 1; i <= m; i++) cin >> d[i] >> l[i] >> r[i];

	int begin = 1, end = m;
	if (isok(m)) {
		cout << "0";
		return 0;
	} 
	while (begin < end) {
		int mid = (begin + end) / 2;
		if (isok(mid)) begin = mid + 1;
		else end = mid;
	}
	cout << "-1" << endl << begin << endl;
	return 0;
}

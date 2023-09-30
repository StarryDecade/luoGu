#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 7;
struct date {
	int val;
	int num;

}a[N];

bool cmp(date a, date b) {
	if (a.val == b.val) return a.num < b.num;
	return a.val < b.val;
}

int n, ans = 1, cnt;
int vis[N];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].val;
		a[i].num = i;
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		if (i < a[i].num) cnt++; // 当前位置交换过了
		if (vis[i]) cnt--; // 当前位置交换过了 
		vis[a[i].num] = true;
		ans = max(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}

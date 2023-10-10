#include <iostream>
#include <algorithm>
using namespace std;
const int N = 70;

int n, m, a[N], nxt[N], cnt, sum, len;
bool used[N], ok;

bool cmp(int a, int b) {
	return a > b;
}

void dfs(int k, int last, int rest) {
	if (!rest) {
		if (k == m) {
			ok = 1;
			return ;
		}
		for (int i = 1; i <= cnt; i++) {
			if(!used[i]) {
				used[i] = 1;
				dfs(k + 1, i, len - a[i]);
				used[i] = 0;
				break;
			}
		}
		if (ok) return;
	}
	int l = last + 1, r = cnt, mid;
	while (l < r) {
		mid = (l + r) >> 1;
		if (a[mid] <= rest) r = mid;
		else l = mid + 1;
	}
	for (int i = l; i <= cnt; i++) {
		if (!used[i]) {
			used[i] = 1;
			dfs(k, i, rest - a[i]);
			used[i] = 0;
			if (ok) return;

			if (rest == a[i] || rest == len) return;
			i = nxt[i];
			if (i == cnt) return;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[++cnt];
		sum += a[cnt];
	}
	sort(a + 1, a + 1 + n, cmp);

	nxt[cnt] = cnt; // 记录下标
	for (int i = cnt - 1; i > 0; i--) {
		if (a[i] == a[i + 1]) nxt[i] = nxt[i + 1];
		else nxt[i] = i;
	}
	for (len = a[1]; len <= sum / 2; len++) {
		if (sum % len) continue;
		m = sum / len;
		ok = 0;
		used[1] = 1;
		dfs(1, 1, len - a[1]);
		used[1] = 0;
		if (ok) {
			cout << len << endl;
			return 0;
		}
	}
	cout << sum << endl;
	return 0;
}

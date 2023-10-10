#include <iostream>
#include <unordered_map>
using namespace std;
const int N = 30;

unordered_map<long long, long long> M[N];
long long fact[N];
int n, k, a[N];
long long s, ans;

void dfs1(int now, int end, long long S, int used) {
	if (used > k) return;
	if (now > end) {
		M[used][S]++;
		return;
	}
	dfs1(now + 1, end, S, used);
	dfs1(now + 1, end, S + a[now], used);
	if (a[now] <= 20) dfs1(now + 1, end, S + fact[a[now]], used + 1); 
}

void dfs2(int now, int end, long long S, int used) {
	if (used > k) return;
	if (S > s) return;
	if (now > end) {
		for (int i = 0; i <= k - used; i++) ans += M[i][s - S];
		return;
	}
	dfs2(now + 1, end, S, used);
	dfs2(now + 1, end, S + a[now], used);
	if (a[now] <= 20) dfs2(now + 1, end, S + fact[a[now]], used + 1);
}

int main() {
	cin >> n >> k >> s;
	fact[1] = 1ll;
	for (int i = 2; i <= 20; i++) fact[i] = fact[i - 1] * i;
	for (int i = 1; i <= n; i++) cin >> a[i];
	dfs1(1, (n + 1) / 2, 0, 0);
	dfs2((n + 1) / 2 + 1, n, 0, 0);
	cout << ans << endl;
	return 0;
}

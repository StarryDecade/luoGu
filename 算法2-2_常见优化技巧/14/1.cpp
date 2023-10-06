#include <iostream>
#include <deque>
using namespace std;
const int maxl = 5e5 + 7;

int p[2 * maxl], s[2 * maxl];
deque<int> q;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> p[i];
	for (int i = 1; i <= n + m - 1; i++) s[i] = s[i - 1] + p[i];

	int ans = 0;
	for (int i = 1; i <= n + m - 1; i++) {
		while(!q.empty() && i - q.front() + 1 > m) q.pop_front();
		while(!q.empty() && s[q.back()] <= s[i]) q.pop_back();
		q.push_back(i);
		if (i < m) continue;
		int L = i - m + 1;
		int R = q.front();
		if (s[R] - s[L - 1] > ans)	ans = s[R] - s[L - 1];
	}
	cout << ans << endl;
}

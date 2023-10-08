#include <iostream>
#include <set>
using namespace std;
const int N = 2e5 + 7;

int dp[N], m, ans = 0;
set<string> s[20];

int main() {
	string tp;
	while (cin >> tp) {
		if (tp == ".") break;
		s[tp.size()].insert(tp);
		m = max(m, int(tp.size()));
	}

	dp[0] = 1;
	string n = " ";
	while (cin >> tp) n = n + tp;
	for (int i = 1; i < n.size(); i++) {
		for (int j = min(i, m); j >= 1; j--) {
			string tt = n.substr(i - j + 1, j);
			if (s[tt.size()].count(tt) && dp[i - j]) {
				ans = i;
				dp[i] = 1;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}

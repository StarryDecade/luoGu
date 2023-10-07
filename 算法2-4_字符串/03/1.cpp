#include <algorithm>
#include <iostream>
using namespace std;
const int maxl = 2e3 + 7;

int n;
string s[maxl];
int dp[maxl], ans = 0;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		dp[i] = 1;
		for (int j = i - 1; j >= 1; j--) {
			if (s[j][s[i].find(s[j])] == s[i][0]) dp[i] = max(dp[i], dp[i] + 1);
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
	return 0;
}

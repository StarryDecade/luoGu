#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
const int N = 20;

int n;
double ans;
double a[N][N];
double x[N], y[N];
double dp[N][34000];

double dis(int v, int w) {
	return sqrt((x[v] - x[w]) * (x[v] - x[w]) + (y[v] - y[w]) * (y[v] - y[w]));
} 

int main() {
	memset(dp, 127, sizeof(dp));
	ans = dp[0][0];
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	x[0] = 0, y[0] = 0;
	
	for (int i = 0; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			a[i][j] = dis(i, j);
			a[j][i] = a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) dp[i][(1 << (i - 1))] = a[0][i];
	for (int k = 1; k < (1 << n); k++) {
		for (int i = 1; i <= n; i++) {
			if ((k & (1 << (i - 1))) == 0)	continue;
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				if ((k & (1 << (j - 1))) == 0) continue;
				dp[i][k] = min(dp[i][k], dp[j][k - (1 << (i - 1))] + a[i][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) ans = min(ans, dp[i][(1 << n) - 1]);
	printf("%.2f\n", ans);
	return 0;
}

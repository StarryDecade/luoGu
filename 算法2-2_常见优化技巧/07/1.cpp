#include <iostream>
#include <deque>
using namespace std;
const int N = 1e3 + 7;

int a, b, n;
int c[N][N];
int max1[N][N], max2[N][N];
int min1[N][N], min2[N][N];

deque<int> q1, q2;

int main() {
	cin >> a >> b >> n;
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			cin >> c[i][j];
		}
	}
	for (int i = 1; i <= a; i++) {
		q1.clear();
		q2.clear();
		for (int j = 1; j <= b; j++) {
			while(!q1.empty() && j - q1.front() + 1 > n) q1.pop_front();
			while(!q1.empty() && c[i][q1.back()] <= c[i][j]) q1.pop_back();
			q1.push_back(j);
			if (j >= n)	max1[i][j - n + 1] = c[i][q1.front()];

			while(!q2.empty() && j - q2.front() + 1 > n) q2.pop_front();
			while(!q2.empty() && c[i][q2.back()] >= c[i][j]) q2.pop_back();
			q2.push_back(j);
			
			if (j >= n)	min1[i][j - n + 1] = c[i][q2.front()];
		}
	}

	for (int j = 1; j <= b - n + 1; j++) {
		q1.clear();
		q2.clear();
		for (int i = 1; i <= a; i++) {
			while(!q1.empty() && i - q1.front() + 1 > n) q1.pop_front();
			while(!q1.empty() && max1[q1.back()][j] <= max1[i][j]) q1.pop_back();
			q1.push_back(i);
			if (i >= n)	max2[i - n + 1][j] = max1[q1.front()][j];

			while(!q2.empty() && i - q2.front() + 1 > n) q2.pop_front();
			while(!q2.empty() && min1[q2.back()][j] >= min1[i][j]) q2.pop_back();
			q2.push_back(i);
			if (i >= n)	min2[i - n + 1][j] = min1[q2.front()][j];
		}
	}

	int ans = 2e9;
	for (int i = 1; i <= a - n + 1; i++) {
		for (int j = 1; j <= b - n + 1; j++) {
			ans = min(ans, max2[i][j] - min2[i][j]);
		}
	}
	cout << ans << endl;
}

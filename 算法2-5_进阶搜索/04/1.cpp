#include <iostream>
#include <map>
#include <queue>
using namespace std;
#define ll long long
int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};

ll n;

int main() {
	cin >> n;
	queue<ll> q;
	q.push(n);
	map<ll, ll> m;
	m[n] = 0;

	while (!q.empty()) {
		ll u = q.front();
		q.pop();
		int c[3][3], f = 0, g = 0, n = u;
		
		if (u == 123804765) break;

		for (int i = 2; i >= 0; i--) {
			for (int j = 2; j >= 0; j--) {
				c[i][j] = n % 10;
				n /= 10;
				if (!c[i][j]) {
					f = i;
					g = j;
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			int x = f + dx[i];
			int y = g + dy[i];
			ll ns = 0;
			if (x < 0 || y < 0 || x > 2 || y > 2) continue;
			swap(c[x][y], c[f][g]);
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					ns = ns * 10 + c[i][j];
				}
			}
			if (!m.count(ns)) {
				m[ns] = m[u] + 1;
				q.push(ns);
			}
			swap(c[x][y], c[f][g]);
		}
	}
	cout << m[123804765] << endl;
	return 0;
}

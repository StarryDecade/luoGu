#include <iostream>
#include <stack>
using namespace std;

int n, t;
long long ans;
stack<int> a;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t;
		while (!a.empty() && a.top() <= t) {
			a.pop();
		}
		ans += a.size();
		a.push(t);
	}
	cout << ans << endl;
	return 0;
}

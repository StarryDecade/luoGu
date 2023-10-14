#include <functional>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int N = 1e5 + 7;

int n;
int a[N];
int mid;

priority_queue<int, vector<int>, less<int>> ql;
priority_queue<int, vector<int>, greater<int>> qg;

int main (int argc, char *argv[]) {
	cin >> n;
	cin >> a[1];
	mid = a[1];
	cout << mid << endl;
	for (int i = 2; i <= n; i++) {
		cin >> a[i];
		if (a[i] > mid) qg.push(a[i]);
		else ql.push(a[i]);
		if (i % 2) {
			while (ql.size() != qg.size()) {
				if (ql.size() > qg.size()) {
					qg.push(mid);
					mid = ql.top();
					ql.pop();
				} else {
					ql.push(mid);
					mid = qg.top();
					qg.pop();
				}
			}
			cout << mid << endl;
		}
	}
	return 0;
}

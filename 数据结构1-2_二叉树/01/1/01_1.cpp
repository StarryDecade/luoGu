#include <iostream>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

int n;
map<int, int> mp;
queue<int> q;

int main() {
	cin >> n;
	for (int i = 1; i <= pow(2, n); i++) {
		int tmp;
		cin >> tmp;
		mp[i] = tmp;
		q.push(i);
	}

	if (n == 0) {
		cout << 1 << endl;
		return 0;
	}

	while (q.size() > 2) {
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		mp[x] > mp[y] ? q.push(x) : q.push(y);
	}
	
	int x = q.front();
	q.pop();
	int y = q.front();
	q.pop();
	cout << (mp[x] < mp[y] ? x : y) << endl;

	return 0;
}

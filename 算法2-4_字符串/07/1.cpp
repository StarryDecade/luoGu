#include <iostream>
using namespace std;
const int N = 1e6 + 7;

int n, nxt[N];
string s;
long long ans = 0;

int main() {
	cin >> n >> s;
	s = " " + s;

	for (int i = 2, j = 0; i < s.size(); i++) {
		while(j && s[i] != s[j + 1]) j = nxt[j];
		if (s[i] == s[j + 1]) j++;
		nxt[i] = j;
	}
	for (int i = 2, j = 2; i < s.size(); i++, j = i) {
		while(nxt[j]) j = nxt[j];
		if (nxt[i]) nxt[i] = j;
		ans += i - j;
	}
	cout << ans << endl;
	return 0;
}

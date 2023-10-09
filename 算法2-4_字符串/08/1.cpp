#include <iostream>
using namespace std;
const int N = 1e6 + 7;
const int mod = 1e9 + 7;

int n, T;
int nxt[N], num[N];
long long ans;
string s;

/*
*	num[i] —— 在第1到第i位中前缀和后缀相同的数量(前缀后缀重叠也计算进答案).
*	nxt[i] —— 最长公共前后缀的下标
*/
void getnxt() {
	for (int i = 2, j = 0; i < s.size(); i++) {
		while(j && s[i] != s[j + 1]) j = nxt[j];
		if (s[i] == s[j + 1]) j++;
		nxt[i] = j;
		num[i] = num[j] + 1;
		cout << i << " " << j << " " << nxt[i] << " " << num[i] << endl;
	}
}

void getnum() {
	for (int i = 2, j = 0; i < s.size(); i++) {
		while(j && s[i] != s[j + 1]) j = nxt[j];
		if (s[i] == s[j + 1]) j++;
		while((j << 1) > i) j = nxt[j];
		ans = (ans * (long long)(num[j] + 1)) % mod;
	}
}
int main() {
	cin >> T;
	while (T--) {
		ans = 1;
		num[1] = 1;
		cin >> s;
		s = " " + s;
		getnxt();
		getnum();
		cout << ans << endl;
	}
	return 0;
}

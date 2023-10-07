#include <iostream>
using namespace std;
const int maxl = 1e6 + 7;
string a, b;
int kmp[maxl];

void getkmp() { // 字串的next数组
	for (int i = 1, j = 0; i < b.size(); i++) {
		while(j && b[i] != b[j]) j = kmp[j - 1];
		if (b[i] == b[j])	j++;
		kmp[i] = j;
	}
}

void KMP() {
	for (int i = 0, j = 0; i < a.size(); i++) { // 匹配
		while(j && a[i] != b[j]) j = kmp[j - 1];
		if (a[i] == b[j]) j++;
		if (j == b.size()) {
			cout << i - b.size() + 2 << endl; // 相减差一 + 1 下标从1开始 + 1
		}
	}
}

int main() {
	cin >> a >> b;
	getkmp();
	KMP();
	for (int i = 0; i < b.size(); i++) cout << kmp[i] << " ";
	return 0;
}

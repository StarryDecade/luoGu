#include <iostream>
using namespace std;
const int N = 5e5 + 7;

string s;
int n, m, ch[N][26], tag[N], tot = 1;
/*
 *	ch[N][26] —— 节点的关系
 *	tag[N] —— 最后一个字符为节点 u 的名字未被访问到记录为 1
 *	tot —— 节点的个数
 */
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        int u = 1;
        for (int j = 0; j < s.size(); j++) {
            int c = s[j] - 'a';
            if (!ch[u][c]) ch[u][c] = ++tot;
            u = ch[u][c];
        }
        tag[u] = 1;
    }
	cin >> m;
	while (m--) {
		cin >> s;
		int u = 1;
		for (int j = 0; j < s.size(); j++) {
			int c = s[j] - 'a';
			u = ch[u][c];
			if (!u) break;
		}
		if (tag[u] == 1) {
			tag[u] = 2;
			cout << "OK" << endl;
		} else if (tag[u] == 2) cout << "REPEAT" << endl;
		else cout << "WRONG" << endl;
	}
    return 0;
}

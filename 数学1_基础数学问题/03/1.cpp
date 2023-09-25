#include <iostream>
#include <climits>
using namespace std;
const int maxl = 105;
struct node {
	int val;
	int count;
}m_node[maxl];

int idx = 0;//质因子下标
int n, m1, m2, temp, minn = INT_MAX;

int main() {
	cin >> n;
	cin >> m1 >> m2;
	for (int i = 2; i <= m1; i++) { // 分解质因数
		if (m1 % i == 0) {
			idx++;
			m_node[idx].val = i;
			while (m1 % i == 0) {
				m_node[idx].count++;
				m1 /= i;
			}
			m_node[idx].count *= m2;
		}
	}
	while (n--) { // 每种细胞
		cin >> temp;
		bool flag = true;
		for (int i = 1; i <= idx; i++) { // 判断这种细胞的因数能不能包含上面的
			if (temp % m_node[i].val != 0) {
				flag = false;
				break;
			}
		}
		if (flag) { // 能包含
			int maxn = 0;
			for (int i = 1; i <= idx; i++) { // 每种至少几次方算出来
				int cnt = 0;
				while (temp % m_node[i].val == 0) {
					cnt++;
					temp /= m_node[i].val;
				}
				int sec = (m_node[i].count - 1) / cnt + 1;
				maxn = max(maxn, sec); // 求最大值，保证每个因素都能包含
			}
			minn = min(minn, maxn); // 求每种细胞花费时间最少
		}
	}
	cout << (minn == INT_MAX ? -1 : minn )<< endl;
	return 0;
}

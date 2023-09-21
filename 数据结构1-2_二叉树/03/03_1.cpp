#include <iostream>
using namespace std;

void dfs(string s1, string s2) {
    char root = s2[0];
    int len1 = s1.find(root);         // root 的下标
    int len2 = s1.size() - len1 - 1;  // 右子树长度
	if (len1)	dfs(s1.substr(0, len1), s2.substr(1, len1)); // 左子树的中序、前序
	if (len2)	dfs(s1.substr(len1 + 1, len2), s2.substr(len1 + 1, len2)); // 右子树的中序、前序
	cout << root; // 左子树最先遍历完
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    dfs(s1, s2);
    return 0;
}

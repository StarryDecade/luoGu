#include <iostream>
using namespace std;

void traversal(string s1, int inorderBegin, int inorderEnd, string s2, int postorderBegin, int postorderEnd) {
	if (inorderBegin > inorderEnd) return;
	char val = s2[postorderEnd];
	cout << val;

	int delimiterIndex; // 左右子树的分割点
	for (delimiterIndex = inorderBegin; delimiterIndex < inorderEnd; delimiterIndex++) {
		if (s1[delimiterIndex] == val) break;
	}
	
	// 左子树
	// 中序
	int leftInorderBegin = inorderBegin;
	int leftInorderEnd = delimiterIndex - 1;
	// 前序
	int leftpostorderBegin = postorderBegin;
	int leftpostorderEnd = postorderBegin + delimiterIndex - inorderBegin - 1;

	// 右子树
	int rightInorderBegin = delimiterIndex + 1;
	int rightInorderEnd = inorderEnd;
	int rightpostorderBegin = postorderBegin + delimiterIndex - inorderBegin;
	int rightpostorderEnd = postorderEnd - 1;

	traversal(s1, leftInorderBegin, leftInorderEnd, s2, leftpostorderBegin, leftpostorderEnd);
	traversal(s1, rightInorderBegin, rightInorderEnd, s2, rightpostorderBegin, rightpostorderEnd);
	
}



int main() {
	string s1, s2;
	cin >> s1 >> s2;
	traversal(s1, 0, s1.size() - 1, s2, 0, s2.size() - 1);
	return 0;
}

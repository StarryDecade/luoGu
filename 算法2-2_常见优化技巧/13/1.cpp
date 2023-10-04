#include <iostream>
#include <stack>
using namespace std;

stack<int> st;
int n, num, w, h;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> w >> h;
		while(!st.empty() && h <= st.top()) {
			if (h == st.top()) num++;
			st.pop();
		}
		st.push(h);
	}
	cout << n - num << endl;
	return 0;
}

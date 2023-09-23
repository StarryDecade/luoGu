#include<iostream>
#include<cstdio>
#include<vector>
#define pb push_back
const int N = 10010;
const int INF = 0x7fffffff;
inline int read() {
	int r = 0; bool w = 0; char ch = getchar();
	while(ch < '0' || ch > '9') w = ch == '-' ? 1 : w, ch = getchar();
	while(ch >= '0' && ch <= '9') r = (r << 3) + (r << 1) + (ch ^ 48), ch = getchar();
	return w ? ~r + 1 : r;
}
#define ls tree[x].son[0]
#define rs tree[x].son[1]
struct Node {
	int val, siz, cnt, son[2];
}tree[N];
int n, root, tot;
inline void add(int v) {
	if(!tot) {
		root = ++tot;
		tree[tot].cnt = tree[tot].siz = 1;
		tree[tot].son[0] = tree[tot].son[1] = 0;
		tree[tot].val = v;
		return ;
	}
	int x = root, last = 0;
	do {
		++tree[x].siz;
		if(tree[x].val == v) {
			++tree[x].cnt;
			break;
		}
		last = x;
		x = tree[last].son[v > tree[last].val];
		if(!x) {
			tree[last].son[v > tree[last].val] = ++tot;
			tree[tot].son[0] = tree[tot].son[1] = 0;
			tree[tot].val = v;
			tree[tot].cnt = tree[tot].siz = 1;
			break;
		}
	} while(true);//Code by do_while_true qwq
}
int queryfr(int val) {
	int x = root, ans = -INF;
	do {
		if(x == 0) return ans;
		if(tree[x].val >= val) {
			if(ls == 0) return ans;
			x = ls;
		}
		else {
			if(rs == 0) return tree[x].val;
			ans = tree[x].val;
			x = rs;
		}
	} while(true);
}
int queryne(int v) {
	int x = root, ans = INF;
	do {
		if(x == 0) return ans;
		if(tree[x].val <= v) {
			if(rs == 0) return ans;
			x = rs;
		}
		else {
			if(ls == 0) return tree[x].val;
			ans = tree[x].val;
			x = ls;
		}
	} while(true);
}
int queryrk(int rk) {
	int x = root;
	do {
		if(x == 0) return INF;
		if(tree[ls].siz >= rk) x = ls;
		else if(tree[ls].siz + tree[x].cnt >= rk) return tree[x].val;
		else rk -= tree[ls].siz + tree[x].cnt, x = rs;
	} while(true);
}
int queryval(int v) {
	int x = root, ans = 0;
	do {
		if(x == 0) return ans;
		if(tree[x].val == v) return ans + tree[ls].siz;
		else if(tree[x].val > v) x = ls;
		else ans += tree[ls].siz + tree[x].cnt, x = rs;
	} while(true);
}
int main() {
	n = read();
	while(n--) {
		int opt = read(), x = read();
		if(opt == 1) printf("%d\n", queryval(x) + 1);
		if(opt == 2) printf("%d\n", queryrk(x));
		if(opt == 3) printf("%d\n", queryfr(x));
		if(opt == 4) printf("%d\n", queryne(x));
		if(opt == 5) add(x);
	}
	return 0;
}

#include <cstring>
#include <iostream>
using namespace std;
const int maxl = 2 * 1e5 + 7;

int w[maxl], v[maxl], l[maxl], r[maxl];
long long pre_n[maxl], pre_v[maxl];
long long Y, s, sum;
int n, m, mx = -1, mn = 2147483647;

bool check(int W) {
    Y = 0, sum = 0;
    memset(pre_n, 0, sizeof(pre_n));
    memset(pre_v, 0, sizeof(pre_v));
    for (int i = 1; i <= n; i++) {
        if (w[i] >= W) {
            pre_n[i] = pre_n[i - 1] + 1;
            pre_v[i] = pre_v[i - 1] + v[i];
        } else {
            pre_n[i] = pre_n[i - 1];
            pre_v[i] = pre_v[i - 1];
        }
    }
    for (int i = 1; i <= m; i++) {
        Y += (pre_n[r[i]] - pre_n[l[i] - 1]) * (pre_v[r[i]] - pre_v[l[i] - 1]);
    }

    sum = llabs(Y - s);
    if (Y > s)
        return true;
    else
        return false;
}

int main() {
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
        mx = max(mx, w[i]);
        mn = min(mn, w[i]);
    }

    for (int i = 1; i <= m; i++) {
        cin >> l[i] >> r[i];
    }

    int left = mn - 1, right = mx + 2, mid;
    long long ans = 0x3f3f3f3f3f3f3f3f;
    while (left <= right) {
        mid = (left + right) >> 1;
        if (check(mid))
            left = mid + 1;
        else
            right = mid - 1;
        if (sum < ans) ans = sum;
    }
    cout << ans << endl;
    return 0;
}

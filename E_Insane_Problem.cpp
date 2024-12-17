
/*
    Code by: KoKoDuDu
    Created: 15.12.2024 21:54:46
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int k, l, r, x, y;
    cin >> k >> l >> r >> x >> y;
    int ans = 0;
    int tmp = 1;
    while (tmp <= y) {
        int u = (x + tmp - 1) / tmp;
        int v = y / tmp;
        ans += max(0LL, min(r, v) - max(l, u) + 1);
        tmp *= k;
    }
    cout << ans << '\n';
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
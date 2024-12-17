
/*
    Code by: KoKoDuDu
    Created: 14.12.2024 22:40:49
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1), pos(n + 1), check(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    int ans = 1;
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
        check[b[i]] = 1;
    }
    for (int i = 1; i <= m; ++i) {
        int cnt = 0;
        cnt += (pos[b[i]] != 1 && !check[a[pos[b[i]] - 1]]);
        cnt += (pos[b[i]] != n && !check[a[pos[b[i]] + 1]]);
        check[b[i]] = 0;
        ans *= cnt;
        ans %= MOD;
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
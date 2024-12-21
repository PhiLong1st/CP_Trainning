
/*
    Code by: KoKoDuDu
    Created: 19.12.2024 16:28:58
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> dp(1001, vector<int>(1001));
    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        dp[x][y] += x * y;
    }
    for (int i = 1; i <= 1000; ++i) {
        dp[i][1] += dp[i - 1][1];
        dp[1][i] += dp[1][i - 1];
    }
    for (int i = 1; i <= 1000; ++i) {
        for (int j = 1; j <= 1000; ++j) {
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }
    while (q--) {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        if (min(abs(u - x), abs(v - y)) <= 1) {
            cout << 0 << '\n';
            continue;
        }
        x++, y++, u--, v--;
        // cout << x << ' ' << y << ' ' << u << ' ' << v << '\n';
        cout << dp[u][v] - dp[u][y - 1] - dp[x - 1][v] + dp[x - 1][y - 1] << '\n';
    }
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
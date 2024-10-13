

/*
    Code by: KoKoDuDu
    Created: 13.10.2024 19:32:58
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n + 1);
    vector<vector<int>>dp(n + 1, vector<int>(k + 1));
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] = a[i - 1] + a[i];
    }
    for (int i = m; i <= n; i++) {
        int val = a[i] - a[i - m];
        for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i - m][j - 1] + val;
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }
    int ans = 0;
    cout << dp[n][k];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
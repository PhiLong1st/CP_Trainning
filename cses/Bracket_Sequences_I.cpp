
/*
    Code by: KoKoDuDu
    Created: 27.11.2024 15:22:12
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    if (n % 2) return void(cout << 0);
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n / 2 + 2, vector<int>(2)));
    dp[1][1][0] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= min(i, n - i); ++j) {
            dp[i][j][0] = dp[i - 1][j - 1][1] + dp[i - 1][j - 1][0];
            dp[i][j][0] %= MOD;
            dp[i][j][1] = dp[i - 1][j + 1][1] + dp[i - 1][j + 1][0];
            dp[i][j][1] %= MOD;
            // cout << dp[i][j][1] << ' ';
        }
        // cout << '\n';
    }
    cout << dp[n][0][1];
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
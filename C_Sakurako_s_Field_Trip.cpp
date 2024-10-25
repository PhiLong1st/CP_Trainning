

/*
    Code by: KoKoDuDu
    Created: 24.10.2024 23:07:20
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;
const int INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(2, INF));
    dp[1][0] = dp[1][1] = 0;
    for (int i = 2; i <= (n) / 2; ++i) {
        int u = (a[i] == a[i - 1]) + (a[n - i + 1] == a[n - i + 2]);
        int v = (a[i] == a[n - i + 2]) + (a[n - i + 1] == a[i - 1]);
        dp[i][0] = min({ dp[i - 1][0] + u, dp[i - 1][1] + v });
        dp[i][1] = min({ dp[i - 1][0] + v, dp[i - 1][1] + u });
        // cout << dp[i][0] << ' ' << dp[i][1] << '\n';
    }
    int bonus = 0;
    if (n % 2 == 0) {
        bonus = (a[n / 2] == a[(n) / 2 + 1]);
    }   
    else {
        bonus = (a[(n + 1) / 2] == a[n / 2]) + (a[(n + 1) / 2] == a[(n + 1) / 2 + 1]);
    }
    cout << min(dp[(n) / 2][0], dp[(n) / 2][1]) + bonus << '\n';
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
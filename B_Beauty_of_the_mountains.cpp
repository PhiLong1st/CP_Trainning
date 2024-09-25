/*
    Code by: KoKoDuDu
    Created: 21.09.2024 03:45:44
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    vector<vector<int>> sum2d(n + 1, vector<int>(m + 1));
    vector<string>s(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    int sum0 = 0, sum1 = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sum0 += (s[i][j - 1] == '1') ? 0 : a[i][j];
            sum1 += (s[i][j - 1] == '0') ? 0 : a[i][j];
        }
    }
    int dist = abs(sum0 - sum1);
    if (dist == 0) {
        return void(cout << "YES\n");
    }
    // cout << sum0 << " " << sum1 << "\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sum2d[i][j] = sum2d[i - 1][j] + sum2d[i][j - 1] - sum2d[i - 1][j - 1] + (s[i][j - 1] == '1');
            // cout << dp[i][j] << " ";
        }
        // cout << "\n";
    }
    set<int> div;
    for (int i = k; i <= n; i++) {
        for (int j = k; j <= m; j++) {
            int sum = sum2d[i][j] - sum2d[i - k][j] - sum2d[i][j - k] + sum2d[i - k][j - k];
            if (abs(2 * sum - k * k) != 0) {
                div.insert(abs(2 * sum - k * k));
            }
        }
    }
    if (div.empty()) {
        return void(cout << "NO\n");
    }
    vector<int>dp(1000);
    dp[0] = 1;
    int last = 0;

    // cout << dist << " ";
    int gcd = 0;
    for (int val : div) {
        // cout << val << " ";
        gcd = __gcd(gcd, val);
    }
    if (dist % gcd == 0) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

    // for (int i = 0; i < 1000; i++) {
    //     for (int val : div) {
    //         if (i >= val) {
    //             dp[i] = max(dp[i], dp[i - val]);
    //         }
    //     }
    //     if (dp[i] == 1) {
    //         last = i;
    //     }
    // }
    // // cout << last << "a";
    // if (last != 0)
    //     dist %= last;
    // cout << ((dp[dist]) ? "YES\n" : "NO\n");
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int numTest = 1;
    cin >> numTest;
    while (numTest--) {
        solve();
    }
    return 0;
}
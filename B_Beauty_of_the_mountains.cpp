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
    int cnt_zero = 0, cnt_one = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cnt_zero += (s[i][j - 1] == '1') ? 0 : a[i][j];
            cnt_one += (s[i][j - 1] == '0') ? 0 : a[i][j];
        }
    }
    int dist = abs(cnt_zero - cnt_one);
    if (dist == 0) return void(cout << "YES\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sum2d[i][j] = sum2d[i - 1][j] + sum2d[i][j - 1] - sum2d[i - 1][j - 1] + (s[i][j - 1] == '1');
        }
    }
    set<int> divisors;
    for (int i = k; i <= n; i++) {
        for (int j = k; j <= m; j++) {
            int val = sum2d[i][j] - sum2d[i - k][j] - sum2d[i][j - k] + sum2d[i - k][j - k];
            if (abs(2 * val - k * k) != 0) {
                divisors.insert(abs(2 * val - k * k));
            }
        }
    }
    if (divisors.empty()) return void(cout << "NO\n");
    int gcd = 0;
    for (int val : divisors) {
        gcd = __gcd(gcd, val);
    }
    cout << ((dist % gcd == 0) ? "YES\n" : "NO\n");
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
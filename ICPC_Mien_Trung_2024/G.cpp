

/*
    Code by: KoKoDuDu
    Created: 22.10.2024 15:35:34
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    vector<vector<int>>a(n + 2, vector<int>(m + 2));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            a[i][j] = 1;
        }
    }
    cout << a[p - 1][q - 1] + a[p - 1][q] + a[p - 1][q + 1] + a[p][q - 1] + a[p][q + 1] + a[p + 1][q - 1] + a[p + 1][q] + a[p + 1][q + 1];
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
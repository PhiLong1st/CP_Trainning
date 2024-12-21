
/*
    Code by: KoKoDuDu
    Created: 20.12.2024 22:17:18
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> ans(n + 1);
    if (n % 2 == 0) {
        for (int i = 1; i <= n; ++i) {
            ans[i] = i % 2;
        }
        if (x % 2 == y % 2) {
            ans[y] = 2;
        }
    }
    else {
        ans[x] = 2;
        for (int i = 1; i < x; ++i) {
            ans[i] = (i + 1) % 2;
        }
        for (int i = x + 1; i <= n; ++i) {
            ans[i] = i % 2;
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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
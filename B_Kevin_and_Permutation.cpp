
/*
    Code by: KoKoDuDu
    Created: 19.12.2024 21:51:58
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> isUsed(n + 1), ans(n + 1);
    int cnt = 1;
    for (int i = k; i <= n; i += k) {
        ans[i] = cnt++;
    }
    for (int i = 1; i <= n; ++i) {
        if (ans[i] == 0) {
            ans[i] = cnt++;
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

/*
    Code by: KoKoDuDu
    Created: 02.12.2024 22:27:25
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;
const int INF = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> suf(n);
    string s;
    cin >> s;
    for (int i = n - 1; i >= 0; --i) {
        if (i == n - 1) suf[i] = ((s[i] == '1') ? 1 : -1);
        else suf[i] = suf[i + 1] + ((s[i] == '1') ? 1 : -1);
    }
    sort(suf.begin() + 1, suf.end(), greater<>());
    int ans = 0;
    // for (int i = 0; i < n; ++i) {
    //     cout << suf[i] << ' ';
    // }
    // if (ans >= k) {
    //     cout << 2 << '\n';
    //     return;
    // }
    for (int i = 1; i < n; ++i) {
        if (ans >= k) {
            cout << i << '\n';
            return;
        }
        ans += suf[i];
    }
    if (ans >= k) {
        cout << n << '\n';
        return;
    }
    cout << -1 << '\n';
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

/*
    Code by: KoKoDuDu
    Created: 03.12.2024 01:27:07
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), suf(n + 2);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = n; i >= 1; --i) {
        suf[i] = suf[i + 1] + a[i];
    }
    int ans = suf[1];
    for (int i = 2; i <= n; ++i) {
        if (suf[i] >= 0) {
            ans += suf[i];
        }
    }
    cout << ans << '\n';
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
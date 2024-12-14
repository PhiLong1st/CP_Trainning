
/*
    Code by: KoKoDuDu
    Created: 03.12.2024 01:40:14
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), suf(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = n; i >= 1; --i) {
        if (i == n) suf[i] = a[i];
        else suf[i] = suf[i + 1] + a[i];
    }
    int ans = suf[1];
    sort(suf.begin() + 2, suf.end(), greater<>());
    // for (int i = 1;i <= n; ++i) {
    //     cout << suf[i] << ' ';
    // }
    for (int i = 2; i <= k; ++i) {
        ans += suf[i];
    }
    cout << ans;
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
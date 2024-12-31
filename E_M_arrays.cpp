
/*
    Code by: KoKoDuDu
    Created: 29.12.2024 14:55:05
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), cnt(m + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        cnt[a[i] % m]++;
    }
    int ans = (cnt[0] != 0);
    for (int i = 1; i <= m / 2; ++i) {
        if (i * 2 == m) {
            ans += (cnt[i] != 0);
            continue;
        }
        if (cnt[i] + cnt[m - i] == 0) continue;
        if (abs(cnt[i] - cnt[m - i]) <= 1) {
            ans++;
        }
        else {
            ans += cnt[i] + cnt[m - i] - 2 * min(cnt[i], cnt[m - i]);
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
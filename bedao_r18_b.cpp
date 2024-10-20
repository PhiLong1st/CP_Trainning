

/*
    Code by: KoKoDuDu
    Created: 19.10.2024 09:33:24
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
    vector<int> a(n + 1), maxx(n + 1), minn(n + 1, INF);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] = a[i - 1] + a[i];
    }
    for (int i = k; i <= n; i++) {
        maxx[i] = max(maxx[i - 1], a[i] - a[i - k]);
        minn[i] = min(minn[i - 1], a[i] - a[i - k]);
        // cout << minn[i] << ' ';
    }
    int ans = 0;
    for (int i = 2 * k; i <= n; i++) {
        ans = max(ans, abs(a[i] - a[i - k] - maxx[i - k]));
        ans = max(ans, abs(a[i] - a[i - k] - minn[i - k]));
        // cout << a[i] - a[i - k] << ' ' << minn[i - k] << '\n';
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

/*
    Code by: KoKoDuDu
    Created: 16.12.2024 17:28:02
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), prefix_sum(2 * n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        a.push_back(a[i]);
    }
    for (int i = 1; i <= 2 * n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + a[i];
    }
    auto query = [&](int prefix) -> int {
        int ans = prefix / n * prefix_sum[n];
        int start = prefix / n;
        ans += prefix_sum[start + prefix % n] - prefix_sum[start];
        return ans;
        };
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << query(r) - query(l - 1) << '\n';
    }
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
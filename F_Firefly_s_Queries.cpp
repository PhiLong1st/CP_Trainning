
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
    vector<int> a(n + 1), prefix_sum(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        prefix_sum[i] = prefix_sum[i - 1] + a[i];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int left = (l + n - 1) / n;
        int right = (r + n - 1) / n;
        int ans = 0;
        int pre = 0, suf = 0;
        cout << left << ' ' << right << '\n';
        if (right != left) {
            ans = (right - left - 1) * prefix_sum[n];
            suf = prefix_sum[min(n, right + r - n * (right - 1))] - prefix_sum[right - 1] + prefix_sum[(right + r - n * (right - 1) - 1) % n];
            pre = prefix_sum[n] - prefix_sum[min(left + l - n * (left - 1) - 1, n)] + prefix_sum[(left + l - n * (left - 1)) % n];
        }
        else {
        }
        cout << prefix_sum[n] - prefix_sum[min(left + l - n * (left - 1) - 1, n)] << ' ';
        // cout << suf << ' ' << pre << " ";
        // cout << pre << ' ' << suf << ' ' << prefix_sum[(right + r - n * (right - 1) - 1) % n] << '\n';
        // cout << prefix_sum[min(n, right + r - n * (right - 1))] - prefix_sum[right - 1] << '\n';
        cout << ans + suf + pre << '\n';
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
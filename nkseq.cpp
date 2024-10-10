
/*
    Code by: KoKoDuDu
    Created: 30.09.2024 11:08:20
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, ans = 0;
    cin >> n;
    vector<int> a(n + 1), prefix_sum(n + 1), min_left(n + 1, INT_MAX), min_right(n + 2, INT_MAX);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        prefix_sum[i] = prefix_sum[i - 1] + a[i];
        min_left[i] = min(min_left[i - 1], prefix_sum[i]);
    }
    for (int i = n; i >= 1; --i) {
        min_right[i] = min(min_right[i + 1], prefix_sum[i]);
    }
    for (int i = 1; i <= n; ++i) {
        ans += ((min_right[i] > prefix_sum[i - 1]) && (prefix_sum[n] - prefix_sum[i - 1] + min_left[i - 1] > 0));
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
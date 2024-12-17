
/*
    Code by: KoKoDuDu
    Created: 16.12.2024 17:12:51
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    int pre = n * k + n * (n - 1) / 2;
    int l = 0, r = n - 1;
    int ans = INT_MAX;
    int pos = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        int val = mid * (2 * k + mid - 1);
        if (val <= pre) {
            pos = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    for (int i = max(0LL, pos - 5); i <= min(n - 1, pos + 5); ++i) {
        int val = i * (2 * k + i - 1);
        ans = min(ans, abs(pre - val));
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
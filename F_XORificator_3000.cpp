
/*
    Code by: KoKoDuDu
    Created: 30.12.2024 16:52:56
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int l, r, p, k;
    cin >> l >> r >> p >> k;
    auto calc_xor_1_n = [&](int n) {
        if (n % 4 == 0) return n;
        if (n % 4 == 3) return 0LL;
        if (n % 4 == 2) return (n - 2) ^ (n - 1) ^ n;
        if (n % 4 == 1) return (n - 1) ^ n;
        };
    auto calc = [&](int x) {
        int ans = 0;
        if (x < k) {
            return 0LL;
        }
        if (x == k) {
            return k;
        }
        x -= k;
        int cnt = x / (1LL << p);
        // cout << cnt << ' ';
        int remain = ((cnt % 4) % 2) ? 0 : k;
        return (calc_xor_1_n(cnt) << p) ^ remain;
        };
    // cout << (calc_xor_1_n(3) << p) << ' ';
    // cout << (calc(l - 1) ^ calc_xor_1_n(l - 1)) << ' ';
    // cout << (calc(r) ^ calc_xor_1_n(r));
    // cout << calc(r) << ' ';
    // cout << calc_xor_1_n(r);
    // int ans = 0;
    // for (int i = 1; i <= r; ++i) {
    //     if (i % (1LL << p) != k) {
    //         ans ^= i;
    //     }
    // }
    // cout << ans << ' ';
    // ans = 0;
    // for (int i = 1; i < l; ++i) {
    //     if (i % (1LL << p) != k) {
    //         ans ^= i;
    //     }
    // }
    // cout << ans;
    cout << ((calc(r) ^ calc_xor_1_n(r)) ^ (calc(l - 1) ^ calc_xor_1_n(l - 1))) << '\n';
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
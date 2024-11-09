
/*
    Code by: KoKoDuDu
    Created: 09.11.2024 22:01:12
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int l, r, k;
    cin >> l >> r >> k;
    cout << max(0LL, r / k - l + 1) << '\n';
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
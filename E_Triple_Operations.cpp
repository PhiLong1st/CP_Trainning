
/*
    Code by: KoKoDuDu
    Created: 17.12.2024 10:44:43
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int l, r;
    cin >> l >> r;
    int ans = 0;
    int tmp = l;
    int rem = 0;
    int pos = 1;
    while (tmp > 0) {
        ans += 2;
        rem++;
        pos *= 3;
        tmp /= 3;
    }
    while (pos <= r) {
        ans += 1 + (pos - l) * rem;
        rem++;
        l = pos;
        pos *= 3;
    }
    ans += (r - l) * rem;
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
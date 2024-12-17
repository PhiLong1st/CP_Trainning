
/*
    Code by: KoKoDuDu
    Created: 15.12.2024 21:41:39
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int m, a, b, c;
    cin >> m >> a >> b >> c;
    int ans = 0;
    int r1 = m - min(m, a);
    int r2 = m - min(m, b);
    ans += min(m, a);
    ans += min(m, b);
    ans += min(r1 + r2, c);
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
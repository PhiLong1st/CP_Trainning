
/*
    Code by: KoKoDuDu
    Created: 17.12.2024 10:17:35
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = 0;
    ans += ((min(a, b) > min(c, d)) && (max(a, b) > max(c, d)));
    ans += (min(a, b) > max(c, d)) && (max(a, b) > min(c, d));
    ans += ((max(a, b) > min(c, d)) && (min(a, b) > max(c, d)));
    ans += (max(a, b) > max(c, d)) && (min(a, b) > min(c, d));

    ans += ((min(a, b) > min(c, d)) && (max(a, b) == max(c, d)));
    ans += (min(a, b) > max(c, d)) && (max(a, b) == min(c, d));
    ans += ((max(a, b) > min(c, d)) && (min(a, b) == max(c, d)));
    ans += (max(a, b) > max(c, d)) && (min(a, b) == min(c, d));

    ans += ((min(a, b) == min(c, d)) && (max(a, b) > max(c, d)));
    ans += (min(a, b) == max(c, d)) && (max(a, b) > min(c, d));
    ans += ((max(a, b) == min(c, d)) && (min(a, b) > max(c, d)));
    ans += (max(a, b) == max(c, d)) && (min(a, b) > min(c, d));
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
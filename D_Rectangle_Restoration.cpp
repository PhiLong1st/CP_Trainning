
/*
    Code by: KoKoDuDu
    Created: 01.10.2024 15:52:06
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    double x, y;
    cin >> x >> y;
    double ans = numeric_limits<double>::max();
    if (x >= y) {
        if (2.0 * y > x)
            ans = min(ans, x / 2.0 + y);
    }
    else {
        if (2.0 * x > y) {
            ans = min(ans, 2.0 * x);
        }
        ans = min(ans, 2.0 * y - x);
        ans = min(ans, y + x / 2.0);
    }
    if (ans == numeric_limits<double>::max()) {
        cout << -1;
        return;
    }
    cout << fixed << setprecision(4) << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int numTest = 1;
    while (numTest--) {
        solve();
    }
    return 0;
}
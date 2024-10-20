

/*
    Code by: KoKoDuDu
    Created: 20.10.2024 08:19:07
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    while (a != 0 && b != 0) {
        ans++;
        if (a < b) {
            b -= a;
        }
        else {
            a -= b;
        }
        // cout << a << ' ' << b << '\n';
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
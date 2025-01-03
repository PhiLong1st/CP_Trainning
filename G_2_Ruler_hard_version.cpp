
/*
    Code by: KoKoDuDu
    Created: 17.12.2024 11:59:28
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    function < int(int, int)> ask = [&](int a, int b) {
        cout << "? " << a << " " << b << "\n";
        cout.flush();
        int x;
        cin >> x;
        return x;
        };
    int l = 2, r = 999;
    int ans = 0;
    for (int i = 1; i <= 7;++i) {
        int x1 = l + (r - l) / 3;
        int x2 = r - (r - l) / 3;
        int val = ask(x1, x2);
        if (val == x1 * x2) {
            l = x2 + 1;
        }
        if (val == x1 * (x2 + 1)) {
            l = x1 + 1;
            r = x2 - 1;
            ans = x2;
        }
        if (val == (x1 + 1) * (x2 + 1)) {
            r = x1 - 1;
            ans = x1;
        }
    }
    cout << "! " << ans << '\n';
    cout.flush();
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
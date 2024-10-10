

/*
    Code by: KoKoDuDu
    Created: 06.10.2024 01:36:24
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
    }
    double l = 0, r = 1e18;
    for (int i = 1; i <= n; ++i) {
        if (r < 1.0 * i / b[i]) return void(cout << "-1\n");
        if (a[i] != 0) {
            if (1.0 * i / a[i] < l) return void(cout << "-1\n");
            r = min(r, 1.0 * i / a[i]);
        }
        l = max(l, 1.0 * i / b[i]);
    }
    cout << fixed << setprecision(12) << l << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
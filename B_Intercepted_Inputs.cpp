
/*
    Code by: KoKoDuDu
    Created: 19.12.2024 15:26:59
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector <int> check(n + 1), a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        int x = a[i];
        if ((n - 2) % x == 0 && check[(n - 2) / x]) {
            cout << x << ' ' << (n - 2) / x << '\n';
            return;
        }
        check[x] = 1;
    }
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

/*
    Code by: KoKoDuDu
    Created: 28.10.2024 21:41:49
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    int tmp = min(x, y);
    cout << 0 << ' ' << 0 << ' ' << tmp << ' ' << tmp << '\n';
    cout << 0 << ' ' << tmp << ' ' << tmp << ' ' << 0 << '\n';
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
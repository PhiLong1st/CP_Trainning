
/*
    Code by: KoKoDuDu
    Created: 16.12.2024 16:19:13
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    int a = (x + k - 1) / k;
    int b = (y + k - 1) / k;
    if (a <= b) {
        cout << 2 * a + (b - a) * 2 << '\n';
    }
    else {
        cout << 2 * b + (a - b) * 2 - 1 << '\n';
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
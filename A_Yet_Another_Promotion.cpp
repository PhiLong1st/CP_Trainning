
/*
    Code by: KoKoDuDu
    Created: 29.12.2024 14:22:35
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int a, b, n, m;
    cin >> a >> b >> n >> m;
    cout << min(((n / (m + 1)) * m) * a, ((n / (m + 1)) * (m + 1)) * b) + (n % (m + 1)) * min(a, b) << '\n';
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
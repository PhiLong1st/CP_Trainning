
/*
    Code by: KoKoDuDu
    Created: 01.10.2024 15:03:00
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    int ans = INT_MAX;
    for (int i = 1; i < 100; ++i) {
        for (int j = i + 1; j <= 100; ++j) {
            if (i * a + j * b <= n) {
                ans = min(ans, n - i * a - j * b);
            }
        }
    }
    cout << ans;
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
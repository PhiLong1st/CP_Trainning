
/*
    Code by: KoKoDuDu
    Created: 26.09.2024 02:15:23
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, p, w, d, x = 0;
    cin >> n >> p >> w >> d;
    for (int i = 0;i < 1e6;i++)
        if (p >= i * d && (p - i * d) % w == 0 && (x = (p - i * d) / w) + i <= n) {
            cout << x << ' ' << i << ' ' << n - x - i;
            return;
        }
    cout << -1;
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
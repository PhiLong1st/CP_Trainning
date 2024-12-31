
/*
    Code by: KoKoDuDu
    Created: 29.12.2024 16:03:47
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    if (n == 1 || n == 2) {
        cout << -1;
        return;
    }
    if (n % 2 == 0) {
        cout << ((n * n) / 4 - 1) << ' ' << ((n * n) / 4 + 1);
    }
    else {
        cout << ((n * n + 1) / 2 - 1) << ' ' << ((n * n + 1) / 2);
    }
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

/*
    Code by: KoKoDuDu
    Created: 19.12.2024 15:33:09
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    if (n <= 4) {
        cout << "-1 \n";
        return;
    }
    for (int i = 1; i <= n; i += 2) {
        if (i != 5) cout << i << ' ';
    }
    cout << 5 << ' ' << 4 << ' ';
    for (int i = 2; i <= n; i += 2) {
        if (i != 4) cout << i << ' ';
    }
    cout << '\n';
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

/*
    Code by: KoKoDuDu
    Created: 19.12.2024 17:55:08
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    if (n % 4 == 0) {
        for (int i = 0; i < n; ++i) {
            cout << i << ' ';
        }
        cout << '\n';
    }
    if (n % 4 == 1) {
        for (int i = 4; i < n + 3; ++i) {
            cout << i << ' ';
        }
        cout << 0 << '\n';
    }
    if (n % 4 == 2) {
        for (int i = 0; i < n - 6; ++i) {
            cout << i << ' ';
        }
        cout << (1LL << 21) << ' ' << (1LL << 22) << ' ' << (1LL << 23) << ' ' << (1LL << 24) << ' ' << ((1LL << 21) ^ (1LL << 23)) << ' ' << ((1LL << 22) ^ (1LL << 24));
        cout << '\n';
    }
    if (n % 4 == 3) {
        for (int i = 4; i < n + 1; ++i) {
            cout << i << ' ';
        }
        cout << 2 << ' ' << 1 << ' ' << 3;
        cout << '\n';
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
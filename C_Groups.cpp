
/*
    Code by: KoKoDuDu
    Created: 01.10.2024 15:17:37
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<bitset<1001>>a(6);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 5; ++j) {
            int x;
            cin >> x;
            if (x == 1) {
                a[j].set(i);
            }
        }
    }
    for (int i = 1; i <= 5; ++i) {
        for (int j = 1; j <= 5; ++j) {
            if (i == j) continue;
            int x = a[i].count(), y = a[j].count();
            bitset<1001> tmp = a[i] | a[j];
            if (x >= n / 2 && y >= n / 2 && tmp.count() == n) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
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
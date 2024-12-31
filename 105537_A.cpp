
/*
    Code by: KoKoDuDu
    Created: 30.12.2024 19:38:58
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int l, h;
    cin >> l >> h;
    if (l % 2 != 0) {
        cout << h;
    }
    else {
        cout << h - h % 2;
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
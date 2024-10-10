
/*
    Code by: KoKoDuDu
    Created: 26.09.2024 02:03:56
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    if ((a + c - 1) / c + (b + d - 1) / d > k) {
        cout << "-1\n";
    }
    else {
        cout << (a + c - 1) / c << ' ' << (b + d - 1) / d << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int numTest = 1;
    cin >> numTest;
    while (numTest--) {
        solve();
    }
    return 0;
}
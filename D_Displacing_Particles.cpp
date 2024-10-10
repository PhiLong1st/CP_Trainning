
/*
    Code by: KoKoDuDu
    Created: 27.09.2024 20:17:56
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

int getMinBit(int n) {
    if (n == 0)
        return 0;  // No bits are set
    return n & -n;
}
void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << min(a - 1 - __builtin_ctz(b), a - 1 - __builtin_ctz(c));
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
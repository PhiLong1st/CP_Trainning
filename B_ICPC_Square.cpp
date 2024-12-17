
/*
    Code by: KoKoDuDu
    Created: 17.12.2024 09:56:42
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n, d, s;
    cin >> n >> d >> s;
    n /= s;
    d /= s;

    int mul = 1;
    if (d == 0) {
        mul = 1;
    }
    else if (n >= 2 * d) {
        mul = 2 * d;
    }
    else if (n <= d + 1) {
        mul = n;
    }
    else {
        for (int x = 2; x <= 1000000; x++) {
            int g = min(n / x, d / (x - 1));
            mul = max(mul, x * g);
        }
    }
    cout << s * mul;
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


/*
    Code by: KoKoDuDu
    Created: 19.10.2024 09:14:07
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int a, b;
    cin >> a >> b;
    if (a == 0) {
        cout << 0 << ' ' << 1 << '\n';
        return;
    }
    if (a + b == 0) {
        cout << 0 << ' ' << 0 << '\n';
        return;
    }
    if ((a < 0 && b < 0) || (a >= 0 && b > 0)) {
        int gcd = __gcd(abs(a), abs(b));
        a /= gcd;
        b /= gcd;
        cout << abs(a) << ' ' << abs(b) << '\n';
    }
    else {
        if (abs(a) < abs(b)) {
            int gcd = __gcd(abs(a), abs(b));
            a /= gcd;
            b /= gcd;
            cout << '-' << abs(a) << ' ' << abs(b) << '\n';
        }
        else {
            int gcd = __gcd(abs(a), abs(b));
            a /= gcd;
            b /= gcd;
            cout << abs(a) << ' ' << '-' << abs(b) << '\n';
        }
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
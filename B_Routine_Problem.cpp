

/*
    Code by: KoKoDuDu
    Created: 13.10.2024 18:30:57
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a * d <= b * c) {
        int t = __gcd(b * c - a * d, b * c);
        cout << (b * c - a * d) / t << "/" << (b * c) / t << "\n";
    }
    else {
        int t = __gcd(d * a - b * c, a * d);
        cout << (d * a - b * c) / t << "/" << (a * d) / t << "\n";
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
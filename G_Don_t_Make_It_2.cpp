

/*
    Code by: KoKoDuDu
    Created: 26.10.2024 17:35:12
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    if (n <= 3) {
        cout << 1 << '\n';
        return;
    }
    if (n % 2) n--;
    int lg = log2(n);
    cout << (1LL << lg) - 1 << '\n';
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
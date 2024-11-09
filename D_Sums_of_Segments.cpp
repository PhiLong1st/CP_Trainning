
/*
    Code by: KoKoDuDu
    Created: 28.10.2024 22:09:14
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] = a[i - 1] + a[i];
        b[i] = b[i - 1] + a[i];
    }
    int q;
    cin >> q;
    function<int(int, int)>getSum = [&](int x, int y) {
        if (y < x) return 0LL;
        return a[y] - a[x - 1];
        };
    while (q--) {
        int l, r;
        cin >> l >> r;
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
}int
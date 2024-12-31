
/*
    Code by: KoKoDuDu
    Created: 28.12.2024 21:36:52
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    bool isOk = false;
    for (int i = 1; i < n; ++i) {
        if (min(a[i], a[i + 1]) * 2 > max(a[i], a[i + 1])) {
            isOk = true;
        }
        if (a[i] == a[i + 1]) {
            isOk = true;
        }
    }
    cout << ((isOk) ? "YES\n" : "NO\n");
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